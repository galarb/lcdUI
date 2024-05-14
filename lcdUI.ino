/*   ****   A simple User interface   ****
  featuring : LCD16x2 I2C
          SELECT push button
                ENTER push button
    
    press SELECT to choose between Mode1 and 2.
    press ENTER in order to proceed to the chosen mode
    
    by: Gal Arbel, 2024
*/
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

int btn1pin = 3; //SELECT
int btn2pin = 4; //ENTER
bool btn1state = digitalRead(btn1pin); 

void setup()
{
  pinMode(btn1pin, INPUT_PULLUP);
  pinMode(btn2pin, INPUT_PULLUP);

  Serial.begin(9600);
  lcd.init();                   
  lcd.backlight();

  select();

}

void loop(){
  if(!btn1state){
    Serial.println("performing task 1");
    }
  else{
      Serial.println("performing task 2");
     }

}

void select(){
  lcd.setCursor(3,0);
  lcd.print("select mode");
  lcd.setCursor(1,1);
  lcd.print("mode 1");
  lcd.setCursor(9,1);
  lcd.print("mode 2");
  while(digitalRead(btn2pin)){//after "enter" release the loop
      bool btn1 = digitalRead(btn1pin);
    if(!btn1){
      btn1state = !btn1state;
    }
    if(!btn1state){
    
      lcd.setCursor(0,1);
      lcd.print("[");
      lcd.setCursor(7,1);
      lcd.print("]"); 
      lcd.setCursor(8,1);
      lcd.print(" ");
      lcd.setCursor(15,1);
      lcd.print(" ");
    } 
    else {
      lcd.setCursor(0,1);
      lcd.print(" ");
      lcd.setCursor(7,1);
      lcd.print(" "); 
      lcd.setCursor(8,1);
      lcd.print("[");
      lcd.setCursor(15,1);
      lcd.print("]");  
    }
  }
  lcd.clear();
}
