#ifndef RCOUTPUT
#define RCOUTPUT

#define PWN_OUTPUT 0


class RCOutput
{
public:
    virtual bool initialize() = 0;
    virtual void setFrequency(float frequency) = 0;
    virtual bool set_duty_cycle(unsigned int channel, float period) = 0;

};

#endif // RCOUTPUT

