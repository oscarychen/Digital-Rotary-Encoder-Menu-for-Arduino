void menuAction(unsigned int menuCode) {
 //gets called when rotary encoder is clicked,
  //check the current location inside the menu,
  //execute approriate actions
  //returns true if some action is executed
  //returns false if nothing is done
 Serial.print("menuAction called with menuCode = ");
 Serial.println(menuCode);
  
      switch (menuCode) {

        case 11:  //set current time

        if (subMenuActive != 3) {  //initialize the subMenu3
          
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("CURRENT TIME:");
          subMenuActive = 3;
          subMenuPos = 0;
          subMenuClick = 0;
          subMenu3Update(0); //calls subMenu3Update with 0 (no action)
          
        } else if (subMenuActive == 3) {  //already initialized
          
          subMenuActive = 0;  //deactivate submenu, activate main menu
          lcd.clear();
          menuPos = 1;
          updateMenuDisplay(menuPos);
          //code to set time variables
        }
        
        break;
        
        case 211: //set opMode to continuous mode
 
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("CONTINUOUS MODE");
          lcd.setCursor(0,1);
          lcd.print("ACTIVATED..");
          
          menuPos = 2;  //return to a previous menu location
          delay(1000);
          updateMenuDisplay(menuPos);
          
          break;

          case 221: //set opMode to daily volume target mode
 
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("DAILY VOLUME MODE");
          lcd.setCursor(0,1);
          lcd.print("ACTIVATED..");
          
          menuPos = 222;  //return to a previous menu location
          delay(1000);
          updateMenuDisplay(menuPos);
          
          break;

        case 2221: //setting daily target volume

          if (subMenuActive != 1) {    //if subMenu1 is not active, activate it

            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("DAILY TARGET VOLUME:");
            subMenuActive = 1;    //activate subMenu1
            subMenuPos = 10;     //sub menu initialization, set it to current daily volume target
            subMenuClick = 0;
            subMenu1Update(0);  //calls subMenu1Update with 0 (no action)

          } else if (subMenuActive == 1) {    //if subMenu1 is already active, execute action from sub menu1 and activate main menu

            subMenuActive = 0;  //deactivate submenu, activate main menus
            
            //set daily target variable to subMenuPos;
            
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("DAILY TARGET VOLUME");
            lcd.setCursor(0,1);
            lcd.print("SET TO ");
            lcd.print(subMenuPos);
            lcd.print(" LITRES");
            menuPos = 222;  //return to previous main menu position
            
            delay(1000);
            updateMenuDisplay(menuPos);

          }
          
          break;


        case 2231:  //set time for daily water change

        if (subMenuActive != 3) {  //initialize the subMenu3
          
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("START DAILY WATER CHANGE AT");
          subMenuActive = 3;
          subMenuPos = 0;
          subMenuClick = 0;
          subMenu3Update(0); //calls subMenu3Update with 0 (no action)
          
        } else if (subMenuActive == 3) {  //already initialized
          
          subMenuActive = 0;  //deactivate submenu, activate main menu
          lcd.clear();
          menuPos = 1;
          updateMenuDisplay(menuPos);
          //code to set time variables
        }
        
        break;

        case 231:
          //set opMode to top-off only mode

          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("TOP-OFF ONLY MODE");
          lcd.setCursor(0,1);
          lcd.print("ACTIVATED..");
          menuPos = 2;  //return to a previous menu location
          delay(1000);
          updateMenuDisplay(menuPos);
          break;

        case 241:
          //set opMode to daily timer mode

          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("DAILY TIMER MODE");
          lcd.setCursor(0,1);
          lcd.print("ACTIVATED..");
          menuPos = 242;  //return to a previous menu location
          
          delay(1000);
          updateMenuDisplay(menuPos);
          break;


        case 2421: //setting drain duration in minutes

          if (subMenuActive != 1) {    //if subMenu1 is not active, activate it

            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("DRAIN FOR THIS MANY MINUTES:");
            subMenuActive = 1;    //activate subMenu1
            subMenuPos = 10;     //sub menu initialization, set it to current daily volume target
            subMenuClick = 0;
            subMenu1Update(0);  //calls subMenu1Update with 0 (no action)

          } else if (subMenuActive == 1) {    //if subMenu1 is already active, execute action from sub menu1 and activate main menu

            subMenuActive = 0;  //deactivate submenu, activate main menus
            
            //set daily target variable to subMenuPos;
            
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("DRAIN DURATION");
            lcd.setCursor(0,1);
            lcd.print("SET TO ");
            lcd.print(subMenuPos);
            lcd.print(" MINUTES");
            menuPos = 242;  //return to previous main menu position
            
            delay(1000);
            updateMenuDisplay(menuPos);

          }
          
          break;

        case 2431:  //set time for daily water change

        if (subMenuActive != 3) {  //initialize the subMenu3
          
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("START DAILY WATER CHANGE AT");
          subMenuActive = 3;
          subMenuPos = 0;
          subMenuClick = 0;
          subMenu3Update(0); //calls subMenu3Update with 0 (no action)
          
        } else if (subMenuActive == 3) {  //already initialized
          
          subMenuActive = 0;  //deactivate submenu, activate main menu
          lcd.clear();
          menuPos = 1;
          updateMenuDisplay(menuPos);
          //code to set time variables
        }
        
        break;
          

        case 311: //setting calibration factor
          
          break;

        case 411: //low pressure enable/disable
          //menuPos = 41; //return to a previous menu position;
          if (subMenuActive != 2) {    //if subMenu2 is not active, activate it
            
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("ENABLE LOW PRESSURE SWITCH?");
            
            subMenuActive = 2;  //activate subMenu2
            subMenuPos = 1;     //sub menu initialization, set it to current setting
            subMenuClick = 0;
            subMenu2Update(0);  //calls subMenu2Update with zero (no action)

            

          } else if (subMenuActive == 2) {    //if subMenu2 is already active, execute action from sub menu2
            
            subMenuActive = 0;  //activate main menus
            //set daily target variable to subMenuPos;

            lcd.clear();
            lcd.setCursor(0,0);
            if (subMenuPos == 1) {
              lcd.print("LOW PRESSURE SWITCH ENABLED");
              
            } else {
              lcd.print("LOW PRESSURE SWITCH DISABLED");
            }
            
            menuPos = 41; //next menu position;
            
            delay(1000);
            updateMenuDisplay(menuPos);
            
          }

          break;

        case 421: //setting delay duration in minutes

          if (subMenuActive != 1) {    //if subMenu1 is not active, activate it

            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("DELAY FILLING FOR THIS MANY MINUTES:");
            subMenuActive = 1;    //activate subMenu1
            subMenuPos = 10;     //sub menu initialization, set it to current daily volume target
            subMenuClick = 0;
            subMenu1Update(0);  //calls subMenu1Update with 0 (no action)

          } else if (subMenuActive == 1) {    //if subMenu1 is already active, execute action from sub menu1 and activate main menu

            subMenuActive = 0;  //deactivate submenu, activate main menus
            
            //set daily target variable to subMenuPos;
            
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("DELAY DURATION");
            lcd.setCursor(0,1);
            lcd.print("SET TO ");
            lcd.print(subMenuPos);
            lcd.print(" MINUTES");
            menuPos = 4;  //return to previous main menu position
            
            delay(1000);
            updateMenuDisplay(menuPos);

          }
          
          break;

        case 511: //setting drain pump power level

          if (subMenuActive != 1) {    //if subMenu1 is not active, activate it

            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("SET DRAIN PUMP POWER (DEFAULT 255):");
            subMenuActive = 1;    //activate subMenu1
            subMenuPos = 10;     //sub menu initialization, set it to current daily volume target
            subMenuClick = 0;
            subMenu1Update(0);  //calls subMenu1Update with 0 (no action)

          } else if (subMenuActive == 1) {    //if subMenu1 is already active, execute action from sub menu1 and activate main menu

            subMenuActive = 0;  //deactivate submenu, activate main menus
            
            //set daily target variable to subMenuPos;
            
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("DRAIN PUMP POWER");
            lcd.setCursor(0,1);
            lcd.print("SET TO ");
            lcd.print(subMenuPos);
            lcd.print("");
            menuPos = 5;  //return to previous main menu position
            
            delay(1000);
            updateMenuDisplay(menuPos);

          }
          
          break;

        case 611: //ESD drain duration

          if (subMenuActive != 1) {    //if subMenu1 is not active, activate it

            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("SET EMERGENCY DRAIN DURATION:");
            subMenuActive = 1;    //activate subMenu1
            subMenuPos = 10;     //sub menu initialization, set it to current daily volume target
            subMenuClick = 0;
            subMenu1Update(0);  //calls subMenu1Update with 0 (no action)

          } else if (subMenuActive == 1) {    //if subMenu1 is already active, execute action from sub menu1 and activate main menu

            subMenuActive = 0;  //deactivate submenu, activate main menus
            
            //set daily target variable to subMenuPos;
            
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("ESD DRAIN DURATION");
            lcd.setCursor(0,1);
            lcd.print("SET TO ");
            lcd.print(subMenuPos);
            lcd.print(" MINUTES");
            menuPos = 61;  //return to previous main menu position
            
            delay(1000);
            updateMenuDisplay(menuPos);

          }
          
          break;

        case 621: //ESD auto reset enable/disable
          //menuPos = 41; //return to a previous menu position;
          if (subMenuActive != 2) {    //if subMenu2 is not active, activate it
            
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("ENABLE AUTO RESET ESD?");
            
            subMenuActive = 2;  //activate subMenu2
            subMenuPos = 1;     //sub menu initialization, set it to current setting
            subMenuClick = 0;
            subMenu2Update(0);  //calls subMenu2Update with zero (no action)

            

          } else if (subMenuActive == 2) {    //if subMenu2 is already active, execute action from sub menu2
            
            subMenuActive = 0;  //activate main menus
            //set daily target variable to subMenuPos;

            lcd.clear();
            lcd.setCursor(0,0);
            if (subMenuPos == 1) {
              lcd.print("ESD AUTO RESET ENABLED");
              
            } else {
              lcd.print("ESD AUTO RESET DISABLED");
            }
            
            menuPos = 63; //next menu position;
            
            delay(1000);
            updateMenuDisplay(menuPos);
            
          }

          break;

        case 631: //ESD auto reset delay

          if (subMenuActive != 1) {    //if subMenu1 is not active, activate it

            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("SET ESD AUTO RESET DELAY (HOURS):");
            subMenuActive = 1;    //activate subMenu1
            subMenuPos = 10;     //sub menu initialization, set it to current daily volume target
            subMenuClick = 0;
            subMenu1Update(0);  //calls subMenu1Update with 0 (no action)

          } else if (subMenuActive == 1) {    //if subMenu1 is already active, execute action from sub menu1 and activate main menu

            subMenuActive = 0;  //deactivate submenu, activate main menus
            
            //set daily target variable to subMenuPos;
            
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("ESD AUTO RESET DELAY");
            lcd.setCursor(0,1);
            lcd.print("SET TO ");
            lcd.print(subMenuPos);
            lcd.print(" HOURS");
            menuPos = 64;  //return to previous main menu position
            
            delay(1000);
            updateMenuDisplay(menuPos);

          }
          
          break;

        case 641: //Setting # of ESD auto reset allowed

          if (subMenuActive != 1) {    //if subMenu1 is not active, activate it

            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("MAX # OF ESD AUTO RESETS ALLOWED:");
            subMenuActive = 1;    //activate subMenu1
            subMenuPos = 10;     //sub menu initialization, set it to current daily volume target
            subMenuClick = 0;
            subMenu1Update(0);  //calls subMenu1Update with 0 (no action)

          } else if (subMenuActive == 1) {    //if subMenu1 is already active, execute action from sub menu1 and activate main menu

            subMenuActive = 0;  //deactivate submenu, activate main menus
            
            //set daily target variable to subMenuPos;
            
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("MAX # OF AUTO RESET");
            lcd.setCursor(0,1);
            lcd.print("SET TO ");
            lcd.print(subMenuPos);
            lcd.print("");
            menuPos = 6;  //return to previous main menu position
            
            delay(1000);
            updateMenuDisplay(menuPos);

          }
          
          break;

        case 71: //master reset
          
          if (subMenuActive != 2) {    //if subMenu2 is not active, activate it
            
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("RESET ALL ERRORS?");
            
            subMenuActive = 2;  //activate subMenu2
            subMenuPos = 1;     //sub menu initialization, set it to current setting
            subMenuClick = 0;
            subMenu2Update(0);  //calls subMenu2Update with zero (no action)

            

          } else if (subMenuActive == 2) {    //if subMenu2 is already active, execute action from sub menu2
            
            subMenuActive = 0;  //activate main menus
            //set daily target variable to subMenuPos;

            lcd.clear();
            lcd.setCursor(0,0);
            if (subMenuPos == 1) {
              lcd.print("RESET COMPLETED");
              
            } else {
              
            }
            
            menuPos = 7; //next menu position;
            
            delay(1000);
            updateMenuDisplay(menuPos);
            
          }

          break;

        case 81: //manual drain

          break;

        case 82: //manual fill

          break;

        default:
          Serial.print("Main menu case not found: ");
          Serial.println(menuCode);

          break;
      }
}

