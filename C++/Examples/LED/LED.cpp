#include "Navio2/RGBled.h"
#include <memory>
#include "Common/Util.h"
#include <Common/gpio.h>
#include <Common/led.h>
#include "Navio+/PCA9685.h"

using namespace Navio;


class Led_navio2 : public Led
{
    RGBled LED;
    virtual void initialize()
    {
        if(!LED.initialize()) return EXIT_FAILURE;
    }

    virtual void settColor(Colors c)
    {
        switch (c)
            case Colors::Yellow:
                LED.setColor(Colors::Yellow);
                break;
            case Colors::Green:
                LED.setColor(Colors::Green);
                break;
            case Colors::Cyan:
                LED.setColor(Colors::Cyan);
                break;
            case Colors::Magenta:
                LED.setColor(Colors::Magenta);
                break;
            case Colors::Re:
                LED.setColor(Colors::Red);
                break;
            case Colors::Blue:
                LED.setColor(Colors::Blue);
                break;
    }

};

class Led_navio : public Led
{
    PCA9685 pwm;

    virtual void initialize()
    {
        static const uint8_t outputEnablePin = RPI_GPIO_27;

        Pin pin(outputEnablePin);

        if (pin.init()) {
            pin.setMode(Pin::GpioModeOutput);
            pin.write(0); /* drive Output Enable low */
        } else {
            fprintf(stderr, "Output Enable not set. Are you root?\n");
            return 1;
        }

        pwm.initialize();
    }

    virtual void settColor(Color c)
    {
        switch (c)
            case Color.YELLOW:
                pwm.setPWM(2, 0);
                pwm.setPWM(1, 0);
                pwm.setPWM(0, 4095);
                break;
            case Color.GREEN:
                pwm.setPWM(2, 4095);
                pwm.setPWM(1, 0);
                pwm.setPWM(0, 4095);
                break;
            case Color.CYAN:
                pwm.setPWM(2, 4095);
                pwm.setPWM(1, 0);
                pwm.setPWM(0, 0);
                break;
            case Color.MAGENTA:
                LED.setColor(Colors::Magenta);
                pwm.setPWM(2, 0);
                pwm.setPWM(1, 4095);
                pwm.setPWM(0, 0);
                break;
            case Color.RED:
                pwm.setPWM(2, 0);
                pwm.setPWM(1, 4095);
                pwm.setPWM(0, 4095);
                break;
            case Color.BLUE:
                pwm.setPWM(2, 4095);
                pwm.setPWM(1, 4095);
                pwm.setPWM(0, 0);
                break;
    }

};


std::unique_ptr <Led> Get_led()
{
    if (get_navio_version() == NAVIO2)
        auto ptr = std::unique_ptr <Led>{ new Led_navio2() };
    else
        auto ptr = std::unique_ptr <Led>{ new Led_navio() };

    return ptr;

}

int main()
{

    if (check_apm()) {
        return 1;
    }

    auto led = Get_led();

        while (true) {
            led -> setColor(Colors::Green);
            printf("LED is green\n");
            sleep(1);

            led -> setColor(Colors::Cyan);
            printf("LED is cyan\n");
            sleep(1);

            led -> setColor(Colors::Blue);
            printf("LED is blue\n");
            sleep(1);

            led -> setColor(Colors::Magenta);
            printf("LED is magenta\n");
            sleep(1);

            led -> setColor(Colors::Red);
            printf("LED is red\n");
            sleep(1);

            led -> setColor(Colors::Yellow);
            printf("LED is yellow\n");
            sleep(1);
        }

    return 0;
}
