import math
import time

import RPi.GPIO as GPIO

import navio.Common.util
import navio.Navio2.pwm
from navio.Navio.adafruit_pwm_servo_driver import PWM

navio.Common.util.check_apm()

PWM_OUTPUT = 0
SERVO_MIN = 1.250 #ms
SERVO_MAX = 1.750 #ms

if (navio.Common.util.get_navio_version() == "NAVIO2"):

	with navio.Navio2.pwm.PWM(PWM_OUTPUT) as pwm:
		pwm.set_period(50)
		pwm.enable()

		while (True):
			pwm.set_duty_cycle(SERVO_MIN)
			time.sleep(1)
			pwm.set_duty_cycle(SERVO_MAX)
			time.sleep(1)

else:

	#drive Output Enable in PCA low
	#pin = navio.Navio.gpio.Pin(27)
	#pin.write(0)

	GPIO.setmode(GPIO.BCM)
	GPIO.setup(27, GPIO.OUT)
	GPIO.output(27, GPIO.LOW)

	PCA9685_DEFAULT_ADDRESS = 0x40
	frequency = 50

	NAVIO_RCOUTPUT_1 = 3

	#convert mS to 0-4096 scale:
	SERVO_MIN_ms = math.trunc((SERVO_MIN * 4096.0) / (1000.0 / frequency) - 1)
	SERVO_MAX_ms = math.trunc((SERVO_MAX * 4096.0) / (1000.0 / frequency) - 1)

	pwm = PWM(0x40, debug=False)

	# Set frequency to 60 Hz
	pwm.setPWMFreq(frequency)

	while(True):
		pwm.setPWM(NAVIO_RCOUTPUT_1, 0, SERVO_MIN_ms);
		time.sleep(1);
		pwm.setPWM(NAVIO_RCOUTPUT_1, 0, SERVO_MAX_ms);
		time.sleep(1);
