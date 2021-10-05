
#include "centerFormat.h"

#include "rainfall.h"
#include "temperature.h"
#include "weather.h"

#include <iostream>
#include <string>
#include <vector>

class Temperature;
class Rainfall;
class Weather;

const int LEN_OF_DATASET = 2;

/* Temperature Validation Range */
const double topTemp = 60.0;
const double bottomTemp = -70.0;

/* Rainfall Validation Range */
const int topRain = 25;
const int bottomRain = 1; 

void cinCheck()
{
  if (std::cin.fail())
  {
    std::cout << "Please check the data type, and re-type again." << std::endl;
    exit(1);
  }
}

bool checkTempRange(Temperature& temp)
{
  if (temp.getMinTemperature() < bottomTemp || temp.getMaxTemperature() > topTemp)
  {
    return 1;
  }
  
  if (temp.getMaxTemperature() < temp.getMinTemperature())
  {
    return 1;
  }

  return 0;
}

bool checkRainRange(Rainfall& rain)
{
  if (rain.getMinRainfall() < bottomRain || rain.getMaxRainfall() > topRain)
  {
    return 1;
  }
  
  if (rain.getMaxRainfall() < rain.getMinRainfall())
  {
    return 1;
  }

  return 0;
}

void takingTempInputs(std::vector<Temperature> &tempVect)
{
  for(int i=0; i<LEN_OF_DATASET; i++)
  {
    double tempMax;
    double tempMin;
    double tempAvg;

    std::cout << "Enter min temperature value." << std::endl;
    std::cin >> tempMin;
    cinCheck();

    std::cout << "Enter max temperature value." << std::endl;
    std::cin >> tempMax;
    cinCheck();

    std::cout << "Enter avg temperature value." << std::endl;
    std::cin >> tempAvg;
    cinCheck();

    Temperature temp(tempMax, tempMin, tempAvg);

    bool tempValidator = checkTempRange(temp);

    if (tempValidator)
    {
      std::cout << "Please check the Max and Min Values, and re-type again." << std::endl;
      exit(1);
    } else
    {
      tempVect.push_back(temp);
    }
  }
}

void takingRainInputs(std::vector<Rainfall> &rainVect)
{
  for(int i=0; i<LEN_OF_DATASET; i++)
  {
    int rainMax;
    int rainMin;
    int rainAvg;

    std::cout << "Enter min Rainfall value." << std::endl;
    std::cin >> rainMin;
    cinCheck();

    std::cout << "Enter max Rainfall value." << std::endl;
    std::cin >> rainMax;
    cinCheck();

    std::cout << "Enter avg Rainfall value." << std::endl;
    std::cin >> rainAvg;
    cinCheck();

    Rainfall rain(rainMax, rainMin, rainAvg);

    bool rainValidator = checkRainRange(rain);

    if (rainValidator)
    {
      std::cout << "Please check the Max and Min Values, and re-type again." << std::endl;
      exit(1);
    } else
    {
      rainVect.push_back(rain);
    }
  }
}

Weather meanCalculation(const std::vector<Temperature> &tempVect, const std::vector<Rainfall> &rainVect)
{
  int sumRainMax=0;
  int sumRainMin=0;
  int sumRainAvg=0;

  double sumTempMax=0.0;
  double sumTempMin=0.0;
  double sumTempAvg=0.0;

  for (int i=0; i<LEN_OF_DATASET; i++)
  {
    sumTempMax += tempVect[i].getMaxTemperature();
    sumTempMin += tempVect[i].getMinTemperature();
    sumTempAvg += tempVect[i].getAvgTemperature();

    sumRainMax += rainVect[i].getMaxRainfall();
    sumRainMin += rainVect[i].getMinRainfall();
    sumRainAvg += rainVect[i].getAvgRainfall();
  }

  sumTempMax /= LEN_OF_DATASET;
  sumTempMin /= LEN_OF_DATASET;
  sumTempAvg /= LEN_OF_DATASET;

  sumRainMax /= LEN_OF_DATASET;
  sumRainMin /= LEN_OF_DATASET;
  sumRainAvg /= LEN_OF_DATASET;

  Rainfall meanRain(sumRainMax, sumRainMin, sumRainAvg);
  Temperature meanTemp(sumTempMax, sumTempMin, sumTempAvg);
  Weather meanWeather(meanRain, meanTemp);

  return meanWeather;
}

