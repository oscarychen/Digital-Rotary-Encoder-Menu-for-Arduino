#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


/////Rotary Encoder Pin Assignment/////
#define rotaryPin_A 12
#define rotaryPin_B 13
#define rotaryButtonPin 8

#define inputTimeOut 10000   //time out for human input session, milliseconds

unsigned int maxMenuItems;     //number of menu items
unsigned char encoder_A = 0;  
unsigned char encoder_B = 0;
unsigned char encoder_A_prev = 0;
unsigned char encoder_C = 1;  //encoder button
unsigned char encoder_C_prev = 1;
unsigned long currentTime;
unsigned long loopTime;
/////End of Rotary Encoder Declarations/////

/////Global time variable, Hour : Minute Settings
unsigned int setHour = 0;
unsigned int setMinute = 0;
////////

//////Menu declarations///////
unsigned int menuPos = 0; //current menu position
unsigned int lastMenuPos = 0; //previous menu position
unsigned int parentMenuPos = 0; //parent menu position
bool humanInputActive = false;  //flag to indicate if input session is active
unsigned subMenuActive = 0;   //flag to indicate a sub selection menu session is active: 0 - main menu; 1 - number selection 1- 255; 2 - binary selection yes/no; 3 - time setting;
unsigned int subMenuPos = 0;  //sub menu rotary position
unsigned int subMenuClick = 0; //sub menu click counter
//unsigned long inputTimeOut = 10000;   //time out for human input session, milliseconds
unsigned long lastInputTime = millis(); //keep track of time of last human input

typedef struct menu_type
 {
     
     menu_type()
     : code(0), text("")
     {
       //do nothing
     }
     
     unsigned int code; //code that indicate address (position) in the menu tree
     String text; //text to be displayed for the menu selection
     
 }  menu_type;

menu_type menu[100] = {}; //initilizing menu array, use a number >= than the number of menu options


/////End of Menu declarations////

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  Serial.begin(9600);
  rotaryEncoderInit();
  menuInit();

  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  rotaryEncoderUpdate();
  lcdBackLight();
}

void rotaryEncoderInit() {
//Rotary encoder initialization

  pinMode(rotaryPin_A, INPUT_PULLUP);
  pinMode(rotaryPin_B, INPUT_PULLUP);
  pinMode(rotaryButtonPin, INPUT_PULLUP);
  currentTime = millis();
  loopTime = currentTime;
}

void rotaryEncoderUpdate() {
//rotary encoder update, to be called from main loop()

  currentTime = millis();
  if (currentTime >= (loopTime + 1) ) {
    encoder_A = digitalRead(rotaryPin_A);
    encoder_B = digitalRead(rotaryPin_B);
    encoder_C = digitalRead(rotaryButtonPin);

    //handling knob rotation
    if ( (encoder_A == 0) && (encoder_A_prev == 1) ) {  //encoder changed position

      lastInputTime = millis();
      
      if (encoder_B == 1) { //B is high, so encoder moved clockwise
        //Serial.println("encoder rotated CW");

        switch (subMenuActive) { //send encoder action to appropriate menu handler
          case 0: //main menu
            menuUpdate(2);
            break;

          case 1: //subMenu1
            subMenu1Update(2);
            break;

          case 2: //subMenu2
            subMenu2Update(2);
            break;

          case 3:
            subMenu3Update(2);
            break;
            
          default:
            menuUpdate(2);
            break;
        }
        
        
      } else {  //else, encoder moved counter-clockwise
        //Serial.println("encoder rotated CCW");

        switch (subMenuActive) {  //call the appropriate menuupdater depending on which sub menu is active
          case 0:
            menuUpdate(3);
            break;

          case 1:
            subMenu1Update(3);
            break;

          case 2:
            subMenu2Update(3);
            break;

          case 3:
            subMenu3Update(3);
            break;

          default:
            menuUpdate(3);
            break;
        }
      }

    }
    
    //handling push button
    if ( (encoder_C == 0) && (encoder_C_prev == 1) ) { //button pushed
      //Serial.println("encoder button closed.");

      lastInputTime = millis();
      
      switch (subMenuActive) {  //call the appropriate menuupdater depending on which sub menu is active
          case 0:
            menuUpdate(1);
            break;

          case 1:
            subMenu1Update(1);
            break;

          case 2:
            subMenu2Update(1);
            break;

          case 3:
            subMenu3Update(1);
            break;

          default:
            menuUpdate(1);
            break;
        }
      
    } else if ( (encoder_C == 1) && (encoder_C_prev == 0) )  {  //button
      //Serial.println("encoder button opened.");
      
    }
    
    encoder_A_prev = encoder_A;
    encoder_C_prev = encoder_C;
    loopTime = currentTime;

//input time out
    if ( (millis() - lastInputTime) > inputTimeOut ) {
      humanInputActive = false;
      menuPos = 0;
      lastMenuPos = 0;
      menuUpdate(0);
      subMenuActive = 0;
      
    } else {
      humanInputActive = true;
    }
    
  }
  
}



