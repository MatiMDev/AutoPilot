#include "SensorHandler.h"
#include "Adafruit_BMP085.h"
#include "GPS.h"

using namespace SensorHandler;

String q = "";

void setup() 
{
	SensorHandler::setup();
	Serial.begin(9600);
	Serial1.begin(9600);
}

void loop() 
{
    if (Serial1.available())
    {
        int data = Serial1.read();
        //Serial.write(data);
        q += (char)data;
        //aString += (char)data;

        if (data == '\n')
        {
            //Serial.println("New line");
            //if (compareString(q, "GNGGA"))
            //{
            
            //}
            GPS gps;
            //Serial.println(gps.compareString(q, "$GNGGA"));

            if (gps.compareString(q, "$GNGGA") >= 0)
            {
                Serial.println(q);
                gps.ParseGNGGA(q);
                Serial.println(gps.gpsData.time);
            }

            q = "";
            delay(2000);
            //aString = "";
        }
        //q += data + ", ";

        /*if (data == '\n')
        {



            delay(5000);
        }*/


        //q = {0};

    }
}