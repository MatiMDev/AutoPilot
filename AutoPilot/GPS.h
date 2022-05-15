#pragma once

#include "GPSData.h"

class GPS
{
    public:
    static GPSData gpsData;

    static void ParseGNGGA(String data);
};