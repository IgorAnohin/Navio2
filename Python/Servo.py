import time

import navio.Common.util
import navio.Navio2.RCOutput_Navio2
import navio.Navio.RCOutput_Navio

PWM_OUTPUT = 0

def get_pwm():
	if (navio.Common.util.get_navio_version() == "NAVIO2"):
		return navio.Navio2.RCOutput_Navio2.RCOutput_Navio2(PWM_OUTPUT)
	else:
		return navio.Navio.RCOutput_Navio.RCOutput_Navio(PWM_OUTPUT)

navio.Common.util.check_apm()

with get_pwm() as pwm:
	pwm.set_period(50)
	pwm.enable()

	while (True):
		pwm.set_duty_cycle(pwm.SERVO_MIN)
		time.sleep(1)
		pwm.set_duty_cycle(pwm.SERVO_MAX)
		time.sleep(1)
