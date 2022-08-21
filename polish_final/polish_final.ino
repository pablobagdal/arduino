#include <Wire.h>
#include <HMC5883L.h>
 
HMC5883L compass;
 
int previousDegree;
 
void setup()
{
  Serial.begin(9600);
 
  // Inicjalizacja HMC5883L
  Serial.println("Initialize HMC5883L");
  while (!compass.begin())
  {
    Serial.println("Nie odnaleziono HMC5883L, sprawdz polaczenie!");
    delay(500);
  }
 
  // Ustawienie zakresu pomiarowego
  compass.setRange(HMC5883L_RANGE_1_3GA);
 
  // Ustawienie trybu pracy
  compass.setMeasurementMode(HMC5883L_CONTINOUS);
 
  // Ustawienie czestotliwosci pomiarow
  compass.setDataRate(HMC5883L_DATARATE_15HZ);
 
  // Liczba usrednionych probek
  compass.setSamples(HMC5883L_SAMPLES_4);
}
 
void loop()
{
  // Pobranie wektorów znormalizowanych
  Vector norm = compass.readNormalize();
 
  // Obliczenie kierunku (rad)
  float heading = atan2(norm.YAxis, norm.XAxis);
 
  // Ustawienie kata deklinacji dla Bytomia 4'26E (positive)
  // Formula: (deg + (min / 60.0)) / (180 / M_PI);
  float declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / M_PI);
  heading += declinationAngle;
 
  // Korekta katow
  if (heading < 0)
  {
    heading += 2 * PI;
  }
 
  if (heading > 2 * PI)
  {
    heading -= 2 * PI;
  }
 
  // Zamiana radianow na stopnie
  float headingDegrees = heading * 180/M_PI;
 
  // Output
  Serial.print(" Heading = ");
  Serial.print(heading);
  Serial.print(" Degress = ");
  Serial.print(headingDegrees);
  Serial.println();
 
  delay(100);
 
  delay(100);
}#include <Wire.h>
#include <HMC5883L.h>
 
HMC5883L compass;
 
int previousDegree;
 
void setup()
{
  Serial.begin(9600);
 
  // Inicjalizacja HMC5883L
  Serial.println("Initialize HMC5883L");
  while (!compass.begin())
  {
    Serial.println("Nie odnaleziono HMC5883L, sprawdz polaczenie!");
    delay(500);
  }
 
  // Ustawienie zakresu pomiarowego
  compass.setRange(HMC5883L_RANGE_1_3GA);
 
  // Ustawienie trybu pracy
  compass.setMeasurementMode(HMC5883L_CONTINOUS);
 
  // Ustawienie czestotliwosci pomiarow
  compass.setDataRate(HMC5883L_DATARATE_15HZ);
 
  // Liczba usrednionych probek
  compass.setSamples(HMC5883L_SAMPLES_4);
}
 
void loop()
{
  // Pobranie wektorów znormalizowanych
  Vector norm = compass.readNormalize();
 
  // Obliczenie kierunku (rad)
  float heading = atan2(norm.YAxis, norm.XAxis);
 
  // Ustawienie kata deklinacji dla Bytomia 4'26E (positive)
  // Formula: (deg + (min / 60.0)) / (180 / M_PI);
  float declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / M_PI);
  heading += declinationAngle;
 
  // Korekta katow
  if (heading < 0)
  {
    heading += 2 * PI;
  }
 
  if (heading > 2 * PI)
  {
    heading -= 2 * PI;
  }
 
  // Zamiana radianow na stopnie
  float headingDegrees = heading * 180/M_PI;
 
  // Output
  Serial.print(" Heading = ");
  Serial.print(heading);
  Serial.print(" Degress = ");
  Serial.print(headingDegrees);
  Serial.println();
 
  delay(100);
 
  delay(100);
}
