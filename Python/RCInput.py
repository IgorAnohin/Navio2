import time

import navio.Common.util

import navio.Navio2.RCInput_Navio2
import navio.Navio.RCInput_Navio

def get_rcin():
    if navio.Common.util.get_navio_version() == "NAVIO2":

        return navio.Navio2.RCInput_Navio2.RCInput_Navio2()
    else:
        return navio.Navio.RCInput_Navio.RCInput_Navio()


navio.Common.util.check_apm()

rcin = get_rcin()
while (True):
    period = rcin.read(1)
    print period
    time.sleep(1)
