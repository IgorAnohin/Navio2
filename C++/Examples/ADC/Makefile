CXX ?= g++
NAVIO = ../..
INCLUDES = -I ../..

all:
	$(CXX) -std=gnu++11 $(INCLUDES) ADC.cpp $(NAVIO)/Common/Util.cpp $(NAVIO)/Navio+/ADS1115.cpp $(NAVIO)/Common/I2Cdev.cpp $(NAVIO)/Navio2/ADC.cpp -o ADC

clean:
	rm ADC
