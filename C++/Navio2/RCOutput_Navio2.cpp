#include "RCOutput_Navio2.h"

#define PWM_OUTPUT 0


RCOutput_Navio2::RCOutput_Navio2()
{

}

bool RCOutput_Navio2::initialize()
{
    if (!pwm.init(PWM_OUTPUT)) {
        fprintf(stderr, "Output Enable not set. Are you root?\n");
        return 0;
    }

    pwm.enable(PWM_OUTPUT);
}

void RCOutput_Navio2::setFrequency(float frequency)
{
    pwm.set_period(PWM_OUTPUT, frequency);
}

bool RCOutput_Navio2::set_duty_cycle(unsigned int channel, float period)
{
    pwm.set_duty_cycle(channel, period / 1000);
}
