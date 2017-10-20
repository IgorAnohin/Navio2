#ifndef LED_NAVIO2_H
#define LED_NAVIO2_H

#include <Common/Led.h>
#include <Navio2/RGBled.h>

class Led_Navio2 : public Led
{
public:
    Led_Navio2();
    bool initialize();
    void setColor(Colors color);

private:
    RGBled pwm;
};

#endif // LED_NAVIO2_H
