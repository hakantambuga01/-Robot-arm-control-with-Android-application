 #include <Servo.h>
 #include<SoftwareSerial.h>

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

signed int pos1;
signed int pos2;
signed int pos3;
signed int pos4;
char gelenVeri;
int a,b,c,d,e,f,g,h;


 

void setup() {

  Serial.begin(9600);
  motor1.attach(6);
  motor2.attach(7);
  motor3.attach(8);
  motor4.attach(9);

  pos1=90;
  motor1.write(pos1);
  pos2=30;
  motor2.write(pos2);
  pos3=40;
  motor3.write(pos3);
  pos4=0;
  motor4.write(pos4);
  

}

void loop() {

  while(Serial.available()>0){

    gelenVeri=Serial.read();

////////////////////////////////// SAĞA ve SOLA DÖNME /////////////////
    if(gelenVeri=='A')a=1;
    while(a==1)
    {
      pos1++;
      motor1.write(pos1);
      if(pos1 >= 180)pos1=180;
      delay(15);
      gelenVeri=Serial.read();
      if(gelenVeri=='P')a=0;
    }

    if(gelenVeri=='B')b=1;
    while(b==1)
    {
      pos1--;
      motor1.write(pos1);
      if(pos1 <= 0)pos1=0;
      delay(15);   
      gelenVeri=Serial.read();
      if(gelenVeri=='P')b=0;
    }
    
  }
  /////////////////////// 1.KOL İLERİ VE GERİ//////////////

  if(gelenVeri=='C')c=1;
    while(c==1)
    {
      pos2++;
      motor2.write(pos2);
       if(pos2 >= 120)pos2=120;
        delay(10);
      gelenVeri=Serial.read();
      if(gelenVeri=='P')c=0;
    }
    
    if(gelenVeri=='D')d=1;
    while(d==1)
    {
      pos2--;
      motor2.write(pos2);
       if(pos2 <= 0)pos2=0;
       delay(15);
      gelenVeri=Serial.read();
      if(gelenVeri=='P')d=0;
    }
    //////////////////////// 2.KOL İLERİ ve GERİ///////////////

    if(gelenVeri=='E')e=1;
    while(e==1)
    {
      pos3++;
      motor3.write(pos3);
      if(pos3 >= 60)pos3=60;
      delay(25);
      gelenVeri=Serial.read();
      if(gelenVeri=='P')e=0;
    }

    if(gelenVeri=='F')f=1;
    while(f==1)
    {
      pos3--;
      motor3.write(pos3);
      if(pos3 <= 0)pos3=0;
      delay(25); 
      gelenVeri=Serial.read();
      if(gelenVeri=='P')f=0;
    }

    ////////////////////// AĞZI AÇ ve KAPAT/////////////////

    if(gelenVeri=='G')g=1;
    while(g==1)
    {
      pos4++;
      motor4.write(pos4);
      if(pos4 >= 60)pos4=60;
      delay(10);  
      gelenVeri=Serial.read();
      if(gelenVeri=='P')g=0;
    }

    if(gelenVeri=='H')h=1;
    while(h==1)
    {
      pos4--;
      motor4.write(pos4);
       if(pos4 <= 0)pos4=0;
       delay(10);
      gelenVeri=Serial.read();
      if(gelenVeri=='P')h=0;
    }



}
