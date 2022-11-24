void getSensorReadings(){
  temperature = bme.readTemperature();
  // Convert temperature to Fahrenheit
  //temperature = 1.8 * bme.readTemperature() + 32;
  humidity = bme.readHumidity();
  pressure = bme.readPressure()/ 100.0F;
}
