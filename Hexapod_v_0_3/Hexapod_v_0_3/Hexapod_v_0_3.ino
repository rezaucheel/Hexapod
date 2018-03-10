#include <PWMServo.h>
#include <Ultrasonic.h>

/*
 *    UNIT KEGIATAN MAHASISWA RESEARCH & DEVELOPMENT KELUARGA MAHASISWA 
 *   UNIVERSITAS PANCASILA (UKM R&D KMUP) TO KONTES ROBOT INDONESIA 2018 
 *          DIVISI KONTES ROBOT PEMADAM API INDONESIA "CAKRAPANCA"
 *-------------------------------------------------------------------------        
 * PELETAKAN PIN SERVO TEENSY 3.6 | POSISI MUKA ROBOT |  
 *    KAKI   ARRAY   X   Y   Z    |  KIRI  &  KANAN   |
 *-------------------------------------------------------------------------
 *     1       0     2   3   4    |    3        0     |
 *     2       1     5   6   7    |    4        1     |
 *     3       2     8   29  30   |    5        2     |
 *     4       3     23  22  21   |
 *     5       4     20  17  16   |
 *     6       5     14  38  37   | 
 */


 PWMServo ServoX[6];  // Variabel X yang menunjukkan bilangan array dari tiap Servo.
 PWMServo ServoY[6];  // Variabel Y yang menunjukkan bilangan array dari tiap Servo.
 PWMServo ServoZ[6];  // Variabel Z yang menunjukkan bilangan array dari tiap Servo.

 int servo_pos_x[6][3];
 int servo_pos_y[6][2];
 int servo_pos_z[6][2];
 int kaki_genap[3];
 int kaki_ganjil[3];

 const int forward = 0;
 const int netral  = 1;
 const int rear    = 2;
 const int up      = 0;
 const int down    = 1;
 const int in      = 2;
 const int out     = 3;

 char sz[]="Kanan;100;200;300;400";
 String serialResponse="";
 String tes[10];

  int check1 = 51;
  int check2 = 47;
  int check3 = 43;
  int check4 = 39;
  
  int checkpoint1 = 0;
  int checkpoint2 = 0;
  int checkpoint3 = 0;
  int checkpoint4 = 0;
  
  int ultrasonic[] = {11,12,24,25,26,27};
  char *pingString[] = {"Depan : ","Depan Kiri : ", "Depan Kanan : ", "Kiri : ", "Kanan : ","Belakang : "};
  
 void register_servo(){
   kaki_genap[0]  = 0;
   kaki_genap[1]  = 2;
   kaki_genap[2]  = 4;
   kaki_ganjil[0] = 1;
   kaki_ganjil[1] = 3;
   kaki_ganjil[2] = 5;

   ServoX[0].attach(2);
   ServoY[0].attach(3);
   ServoZ[0].attach(4);
   servo_pos_x[0][forward] = 180;
   servo_pos_x[0][netral]  = 160;
   servo_pos_x[0][rear]    = 140;
   servo_pos_y[0][up]      = 180;
   servo_pos_y[0][down]    = 140;
   servo_pos_z[0][up]      = 160;
   servo_pos_z[0][down]    = 180;

   ServoX[1].attach(5);
   ServoY[1].attach(6);
   ServoZ[1].attach(7);
   servo_pos_x[1][forward] = 110;
   servo_pos_x[1][netral]  = 90;
   servo_pos_x[1][rear]    = 70;
   servo_pos_y[1][up]      = 180;
   servo_pos_y[1][down]    = 140;
   servo_pos_z[1][up]      = 160;
   servo_pos_z[1][down]    = 180;

   ServoX[2].attach(8);
   ServoY[2].attach(29);
   ServoZ[2].attach(30);
   servo_pos_x[2][forward] = 40;
   servo_pos_x[2][netral]  = 20;
   servo_pos_x[2][rear]    = 0;
   servo_pos_y[2][up]      = 0;
   servo_pos_y[2][down]    = 40;
   servo_pos_z[2][up]      = 20;
   servo_pos_z[2][down]    = 0;

   ServoX[3].attach(23);
   ServoY[3].attach(22);
   ServoZ[3].attach(21);
   servo_pos_x[3][forward] = 20;
   servo_pos_x[3][netral]  = 40;
   servo_pos_x[3][rear]    = 60;
   servo_pos_y[3][up]      = 0;
   servo_pos_y[3][down]    = 30;
   servo_pos_z[3][up]      = 30;
   servo_pos_z[3][down]    = 0;

   ServoX[4].attach(20);
   ServoY[4].attach(36);
   ServoZ[4].attach(35);
   servo_pos_x[4][forward] = 70;
   servo_pos_x[4][netral]  = 90;
   servo_pos_x[4][rear]    = 110;
   servo_pos_y[4][up]      = 0;
   servo_pos_y[4][down]    = 40;
   servo_pos_z[4][up]      = 20;
   servo_pos_z[4][down]    = 0;

   ServoX[5].attach(14);
   ServoY[5].attach(38);
   ServoZ[5].attach(37);
   servo_pos_x[5][forward] = 140;
   servo_pos_x[5][netral]  = 160;
   servo_pos_x[5][rear]    = 180;
   servo_pos_y[5][up]      = 180;
   servo_pos_y[5][down]    = 130;
   servo_pos_z[5][up]      = 155;
   servo_pos_z[5][down]    = 180;
}

