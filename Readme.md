CS 115-003: Object-Oriented Design Assignment #1 (Total: 20 points)

Instructions:

- Ensure instructions and requirements have been read carefully
- Utilize header files (.h) and implementation files (.cpp) for your solution program
- Zip your submission into a single file before uploading to URCourses
- Write your own solutions (A copied solution will result in a zero mark for both parties involved)

Problem 1 (10 points): Write a program by using the following three structures to store the weather data for a particular month:

struct temperature

{

double maxTemperature;

double minTemperature;

double avgTemperature;

};

struct rainfall

{

int maxRainfall;

int minRainfall;

int avgRainfall;

};

struct weather

{

rainfall rain;

temperature temp;

};

The program should have an array (a data structure that has 12 slots ) to store 12 months’ weather data. When the program runs, a prompt window will be shown for the users to enter data for each month. The program then should display month-wise min., max. and average temperatures and rainfalls in a table-like format. In addition, it should display the average min., the average max. and the average mean temperature of the entire year (12 months in total) at the end of the output. Similarly, it should also display the average min., the average max. and the average mean rainfall of the entire year (12 months in total).

The following checks should be implemented for valid inputs. In other words, if the input values are out-of-range, the program should be able to catch exceptions.

1. Temperature range: -70 to +60 C
1. Rainfall range: 1mm to 25mm
1. Min. value <= Average value <= Max value

Problem 2 (10 points): Rewrite the previous program by using three classes to store the weather data for a particular month:

class Temperature

{

private:

double maxTemperature;

double minTemperature;

double avgTemperature;

/\* You can add more variables as needed \*/

/\* You can add more functions as needed \*/

public:

Temperature(double&, double&, double&); /\* Constructor \*/

Temperature(const Temperature&); /\* Copy Constructor \*/

~Temperature(); /\* Destructor \*/

void print(); /\* Print the maxTemperature, minTemperature, and avgTemperature values of the object \*/

/\* You can add more functions as needed \*/

};

class Rainfall

{

private:

int maxRainfall;

int minRainfall;

int avgRainfall;

/\* You can add more variables as needed \*/

/\* You can add more functions as needed \*/

public:

Rainfall(int&, int&, int&); /\* Constructor \*/

Rainfall(const Rainfall&); /\* Copy Constructor \*/

~Rainfall(); /\* Destructor \*/

void print(); /\* Print the maxRainfall, minRainfall, and avgRainfall values of the object \*/ /\* You can add more functions as needed \*/

};

class Weather

{

private:

Rainfall rain;

Temperature temp;

/\* You can add more variables as needed \*/ /\* You can add more functions as needed \*/

public:

Weather(Rainfall&, Temperature&); /\* Constructor \*/ Weather(const Weather&); /\* Copy Constructor \*/ ~Weather(); /\* Destructor \*/

/\* You can add more functions as needed \*/

};

Please implement the Constructor,Copy Constructor, Destructor, Print, and other methods (as needed) in each class.

The program should have a **vector** (a container defined in C++ std::vector representing an array that can change in size) to store 12 months’ weather data. *(Same as the previous questions)* When the program runs, a prompt window will be shown for the users to enter data for each month. The program then should display month-wise min., max. and average temperatures and rainfalls in a table-like format. In addition, it should display the average min., the average max. and the average mean temperature of the entire year (12 months in total) at the end of the output. Similarly, it should also display the average min., the average max. and the average mean rainfall of the entire year (12 months in total).

*(Same as the previous question)* The following checks should be implemented for valid inputs. In other words, if the input values are out-of-range, the program should be able to catch exceptions.

4. Temperature range: -70 to +60 C
4. Rainfall range: 1mm to 25mm
4. Min. value <= Average value <= Max value