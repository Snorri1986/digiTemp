/*----- LCD 16x2 & termo sensor DS18B20 ------ */
#include <LiquidCrystal.h> 
#include <OneWire.h>
#include <DallasTemperature.h>

/*------- LCD --------*/
#define LCD_RS_PIN  12
#define LCD_E_PIN   11
#define LCD_D4_PIN  6
#define LCD_D5_PIN  7
#define LCD_D6_PIN  8 
#define LCD_D7_PIN  9

/*------ LED --------*/
#define LED_H 4
#define LED_W 5
#define LED_N 3

/*-----DS18B20------*/
#define TMC_F 10
#define TMC_C 2

LiquidCrystal lcd(LCD_RS_PIN,LCD_E_PIN,LCD_D4_PIN,
                  LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN);

void setup() {
  lcd.begin(16,2); // 16 - columns, 2- rows
  delay(1000);
  pinMode(LED_H, LOW);
  pinMode(LED_W, LOW);
  pinMode(LED_N, LOW);
}

void loop() {
  
}
