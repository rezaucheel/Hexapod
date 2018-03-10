//  const int pingPin1 = 11;
//  const int pingPin2 = 12;
//  const int pingPin3 = 24;
//  const int pingPin4 = 25;
//  const int pingPin5 = 26;
//  const int pingPin6 = 27;
//  int inches, cm;
//  unsigned long duration=0;
//
//  void setup() {
//    Serial.begin(9600);
//    pinMode(pingPin1, OUTPUT);
//    pinMode(pingPin2, OUTPUT);
//    pinMode(pingPin3, OUTPUT);
//    pinMode(pingPin4, OUTPUT);
//    pinMode(pingPin5, OUTPUT);
//    pinMode(pingPin6, OUTPUT);
//  }
//  void loop() {
//    pingpin1();
//    pingpin2();
//    pingpin3();
//    pingpin4()
//    pingpin5();
//    pingpin6()
//    delay(500);  
//  }
//
//  void pingpin1(){
//    pinMode(pingPin1, OUTPUT);
//    digitalWrite(pingPin1, LOW);
//    delayMicroseconds(2);
//    digitalWrite(pingPin1, HIGH);
//    delayMicroseconds(5);
//    digitalWrite(pingPin1, LOW);
//    pinMode(pingPin1, INPUT);
//    duration = pulseIn(pingPin1, HIGH);
//    cm = microsecondsToCentimeters(duration);
//    Serial.print(cm);
//    Serial.print(" cm / ");
//  }
//  
//  void pingpin2(){
//    pinMode(pingPin2, OUTPUT);
//    digitalWrite(pingPin2, LOW);
//    delayMicroseconds(2);
//    digitalWrite(pingPin2, HIGH);
//    delayMicroseconds(5);
//    digitalWrite(pingPin2, LOW);
//    pinMode(pingPin2, INPUT);
//    duration = pulseIn(pingPin2, HIGH);
//    cm = microsecondsToCentimeters(duration);
//    Serial.print(cm);
//    Serial.print(" cm");
//    Serial.println();
//  }
//
//  void pingpin3(){
//    pinMode(pingPin3, OUTPUT);
//    digitalWrite(pingPin3, LOW);
//    delayMicroseconds(2);
//    digitalWrite(pingPin3, HIGH);
//    delayMicroseconds(5);
//    digitalWrite(pingPin3, LOW);
//    pinMode(pingPin3, INPUT);
//    duration = pulseIn(pingPin3, HIGH);
//    cm = microsecondsToCentimeters(duration);
//    Serial.print(cm);
//    Serial.print(" cm");
//    Serial.println();
//  }
//
//  void pingpin4(){
//    pinMode(pingPin4, OUTPUT);
//    digitalWrite(pingPin4, LOW);
//    delayMicroseconds(2);
//    digitalWrite(pingPin4, HIGH);
//    delayMicroseconds(5);
//    digitalWrite(pingPin4, LOW);
//    pinMode(pingPin4, INPUT);
//    duration = pulseIn(pingPin4, HIGH);
//    cm = microsecondsToCentimeters(duration);
//    Serial.print(cm);
//    Serial.print(" cm");
//    Serial.println();
//  }
//
//  void pingpin5(){
//    pinMode(pingPin5, OUTPUT);
//    digitalWrite(pingPin5, LOW);
//    delayMicroseconds(2);
//    digitalWrite(pingPin5, HIGH);
//    delayMicroseconds(5);
//    digitalWrite(pingPin5, LOW);
//    pinMode(pingPin5, INPUT);
//    duration = pulseIn(pingPin5, HIGH);
//    cm = microsecondsToCentimeters(duration);
//    Serial.print(cm);
//    Serial.print(" cm");
//    Serial.println();
//  }
//
//  
//  void pingpin6(){
//    pinMode(pingPin6, OUTPUT);
//    digitalWrite(pingPin6, LOW);
//    delayMicroseconds(2);
//    digitalWrite(pingPin6, HIGH);
//    delayMicroseconds(5);
//    digitalWrite(pingPin6, LOW);
//    pinMode(pingPin6, INPUT);
//    duration = pulseIn(pingPin6, HIGH);
//    cm = microsecondsToCentimeters(duration);
//    Serial.print(cm);
//    Serial.print(" cm");
//    Serial.println();
//  }
//  
//  long microsecondsToCentimeters(long microseconds) {
//  return microseconds / 27 / 2;
//  }
