void setup() {
  Serial.begin(9600);
}

int index = 0;

void loop() {
  Serial.println(index);
  
  index++;
}
