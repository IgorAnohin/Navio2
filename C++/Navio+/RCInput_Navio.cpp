#include "RCInput_Navio.h"

RCInput_Navio::RCInput_Navio()
{

}

RCInput_Navio::~RCInput_Navio()
{
}

static void RCInput_Navio::ppmOnEdgeTrampolin(int gpio, int level, uint32_t tick, void *userdata)
{
    RCInput_Navio *self = (RCInput_Navio *) userdata;

    self->ppmOnEdge(gpio, level, tick);
}

void RCInput_Navio::ppmOnEdge(int gpio, int level, uint32_t tick, void *userdata)
    {
    if (level == 0) {
        deltaTime = tick - previousTick;
        previousTick = tick;

        if (deltaTime >= ppmSyncLength) { // Sync
            currentChannel = 0;

            // RC output
            for (int i = 0; i < ppmChannelsNumber; i++)
                self->pwm->setPWMuS(i + 3, channels[i]); // 1st Navio RC output is 3

        }
        else
            if (currentChannel < ppmChannelsNumber)
                channels[currentChannel++] = deltaTime;
    }
}

void RCInput_Navio::initialize()
{
    Pin pin(outputEnablePin);

    if (pin.init()) {
        pin.setMode(Pin::GpioModeOutput);
        pin.write(0); /* drive Output Enable low */
    } else {
        fprintf(stderr, "Output Enable not set. Are you root?");
    }

    // Servo controller setup

    pwm = new PCA9685();
    pwm->initialize();
    pwm->setFrequency(servoFrequency);

    // GPIO setup

    gpioCfgClock(samplingRate, PI_DEFAULT_CLK_PERIPHERAL, 0);
    gpioInitialise();
    previousTick = gpioTick();
    gpioSetAlertFuncEx(ppmInputGpio, RCInput_Navio::ppmOnEdgeTrampolin, this);
}

int RCInput_Navio::read(int ch)
{
    return channels[ch];
}

