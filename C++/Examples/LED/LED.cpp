#include "Navio2/RGBled.h"
#include "Common/Util.h"
#include <Common/gpio.h>
#include "Navio+/PCA9685.h"

using namespace Navio;


int main()
{

    if (check_apm()) {
        return 1;
    }

    int version = get_navio_version();

    if (version == NAVIO2) {

        RGBled led;

        if(!led.initialize()) return EXIT_FAILURE;
        led.setColor(Colors::Yellow);
        printf("LED is yellow\n");
        sleep(1);

        while (true) {
            led.setColor(Colors::Green);
            printf("LED is green\n");
            sleep(1);

            led.setColor(Colors::Cyan);
            printf("LED is cyan\n");
            sleep(1);

            led.setColor(Colors::Blue);
            printf("LED is blue\n");
            sleep(1);

            led.setColor(Colors::Magenta);
            printf("LED is magenta\n");
            sleep(1);

            led.setColor(Colors::Red);
            printf("LED is red\n");
            sleep(1);

            led.setColor(Colors::Yellow);
            printf("LED is yellow\n");
            sleep(1);
        }
    } else {

        static const uint8_t outputEnablePin = RPI_GPIO_27;


        Pin pin(outputEnablePin);

        if (pin.init()) {
            pin.setMode(Pin::GpioModeOutput);
            pin.write(0); /* drive Output Enable low */
        } else {
            fprintf(stderr, "Output Enable not set. Are you root?\n");
            return 1;
        }

        PCA9685 pwm;

        pwm.initialize();

        uint16_t R = 0, G = 0, B = 4095;

        pwm.setPWM(2, R);
        pwm.setPWM(1, G);
        pwm.setPWM(0, B);
        printf("LED is yellow\n");
        sleep(1);

        while (true) {
            for (R = 0; R < 4095; R++)
                pwm.setPWM(2, R);
            printf("LED is green\n");
            sleep(1);

            for (B = 4095; B > 0; B--)
                pwm.setPWM(0, B);
            printf("LED is cyan\n");
            sleep(1);

            for (G = 0; G < 4095; G++)
                pwm.setPWM(1, G);
            printf("LED is blue\n");
            sleep(1);

            for (R = 4095; R > 0; R--)
                pwm.setPWM(2, R);
            printf("LED is magenta\n");
            sleep(1);

            for (B = 0; B < 4095; B++)
                pwm.setPWM(0, B);
            printf("LED is red\n");
            sleep(1);

            for (G = 4095; G > 0; G--)
                pwm.setPWM(1, G);
            printf("LED is yellow\n");
            sleep(1);

        }


    }


    return 0;
}
