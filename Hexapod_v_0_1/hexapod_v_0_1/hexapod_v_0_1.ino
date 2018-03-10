#include <PWMServo.h>

/*
 * 
 * PIN LAYOUT SERVO
 * KAKI      array      X               Y               Z
 * --------------------------------------------------------
 * 1           0        2               3               4
 * 2           1        5               6               7
 * 3           2        8               29              30
 * 4           3        23              22              21
 * 5           4        20              17              16
 * 6           5        14              38              37
 */

 /*
  *   GENAP     GANJIL
  *     0          1
  *     2          3   
  *     4          5
  */


PWMServo ServoX[6];
PWMServo ServoY[6];
PWMServo ServoZ[6];

int servo_pos_x[6][3];
int servo_pos_y[6][2];
int servo_pos_z[6][2];

int kaki_genap[3];
int kaki_ganjil[3];

const int forward = 0;
const int netral = 1;
const int rear = 2;

const int up = 0;
const int down = 1;
const int in = 2;
const int out = 3;

String serialResponse = ""; //Deklrasiin Variabel String/Serial
char sz[] = "kanan;100;200;300;400"; //Memasukan Variabel Kaki Kanan
String tes[10];

void register_servo() {
      kaki_genap[0] = 0;
      kaki_genap[1] = 2;
      kaki_genap[2] = 4;

      kaki_ganjil[0] = 1;
      kaki_ganjil[1] = 3;
      kaki_ganjil[2] = 5;

      ServoX[0].attach(2);
      ServoY[0].attach(3);
      ServoZ[0].attach(4);
      servo_pos_x[0][forward] = 180;
      servo_pos_x[0][netral] = 160;
      servo_pos_x[0][rear] = 140;
      servo_pos_y[0][up] = 180;
      servo_pos_y[0][down] = 140;
      servo_pos_z[0][up] = 160;
      servo_pos_z[0][down] = 180;
      
      ServoX[1].attach(5);
      ServoY[1].attach(6);
      ServoZ[1].attach(7);
      servo_pos_x[1][forward] = 110;
      servo_pos_x[1][netral] = 90;
      servo_pos_x[1][rear] = 70;
      servo_pos_y[1][up] = 180;
      servo_pos_y[1][down] = 140;
      servo_pos_z[1][up] = 160;
      servo_pos_z[1][down] = 180;
      
      ServoX[2].attach(8);
      ServoY[2].attach(29);
      ServoZ[2].attach(30);
      servo_pos_x[2][forward] = 40;
      servo_pos_x[2][netral] = 20;
      servo_pos_x[2][rear] = 0;
      servo_pos_y[2][up] = 0;
      servo_pos_y[2][down] = 40;
      servo_pos_z[2][up] = 20;
      servo_pos_z[2][down] = 0;
      
      ServoX[3].attach(23);
      ServoY[3].attach(22);
      ServoZ[3].attach(21);
      servo_pos_x[3][forward] = 20;
      servo_pos_x[3][netral] = 40;
      servo_pos_x[3][rear] = 60;
      servo_pos_y[3][up] = 0;
      servo_pos_y[3][down] = 30;
      servo_pos_z[3][up] = 30;
      servo_pos_z[3][down] = 0;
      
      ServoX[4].attach(20);
      ServoY[4].attach(36);
      ServoZ[4].attach(35);
      servo_pos_x[4][forward] = 70;
      servo_pos_x[4][netral] = 90;
      servo_pos_x[4][rear] = 110;
      servo_pos_y[4][up] = 0;
      servo_pos_y[4][down] = 40;
      servo_pos_z[4][up] = 20;
      servo_pos_z[4][down] = 0;
      
      ServoX[5].attach(14);
      ServoY[5].attach(38);
      ServoZ[5].attach(37);
      servo_pos_x[5][forward] = 140;
      servo_pos_x[5][netral] = 160;
      servo_pos_x[5][rear] = 180;
      servo_pos_y[5][up] = 180;
      servo_pos_y[5][down] = 130;
      servo_pos_z[5][up] = 155;
      servo_pos_z[5][down] = 180;
}

