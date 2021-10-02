
#include "temperature.h"

#include <iostream>

Temperature::Temperature(): maxTemperature(0.0), minTemperature(0.0), avgTemperature(0.0)
{
  
}

Temperature::Temperature(double& maxTemp, double& minTemp, double& avgTemp) 
{
  maxTemperature = maxTemp;
  minTemperature = minTemp;
  avgTemperature = avgTemp;
}

Temperature::Temperature(const Temperature& temp)
{
  maxTemperature = temp.maxTemperature;
  minTemperature = temp.minTemperature;
  avgTemperature = temp.avgTemperature;
}

Temperature::~Temperature()
{
  
}

void Temperature::print() const
{ 
  std::cout << "Temperature(Min): " << minTemperature << std::endl;
  std::cout << "Temperature(Max): " << maxTemperature << std::endl;
  std::cout << "Temperature(Avg): " << avgTemperature << std::endl;
}

double Temperature::getMaxTemperature() const
{
  return maxTemperature;
}

double Temperature::getMinTemperature() const
{
  return minTemperature;
}

double Temperature::getAvgTemperature() const
{
  return avgTemperature;
}

void Temperature::setMaxTemperature(double newMaxTemp)
{
  maxTemperature = newMaxTemp;
}

void Temperature::setMinTemperature(double newMinTemp)
{
  minTemperature = newMinTemp;
}

void Temperature::setAvgTemperature(double newAvgTemp)
{
  avgTemperature = newAvgTemp;
}
