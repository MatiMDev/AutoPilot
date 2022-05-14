#include "SensorHandler.h"
#include "Adafruit_BMP085.h"

using namespace SensorHandler;

void setup() 
{
	SensorHandler::setup();
}

void loop() 
{
	sendUltrasonicPulse();
	float dist = getDistance();
	if (dist != -1)
	{
		Serial.println("Dist: " + String(dist));
	}
	else
	{
		Serial.println("Dist error");
	}

	Serial.println("Altitude: " + String(SensorHandler::getAltitude()));
	
	delay(2000);
}

