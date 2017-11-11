from navio.Navio.adafruit_pwm_servo_driver import PWM
import RPi.GPIO as GPIO

import math


class RCOutput_Navio():

    PCA9685_DEFAULT_ADDRESS = 0x40

    SERVO_MIN_ms = 1.250
    SERVO_MAX_ms = 1.750

    def __init__(self, pwm_output):
        self.NAVIO_RCOUTPUT = pwm_output + 3
        self.is_initialized = False

    def __enter__(self):
        self.initialize()
        return self

    def initialize(self):
        GPIO.setwarnings(False)

        GPIO.setmode(GPIO.BCM)
        GPIO.setup(27, GPIO.OUT)
        GPIO.output(27, GPIO.LOW)
        self.is_initialized = True

    def enable(self):
        self.pwm = PWM(0X40, debug=False)
        self.pwm.setPWMFreq(self.frequency)

    def set_period(self, period):

        if not self.is_initialized:
            raise RuntimeError("PWM not initialized. Call initialize first")
        self.frequency = period

        self.SERVO_MIN = math.trunc((self.SERVO_MIN_ms * 4096.0) / (1000.0 / self.frequency) - 1)
        self.SERVO_MAX = math.trunc((self.SERVO_MAX_ms * 4096.0) / (1000.0 / self.frequency) - 1)

    def set_duty_cycle(self, ch):
        if not self.is_initialized:
            raise RuntimeError("PWM not initialized. Call initialize first")
        self.pwm.setPWM(self.NAVIO_RCOUTPUT, 0, ch)




