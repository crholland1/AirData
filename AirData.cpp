/*
AirData.cpp
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

/* computes indicated airspeed given differential pressure */
float AirData::getIAS(float qc) {
  return A0 * sqrtf(5.0f*(powf((qc/P0 + 1.0f),(2.0f/7.0f)) - 1.0f));
}

/* computes equivalent airspeed given differential pressure and static pressure */
float AirData::getEAS(float qc, float p) {
  return A0 * sqrtf(5.0f*p/P0*(powf((qc/p + 1.0f),(2.0f/7.0f)) - 1.0f));
}

/* computes true air speed given IAS or EAS and temperature */
float AirData::getTAS(float AS, float T) {
  return AS * sqrtf((T+273.15f)/T0);
}

/* computes pressure altitude given static pressure */
float AirData::getPressureAltitude(float p) {
  return (T0/L)*(1.0f - powf((p/P0),((L*R)/(M*g))));
}

/* computes altitude Above Ground Level (AGL) given static pressure and a bias */
float AirData::getAGL(float p, float c) {
  return getPressureAltitude(p) - c;
}

/* computes altitude above Mean Sea Level (MSL) given AGL and starting altitude */
float AirData::getMSL(float H, float h) {
  return H + h;
}

/* computes density altitude given static pressure and temperature */
float AirData::getDensityAltitude(float p, float T) {
  return (T0/L)*(1.0f - powf(((p/P0)*(T0/(T+273.15f))),((L*R)/(M*g - L*R))));
}

/* approximates temperature as a fuction of altitude */
float AirData::getApproxTemp(float T, float h) {
  return T - L*h;
}

/* computes air density given temperature and pressure */
float AirData::getDensity(float p, float T) {
  return (M*p)/(R*(T+273.15f));
}
