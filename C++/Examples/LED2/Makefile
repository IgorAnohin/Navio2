CXX ?= g++
NAVIO = ../../Navio
INCLUDES = -I ../..
CFLAGS = -std=gnu++11

all:
	$(CXX) $(CFLAGS) $(INCLUDES) $(NAVIO)/gpio.cpp $(NAVIO)/RGBled.cpp $(NAVIO)/PCA9685.cpp $(NAVIO)/I2Cdev.cpp $(NAVIO)/Util.cpp LED.cpp -o LED

clean:
	rm -f LED
