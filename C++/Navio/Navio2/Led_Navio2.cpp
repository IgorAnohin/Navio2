#include "Led_Navio2.h"

Led_Navio2::Led_Navio2()
{

}

bool Led_Navio2::initialize()
{
    return (!pwm.initialize());
}

void Led_Navio2::setColor(Colors color)
{
    pwm.setColor(color);
}


