import time

import navio.Common.util

import navio.Navio2.rcinput

navio.Common.util.check_apm()

if navio.Common.util.get_navio_version() == "NAVIO2":

    rcin = navio.Navio2.rcinput.RCInput()

    while (True):
        period = rcin.read(2)
        print period
        time.sleep(1)
else:
    print "No RCInput on Navio+"