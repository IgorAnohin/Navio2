#include <unistd.h>
#include <cstdio>

#include <Navio2/RCInput.h>
#include "Common/Util.h"

int main(int argc, char *argv[])
{
    RCInput rcin{};

    if (check_apm()) {
        return 1;
    }

    rcin.init();

    while (true) 
    {
        int period = rcin.read(2);
        printf("%d\n", period);
        
        sleep(1);
    }

    return 0;
}