//void serial_debugin() {
//    if (Serial.available() > 0) {
//        serialResponse = Serial.readStringUntil('\r\n');
//        char buf[sizeof(sz)];
//        serialResponse.toCharArray(buf, sizeof(buf));
//        char *p = buf;
//        char *str;
//        int i = 0;
//        while((str = strtok_r(p, ";", &p)) != NULL) {
//            //Serial.println(str);
//            tes[i] = str;
//            i++;
//        }
//        if(tes[0]=="X") {
//            func_berdiri(tes[1].toInt(), tes[2].toInt(), tes[3].toInt()); 
//        } else if(tes[0]=="Y") {
//            func_berdiri(tes[1].toInt(), tes[2].toInt(), tes[3].toInt());
//        } else if(tes[0]=="Z") {
//            func_berdiri(tes[1].toInt(), tes[2].toInt(), tes[3].toInt());
//        }
//    }  
//}
//
//void move_legs_forward(int legs[]) {
//    for(int i=0; i<3; i+=1) {
//        ServoX(legs[i]).write(servo_pos_x[legs[i]][forward]);
//    }
//    delay(75);
//}

void init_position() {
    move_legs_neutral(kaki_genap);
    move_legs_neutral(kaki_ganjil);
}

void lipet_kaki() {
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

void legs_move_neutal(int leg) {
      ServoX[leg].write(servo_pos_x[leg][netral]);
      ServoY[leg].write(servo_pos_y[leg][down]);
      ServoZ[leg].write(servo_pos_z[leg][up]);
}

void move_legs_neutral(int legs[]) {
    for(int i=0; i<3; i+=1) {
        legs_move_neutal(legs[i]);  
    }  
}

void move_legs_up(int legs[]) {
    for(int i=0; i<3; i+=1) {
        ServoY[legs[i]].write(servo_pos_y[legs[i]][up]);
        ServoZ[legs[i]].write(servo_pos_z[legs[i]][down]);
    }  

    delay(75);
}

void move_legs_down(int legs[]) {
    for(int i=0; i<3; i+=1) {
        ServoY[legs[i]].write(servo_pos_y[legs[i]][down]);
        ServoZ[legs[i]].write(servo_pos_z[legs[i]][up]);
    }  

    delay(75);
}

void move_legs_forward(int legs[]) {
    for(int i=0; i<3; i+=1) {
        ServoX[legs[i]].write(servo_pos_x[legs[i]][forward]);
    }  

    delay(75);
}

void move_legs_backward(int legs[]) {
    for(int i=0; i<3; i+=1) {
        ServoX[legs[i]].write(servo_pos_x[legs[i]][rear]);
    }  

    delay(75);
}

void setup() {
    Serial.begin(9600);
    register_servo();
    lipet_kaki();
    delay(3000);
    init_position();
//    lipet_kaki();
//    delay(3000);
//    init_position();
//    delay(3000);
//    lipet_kaki();
}

void loop() {
    if (Serial.available() > 0) {
        serialResponse = Serial.readStringUntil('\r\n');
        char buf[sizeof(sz)];
        serialResponse.toCharArray(buf, sizeof(buf));
        char *p = buf;
        char *str;
        int i = 0;
        while((str = strtok_r(p, ";", &p)) != NULL) {
            tes[i] = str;
            i++;
        }

        if(tes[0]=="netral") {
            lipet_kaki();
            init_position();
        } else if(tes[0]=="ganjil") {
            move_legs_up(kaki_ganjil);
        } else if(tes[0]=="genap") {
            move_legs_up(kaki_genap);
        } else if(tes[0]=="dance") {
            init_position();
            delay(1000);
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
        } else if(tes[0]=="jalan") {
            init_position();
            delay(1000);

            move_legs_up(kaki_ganjil);
            move_legs_forward(kaki_ganjil);
            move_legs_down(kaki_ganjil);

            move_legs_up(kaki_genap);
            move_legs_backward(kaki_ganjil);
            move_legs_forward(kaki_genap);

            move_legs_down(kaki_genap);
            move_legs_up(kaki_ganjil);
            move_legs_backward(kaki_genap);
        } else {
//            ServoX[tes[0].toInt()].write(tes[1].toInt());
//            ServoY[tes[0].toInt()].write(tes[2].toInt());
//            ServoZ[tes[0].toInt()].write(tes[3].toInt());

//            ServoX[tes[0].toInt()].write(tes[1].toInt());
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
