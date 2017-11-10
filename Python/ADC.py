import sys, signal, time

import navio.Navio2.adc
import navio.Navio.ADC_Navio
import navio.Common.util

navio.Common.util.check_apm()


def signal_handler(signal, frame):
    print 'You pressed Ctrl+C!'
    sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)
# print 'Press Ctrl+C to exit'

def get_converter():
    if (navio.Common.util.get_navio_version() == "NAVIO"):
        return navio.Navio.ADC_Navio.ADC_Navio()
    else:
        return navio.Navio2.adc.ADC()



adc = get_converter()
results = [0] * adc.channel_count

while (True):
    s = ''
    for i in range(0, adc.channel_count):
        results[i] = adc.read(i)
        s += 'A{0}: {1:6.4f}V '.format(i, results[i] / 1000)
    print(s)
    time.sleep(0.5)
