/* FakeSonde decoder functions
 * For UI tests purposes without need to have a real sonde around.
 */

#include "FakeSonde.h"
#include "Sonde.h"


FakeSonde::FakeSonde() 
{
}

int FakeSonde::setup(float frequency, int /*type*/) 
{
    return 0;
}

int FakeSonde::receive()
{
    unsigned long t0 = millis();
	Serial.printf("FakeSonde::receive() start at %ld\n",t0);

	delay(1100);
	
	SondeData *sd = &(sonde.si()->d);
	sd->lat = 52.424824;
	sd->lon = 16.922644;
	sd->alt = 81.0;
	sd->vs = 0.0;
	sd->hs = 0.0;
	sd->dir = 0.0;
	sd->sats = 4;
	sd->validPos = 0x7f; // all of seven fields above are valid
	sd->subtype = 0;
	memcpy(sd->typestr, "FAKE", 5);
	strcpy(sd->id, "TEST 0001");
	sd->validID = true;

	Serial.printf("FakeSonde::receive() RX_OK\n");
	return RX_OK;
}

int FakeSonde::waitRXcomplete() 
{
	return 0;
}

FakeSonde fakeSonde = FakeSonde();
