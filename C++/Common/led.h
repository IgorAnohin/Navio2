#ifndef LED
#define LED


class Led {

public:
    virtual void initialize() = 0;
    virtual void settColor(Color c) = 0;

};

#endif // LED

