/*
Provided to you by Emlid Ltd (c) 2015.
twitter.com/emlidtech || www.emlid.com || info@emlid.com

Example: Control servos connected to PWM driver onboard of Navio2 shield for Raspberry Pi.

Connect servo to Navio2's rc output and watch it work.
PWM_OUTPUT = 0 complies to channel number 1, 1 to channel number 2 and so on.
To use full range of your servo correct SERVO_MIN and SERVO_MAX according to it's specification.

To run this example navigate to the directory containing it and run following commands:
make
sudo ./Servo
*/

#include <unistd.h>
#include "Navio2/PWM.h"
#include <Common/gpio.h>
#include "Navio+/PCA9685.h"
#include "Common/Util.h"

#define PWM_OUTPUT 0
#define NAVIO_RCOUTPUT_1 3
#define SERVO_MIN 1.250 /*mS*/
#define SERVO_MAX 1.750 /*mS*/

using namespace Navio;


int main()
{

    int version = get_navio_version();

    if (version == NAVIO2) {

        PWM pwm;

        if (check_apm()) {
            return 1;
        }

        if (!pwm.init(PWM_OUTPUT)) {
            fprintf(stderr, "Output Enable not set. Are you root?\n");
            return 0;
        }

        pwm.enable(PWM_OUTPUT);
        pwm.set_period(PWM_OUTPUT, 50);

        while (true) {
            pwm.set_duty_cycle(PWM_OUTPUT, SERVO_MIN);
            sleep(1);
            pwm.set_duty_cycle(PWM_OUTPUT, SERVO_MAX);
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
        pwm.setFrequency(50);

        while (true) {
            pwm.setPWMmS(NAVIO_RCOUTPUT_1, SERVO_MIN);
            sleep(1);
            pwm.setPWMmS(NAVIO_RCOUTPUT_1, SERVO_MAX);
            sleep(1);
        }
    }


    return 0;
}
