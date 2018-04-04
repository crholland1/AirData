# Air Data
Class for computing air data given sensor measurements. This class can be incorporated into standard C/C++ code or used as an Arduino library.

# Description
This class computes the following types of airspeed:
* Indicated airspeed
* Equivalent airspeed
* True airspeed

This class computes the following types of altitude:
* Pressure altitude
* Altitude above ground level (AGL)
* Altitude above mean sea level (MSL)
* Density altitude

Finally, this class includes methods to estimate:
* Air temperature
* Air density

# Usage
## Installation
For use with the Arduino IDE, simply clone or download this library into your Arduino/libraries folder. For integration with C/C++ projects, integrate the included header and source files; this class needs stdint and math libraries.

## Function Description
### Object Declaration
This library uses the default constructor. The following is an example of declaring an AirData object called *Airdata*.

```C++
AirData Airdata;
```

### Air Data Functions
**float getIAS(float qc)**
This function returns the indicated airspeed (m/s) given differential pressure (Pa).

```C++
float Ias;
float qc = 500.0f;
Ias = Airdata.getIAS(qc);
```

**float getEAS(float qc, float p)**
This function returns the equivalent airspeed (m/s) given differential pressure (Pa) and static pressure (Pa).

```C++
float Ias;
float qc = 500.0f;
float p = 101325.0f;
Ias = Airdata.getEAS(qc, p);
```

**float getTAS(float AS, float T)**
This function returns the true airspeed (m/s) given indicated or equivalent airspeed (m/s) and temperature (C).

```C++
float Tas;
float Ias = 30.0f;
float T = 23.0f;
Tas = Airdata.getTAS(Ias, T);
```

**float getPressureAltitude(float p)**
This function returns the pressure altitude (m) given static pressure (Pa).

```C++
float PressureAltitude;
float p = 101325.0f;
PressureAltitude = Airdata.getPressureAltitude(p);
```

**float getAGL(float p, float c)**
This function returns the altitude above ground level (m) given static pressure (Pa) and a bias. Typical usage would compute pressure altitude at ground level and use the pressure altitude as the bias in the getAGL function.

```C++
float AGL;
float p = 101325.0f;
float c = 1500.0f;
AGL = Airdata.getAGL(p,c);
```

**float getMSL(float H, float h)**
This function returns the altitude above mean sea level (m) given the altitude above ground level (m) and a starting altitude above mean sea level (m). Typical usage would get a starting altitude above mean sea level from GPS data and use the getAGL function to get the altitude above ground level.

```C++
float AGL, MSL;
float InitialAltitude = 0.0f;
float p = 101325.0f;
float c = 1500.0f;
AGL = Airdata.getAGL(p,c);
MSL = Airdata.getMSL(AGL,InitialAltitude);
```

**float getDensityAltitude(float p, float T)**
This function returns the density altitude (m) given the static pressure (Pa) and temperature (C).

```C++
float DensityAltitude;
float p = 101325.0f;
float T = 23.0f;
DensityAltitude = Airdata.getDensityAltitude(p,T);
```

**float getApproxTemp(float T, float h)**
This function returns the approximate temperature (C) at an altitude given a starting temperature (C) and an altitude (m) above that temperature reading using a standard lapse rate calculation.

```C++
float T, AGL;
float T0 = 23.0f;
float p = 101325.0f;
float c = 1500.0f;
AGL = Airdata.getAGL(p,c);
T = Airdata.getApproxTemp(T0,AGL);
```

**float getDensity(float p, float T)**
This function returns the air density (kg/m^3) given a static pressure (Pa) and temperature (C).

```C++
float ro;
float T = 23.0f;
float p = 101325.0f;
ro = Airdata.getDensity(p,T);
```

## Example List

* **StaticValues**: demonstrates declaring an *AirData* object and computing air data given a set of static values.
