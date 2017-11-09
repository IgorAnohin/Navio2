import RPi.GPIO as GPIO
import pigpio

class RCInput_Navio():

    CHANNEL_COUNT = 8
    channels = [0,0,0,0,0,0,0,0]

    def cbf(self, gpio, level, tick):
        if (level == 0):
            deltaTime = tick - self.previousTick
            self.previousTick = tick

            if (deltaTime >= 4000):
                self.currentchannel = 0
            else:
                if (self.currentchannel < self.CHANNEL_COUNT):
                    self.channels[self.currentchannel] = deltaTime
                    self.currentchannel += 1

    def __init__(self):

        GPIO.setmode(GPIO.BCM)
        GPIO.setup(27, GPIO.OUT)
        GPIO.output(27, GPIO.LOW)

        self.pi = pigpio.pi()
        self.pi.set_mode(4, pigpio.INPUT)

        self.currentchannel = 0
        self.previousTick = self.pi.get_current_tick()
        self.cb1 = self.pi.callback(4, pigpio.EITHER_EDGE, self.cbf)

    def read(self, ch):

        return self.channels[ch]

