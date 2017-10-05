CXX ?= g++
NAVIO = ../..
INCLUDES = -I ../..

all:
	$(CXX) -std=c++11 $(INCLUDES) AHRS.cpp $(NAVIO)/Common/MPU9250.cpp $(NAVIO)/Navio2/LSM9DS1.cpp $(NAVIO)/Common/Util.cpp -o AHRS -lrt -lpthread

clean:
	rm AHRS
