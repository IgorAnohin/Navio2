CXX ?= g++
NAVIO = ../..
INCLUDES = -I ../..
CFLAGS = -std=gnu++11

all:
	$(CXX) $(CFLAGS) $(INCLUDES) $(NAVIO)/Common/gpio.cpp $(NAVIO)/Navio2/RGBled.cpp $(NAVIO)/Navio+/PCA9685.cpp $(NAVIO)/Common/I2Cdev.cpp $(NAVIO)/Common/Util.cpp LED.cpp -o LED

clean:
	rm -f LED
