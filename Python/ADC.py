import sys, signal, time

import navio.adc
from navio.adafruit_ads1x15 import ADS1x15
import navio.util

navio.util.check_apm()

def signal_handler(signal, frame):
        print 'You pressed Ctrl+C!'
        sys.exit(0)
signal.signal(signal.SIGINT, signal_handler)
#print 'Press Ctrl+C to exit'

ADS1015 = 0x00  # 12-bit ADC
ADS1115 = 0x01	# 16-bit ADC

# Select the gain
# gain = 6144  # +/- 6.144V
gain = 4096  # +/- 4.096V
# gain = 2048  # +/- 2.048V
# gain = 1024  # +/- 1.024V
# gain = 512   # +/- 0.512V
# gain = 256   # +/- 0.256V

# Select the sample rate
# sps = 8    # 8 samples per second
# sps = 16   # 16 samples per second
# sps = 32   # 32 samples per second
# sps = 64   # 64 samples per second
# sps = 128  # 128 samples per second
sps = 250  # 250 samples per second
# sps = 475  # 475 samples per second
# sps = 860  # 860 samples per second

# Initialise the ADC using the default mode (use default I2C address)
# Set this to ADS1015 or ADS1115 depending on the ADC you are using!
if (navio.util.get_NAVIO_version() == "NAVIO"):

	adc = ADS1x15(ic=ADS1115)

	while 1:

		# Reading all channels
		volts = adc.readADCSingleEnded(0, gain, sps) / 1000
		print "A0: %.4fV" % (volts),

		volts = adc.readADCSingleEnded(1, gain, sps) / 1000
		print "A1: %.4fV" % (volts),

		volts = adc.readADCSingleEnded(2, gain, sps) / 1000
		print "A2: %.4fV" % (volts),

		volts = adc.readADCSingleEnded(3, gain, sps) / 1000
		print "A3: %.4fV" % (volts)

else:
	adc = navio.adc.ADC()
	results = [0] * adc.channel_count

	while (True):
	    s = ''
	    for i in range (0, adc.channel_count):
		results[i] = adc.read(i)
		s += 'A{0}: {1:6.4f}V '.format(i, results[i] / 1000)
	    print(s)
	    time.sleep(0.5)
