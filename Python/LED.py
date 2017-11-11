import time

import navio.Common.util
import navio.Navio2.Led_Navio2
import navio.Navio.Led_Navio

def get_sensor():
	if (navio.Common.util.get_navio_version() == "NAVIO2"):
		return navio.Navio2.Led_Navio2()
	else:
		return navio.Navio.Led_Navio()


navio.Common.util.check_apm()

led = get_sensor()

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

