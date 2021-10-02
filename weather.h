
#ifndef weather_h
#define weather_h

#include "rainfall.h"
#include "temperature.h"

class Temperature;
class Rainfall;

class Weather
{
private:
  Rainfall rain;
  Temperature temp;
  /* You can add more variables as needed */
  /* You can add more functions as needed */
public:
  Weather(Rainfall&, Temperature&); /* Constructor */
  Weather(const Weather&); /* Copy Constructor */
  ~Weather(); /* Destructor */
  void print() const; /* Print the Rainfall and Temperature values of the Weather object */

  /* Getters */
  Temperature getTemperature() const;
  Rainfall getRainfall() const;
  
  /* Setters */
  void setTemperature(const Temperature&);
  void setRainfall(const Rainfall&);
};

#endif /* weather_h */

