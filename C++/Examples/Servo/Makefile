CXX ?= g++
NAVIO = ../../Navio
INCLUDES = -I ../..

all:
	$(CXX) -std=gnu++11 $(INCLUDES) Servo.cpp $(NAVIO)/PWM.cpp $(NAVIO)/PCA9685.cpp $(NAVIO)/I2Cdev.cpp $(NAVIO)/gpio.cpp $(NAVIO)/Util.cpp -o Servo

clean:
	rm Servo
