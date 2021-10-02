

#ifndef temperature_h
#define temperature_h

class Temperature
{
private:
  double maxTemperature;
  double minTemperature;
  double avgTemperature;
  /* You can add more variables as needed */
  /* You can add more functions as needed */
public:
  Temperature(); /* Default Constructor */
  Temperature(double&, double&, double&); /* Constructor */
  Temperature(const Temperature&); /* Copy Constructor */
  ~Temperature(); /* Destructor */
  void print() const; /* Print the maxTemperature, minTemperature, and avgTemperature values of the object */

  /* Getters */
  double getMaxTemperature() const;
  double getMinTemperature() const;
  double getAvgTemperature() const;
  
  /* Setters */
  void setMaxTemperature(double);
  void setMinTemperature(double);
  void setAvgTemperature(double);

};

#endif /* temperature_h */
