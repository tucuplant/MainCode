#include <Time.h>
#include <TimeLib.h>
#include <DS3231.h>
#include <LiquidCrystal.h> // Incluye la Libreria LiquidCrystal
LiquidCrystal lcd(1, 2, 37,39, 41, 43); // Crea un Objeto LC. Parametros: (rs, enable, d4, d5, d6, d7)

DS3231  rtc(SDA, SCL);
time_t t;
int compiled_time[3];
bool luz=false,oxigenador=false;
//PERICO EL DE LOS PALOTES
//PERICO EL DE LOS PALOTES
//PERICO EL DE LOS PALOTES
//PERICO EL DE LOS PALOTES
//CAMBIO
int sensorDepPin = 7;
int sensorTankPin = 6;
int Led23= 22;
int Led24= 23;
int Led25= 24;
int Led26= 25;
int Led27= 26;
int Led28= 27;
int Led29= 28;
int Led30= 29;
int Led31= 30;
int Led32= 31;
int Led33= 32;
int Led34= 33;
int pinLuz= 5;
int pitidoPin = 9;
int nivelDep = 0;
int nivelTank = 0;
int motorPin = 8;
int tiempo_entre_med = 0;

void setup() {
  Serial.begin(9600);
  //Serial.println("Inicio de sketch - valores del depósto");
  //pinMode(sensorDepPin, INPUT);
  //pinMode(sensorTankPin, INPUT);
  pinMode(pitidoPin, OUTPUT);
  pinMode(Led23, OUTPUT);
  pinMode(Led24, OUTPUT);
  pinMode(Led25, OUTPUT);
  pinMode(Led26, OUTPUT);
  pinMode(Led27, OUTPUT);
  pinMode(Led28, OUTPUT);
  pinMode(Led29, OUTPUT);
  pinMode(Led30, OUTPUT);
  pinMode(Led31, OUTPUT);
  pinMode(Led32, OUTPUT);
  pinMode(Led33, OUTPUT);
  pinMode(Led34, OUTPUT);
  pinMode(motorPin, OUTPUT);
  rtc.begin();
  lcd.begin(16,2); // Inicializa la interface para el LCD screen, and determina sus dimensiones (ancho y alto) del display
  
  
  //t = now(); // store the current time in time variable t
  //rtc.setDOW(FRIDAY);  
   /*int h = parseTime(__TIME__,0);
   int m = parseTime(__TIME__,1);
   int s = parseTime(__TIME__,2);*/
  
 //lcd.print(rtc.getTimeStr());
 
   //BUCLE DE TIEMPO
   int count=0,v,h,m,s;
   char* command = strtok(__TIME__, ":");
   while (command != 0) {

      if(count==0){
        h=atoi(command); 
      }
      if(count==1){
        m=atoi(command); 
      }
      if(count==2){
        s=atoi(command); 
      }

      command = strtok(0, ":");
      Serial.println(command);
      count++;
   }
   //BUCLE DE TIEMPO

      
  rtc.setTime(h, m, s);      
  //rtc.setDate(30, 5, 2019); 
   digitalWrite(9, LOW);//LUZ APAGAD
 
}

void loop() {
  //nivelDep=digitalRead(sensorDepPin);
  //nivelTank=digitalRead(sensorTankPin);
  //Serial.print("El valor depósito = "); //VALOR MONITOR SERIE
  //Serial.println(nivelDep); //VALOR MONITOR SERIE
  //Serial.print("El valor tanque = "); //VALOR MONITOR SERIE
  //Serial.println(nivelTank); //VALOR MONITOR SERIE


  for (int i = 22; i <= 27; i++) {
    digitalWrite(i, HIGH);
    delay(0);
    int y=i+6;
    digitalWrite(y, HIGH);
    delay(15);
    digitalWrite(i, LOW);
    delay(0);    
    digitalWrite(y, LOW);
    delay(15);

  }    
  /**INTERVALO LUUZ**/
  int hora= rtc.getTime().hour;
  Serial.println(hora);
  if((hora<22 && hora>7)){
    digitalWrite(9, HIGH);//LUZ ENCENDIDA
  }else {
    digitalWrite(9, LOW);//LUZ APAGADA
  }
/**INTERVALO OXIGENADOR**/
  if((hora<10 && hora>7)||(hora<23 && hora> 18)){
    digitalWrite(motorPin, LOW); // OXIGENADOR ENCENDIDO
  }else {
    if(digitalRead!=HIGH){
    digitalWrite(motorPin, HIGH); //OXIGENADOR APAGADO
    }
  }
  Serial.println(rtc.getTimeStr());
  //Serial.println(__TIME__);
  //digitalWrite(motorPin, HIGH);//Oxigenador apagado
  //digitalWrite(9, HIGH);

  
  //PANTALLA LCD
  lcd.clear();
  lcd.print("  Time"); // Imprime "LCD Tutorial" sobre el LCD
  delay(30);   // 3 segundos de espera
  lcd.setCursor(0,1); // Seteamos la ubicacion texto 0 linea 1 que sera escrita sobre el LCD
  lcd.print(rtc.getTimeStr());
  delay(40);
  lcd.clear(); // Limpia la pantalla
        
   delay(300);
}
