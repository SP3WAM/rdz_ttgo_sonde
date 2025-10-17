#ifndef FAKESONDE_h
#define FAKESONDE_h

#include <stdlib.h>
#include <stdint.h>
#include <Arduino.h>
#ifndef inttypes_h
    #include <inttypes.h>
#endif
#include "DecoderBase.h"

/* Main class */
class FakeSonde : public DecoderBase
{
public:
	FakeSonde();
	int setup(float frequency, int type = 0);
	int receive();
	int waitRXcomplete();
};

extern FakeSonde fakeSonde;

#endif