#ifndef BMP_H
#define BMP_H

#include "HAL.h"
#include <Adafruit_BMP3XX.h>


namespace BMP {
    
    Adafruit_BMP3XX bmp1;
    Adafruit_BMP3XX bmp2;

    const float SEALEVELPRESSURE_HPA = 1011.10; // Sea level pressure of LA 

    double temp1, pressure1, altitude1;
    double temp2, pressure2, altitude2;

    void setupBMP() {
        for (int i=0; i<3000; i++) {
            if(bmp1.begin_SPI(HAL::ALTIMETER1_CS, HAL::sensorSPI))
                break;    
            DEBUGLN("Failed to find BMP 1");
        }


        // bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
        // bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
        // bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
        // bmp.setOutputDataRate(BMP3_ODR_50_HZ);
    }


    
    int readAltimeters() {
  
        if (! bmp1.performReading()) {
            return 0;
        }
        else {
            temp1 = bmp1.temperature;
            pressure1 = bmp1.pressure / 1000.0;
            altitude1 = bmp1.readAltitude(SEALEVELPRESSURE_HPA);
        }


        DEBUG("BMP Altimeter: ");
        DEBUG(temp1);
        DEBUG(" *C, ");
        DEBUG(pressure1);
        DEBUG(" kPa, ");
        DEBUG(altitude1);
        DEBUGLN(" m");

        return 1;

    }

    

}


#endif