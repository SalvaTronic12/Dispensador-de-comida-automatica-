#include <RTClib.h>
#include <Adafruit_SH1106.h>
#include <Servo.h>


#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);
RTC_DS3231 RTC; // objeto del modulo RTC
Servo servo;


int hora = 18;
int minuto = 21;
int segundo = 00;




void setup() {

Serial.begin(9600);
RTC.begin(); 
display.begin(SH1106_SWITCHCAPVCC, 0x3C);
servo.attach(8);
servo.write(0);

//RTC.adjust(DateTime(__DATE__,__TIME__));

}

void loop() {


display.clearDisplay();
DateTime now = RTC.now();






if((hora == now.hour() && minuto == now.minute() && segundo == now.second()) || digitalRead(7) == 1){
  
display.setRotation(0);
display.setCursor(10,10);
display.setTextColor(WHITE);
display.setTextSize(2);
display.println("SIRVIENDO");

display.setRotation(0);
display.setCursor(25,35);
display.setTextColor(WHITE);
display.setTextSize(2);
display.println("COMIDA");
display.display();

servo.write(90);
delay(1300);
servo.write(0);
delay(200);



}

else{
servo.write(0);
 
display.clearDisplay(); 
display.setRotation(0);
display.setCursor(30,0);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println("HORA ACTUAL:");


display.setRotation(0);
display.setCursor(30,15);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(now.hour());

display.setRotation(0);
display.setCursor(45,15);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(":");



display.setRotation(0);
display.setCursor(55,15);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(now.minute());


display.setRotation(0);
display.setCursor(75,15);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(":");

display.setRotation(0);
display.setCursor(85,15);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(now.second());


display.setRotation(0);
display.setCursor(15,30);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println("HORA PROGRAMADA:");



display.setRotation(0);
display.setCursor(30,45);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(hora);

display.setRotation(0);
display.setCursor(45,45);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(":");



display.setRotation(0);
display.setCursor(55,45);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(minuto);


display.setRotation(0);
display.setCursor(75,45);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(":");

display.setRotation(0);
display.setCursor(85,45);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(segundo);

display.display();
}



}
