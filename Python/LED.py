import sys

import navio.leds
import time
import navio.util
import navio.gpio
#from Adafruit_PWM_Servo_Driver import PWM for NAVIO+
from navio.adafruit_pwm_servo_driver import PWM

navio.util.check_apm()

if (navio.util.get_NAVIO_version() == "NAVIO2"):

	led = navio.leds.Led()

	led.setColor('Yellow')
	print "LED is yellow"
	time.sleep(1)

	while (True):

	    led.setColor('Green')
	    print "LED is green"
	    time.sleep(1)

	    led.setColor('Cyan')
	    print "LED is cyan"
	    time.sleep(1)

	    led.setColor('Blue')
	    print "LED is blue"
	    time.sleep(1)

	    led.setColor('Magenta')
	    print "LED is magenta"
	    time.sleep(1)

	    led.setColor('Red')
	    print "LED is red"
	    time.sleep(1)

	    led.setColor('Yellow')
	    print "LED is yellow"
	    time.sleep(1)

else:

	#drive Output Enable in PCA low
	pin = navio.gpio.Pin(27)
	pin.write(0)

	pwm = PWM(0x40, debug=False)

	# Set frequency to 60 Hz
	pwm.setPWMFreq(60)

	step = 1 # light color changing step

	# set initial color
	R = 0
	G = 0
	B = 4095
	pwm.setPWM(0, 0, B)
	print "LED is yellow"
	time.sleep(1)

	while (True):
	    for R in xrange(0, 4095, step):
		pwm.setPWM(2, 0, R)
	    print "LED is green"
	    time.sleep(1)

	    for B in xrange(4095, 0, -step):
		pwm.setPWM(0, 0, B)
	    print "LED is cyan"
	    time.sleep(1)
	    
	    for G in xrange(0, 4095, step):
		pwm.setPWM(1, 0, G)
	    print "LED is blue"
	    time.sleep(1)

	    for R in xrange(4095, 0, -step):
		pwm.setPWM(2, 0, R)
	    print "LED is magenta"
	    time.sleep(1)

	    for B in xrange(0, 4095, step):
		pwm.setPWM(0, 0, B)
	    print "LED is red"
	    time.sleep(1)

	    for G in xrange(4095, 0, -step):
		pwm.setPWM(1, 0, G)
	    print "LED is yellow"
	    time.sleep(1)

