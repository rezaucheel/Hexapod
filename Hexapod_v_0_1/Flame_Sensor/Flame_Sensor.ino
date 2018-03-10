int sensor0 = A0;
int sensor1 = A1;
int sensor2 = A2;
int sensor3 = A3;
int sensor4 = A4;

int nilaisensor0 = 0;
int nilaisensor1 = 0;
int nilaisensor2 = 0;
int nilaisensor3 = 0;
int nilaisensor4 = 0;


int averagenilai = 0;

int outputPin = 13;

status_ruangan = 0;


// ROUTINE
// TRACKING - SAYAP
// route_sayap_kanan
// 

void setup()
{
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);
}
void loop()
{

  nilaisensor0 = analogRead(sensor0);
  nilaisensor1 = analogRead(sensor1);
  nilaisensor2 = analogRead(sensor2);
  nilaisensor3 = analogRead(sensor3);
  nilaisensor4 = analogRead(sensor4);

  averagenilai = (nilaisensor0 + nilaisensor1 + nilaisensor2 + nilaisensor3 + nilaisensor4) / 5;


  if(nilaisensor0>200 && nilaisensor0>nilaisensor2) {
    Serial.println("API DI KIRI");
  } else if(nilaisensor1>200 && nilaisensor1>nilaisensor2) {
    Serial.println("API DI KIRI");  
  } else if(nilaisensor3>200 && nilaisensor3>nilaisensor2) {
    Serial.println("API DI KANAN");  
  } else if(nilaisensor4>200 && nilaisensor4>nilaisensor2) {
    Serial.println("API DI KANAN");  
  } else {
     Serial.println("tidak ada api"); 
  }

  if(nilaisensor1>200 && nilaisensor2>200 && nilaisensor3>200) {
    Serial.println("API DI DEPAN"); 
  }
  
  delay(500);
//  if (averagenilai >= 200) {
//    // turn LED on:
//    digitalWrite(outputPin, HIGH);
////    Serial.println("Terdeteksi Panas Api");
//  } else {
//    // turn LED off:
//    digitalWrite(outputPin, LOW);
////    Serial.println("Tidak Terdeteksi Panas Api");
//    delay(100);
//  }

}
