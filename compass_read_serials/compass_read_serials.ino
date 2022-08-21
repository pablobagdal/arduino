#include <Wire.h>  // подключим стандартную библиотеку I2C
#define addr 0x1E // I2C адрес цифрового компаса HMC5883L
  
void setup() {
  Serial.begin(9600); // инициализация последовательного порта
  Wire.begin(); // инициализация I2C
} 
  
void loop() {
//  Serial.print("Let's start");
//  delay(1000);
  Wire.beginTransmission(addr); // начинаем связь с устройством по адресу 0x1E
  Wire.write(0x0A); // регистр, с которого мы начнём запрашивать данные   
  Wire.endTransmission();  
 
  Wire.requestFrom(addr, 3, true); // запрашиваем 3 байта у ведомого
  
  if(true != true) {
    while( Wire.available() ) {
      char a = Wire.read(); // считываем байт из регистра 0xA; устройство само переходит к следующему регистру
      char b = Wire.read(); // считываем байт из регистра 0xB
      char c = Wire.read(); // считываем байт из регистра 0xС
  
      // Выводим считанное в последовательный порт:
      Serial.print("A = ");   
      Serial.println(a, HEX); 
      Serial.print("B = ");  
      Serial.println(b, HEX); 
      Serial.print("C = ");  
      Serial.println(c, HEX); 
      Serial.println();    
    } 
  } else {
    Serial.println("Wire is not available");
  }
     
  delay(100);
}