unsigned int menuVerifyPos(unsigned int menuCode) {
//accepts a code that represents position in the menu
//checks against the menu, verify it exist, and returns it
//if the menu code given does not exist, 
//returns the closest code smaller than the one given
 
  bool confirmCode = false; //flag to keep track of whether code has been confirmed in menu tree

  for (unsigned int k = 0; k <= (maxMenuItems - 1); k++) {
    
    if (menuCode == menu[k].code) {  //found exact code, returns it
      menuPos = menu[k].code;
      confirmCode = true;
      lastMenuPos = menuCode;
      return menuPos;
    } 

  }

  if (confirmCode == false) {
    menuPos = lastMenuPos;
    return menuPos;   //cannot find menu option, go back to previous menu option
  }

}

void updateMenuDisplay(unsigned int menuCode) {
//prints menu selection to the LCD display
//in order to have a scrolling menu effect, this code looks at item before and after current menu item and display them in a row


  String curMenu;
  String curMenu2;
  String prevMenu;
  String nextMenu;

  curMenu = findMenuTextFromCode(menuCode);
  prevMenu = findMenuTextFromCode(menuCode - 1);
  nextMenu = findMenuTextFromCode((menuCode + 1));

//if string is 20 or more characters long (for 20 char wide LCD display)
 if( prevMenu.length() >= 20) {
  prevMenu.remove(19); //remove anything after the 19th character from string
 }

 if(nextMenu.length() >= 20) {
  nextMenu.remove(19); //remove anything after the 19th character from string
 }

//starts printing to LCD
  lcd.clear();
  lcd.setCursor(1,0); //char index, row index, on LCD
  lcd.print(prevMenu);
  lcd.setCursor(0,1);
  lcd.print(">");
  
//current menu option text is longer than 20 characters (on a 20 char wide LCD)
 if(curMenu.length() >= 20) {
  
  curMenu2 = curMenu;
  curMenu.remove(19); //remove char from index 19 (20th char)
  curMenu2.remove(0,19);  //remove the first 19 char starting from index 0
  
  lcd.setCursor(1,1); //print first 19 char of current menu text
  lcd.print(curMenu);
  lcd.setCursor(0,2);
  lcd.print("-");
  lcd.setCursor(1,2);
  lcd.print(curMenu2);  //print remainig char of current menu text
 
  lcd.setCursor(1,3); //print the next menu text in the 4th row
  lcd.print(nextMenu);
  
 } else {
  
  lcd.print(curMenu); //print the next menu text in the 3rd row
  lcd.setCursor(1,2);
  lcd.print(nextMenu);
 }
  

  
}

String findMenuTextFromCode(unsigned int menuCode) {
//accepts a code representing the code in menu, and returns the corresponding text
  
  for (unsigned int j = 0; j <= (maxMenuItems - 1); j++ ) {
    if (menuCode == menu[j].code) {
      return menu[j].text;
      break;
    }
  }
}


void lcdBackLight(){
 //human inout timeout to turn off lcd back light
  if (humanInputActive == true) {
    lcd.backlight();
  } else {
    lcd.noBacklight();
  }
}


