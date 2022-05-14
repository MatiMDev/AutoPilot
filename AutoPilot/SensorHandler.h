#pragma once

#define TRIGGER_PIN 5
#define ECHO_PIN 2

namespace SensorHandler
{
	void setup();

	//ultrasonic sensor
	void sendUltrasonicPulse();
	void interruptHandler();
	float getDistance();
	//barometer sensor
	float getAltitude();
};

