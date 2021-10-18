#include <SoftwareSerial.h> 

#include <SPI.h> 

#include <Adafruit_GFX.h> 

#include <Adafruit_SSD1306.h> 

//SoftwareSerial obj1(2,3); 

String Data, Text, Phone, Date, Time; 

 

#define SCREEN_WIDTH 128  

#define SCREEN_HEIGHT 64  

 

#define OLED_MOSI   9 

#define OLED_CLK   10 

#define OLED_DC    11 

#define OLED_CS    12 

#define OLED_RESET 13 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, 

  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS); 

void LedPrint(String custom); 

void setup() { 

 Serial.begin(9600); 

 //obj1.begin(9600); 

   // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally 

  if(!display.begin(SSD1306_SWITCHCAPVCC)) { 

    Serial.println(F("SSD1306 allocation failed")); 

    for(;;); // Don't proceed, loop forever 

  } 

  // Show initial display buffer contents on the screen -- 

  // the library initializes this with an Adafruit splash screen. 

  display.display(); 

  delay(2000); // Pause for 2 seconds 

  // Clear the buffer 

  display.clearDisplay(); 

  // Draw a single pixel in white 

  display.drawPixel(10, 10, SSD1306_WHITE); 

  // Show the display buffer on the screen. You MUST call display() after 

  // drawing commands to make them visible on screen! 

  display.display(); 

  delay(2000); 

  LedPrint("Hello, world!"); 

} 

void loop() { 

int i = 0;   

while(Serial.available() > 0){ 

display.clearDisplay(); 

display.setCursor(0,0); 

String Date = Serial.readStringUntil('|'); 

String Time = Serial.readStringUntil('?'); 

String Phone = Serial.readStringUntil('>'); 

String Text = Serial.readStringUntil('\n'); 

delay(20); 

//LedPrint("In while loop " + String(i)); 

LedPrint(Date + " Date"); 

LedPrint(Time + " Time"); 

LedPrint(Phone + " Phone"); 

LedPrint(Text + " Text"); 

i++; 

delay(1000); 

} 

LedPrint(Date + " Date"); 

LedPrint(Time + " Time"); 

LedPrint(Phone + " Phone"); 

LedPrint(Text + " Text"); 

} 

void LedPrint(String custom) { 

  display.setTextSize(1);             // Normal 1:1 pixel scale 

  display.setTextColor(SSD1306_WHITE);        // Draw white text 

               // Start at top-left corner 

  display.println(custom); 

  display.display(); 

} 