void lipat_kaki(){
   ServoX[0].write(180);
   ServoY[0].write(180);
   ServoZ[0].write(180);

   ServoX[1].write(100);
   ServoY[1].write(180);
   ServoZ[1].write(180);

   ServoX[2].write(0);
   ServoY[2].write(0);
   ServoZ[2].write(0);

   ServoX[3].write(0);
   ServoY[3].write(0);
   ServoZ[3].write(0);

   ServoX[4].write(75);
   ServoY[4].write(0);
   ServoZ[4].write(0);

   ServoX[5].write(180);
   ServoY[5].write(180);
   ServoZ[5].write(180); 
}

void init_position(){
   move_legs_neutral(kaki_genap);
   move_legs_neutral(kaki_ganjil);
}

void legs_move_neutral(int leg){
   ServoX[leg].write(servo_pos_x[leg][netral]);
   ServoY[leg].write(servo_pos_y[leg][down]);
   ServoZ[leg].write(servo_pos_z[leg][up]);
}

void move_legs_neutral(int legs[]){
   for(int i=0; i<3; i+=1) {
      legs_move_neutral(legs[i]);
   }
}

void move_legs_up(int legs[]){
   for (int i=0; i<3; i+=1){
      ServoY[legs[i]].write(servo_pos_y[legs[i]][up]);
      ServoZ[legs[i]].write(servo_pos_z[legs[i]][down]);
   }
    delay(75);
}

void move_legs_down(int legs[]){
    for (int i=0; i<3; i+=1){
      ServoY[legs[i]].write(servo_pos_y[legs[i]][down]);
      ServoZ[legs[i]].write(servo_pos_z[legs[i]][up]);
    }
    delay(75);
}

void move_legs_forward(int legs[]){
    for (int i=0; i<3; i+=1){
      ServoX[legs[i]].write(servo_pos_x[legs[i]][forward]);
    }
    delay(75);
}

void move_legs_backward(int legs[]){
    for(int i=0; i<3; i+=1){
      ServoX[legs[i]].write(servo_pos_x[legs[i]][rear]);
    }
    delay(75);
}

void setup(){
    Serial.begin(9600);
    register_servo();
    lipat_kaki();
    delay(3000);
    init_position();
    maju();       
}

