
#include "weather.h"

#include <iostream>

Weather::Weather(): rain(), temp()
{
}

Weather::Weather(Rainfall& rainfall, Temperature& temperature)
{
  rain = rainfall;
  temp = temperature;
}

Weather::Weather(const Weather& weather)
{
  rain = weather.rain;
  temp = weather.temp;
}

Weather::~Weather()
{

}

void Weather::print() const
{
  temp.print();
  rain.print();
}

Temperature Weather::getTemperature() const
{
  return temp;
}

Rainfall Weather::getRainfall() const
{
  return rain;
}

void Weather::setTemperature(const Temperature& temperature)
{
  temp = temperature;
}

void Weather::setRainfall(const Rainfall& rainfall)
{
  rain = rainfall;
}
