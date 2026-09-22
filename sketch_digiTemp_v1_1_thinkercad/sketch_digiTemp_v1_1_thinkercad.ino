/*----- LCD 16x2 & termo sensor DS18B20 ------ */
#include <LiquidCrystal.h>
//#include <OneWire.h>
//#include <DallasTemperature.h>

/*------- LCD --------*/
#define LCD_RS_PIN 12
#define LCD_E_PIN 11
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9

/*------ LED --------*/
#define LED_H 4
#define LED_W 5
#define LED_N 3

/*-----DS18B20------*/
#define TMC_F 10
#define TMC_C 2

/*---- TMP36-----*/
/*---- Only for test via ThinkerCAD -----*/
#define TMP_TEST A0

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN,
                  LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

//OneWire celciusWire(TMC_C);
//OneWire fahrenheitWire(TMC_F);
//DallasTemperature sensorsCelcius(&celciusWire);
//DallasTemperature sensorsFahrenheit(&fahrenheitWire);

unsigned long measurnmentDelay = 1000;

float celciusGrad = 0.0;
float fahrenheitGrad = 0.0;

/*void showTempSerial() {
  sensorsCelcius.requestTemperatures();
  sensorsFahrenheit.requestTemperatures();

  celciusGrad = sensorsCelcius.getTempCByIndex(0);
  fahrenheitGrad = sensorsFahrenheit.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.print(celciusGrad);
  Serial.print(" C");

  Serial.print("Temperature: ");
  Serial.print(fahrenheitGrad);
  Serial.print(" F");
}*/

// only for test 
// TODO: remove before GO to Production
void showTempSerialAnalogThinkerCAD() {
  int value = analogRead(TMP_TEST);

  float voltage = value * 5.0 / 1023.0;
  float temperature = (voltage - 0.5) * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  delay(1000);
}

void initLCD() {
  lcd.setCursor(0, 0);
  lcd.print("Hello,digiTemp");
}

void setup() {
  /*---- LCD & LEDs -----*/
  lcd.begin(16, 2);
  delay(1000);
  pinMode(LED_H, LOW);
  pinMode(LED_W, LOW);
  pinMode(LED_N, LOW);
  /*--- Serial monitor --- */
  Serial.begin(9600);
  /*----- DS18B20  ------*/
  //sensorsCelcius.begin();
  //sensorsFahrenheit.begin();
}

void loop() {
  //showTempSerial();
  //showTempSerialAnalogThinkerCAD();
  initLCD();
}