void loop(){
//    
//    checkpoint1 = digitalRead (check1); 
//    checkpoint2 = digitalRead (check2); 
//    checkpoint3 = digitalRead (check3); 
//    checkpoint4 = digitalRead (check4); 
//
//    sonar();
//    delay(50);
//    
//    if(ultrasonic(0) <= 18)
//      {
//        sonar();
//        delay(50);
//               
//        if (checkpoint3 != HIGH)
//          {
//            if (ultrasonic(3) > ultrasonic(4)) 
//              { 
//                belok_kiri(); 
//                delay(20);
//                
//                if ( checkpoint1 != HIGH ) { digitalWrite(check1, HIGH); }
//                else if ( checkpoint1 == HIGH && checkpoint2 != HIGH ) { digitalWrite(check2, HIGH); }
//                else if ( checkpoint1 == HIGH && checkpoint2 == HIGH && checkpoint3 != HIGH ) { digitalWrite(check3, HIGH); }
//              }
//              
//            if (ultrasonic(3) < ultrasonic(4))                 
//              { 
//                belok_kanan(); 
//                delay(20);
//                
//                if ( checkpoint1 != HIGH ) { digitalWrite(check1, HIGH); }
//                else if ( checkpoint1 == HIGH && checkpoint2 != HIGH ) { digitalWrite(check2, HIGH); }
//                else if ( checkpoint1 == HIGH && checkpoint2 == HIGH && checkpoint3 != HIGH ) { digitalWrite(check3, HIGH); }
//              }
//          }
//          
//        if (checkpoint3 == HIGH)
//          {
//            belok_kiri(); 
//            delay(20); 
//            digitalWrite(check4, HIGH);
//          }
//   
//        if (checkpoint4 == HIGH)
//          {
//            gerak(berhenti1,sizeof(berhenti1));
//            delay(10000);
//            digitalWrite(check1, LOW);
//            digitalWrite(check2, LOW);
//            digitalWrite(check3, LOW);
//            digitalWrite(check4, LOW);            
//          }      
//      }
//    
//    //else if(ultrasonic(3) > 20 && ultrasonic(4) > 20)  { maju2(); muter_ka3(); maju5(); delay(20); }  
//    else if(ultrasonic(1) <= 11 ){belok_kanan();delay(20); }
//    else if(ultrasonic(2) <= 11 ){belok_kiri();delay(20); }
//    else  { maju(); 
//    }
    
    
    if(Serial.available() > 0){
      serialResponse = Serial.readStringUntil('\r\n');
      char buf[sizeof(sz)];
      serialResponse.toCharArray(buf, sizeof(buf));
      char *p = buf;
      char *str;
      int i=0;
      while ((str = strtok_r(p,";", &p)) !=NULL){
        tes[i] = str;
        i++;
    }
      if(tes[0]=="siap"){
        lipat_kaki();
        init_position();  
    } else if (tes[0]=="lipat"){
        lipat_kaki();     
    } else if (tes[0]=="angkatganjil"){
        move_legs_up(kaki_ganjil);
    } else if (tes[0]=="angkatgenap"){
        move_legs_up(kaki_genap);      
    } else if (tes[0]=="atraksi"){
        move_legs_up(kaki_ganjil);
        delay(1000);
        init_position();
        delay(1000);
        move_legs_up(kaki_genap);
        delay(1000);
        init_position();
        delay(1000);
        move_legs_up(kaki_ganjil);
        delay(1000);
        init_position();
        delay(1000);
        move_legs_up(kaki_genap);
        delay(1000);
        init_position(); 
    }
    else if (tes[0]=="maju"){
      for (int i=0; i<tes[1].toInt(); i+=1){
        move_legs_up(kaki_ganjil);
        move_legs_forward(kaki_ganjil);
        move_legs_down(kaki_ganjil);
        move_legs_up(kaki_genap);
        move_legs_backward(kaki_ganjil);
        move_legs_forward(kaki_genap);
        move_legs_down(kaki_genap);
        move_legs_up(kaki_ganjil);
        move_legs_backward(kaki_genap);
      }
      init_position();
    } else if (tes[0]=="mundur"){
      for(int i=0; i<tes[1].toInt(); i+=1){
        move_legs_up(kaki_ganjil);
        move_legs_backward(kaki_ganjil);
        move_legs_down(kaki_ganjil);

        move_legs_up(kaki_genap);
        move_legs_forward(kaki_ganjil);
        move_legs_backward(kaki_genap);

        move_legs_down(kaki_genap);
        move_legs_up(kaki_ganjil);
        move_legs_forward(kaki_genap);       
      }
      init_position();
    } else if (tes[0]=="belok_kanan"){
      for(int i=0; i<tes[1].toInt(); i+=1){
        move_legs_up(kaki_ganjil);
        ServoX[1].write(servo_pos_x[1][rear]);
        ServoX[3].write(servo_pos_x[3][forward]);
        ServoX[5].write(servo_pos_x[5][forward]);
        delay(75);
        move_legs_down(kaki_ganjil);
        ServoX[1].write(servo_pos_x[1][forward]);
        ServoX[3].write(servo_pos_x[3][rear]);
        ServoX[5].write(servo_pos_x[5][rear]);
        delay(75);
        move_legs_up(kaki_genap); 
        ServoX[0].write(servo_pos_x[0][rear]);
        ServoX[2].write(servo_pos_x[2][rear]);
        ServoX[4].write(servo_pos_x[4][forward]);
        delay(75);
        move_legs_down(kaki_genap);
        ServoX[0].write(servo_pos_x[0][forward]);
        ServoX[2].write(servo_pos_x[2][forward]);
        ServoX[4].write(servo_pos_x[4][rear]);
        delay(75);     
      }
      init_position();
    } else if (tes[0]=="belok_kiri"){
      for(int i=0; i<tes[1].toInt(); i+=1){
        move_legs_up(kaki_genap);
        ServoX[0].write(servo_pos_x[0][forward]);
        ServoX[2].write(servo_pos_x[2][forward]);
        ServoX[4].write(servo_pos_x[4][rear]);
        delay(75);
        move_legs_down(kaki_genap);
        ServoX[0].write(servo_pos_x[0][rear]);
        ServoX[2].write(servo_pos_x[2][rear]);
        ServoX[4].write(servo_pos_x[4][forward]);
        delay(75);
        move_legs_up(kaki_ganjil); 
        ServoX[1].write(servo_pos_x[1][forward]);
        ServoX[3].write(servo_pos_x[3][rear]);
        ServoX[5].write(servo_pos_x[5][rear]);
        delay(75);
        move_legs_down(kaki_ganjil);
        ServoX[1].write(servo_pos_x[1][rear]);
        ServoX[3].write(servo_pos_x[3][forward]);
        ServoX[5].write(servo_pos_x[5][forward]);
        delay(75);  
      }
      init_position();
   }  else {
//              UNTUK TES DERAJAT SERVO 1/3
//      ServoX[tes[0].toInt()].write(tes[1].toInt());
//      ServoY[tes[0].toInt()].write(tes[2].toInt());
//      ServoZ[tes[0].toInt()].write(tes[3].toInt());

//              UNTUK TES DERAJAT SERVO 1/1 
//      ServoX[tes[0].toInt()].write(tes[1].toInt());
          
//      }
    
   }
}
        move_legs_up(kaki_ganjil);
        move_legs_forward(kaki_ganjil);
        move_legs_down(kaki_ganjil);
        move_legs_up(kaki_genap);
        move_legs_backward(kaki_ganjil);
        move_legs_forward(kaki_genap);
        move_legs_down(kaki_genap);
        move_legs_up(kaki_ganjil);
        move_legs_backward(kaki_genap);
}

