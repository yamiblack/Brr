#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2,3); // RX | TX

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

  display.clearDisplay();
 
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("ready");
  display.display();
}

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
  }
    
  delay(3000);
  digitalWrite(4, LOW);
  my = 0; 
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("ready");
  display.display();
 
}
