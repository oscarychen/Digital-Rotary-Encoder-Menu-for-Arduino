void menuUpdate(unsigned char encoderAction) {  //main menu navigation updater
//called on by rotary encoder actions
//parameter 0: no action from encoder
//parameter 1: encoder click
//parameter 2: encoder CW rotation
//parameter 3: encoder CCW rotation

//unsigned int verifiedMenuPos;
  
  if (encoderAction == 0) {
    //no action
    
  } else {  //triggered by action
  
    if (encoderAction == 1) {  //encoder click button
      
      //code below takes menu position to the next sub branch
      if (menuPos % 10 == 0) {  //if menu selection is at XX0 (zero at the end)
        menuPos = menuPos / 10; //go back up one level of menu (we use zero as the 'return' menu selection)
      } else {
        menuPos = menuPos * 10 + 1; //else, go further in one level of menu from the current selection
      }

      menuPos = menuVerifyPos(menuPos);
      menuAction(menuPos);  //click execution
      updateMenuDisplay(menuPos);
  
    } else if (encoderAction == 2) {  //encoder CW rotation
  
      if (menuPos % 10 == 9) {  //if current selection is at XX9
        //do nothing
      } else {
        menuPos ++;
      }
      
      menuPos = menuVerifyPos(menuPos);      
      updateMenuDisplay(menuPos);
  
      
    } else if (encoderAction == 3) {  //encoder CCW rotation
  
      if (menuPos % 10 == 0) {  //if current selection is at XX0
        //do nothing
      } else {
        menuPos --;
      }
      
      menuPos = menuVerifyPos(menuPos);
      updateMenuDisplay(menuPos);
    }

    lastMenuPos = menuPos;

    Serial.print("menuPos = ");
    Serial.println(menuPos);

  }
}

void subMenu1Update(unsigned char encoderAction) { //sub menu type 1 updater: number selection 1 - 255
//called on by rotary encoder actions with a parameter to indicate:
//parameter 0: no action from encoder
//parameter 1: encoder click
//parameter 2: encoder CW rotation
//parameter 3: encoder CCW rotation

  if (encoderAction == 0) {
    // no action
  } else {
  
    if (encoderAction == 1) { //encoder click
      subMenuClick++;
      //Serial.print("subMenu1Update: click++; click = ");
      //Serial.println(subMenuClick);
  
      if(subMenuClick == 1) { //single click to exit sub menu
        lcd.clear();
        menuAction(menuPos);   //calls menuAction with last main menu tree position
      }
      
    } else if (encoderAction == 2) {  //CW rotation
  
      if (subMenuPos >= 255) {
        subMenuPos = 1; 
      } else {
        subMenuPos++;
      }
      
    } else if (encoderAction == 3) {  //CCW rotation
  
      if (subMenuPos <= 1) {
        subMenuPos = 255;
      } else {
        subMenuPos--;
      }
      
    }

    //update 4th row of LCD to display sub menu position
    lcd.setCursor(0,3);
    lcd.print("                    ");
    lcd.setCursor(0,3);
    lcd.print(subMenuPos); 
  }
}

void subMenu2Update(unsigned char encoderAction){ //sub menu type 2, yes-no selection
//called on by rotary encoder actions
//parameter 0: no action from encoder
//parameter 1: encoder click
//parameter 2: encoder CW rotation
//parameter 3: encoder CCW rotation

 if (encoderAction == 1) { //encoder click
    
    subMenuClick++;

    if(subMenuClick == 1) { //single click to exit sub menu
      lcd.clear();
      menuAction(menuPos);   //calls menuAction with last main menu tree position
    }
    
  } else {  //encoder rotation
  if (encoderAction != 0) {
    if (subMenuPos != 1) { //flip subMenuPos between 0 and 1
      subMenuPos = 1;      
    } else {
      subMenuPos = 0;
    }
  }

    //update 4th row of LCD to display sub menu position
    lcd.setCursor(0,3);
    lcd.print("                    ");
    lcd.setCursor(0,3);
    
    if (subMenuPos == 1) {
      lcd.print("YES"); 
    } else if (subMenuPos == 0) {
      lcd.print("NO");
    }
  
  }

}

void subMenu3Update(unsigned char encoderAction) { //sub menu type 3 updater: time setting
//called on by rotary encoder actions with a parameter to indicate:
//parameter 0: no action from encoder
//parameter 1: encoder click
//parameter 2: encoder CW rotation
//parameter 3: encoder CCW rotation

  if (encoderAction == 0) {
    // no action
  } else {
  
    if (encoderAction == 1) { //encoder click
      subMenuClick++;

      if(subMenuClick == 1) { //first click to finish setting hour, move on to set minutes
        
        subMenuPos = 0; //reset subMenuPos to be used for setting minute
        
      } else if(subMenuClick == 2) { //second click to record minute, exit menu
         
        //:::code to set hour and minute to global variables:::
        
        lcd.clear();
        menuAction(menuPos);   //calls menuAction with last main menu tree position
      }
      
    } else if (encoderAction == 2) {  //CW rotation

      if (subMenuClick == 0) {  //setting hour
        
        if (subMenuPos >= 24) { //scrolling end limits
          subMenuPos = 0; 
        } else {
          subMenuPos++;
        }
        
        setHour = subMenuPos;
        
      } else if (subMenuClick == 1) { //setting minute
        
        if (subMenuPos >= 59) { //scrolling end limits
          subMenuPos = 0; 
        } else {
          subMenuPos++;
        }

        setMinute = subMenuPos;
      }
      
    } else if (encoderAction == 3) {  //CCW rotation

      if (subMenuClick == 0) {  //setting hour
        
        if (subMenuPos <= 0) {  //scrolling end limits
          subMenuPos = 24;
        } else {
          subMenuPos--;
        }

        setHour = subMenuPos;

      } else if (subMenuClick == 1) { //setting minute

        if (subMenuPos <= 0) {  //scrolling end limits
          subMenuPos = 59;
        } else {
          subMenuPos--;
        }

        setMinute = subMenuPos;
      }
      
    }
    
    //update 4th row of LCD to display sub menu position
    lcd.setCursor(0,3);
    lcd.print("                    ");
    lcd.setCursor(0,3);
    lcd.print(setHour);
    lcd.print(":");
    lcd.print(setMinute);
  }
}