void maju(){
  move_legs_up(kaki_ganjil);
        move_legs_forward(kaki_ganjil);
        move_legs_down(kaki_ganjil);
        move_legs_up(kaki_genap);
        move_legs_backward(kaki_ganjil);
        move_legs_forward(kaki_genap);
        move_legs_down(kaki_genap);
        move_legs_up(kaki_ganjil);
        move_legs_backward(kaki_genap);
}

void mundur(){
        move_legs_up(kaki_ganjil);
        move_legs_backward(kaki_ganjil);
        move_legs_down(kaki_ganjil);

        move_legs_up(kaki_genap);
        move_legs_forward(kaki_ganjil);
        move_legs_backward(kaki_genap);

        move_legs_down(kaki_genap);
        move_legs_up(kaki_ganjil);
        move_legs_forward(kaki_genap);

}

void belok_kanan(){
        move_legs_up(kaki_ganjil);
        ServoX[1].write(servo_pos_x[1][rear]);
        ServoX[3].write(servo_pos_x[3][forward]);
        ServoX[5].write(servo_pos_x[5][forward]);
        delay(75);
        move_legs_down(kaki_ganjil);
        ServoX[1].write(servo_pos_x[1][forward]);
        ServoX[3].write(servo_pos_x[3][rear]);
        ServoX[5].write(servo_pos_x[5][rear]);
        delay(75);
        move_legs_up(kaki_genap); 
        ServoX[0].write(servo_pos_x[0][rear]);
        ServoX[2].write(servo_pos_x[2][rear]);
        ServoX[4].write(servo_pos_x[4][forward]);
        delay(75);
        move_legs_down(kaki_genap);
        ServoX[0].write(servo_pos_x[0][forward]);
        ServoX[2].write(servo_pos_x[2][forward]);
        ServoX[4].write(servo_pos_x[4][rear]);
        delay(75);
}

