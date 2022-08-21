#include <Wire.h>
#include <HMC5883L.h>
 
HMC5883L compass;
 
void setup()
{
  // Эта строка для вывода в специальную консоль с выставленным параметром. В консоли также задаётся этот параметр, поэтому он должен совпадать, иначе будет не правильно читаться текст
  Serial.begin(9600);
 
  // Inicialization HMC5883L
  Serial.println("Initialize HMC5883L");
  while (!compass.begin())
  {
    Serial.println("HMC5883L not found, check connection!");
    delay(500);
  }
 
  // Setting the measuring range
  // +/- 0.88 Ga: HMC5883L_RANGE_0_88GA
  // +/- 1.30 Ga: HMC5883L_RANGE_1_3GA (domyslny)
  // +/- 1.90 Ga: HMC5883L_RANGE_1_9GA
  // +/- 2.50 Ga: HMC5883L_RANGE_2_5GA
  // +/- 4.00 Ga: HMC5883L_RANGE_4GA
  // +/- 4.70 Ga: HMC5883L_RANGE_4_7GA
  // +/- 5.60 Ga: HMC5883L_RANGE_5_6GA
  // +/- 8.10 Ga: HMC5883L_RANGE_8_1GA
  compass.setRange(HMC5883L_RANGE_1_3GA);
 
  // Working mode setting
  // Sleep:              HMC5883L_IDLE
  // Single measurement:     HMC5883L_SINGLE
  // Continuous measurement: HMC5883L_CONTINOUS (default)
  compass.setMeasurementMode(HMC5883L_CONTINOUS);
 
  // Setting the measurement frequency
  //  0.75Hz: HMC5883L_DATARATE_0_75HZ
  //  1.50Hz: HMC5883L_DATARATE_1_5HZ
  //  3.00Hz: HMC5883L_DATARATE_3HZ
  //  7.50Hz: HMC5883L_DATARATE_7_50HZ
  // 15.00Hz: HMC5883L_DATARATE_15HZ (default)
  // 30.00Hz: HMC5883L_DATARATE_30HZ
  // 75.00Hz: HMC5883L_DATARATE_75HZ
  compass.setDataRate(HMC5883L_DATARATE_15HZ);
 
  // Number of averaged samples
  // 1 plug:  HMC5883L_SAMPLES_1 (default)
  // 2 plugs: HMC5883L_SAMPLES_2
  // 4 plugs: HMC5883L_SAMPLES_4
  // 8 plugs: HMC5883L_SAMPLES_8
  compass.setSamples(HMC5883L_SAMPLES_1);
}
 
void loop()
{
  // Download raw measurements
  Vector raw = compass.readRaw();
 
  // Downloading normalized measurements
  Vector norm = compass.readNormalize();
 
  // Great results
  Serial.print(" Xraw = ");
  Serial.print(raw.XAxis);
  Serial.print(" Yraw = ");
  Serial.print(raw.YAxis);
  Serial.print(" Zraw = ");
  Serial.print(raw.ZAxis);
  Serial.print(" Xnorm = ");
  Serial.print(norm.XAxis);
  Serial.print(" Ynorm = ");
  Serial.print(norm.YAxis);
  Serial.print(" ZNorm = ");
  Serial.print(norm.ZAxis);
  Serial.println();  
 
  delay(100);
}
