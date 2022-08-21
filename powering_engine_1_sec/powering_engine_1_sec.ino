// Декларируем номер дискретного выхода
int motorPin = 2;
void setup() {
//Назначаем второй дискретный вывод как выход
pinMode(motorPin, OUTPUT);
}
void loop(){
// Включить мотор
digitalWrite(motorPin, HIGH);
// Подождать 1000 мс
delay(1000);
// Выключить мотор
digitalWrite(motorPin, LOW);
// Подождать 1000 мс
delay(1000);
}// Декларируем номер дискретного выхода