void belok_kiri(){
        move_legs_up(kaki_genap);
        ServoX[0].write(servo_pos_x[0][forward]);
        ServoX[2].write(servo_pos_x[2][forward]);
        ServoX[4].write(servo_pos_x[4][rear]);
        delay(75);
        move_legs_down(kaki_genap);
        ServoX[0].write(servo_pos_x[0][rear]);
        ServoX[2].write(servo_pos_x[2][rear]);
        ServoX[4].write(servo_pos_x[4][forward]);
        delay(75);
        move_legs_up(kaki_ganjil); 
        ServoX[1].write(servo_pos_x[1][forward]);
        ServoX[3].write(servo_pos_x[3][rear]);
        ServoX[5].write(servo_pos_x[5][rear]);
        delay(75);
        move_legs_down(kaki_ganjil);
        ServoX[1].write(servo_pos_x[1][rear]);
        ServoX[3].write(servo_pos_x[3][forward]);
        ServoX[5].write(servo_pos_x[5][forward]);
        delay(75);
 
}


//void ping()
//  {
//    unsigned long ultrasoundValue;
//    for(int i=0; i < 5; i++)
//    {
//      ultrasoundValue = ultrasonic(i);
//      Serial.print(pingString[i]);
//      Serial.print(ultrasoundValue);
//      Serial.print("cm, ");    
//      delay(1);
//    }
//    Serial.println();
//    delay(1);
//  }
//  
//unsigned long ultrasonic(int i)
//  {
//    unsigned long echo;
//
//    pinMode(ultraSoundSignalPins[i], OUTPUT); // Switch signalpin to output
//    digitalWrite(ultraSoundSignalPins[i], LOW); // Send low pulse
//    delayMicroseconds(2); // Wait for 2 microseconds
//    digitalWrite(ultraSoundSignalPins[i], HIGH); // Send high pulse
//    delayMicroseconds(5); // Wait for 5 microseconds
//    digitalWrite(ultraSoundSignalPins[i], LOW); // Holdoff
//    pinMode(ultraSoundSignalPins[i], INPUT); // Switch signalpin to input
//    digitalWrite(ultraSoundSignalPins[i], HIGH); // Turn on pullup resistor
//    echo = pulseIn(ultraSoundSignalPins[i], HIGH); //Listen for echo
//    return (echo / 58.138); //convert to CM
//  }



















