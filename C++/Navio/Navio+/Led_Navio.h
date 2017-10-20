#ifndef LED_NAVIO_H
#define LED_NAVIO_H

#include <Common/Led.h>
#include "Navio+/PCA9685.h"
#include <Common/gpio.h>


using namespace Navio;

class Led_Navio : public Led
{
public:
    Led_Navio();
    bool initialize();
    void setColor(Colors color);

private:
    PCA9685 pwm;
};

#endif // LED_NAVIO_H
