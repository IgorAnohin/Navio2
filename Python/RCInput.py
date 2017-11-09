import time

import navio.Common.util

import navio.Navio2.rcinput
import navio.Navio.RCInput_Navio

navio.Common.util.check_apm()

if navio.Common.util.get_navio_version() == "NAVIO2":

    rcin = navio.Navio2.rcinput.RCInput()
else:
    rcin = navio.Navio.RCInput_Navio.RCInput_Navio()

    while (True):
        period = rcin.read(1)
        print period
        time.sleep(1)
