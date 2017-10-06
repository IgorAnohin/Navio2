#include "Navio2/RGBled.h"
#include <memory>
#include "Common/Util.h"
#include <Common/gpio.h>
#include <Common/Led.h>
#include "Navio+/PCA9685.h"

using namespace Navio;


class Led_navio2 : public Led
{
    RGBled pwn;

    int initialize()
    {
        if(!pwn.initialize()) return EXIT_FAILURE;
    }

    void setColor(Colors color)
    {
         pwn.setColor(color);

    }

};

class Led_navio : public Led
{
    PCA9685 pwm;

    int initialize()
    {
        static const uint8_t outputEnablePin = RPI_GPIO_27;

        Pin pin(outputEnablePin);

        if (pin.init()) {
            pin.setMode(Pin::GpioModeOutput);
            pin.write(0); /* drive Output Enable low */
        } else {
            fprintf(stderr, "Output Enable not set. Are you root?\n");
            return EXIT_FAILURE;
        }

        pwm.initialize();
    }

    void setColor(Colors color)
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

};


std::unique_ptr <Led> Get_led()
{
    if (get_navio_version() == NAVIO2)
    {
        auto ptr = std::unique_ptr <Led>{ new Led_navio2() };
        return ptr;
    } else
    {
        auto ptr = std::unique_ptr <Led>{ new Led_navio() };
        return ptr;
    }


}

int main()
{

    if (check_apm()) {
        return 1;
    }

    auto led = Get_led();
    if (led -> initialize() == EXIT_FAILURE)
        return EXIT_FAILURE;

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
