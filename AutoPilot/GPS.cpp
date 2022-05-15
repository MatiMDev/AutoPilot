#include "GPS.h"

void GPS::ParseGNGGA(String data)
{
	char dataArray[sizeof(data)];
	data.toCharArray(dataArray, sizeof(data));
	sscanf(dataArray, "&GNGGA,%f,%d,%f,%d", &gpsData.latitude, &gpsData.longitude);
}