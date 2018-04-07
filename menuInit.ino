void menuInit() {
  //menu text display

  unsigned int i = 0;

  menu[i].code = 0;
  menu[i++].text = "EXIT MENU";
  
  menu[i].code = 1;
  menu[i++].text = "SET CURRENT TIME";
    menu[i].code = 11;
    menu[i++].text = "CURRENT TIME:";
  
  menu[i].code = 2;
  menu[i++].text = "SET OPERATING MODE";
  
    menu[i].code = 20;
    menu[i++].text = "PREVIOUS MENU";
  
    menu[i].code = 21;
    menu[i++].text = "CONTINUOUS MODE";
      menu[i].code = 211;
      menu[i++].text = "ACTIVATE";
      
   
    menu[i].code = 22;
    menu[i++].text = "DAILY MODE";
      menu[i].code = 220;
      menu[i++].text = "PREVIOUS MENU";
      menu[i].code = 221;
      menu[i++].text = "ACTIVATE";
      menu[i].code = 222;
      menu[i++].text = "TARGET VOLUME (L)";
        menu[i].code = 2221;
        menu[i++].text = "SET LITRES PER DAY:";
      menu[i].code = 223;
      menu[i++].text = "SCHEDULE TIME";
        menu[i].code = 2231;
        menu[i++].text = "START DAILY WATER CHANGE AT:";
      
      
    
    menu[i].code = 23;
    menu[i++].text = "TOP-OFF ONLY MODE";
      menu[i].code = 230;
      menu[i++].text = "PREVIOUS MENU";
      menu[i].code = 231;
      menu[i++].text = "ACTIVATE";
    
    menu[i].code = 24;
    menu[i++].text = "DAILY TIMER MODE";
      menu[i].code = 240;
      menu[i++].text = "PREVIOUS MENU";
      menu[i].code = 241;
      menu[i++].text = "ACTIVATE";
      menu[i].code = 242;
      menu[i++].text = "DRAIN DURATION";
        menu[i].code = 2421;
        menu[i++].text = "DRAIN FOR THIS MANY MINUTES:";
      menu[i].code = 243;
      menu[i++].text = "SCHEDULE TIME";
        menu[i].code = 2431;
        menu[i++].text = "START DAILY WATER CHANGE AT:";
        
  
  menu[i].code = 3;
  menu[i++].text = "FLOW METER";
      menu[i].code = 30;
      menu[i++].text = "PREVIOUS MENU";
      menu[i].code = 31;
      menu[i++].text = "CALIBRATION FACTOR";

  
  menu[i].code = 4;
  menu[i++].text = "LOW PRESSURE SWITCH";
      menu[i].code = 40;
      menu[i++].text = "PREVIOUS MENU";
      menu[i].code = 41;
      menu[i++].text = "ENABLE/DISABLE LOW PRESSURE SWITCH";
        menu[i].code = 411;
        menu[i++].text = "DELAY FILLING IF PRESSURE IS LOW?";
      menu[i].code = 42;
      menu[i++].text = "DELAY DURATION";
        menu[i].code = 421;
        menu[i++].text = "DELAY DURATION IN MINUTES:";
  
  menu[i].code = 5;
  menu[i++].text = "DRAIN PUMP/VALVE";
      menu[i].code = 50;
      menu[i++].text = "PREVIOUS MENU";
      menu[i].code = 51;
      menu[i++].text = "DRAIN PUMP SPEED";
        menu[i].code = 511;
        menu[i++].text = "SET DRAIN PUMP POWER (DEFAULT 255):";

  menu[i].code = 6;
  menu[i++].text = "EMERGENCY SHUTDOWN";
    menu[i].code = 60;
    menu[i++].text = "PREVIOUS MENU";
    menu[i].code = 61;
    menu[i++].text = "DRAIN DURATION";
      menu[i].code = 611;
      menu[i++].text = "EMERGENCY DRAIN DURATION (MINUTES):";
    menu[i].code = 62;
    menu[i++].text = "ALLOW AUTO RESET";
      menu[i].code = 621;
      menu[i++].text = "ENABLE AUTO RESET?";
    menu[i].code = 63;
    menu[i++].text = "AUTO RESET DELAY";
      menu[i].code = 631;
      menu[i++].text = "SET AUTO RESET DELAY (HOURS):";
    menu[i].code = 64;
    menu[i++].text = "MAX # AUTO RESETS";
      menu[i].code = 641;
      menu[i++].text = "MAX # OF AUTO RESETS ALLOWED:";
  
  menu[i].code = 7;
  menu[i++].text = "RESET ERRORS";
    menu[i].code = 71;
    menu[i++].text = "RESET ALL ERRORS?";
  
  menu[i].code = 8;
  menu[i++].text = "MAINTENANCE";
    menu[i].code = 80;
    menu[i++].text = "PREVIOUS MENU";
    menu[i].code = 81;
    menu[i++].text = "HOLD TO OPEN DRAIN";
    menu[i].code = 82;
    menu[i++].text = "HOLD TO OPEN INLET";

 maxMenuItems = i + 1;

}
