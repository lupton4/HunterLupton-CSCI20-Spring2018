#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE
 /*
   * Constructor #1.
   * Sets kelvin_ to 0
   */
    Temperature::Temperature(){
        kelvin_ = 0;
    }
  /*
   * Constructor #2.
   * Sets kelvin_ to the supplied value
   * @param double kelvin - The value to set the internal kelvin to
   */

  Temperature::Temperature(double kelvin){
      kelvin_ = kelvin;
  }
  

  /*
   * Constructor #3.
   * Converts the supplied temperature to kelvin and internally stores it.
   * The temperature's unit will be provided in the second argument.
   * If the second argument is not value (i.e. not 'F' or 'C') assume the
   * temperature is in kelvin
   * @param double temp - The value to set the internal kelvin to once
   *                    - converted.
   * @param char unit - The type of unit temp is. Will be either 'F' or 'C',
   *                    case-insensitive
   */
  
  Temperature::Temperature(double temp, char unit){
      unit = toupper(unit);
      if (unit == 'C'){
          SetTempFromCelsius(temp);
      }
      else if (unit == 'F'){
          SetTempFromFahrenheit(temp);
      }
      else
        kelvin_ = temp;
  }

  /*
   * The temperature will come in as kelvin and this function will set the
   * internal temp to this value
   * @param double kelvin - The value to set the internal kelvin to.
   */
  void Temperature::SetTempFromKelvin(double kelvin){
      kelvin_ = kelvin;
  }

  
  /*
   * The temperature will come in as Celsius and this function will set the
   * internal temp to this value, once converted to kelvin
   * Formula: k = c + 273.15
   * @param double celsius - The value (in celsius) to set the internal kelvin
   *                       - to.
   */
  
  void Temperature::SetTempFromCelsius(double celsius){
      kelvin_= (celsius + 273.15);
  }

  /*
   * The temperature will come in as Fahrenheit and this function will set the
   * internal temp to this value, once converted to kelvin
   * Formula: k = (5.0 * (f - 32) / 9) + 273.15
   * @param double fahrenheit - The value (in fahrenheit) to set the internal
   *                          - kelvin to.
   */
  
  void Temperature::SetTempFromFahrenheit(double fahrenheit){
    kelvin_ = ((5.0 * (fahrenheit - 32) / 9) + 273.15);
  }
  /*
   * Gets the internal temperature in Kelvin.
   * @return double - The temperature in Kelvin
   */
  
  double Temperature::GetTempAsKelvin() const{
      
    return kelvin_;
  }
  /*
   * Returns the internal temp converted to Celsius
   * Formula: k - 273.15
   * @return double - The temperature in Celsius
   */
   
  
  double Temperature::GetTempAsCelsius() const{
      double cel;
      cel = (kelvin_ - 273.15);
      return cel;
  }
  

  /*
   * Returns the internal temp converted to Fahrenheit
   * Formula: ((c * 9.0) / 5) + 32;
   * @return double - The temperature in Fahrenheit
   */
  
  double Temperature::GetTempAsFahrenheit() const{
      double far;
      far = ((((kelvin_-273.15) * 9.0) / 5) + 32);
      return far;
  }

  /*
   * Get a string representation of the temperature.
   * The string will be formatted as:
   * "TEMP UNIT"
   * where TEMP is the temperature to 2 decimal places and UNIT is either
   * "Kelvin", "Celsius", or "Fahrenheit".
   * The conversion to perform is denoted by the parameter.
   * If the unit given through the argument is invalid, set the string to:
   * "Invalid Unit"
   * @uses stringstream
   * @param char unit - The conversion to perform, either 'K', 'C' or 'F',
   *                    defaults to 'K' and is case-insensitive
   * @return string - A string representation of the temperature or invalid if
   *                  the provided unit is not recognized
   */
   
  
  string Temperature::ToString(char unit) const{
      unit = toupper(unit);
      stringstream ss;
      
      if (unit == 'K') {
        ss << std::fixed << std::setprecision(2) << GetTempAsKelvin() << " Kelvin";
      }
      else if (unit == 'C') {
        ss << GetTempAsCelsius() << " Celsius";
      }
      else if (unit == 'F') {
        ss << GetTempAsFahrenheit() << " Fahrenheit";
      }
      else {
        ss << "Invalid Unit";
      }
      return ss.str();
      
  }
