#ifndef RCINPUT_NAVIO_H
#define RCINPUT_NAVIO_H

#include <pigpio.h>
#include <Common/RCInput.h>
#include <Common/gpio.h>
#include "RCOutput_Navio.h"
#include "Common/Util.h"

using namespace Navio;


class RCInput_Navio : public RCInput
{

public:
    RCInput_Navio();
    void initialize();
    int read(int ch);
    ~RCInput_Navio();
    void ppmOnEdge(int gpio, int level, uint32_t tick);

private:

    static void ppmOnEdgeTrampolin(int gpio, int level, uint32_t tick, void *userdata);

    static const uint8_t outputEnablePin = RPI_GPIO_27;

    //================================ Options =====================================

    unsigned int samplingRate      = 1;      // 1 microsecond (can be 1,2,4,5,10)
    unsigned int ppmInputGpio      = 4;      // PPM input on Navio's 2.54 header
    unsigned int ppmSyncLength     = 4000;   // Length of PPM sync pause
    unsigned int ppmChannelsNumber = 8;      // Number of channels packed in PPM
    unsigned int servoFrequency    = 50;     // Servo control frequency
    bool verboseOutputEnabled      = true;   // Output channels values to console

    //============================ Objects & data ==================================

    RCOutput *pwm;
    float channels[8];

    //============================== PPM decoder ===================================

    unsigned int currentChannel = 0;
    unsigned int previousTick;
    unsigned int deltaTime;

};

#endif // RCINPUT_NAVIO_H
