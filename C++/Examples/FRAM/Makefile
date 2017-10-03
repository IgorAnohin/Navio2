CC = g++
NAVIO = ../..
INCLUDES = -I ../..

all:
	$(CC) $(INCLUDES) FRAM.cpp $(NAVIO)/Navio+/MB85RC256.cpp $(NAVIO)/Common/I2Cdev.cpp $(NAVIO)/Common/Util.cpp -o FRAM

clean:
	rm FRAM
