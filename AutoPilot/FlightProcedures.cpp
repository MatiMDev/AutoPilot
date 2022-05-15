#include "FlightProcedures.h"
#include "SensorHandler.h"
#include "Arduino.h"

#define TAKE_OFF_TARGET_ALTITUDE 50 // in meters
#define HOVER_THROTTLE 1300
#define ASCENT_THROTTLE 1400
#define FAST_DESCENT_THROTTLE 1100
#define SLOW_DESCENT_TRHOTTLE 1200
#define ULTRASONIC_SENSOR_DISTANCE_FROM_GROUND 25
#define ZERO_THROTTLE 1000


namespace FlightProcedures
{
	void takeOff()
	{
		//setArmChannel(true);
		float startAltitude = SensorHandler::getAltitude();
		if (startAltitude < 1 && startAltitude > -1)
		{
			//setThrottle(ASCENT_THROTTLE);
		}

		while (SensorHandler::getAltitude() < TAKE_OFF_TARGET_ALTITUDE) {}
		//setThrottle(HOVER_THROTTLE);
		// 1000-2000
	}

	void land()
	{
		if (SensorHandler::getAltitude() > 5)
		{
			//setThrottle(FAST_DESCENT_THROTTLE);

			while (readUltrasonic() == -1) {}
		}	
		//setThrottle(SLOW_DESCENT_TRHOTTLE);

		while (readUltrasonic() > ULTRASONIC_SENSOR_DISTANCE_FROM_GROUND) {}
		//setThrottle(ZERO_THROTTLE);
		//setArmChannel(false);
	}

	float readUltrasonic()
	{
		SensorHandler::sendUltrasonicPulse();
		unsigned long startTime = micros();
		while (micros() - startTime < 30000)
		{
			float dist = SensorHandler::getDistance();
			if (dist != -1 && dist <= 500)
			{
				return dist;
			}
		}

		return -1;
	}
}