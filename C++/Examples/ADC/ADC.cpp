#include <unistd.h>
#include <cstdio>
#include <Common/Util.h>
#include <Navio2/ADC.h>
#include "Navio+/ADS1115.h"


int main(int argc, char *argv[])
{
    if (check_apm()) {
        return 1;
    }

    if (get_navio_version() == NAVIO2) {

        ADC adc{};
        adc.init();
        float results[adc.get_channel_count()] = {0.0f};

        while (true) {
            for (int i = 0; i < ARRAY_SIZE(results); i++){
                results[i] = adc.read(i);
                printf("A%d: %.4fV ", i, results[i] / 1000);
            }
            printf("\n");

            usleep(500000);
        }
    } else {

        ADS1115 adc;

        adc.setMode(ADS1115_MODE_SINGLESHOT);
        adc.setRate(ADS1115_RATE_860);

        uint16_t muxes[] = {ADS1115_MUX_P0_NG, ADS1115_MUX_P1_NG, ADS1115_MUX_P2_NG, ADS1115_MUX_P3_NG};
        float results[ARRAY_SIZE(muxes)] = {0.0f};
        int i = 0;

        while (true) {
            adc.setMultiplexer(muxes[i]);

            float conversion = adc.getMilliVolts();
            results[i] = conversion;

            i = (i + 1) % ARRAY_SIZE(muxes);

            for (int j = 0; j < ARRAY_SIZE(muxes); j++) {
                printf("A%d: %.4fV ", j, results[j] / 1000);
            }
            printf("\n");
        }
    }

    return 0;
}
