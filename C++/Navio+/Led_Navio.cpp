#include "Led_Navio.h"

Led_Navio::Led_Navio()
{

}


bool Led_Navio::initialize()
{
    static const uint8_t outputEnablePin = RPI_GPIO_27;
    Pin pin(outputEnablePin);

    if (pin.init()) {
        pin.setMode(Pin::GpioModeOutput);
        pin.write(0); /* drive Output Enable low */
    } else {
        fprintf(stderr, "Output Enable not set. Are you root?\n");
        return true;
    }

    pwm.initialize();
    return false;
}

void Led_Navio::setColor(Colors color)
{
    switch (color)
    {
        case Colors::Yellow:
            pwm.setPWM(2, 0);
            pwm.setPWM(1, 0);
            pwm.setPWM(0, 4095);
            break;
        case Colors::Green:
            pwm.setPWM(2, 4095);
            pwm.setPWM(1, 0);
            pwm.setPWM(0, 4095);
            break;
        case Colors::Cyan:
            pwm.setPWM(2, 4095);
            pwm.setPWM(1, 0);
            pwm.setPWM(0, 0);
            break;
        case Colors::Magenta:
            pwm.setPWM(2, 0);
            pwm.setPWM(1, 4095);
            pwm.setPWM(0, 0);
            break;
        case Colors::Red:
            pwm.setPWM(2, 0);
            pwm.setPWM(1, 4095);
            pwm.setPWM(0, 4095);
            break;
        case Colors::Blue:
            pwm.setPWM(2, 4095);
            pwm.setPWM(1, 4095);
            pwm.setPWM(0, 0);
            break;
    }
}
