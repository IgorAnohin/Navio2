CXX ?= g++
NAVIO = ../../Navio
INCLUDES = -I ../..

all:
	$(CXX) -std=gnu++11 $(INCLUDES) ADC.cpp $(NAVIO)/Util.cpp $(NAVIO)/ADS1115.cpp $(NAVIO)/I2Cdev.cpp $(NAVIO)/ADC.cpp -o ADC

clean:
	rm ADC
