#include "SensorHandler.h"
#include "Arduino.h"
#include "Adafruit_BMP085.h"

namespace SensorHandler
{
	namespace
	{
		unsigned long startTime = 0;
		unsigned long diffTime = 0;
		double distance = 0;
		bool firstCapture = false;
		Adafruit_BMP085 baro;
		float homeAltitude = 0;
	}

	void setup()
	{
		attachInterrupt(digitalPinToInterrupt(ECHO_PIN), interruptHandler, CHANGE);
		pinMode(TRIGGER_PIN, OUTPUT);
		baro.begin();
		homeAltitude = baro.readAltitude();
	}

	void sendUltrasonicPulse()
	{
		digitalWrite(TRIGGER_PIN, HIGH);
		delayMicroseconds(10);
		digitalWrite(TRIGGER_PIN, LOW);
	}

	void interruptHandler()
	{
		if (!firstCapture)
		{
			startTime = micros();
		}
		else
		{
			diffTime = micros() - startTime;
			distance = diffTime / 58.0;
			startTime = 0;
			diffTime = 0;
		}
		firstCapture = !firstCapture;
	}

	float getDistance()
	{
		float temp = distance;
		distance = -1;
		return temp;
	}

	float getAltitude()
	{
		return baro.readAltitude() - homeAltitude;
	}
}