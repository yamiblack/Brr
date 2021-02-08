#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2,3); // RX | TX
// Connect the HC-06 TX to the Arduino RX on pin 2. 
// Connect the HC-06 RX to the Arduino TX on pin 3 through a voltage divider.
// 

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define OLED_RESET 8
Adafruit_SH1106 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 5
#define YPOS 6
#define DELTAY 7


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

#if (SH1106_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SH1106.h!");
#endif

String command ="";
int brr = 4;
int my=0;
void setup() 
{
    Serial.begin(9600);
    bluetooth.begin(9600);  
    pinMode(brr, OUTPUT);
    display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done

  display.clearDisplay();
 
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("ready");
  display.display();
}
 
//void loop()
//{
// 
//while(bluetooth.available())  //mySerial에 전송된 값이 있으면
//  {
//    char myChar = (char)bluetooth.read();  //mySerial int 값을 char 형식으로 변환
//    command+=myChar;   //수신되는 문자를 myString에 모두 붙임 (1바이트씩 전송되는 것을 연결)
//    delay(5);           //수신 문자열 끊김 방지
//  }
//  if(!command.equals(""))  //command 값이 있다면
//  {
//    Serial.println(command); //시리얼모니터에 myString값 출력
//    Serial.println("hi");
//    digitalWrite(4, HIGH);
//    display.clearDisplay();
//    display.setCursor(0,0);
//    display.println(command);
//    display.display();
//  }
//  delay(3000);
//  digitalWrite(4, LOW);
//  command=""; 
//  display.clearDisplay();
//  display.setCursor(0,0);
//  display.println("ready");
//  display.display();
// 
//}

void loop()
{
 
while(bluetooth.available())  //mySerial에 전송된 값이 있으면
  {
    my = bluetooth.read();  //mySerial int 값을 char 형식으로 변환
    delay(5);           //수신 문자열 끊김 방지
  }
  if(my == 1)  //command 값이 있다면
  {
    Serial.println("hi");
    digitalWrite(4, HIGH);
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("hi");
    display.display();
  }/*else if(my == 2)  //command 값이 있다면
  {
      char myChar = (char)bluetooth.read();  //mySerial int 값을 char 형식으로 변환
      command+=myChar;
      delay(5); 
      Serial.println(command);
      digitalWrite(4, HIGH);
      display.clearDisplay();
      display.setCursor(0,0);
      display.println("hi");
      display.display();
      
      
  }*/
  delay(3000);
  digitalWrite(4, LOW);
  my = 0; 
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("ready");
  display.display();
 
}