void buildWeatherVector(std::vector<Weather> &weatherVect, const std::vector<Temperature> &tempVect, const std::vector<Rainfall> &rainVect)
{
  for (int i=0; i<LEN_OF_DATASET; i++)
  {
    Rainfall rain = rainVect[i];
    Temperature temp = tempVect[i];
    weatherVect.push_back(Weather(rain, temp));
  }

  weatherVect.push_back(meanCalculation(tempVect, rainVect));
}

void printTable(const std::vector<Weather> &weatherVect)
{
  const int MARGIN_SIZE=13;
  const int COL_NUM=5;
  std::cout << std::endl;
  std::cout << center("Weather of the Year", MARGIN_SIZE*2) << std::endl;
  std::cout << center("Month",MARGIN_SIZE) << " | "
            << center("T/R",MARGIN_SIZE) << " | "
            << center("Min",MARGIN_SIZE) << " | "
            << center("Max",MARGIN_SIZE) << " | "
            << center("Avg",MARGIN_SIZE) << std::endl;

  std::cout << std::string(MARGIN_SIZE*COL_NUM + COL_NUM*2, '-') << "\n";

  for (int i=0; i<LEN_OF_DATASET; i++)
  {
    std::cout << center(std::to_string(i+1),MARGIN_SIZE) << " | "
              << center("Rainfall",MARGIN_SIZE) << " | "
              << center(std::to_string(weatherVect[i].getRainfall().getMinRainfall()),MARGIN_SIZE) << " | "
              << center(std::to_string(weatherVect[i].getRainfall().getMaxRainfall()),MARGIN_SIZE) << " | "
              << center(std::to_string(weatherVect[i].getRainfall().getAvgRainfall()),MARGIN_SIZE) << std::endl;

    std::cout << center("",MARGIN_SIZE) << " | "
              << center("Temperature",MARGIN_SIZE) << " | "
              << center(std::to_string(weatherVect[i].getTemperature().getMinTemperature()),MARGIN_SIZE) << " | "
              << center(std::to_string(weatherVect[i].getTemperature().getMaxTemperature()),MARGIN_SIZE) << " | "
              << center(std::to_string(weatherVect[i].getTemperature().getAvgTemperature()),MARGIN_SIZE) << std::endl;
  }

  std::cout << std::string(MARGIN_SIZE*5 + 2*5, '-') << "\n";
  std::cout << center("Mean",MARGIN_SIZE) << " | "
            << center("Rainfall",MARGIN_SIZE) << " | "
            << center(std::to_string(weatherVect[LEN_OF_DATASET].getRainfall().getMinRainfall()),MARGIN_SIZE) << " | "
            << center(std::to_string(weatherVect[LEN_OF_DATASET].getRainfall().getMaxRainfall()),MARGIN_SIZE) << " | "
            << center(std::to_string(weatherVect[LEN_OF_DATASET].getRainfall().getAvgRainfall()),MARGIN_SIZE) << std::endl;

  std::cout << center("",MARGIN_SIZE) << " | "
            << center("Temperature",MARGIN_SIZE) << " | "
            << center(std::to_string(weatherVect[LEN_OF_DATASET].getTemperature().getMinTemperature()),MARGIN_SIZE) << " | "
            << center(std::to_string(weatherVect[LEN_OF_DATASET].getTemperature().getMaxTemperature()),MARGIN_SIZE) << " | "
            << center(std::to_string(weatherVect[LEN_OF_DATASET].getTemperature().getAvgTemperature()),MARGIN_SIZE) << std::endl;
}


int main(int argc, const char * argv[]) {

  std::vector<Temperature> tempVec;
  std::vector<Rainfall> rainVec;
  std::vector<Weather> weatherVec;

  takingTempInputs(tempVec);
  takingRainInputs(rainVec);

  buildWeatherVector(weatherVec, tempVec, rainVec);

  printTable(weatherVec);
    
  return 0;
}
