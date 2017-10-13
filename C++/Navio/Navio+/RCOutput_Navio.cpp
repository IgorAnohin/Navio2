#include "RCOutput_Navio.h"

RCOutput_Navio::RCOutput_Navio()
{

}

bool RCOutput_Navio::initialize()
{
    static const uint8_t outputEnablePin = RPI_GPIO_27;


    Pin pin(outputEnablePin);

    if (pin.init()) {
        pin.setMode(Pin::GpioModeOutput);
        pin.write(0); /* drive Output Enable low */
    } else {
        fprintf(stderr, "Output Enable not set. Are you root?\n");
        return 0;
    }

    pwm.initialize();
    return 1;
}

void RCOutput_Navio::setFrequency(float frequency)
{
    pwm.setFrequency(frequency);
}

bool RCOutput_Navio::set_duty_cycle(unsigned int channel, float period)
{
    pwm.setPWMmS(channel+3, period / 1000); // 1st Navio RC output is 3 and period must be less 10

}
