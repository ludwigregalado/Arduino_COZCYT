#include <LiquidCrystal.h>//Incluye los controladores de la pantalla
int alarma=0,tiempo_alarma;//Declaramos unas variables necesarias

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//

void setup() {
  lcd.begin(16, 2);//Iniciamos en la posición 16,2
  lcd.print("Ninguna Alarma");//Imprime un mensaje
  pinMode(7,INPUT);//Establece el modo del pin D7 a entrada
}

void loop() {
  if(digitalRead(7)==HIGH){
      alarma=1;
      lcd.setCursor(0, 0);
      lcd.print("Intruso!!");
                
      tiempo_alarma=millis();//asignamos a la variable un tiempo
      delay(1000);//espera de 1 segundo
   }
              
   if(alarma){
     lcd.setCursor(0,1);
     lcd.print((millis()-tiempo_alarma)/1000);//imprimir el tiempo desde que sonó la alarma
     delay(1000);//espera de 1 segundo
   }
   else{
     lcd.clear();//limpiamos la pantalla
     lcd.print("Ninguna alarma");//imprimimos un mensaje
     
   }
}