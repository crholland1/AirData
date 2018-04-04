/*
StaticValues.ino
Brian R Taylor
brian.taylor@bolderflight.com

Copyright (c) 2018 Bolder Flight Systems

Permission is hereby granted, free of charge, to any person obtaining a copy of this software
and associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "AirData.h"

// An AirData object
AirData Airdata;

// Differential pressure, Pa
float DifferentialPressure_Pa = 500.0f;
// Static pressure, Pa
float StaticPressure_Pa = 40000.0f;
// Temperature, C
float Temperature_C = 23.0f;
// AGL bias
float AGL_Bias = 7000.0f;
// Initial MSL altitude
float Initial_MSL = 1200.0f;

void setup() {
  Serial.begin(115200);
  while(!Serial){}
}

void loop() {
  Serial.print(Airdata.getIAS(DifferentialPressure_Pa));
  Serial.print("\t");
  Serial.print(Airdata.getEAS(DifferentialPressure_Pa,StaticPressure_Pa));
  Serial.print("\t");
  Serial.print(Airdata.getTAS(Airdata.getEAS(DifferentialPressure_Pa,StaticPressure_Pa),Temperature_C));
  Serial.print("\t");
  Serial.print(Airdata.getPressureAltitude(StaticPressure_Pa));
  Serial.print("\t");
  Serial.print(Airdata.getAGL(StaticPressure_Pa,AGL_Bias));
  Serial.print("\t");
  Serial.print(Airdata.getMSL(Airdata.getAGL(StaticPressure_Pa,AGL_Bias),Initial_MSL));
  Serial.print("\t");
  Serial.print(Airdata.getDensityAltitude(StaticPressure_Pa,Temperature_C));
  Serial.print("\t");
  Serial.print(Airdata.getApproxTemp(Temperature_C,Airdata.getAGL(StaticPressure_Pa,AGL_Bias)));
  Serial.print("\t");
  Serial.println(Airdata.getDensity(StaticPressure_Pa,Temperature_C));
  delay(1000);
}
