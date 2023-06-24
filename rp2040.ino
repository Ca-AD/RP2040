//Raspberry Pi Pico Dev Board
#include <HardwareSerial.h>
int led = 25;
char data[31]={0};
char serialData = 0;
char hex = 0;
char flag = 0;
int pm=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial1.begin(115200);

  Serial2.setRX(5);
  Serial2.setTX(4);
  Serial1.setFIFOSize(128);
  Serial2.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(led, HIGH);
  // delay(500);
  // digitalWrite(led, LOW);
  // delay(500);
   if(Serial2.available() > 0)//串口接收到数据
  {
  Serial2.readBytes(data, 31);
  flag=1;
  // Serial1.println(data[6], DEC);
  // Serial1.println("Input String:");
  }
  if(flag==1)
  {
    flag=0;
    pm=(data[6]<<8)+ data[7];

    // Serial1.write(data,10);
    Serial1.print("PM2.5: ");
    Serial1.print(pm);
    Serial1.print(" ug/m3");
    pm=0;
    delay(1000);
  }
  else{

    Serial1.print("NO-PM2.5\n");
  }

}
