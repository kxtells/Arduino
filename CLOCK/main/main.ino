/***
*
* Clock project:
*
* A small clock project:
* https://jcastellssala.com/2016/01/20/arduino-clock-project-overview/
* This clock presents hour and date using MAX72XX Led matrices and an RTC module.
*
*****/
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <avr/power.h>

//Control the Leds
#include "LedControl.h"

//Include all the character definitions (in PROGMEM)
#include "chars.h"

//SETUP RTC
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;

/*
 LedControl.
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,4);

#define DEBUG 1
#define NUM_OF_MATRICES 4 //I am using 4 matrices
#define COLS_PER_MATRIX 8 //Each matrix has 8 columns
#define ROWS 8            //Each matrix has 8 rows
#define BUFFERCOLS COLS_PER_MATRIX * 8
#define COLS (COLS_PER_MATRIX*NUM_OF_MATRICES)

#define SETUP_BUTTON_PIN 2
#define UP_BUTTON_PIN 4
#define DOWN_BUTTON_PIN 3


//This DISPLAY_BUFFER presents the 4 DISPLAY_BUFFERs contiguously
uint8_t DISPLAY_BUFFER[ROWS][BUFFERCOLS] = {0};

tScreenMode MODE = BOOT_ANIM;

uint8_t hour,shour,min,smin,day,sday,month,smonth,counter,event;
uint32_t year,syear;
uint8_t setUpdate;
char dataBuffer[32]; //just a generic buffer to read/write to

/**
 * Clears the whole DISPLAY_BUFFER
 */
void clearDISPLAY_BUFFER(tScrollArea sArea){
    switch(sArea){
        case FULL:
            memset(DISPLAY_BUFFER[0],0,ROWS*BUFFERCOLS);
            break;
        case UPPER:
            memset(DISPLAY_BUFFER[0],0,ROWS*(BUFFERCOLS>>1));
            break;
        case LOWER:
            memset(DISPLAY_BUFFER[(ROWS>>1)],0,ROWS*(BUFFERCOLS>>1));
            break;
    }
}

/*Read an 4x4 value from progrmem into a buffer
* @param dataBuffer (buffer to fill with uint8_t)
* @param char character to read from PROGRAM MEMORY
*/
void read4x4_from_progmem(uint8_t* dataBuffer, char c){
    uint8_t k;
            
    for (k=0;k<16;k++){
      dataBuffer[k] = pgm_read_byte(ASCII_4x4[c] + k);
    }
}

void fill_4x4(uint8_t line, char* str, uint8_t size){
    uint8_t i,c;
    uint8_t nrows = (ROWS>>2);
    uint8_t starti = nrows * line;
    uint8_t rdBuffer[16];

    for(c=0;c<size;c++){ //each character
        read4x4_from_progmem(&rdBuffer[0], str[c]);
        for(i=0;i<4;i++){
            memcpy(DISPLAY_BUFFER[i+4*line] + c*4, rdBuffer + i*4, 4);
        }

    }
}

/**
 * Like fill_4x4 but selecting where the character should start
 */
void fill_4x4_sd(uint8_t line, uint8_t startChar, char* str, uint8_t size){
    uint8_t i,c;
    uint8_t nrows = (ROWS>>2);
    uint8_t starti = nrows * line;
    uint8_t rdBuffer[16];
    uint8_t charCol;

    charCol = startChar;

    for(c=0;c<size;c++){ //each character
        read4x4_from_progmem(&rdBuffer[0], str[c]);
        for(i=0;i<4;i++){
            memcpy(DISPLAY_BUFFER[i+4*line] + charCol*4, rdBuffer + i*4, 4);
        }
        charCol++;
    }
}

/*Read an 8x8 value from progrmem into a buffer
* @param dataBuffer (buffer to fill with uint8_t)
* @param char character to read from PROGRAM MEMORY
*/
void read8x8_from_progmem(uint8_t* dataBuffer, char c){
    uint8_t k;
    uint8_t idx;
    
    idx = c - '0'; //Get character index in our NUMBERS array
    
    for (k=0;k<64;k++){
      dataBuffer[k] = pgm_read_byte(NUMBERS[idx] + k);
    }
}

/**
 * Send a string with numbers
 * @param numbers String with numners. ONLY NUMBERS
 * @param size
 */
void fill_8x8(char* numbers, uint8_t size){
    uint8_t i,n;
    uint8_t rdBuffer[64];

    //Avoid errors please
    if(size * 8 > BUFFERCOLS) return;

    for(n=0;n<size;n++){
        read8x8_from_progmem(&rdBuffer[0], numbers[n]);
        for(i=0;i<ROWS;i++){
            memcpy(DISPLAY_BUFFER[i] + n*8, rdBuffer + i*8, 8);
        }
    }
}

/**
 * Send a string with numbers
 * @param numbers String with numners. ONLY NUMBERS
 * @param startDevice device where to start from
 * @param size
 */
void fill_8x8_sd(char* numbers, uint8_t startDevice, uint8_t size){
    uint8_t i,device,n;
    uint8_t rdBuffer[64];

    device = startDevice;

    for(n=0;n<size;n++){
        read8x8_from_progmem(&rdBuffer[0], numbers[n]);
        for(i=0;i<ROWS;i++){
            memcpy(DISPLAY_BUFFER[i] + device*8, rdBuffer + i*8, 8);
        }
        device++;
    }
}


/*
 * Actually the same as read8x8_from_progmem, but reads from
 * the ICON dataset
* Read an 8x8 value from progrmem into a buffer
* @param dataBuffer (buffer to fill with uint8_t)
* @param char character to read from PROGRAM MEMORY
*/
void readIcon_from_progmem(uint8_t* dataBuffer, uint8_t iconIndex){
    uint8_t k;
    
    for (k=0;k<64;k++){
      dataBuffer[k] = pgm_read_byte(ICONS[iconIndex] + k);
    }
}
/**
 * Draw an specific PROGMEME icon in the DISPLAY_BUFFER 
 * All icons are assumed to be 8x8
 */
void drawIcon(uint8_t iconIndex, uint8_t device){
    uint8_t i,n;
    uint8_t rdBuffer[64];

    readIcon_from_progmem(&rdBuffer[0], iconIndex);
    for(i=0;i<ROWS;i++){
        memcpy(DISPLAY_BUFFER[i] + device*8, rdBuffer + i*8, 8);
    }
}

/**
 * Move the whole DISPLAY_BUFFER to the left
 */
void scrollLeft(tScrollArea sArea){
    uint8_t r,c;
    uint8_t startRow  = 0;
    uint8_t totalRows = ROWS;

    switch (sArea){
      case UPPER:
        startRow = 0;
        totalRows = ROWS / 2;
      break;
      case LOWER:
        startRow = ROWS / 2;
        totalRows = ROWS;
      break;
      default:
        startRow = 0;
        totalRows = ROWS;
      break;
    
    }

    for(r=startRow;r<totalRows;r++){
        for(c=1;c<BUFFERCOLS;c++){
            DISPLAY_BUFFER[r][c-1] = DISPLAY_BUFFER[r][c];
        }
    }
}

/**
 * Move the whole DISPLAY_BUFFER to the Right
 */
void scrollRight(tScrollArea sArea){
    uint8_t r,c;

    for(r=0;r<ROWS;r++){
        for(c=BUFFERCOLS;c>0;c--){
            DISPLAY_BUFFER[r][c] = DISPLAY_BUFFER[r][c-1];
        }
    }
}

//void printLedM(){}

/**
 * Return the uint8_t value representing a row of a device
 * @param device. One of the possible DISPLAY_BUFFERs
 * @param row Which row to get the uint value
 */
uint8_t getRowValue(uint8_t device, uint8_t row){
    uint8_t rowBuffer[8];
    uint8_t result,i;

    memcpy(rowBuffer, DISPLAY_BUFFER[row] + device*COLS_PER_MATRIX, COLS_PER_MATRIX);

    result = 0;
    for(i=0;i<8;i++){
        result = result | (rowBuffer[i] << (7-i));
    }

    return result;
}

/**
 * This function sets the row for a led device
 */
void dummyDriverSetRow(uint8_t device, uint8_t row, uint8_t value){
  lc.setColumn(device, 7-row, value); //TODO WEIRD 7- thing here to review
  //lc.setRow(device, 7-row, value); //TODO WEIRD 7- thing here to review
}


/**
 * This function saves the RTC clock
 */
void saveRTC(){};

/**
 * Fill the 4 DISPLAY_BUFFERs
 */
void sendToMax7291(){
    uint8_t device,r;
    uint8_t rowvalue;

    for(device=0; device<NUM_OF_MATRICES; device++){
        for(r=0;r<ROWS;r++){
            rowvalue = getRowValue(device, r);
            dummyDriverSetRow(device, r, rowvalue);
            //delay(10);
        }
    }
}

/**
 * Check if today it's an event day
 *
 * @param day
 * @param month
 * @param year
 *
 * @returns 250 or the index of the event Day
 *
 */
uint8_t isEventDay(uint8_t day, uint8_t month, uint32_t year){
    uint8_t i;

    //Skip the opening DAY (hacky hack)
    if(day == 24 & month == 12 & year == 2015){
        return 250;
    }

    //Search
    for(i=0; i<sizeof(DAY_EVENTS)/sizeof(DAY_EVENTS[0]); i++){
        if(DAY_EVENTS[i].day == day & DAY_EVENTS[i].month == month){
            return i;
        }
    }

    return 250;
}

//

/**
*
* FUNCTION CALL ON ARDUINO STARTUP
*
*/
void setup() {
    uint8_t i;

    //clock_prescale_set(clock_div_8);
    //SERIAL DEBUG
    Serial.begin(9600);
    while (!Serial);
  
    //SETUP RTC CLOCK
    Wire.begin();
    RTC.begin();
    
    if (! RTC.isrunning()) {
      Serial.println("RTC is NOT running!");
      // following line sets the RTC to the date & time this sketch was compiled
      // RTC.adjust(DateTime(__DATE__, __TIME__));
    }
  
   for(i=0;i<NUM_OF_MATRICES;i++){
    /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
    */
    lc.shutdown(i,false);
    /* Set the brightness to a medium values */
    lc.setIntensity(i,0);
    /* and clear the display */
    lc.clearDisplay(i);
   }

    pinMode(SETUP_BUTTON_PIN, INPUT);
    pinMode(UP_BUTTON_PIN, INPUT);
    pinMode(DOWN_BUTTON_PIN, INPUT);

    counter = 0;
    event = 0;
}




/**
 * Setup button functionality. Does nothing except move between
 * Normal mode to setup modes
 */
void setupButtonInput(){
    int buttonState;

    buttonState = digitalRead(SETUP_BUTTON_PIN);
    switch (buttonState){
        case LOW:
            //NOTHING
            break;
        case HIGH:
            //BUTTON IS PRESSED. CHANGE MODE
            switch(MODE){
                case SET_HOUR:
                    MODE = SET_MINUTE;
                    break;

                case SET_MINUTE:
                    MODE = SET_DAY;
                    break;

                case SET_DAY:
                    MODE = SET_MONTH;
                    break;

                case SET_MONTH:
                    MODE = SET_YEAR;
                    break;

                case SET_YEAR:
                    MODE = SET_RTC;
                    break;
                case BIG_HOUR:
                case EVENT_HOUR:
                    MODE = SET_HOUR;
                    break;
                default:
                    break;
            }
            break;
    }

}

/**
 * Up Button. Ups the value of a setup. be it minutes, hours, day
 * etc
 */
void upButtonInput(){
    int buttonState;
    buttonState = digitalRead(UP_BUTTON_PIN);
    switch (buttonState){
        case LOW:
            //nothing
            break;
        case HIGH:
            switch(MODE){
                case EVENT_HOUR:
                    break;
                case SET_HOUR:
                    shour++;
                    if (shour > 23){
                        shour = 0;
                    }
                    break;

                case SET_MINUTE:
                    smin++;
                    if (smin > 59){
                        smin = 0;
                    }
                    break;

                case SET_DAY:
                    sday++;
                    if (sday > 31){
                        sday = 0;
                    }
                    break;

                case SET_MONTH:
                    smonth++;
                    if (smonth > 12){
                        smonth = 0;
                    }
                    break;

                case SET_YEAR:
                    syear++;
                    if (syear > 3000){
                        syear = 0;
                    }
                    break;

                default:
                    //do nothing
                    break;
            }

            break;
    }
}

/**
 * Down Button. Downs the value of a setup. be it minutes, hours, day
 * etc
 */
void downButtonInput(){
    int buttonState;
    buttonState = digitalRead(DOWN_BUTTON_PIN);
    switch (buttonState){
        case LOW:
            //nothing
            break;
        case HIGH:
            switch(MODE){
                case SET_HOUR:
                    shour--;
                    if (shour == 255){
                        shour = 23;
                    }
                    break;

                case SET_MINUTE:
                    smin--;
                    if (smin == 255){
                        smin = 59;
                    }
                    break;

                case SET_DAY:
                    sday--;
                    if (sday == 255){
                        sday = 31;
                    }
                    break;

                case SET_MONTH:
                    smonth--;
                    if (smonth == 255){
                        smonth = 12;
                    }
                    break;

                case SET_YEAR:
                    syear--;
                    if (syear < 1995){
                        syear = 3000;
                    }
                    break;

                default:
                    //do nothing
                    break;
            }
    }
}
/**
 * Handle the input of the different buttons
 */
void inputButtons(){
    setupButtonInput();
    upButtonInput();
    downButtonInput();
}


void successLogicSetup(){
    clearDISPLAY_BUFFER(FULL);
    drawIcon(ICON_SMILEY2, 4);

    strcpy_P(dataBuffer, (char*)pgm_read_word(&(string_table[STR_GUARDANT])));
    fill_4x4_sd(0, 11, dataBuffer, 8);
    counter = 0;
}

/**
 *
 */
void successLogic(){
    //Display whatever is displayed on success during some time
    scrollLeft(FULL); //move everything to the left
    if(counter >= 8*5){
        MODE = BIG_HOUR;
        counter = 0;
    }
    counter++;
}

/**
 * Clock logic of different modes
 */
void clockLogic(){

    //Do not update the "save" variables
    setUpdate = false;

    switch(MODE){
        case SET_YEAR:
            counter = 0; //Set counter to 0 before saving RTC
            break;
        case SET_RTC:
            if(counter == 0){ //SAVE ONCE
                RTC.adjust(DateTime(syear, smonth, sday, shour, smin, 0));
            }

            //prepare the fanfare
            successLogicSetup();
            MODE = SET_SUCCESS;

            ////Just eye candy, simulate that I'm doing something
            //if(counter >= 8){
            //    MODE = SET_SUCCESS;
            //    counter = 0;
            //}
            //counter++;
            break;

        case SET_SUCCESS:
            successLogic();
            break;
        case BOOT_ANIM:
            counter++;
            if(counter > 8){
                counter = 0;
                MODE = BIG_HOUR;
            }
            break;

        case STRING_TEST:
            //NEXT STRING
            if(counter >= 5){
                event++;
                counter = 0;
            }
            if(event >= NUM_OF_STRINGS){
                event = 0;
            }

            counter++;
            break;

        case ICON_TEST:
            //NEXT STRING
            if(counter >= 5){
                event++;
                counter = 0;
            }
            if(event >= NUM_OF_ICONS){
                event = 0;
            }

            counter++;
            break;

        case BIG_HOUR:
        case EVENT_HOUR:
            //Only check for event day here
            event = isEventDay(day, month, year);
            if(event != 250){
                MODE = EVENT_HOUR;
            }
            else{
                MODE = BIG_HOUR;
            }
            //Update the copies of hour/day etc to SET (in case we change
            //mode to SETUP)
            setUpdate = true;
        break;

    }
}

/**
 * Print whatever depending on the mode
 */
void render() {

    switch(MODE){
        case BIG_HOUR:
            clearDISPLAY_BUFFER(FULL);
            sprintf(dataBuffer, "%02d%02d",hour,min);
            fill_8x8(dataBuffer,4);
            break;
        case EVENT_HOUR:
            clearDISPLAY_BUFFER(FULL);
            sprintf(dataBuffer, "%02d:%02d",hour,min);
            fill_4x4(0, dataBuffer, 5);

            Serial.println(event);
            //All strings from progmem are 8 characters long
            strcpy_P(dataBuffer, (char*)pgm_read_word(&(string_table[DAY_EVENTS[event].strIndex])));
            fill_4x4(1, dataBuffer, 8);
            break;

        //SET MODES
        case SET_HOUR:
            clearDISPLAY_BUFFER(FULL);
            strcpy_P(dataBuffer, (char*)pgm_read_word(&(string_table[STR_HORA])));
            fill_4x4(0,dataBuffer,4);
            sprintf(dataBuffer, "%02d", shour);
            fill_8x8_sd(dataBuffer, 2, 2);
            break;

        case SET_MINUTE:
            clearDISPLAY_BUFFER(FULL);
            strcpy_P(dataBuffer, (char*)pgm_read_word(&(string_table[STR_MIN])));
            fill_4x4(0,dataBuffer,3);
            sprintf(dataBuffer, "%02d", smin);
            fill_8x8_sd(dataBuffer, 2, 2);
            break;

        case SET_DAY:
            clearDISPLAY_BUFFER(FULL);
            strcpy_P(dataBuffer, (char*)pgm_read_word(&(string_table[STR_DIA])));
            fill_4x4(0,dataBuffer,3);
            sprintf(dataBuffer, "%02d", sday);
            fill_8x8_sd(dataBuffer, 2, 2);
            break;

        case SET_MONTH:
            clearDISPLAY_BUFFER(FULL);
            strcpy_P(dataBuffer, (char*)pgm_read_word(&(string_table[STR_MES])));
            fill_4x4(0,dataBuffer,3);
            sprintf(dataBuffer, "%02d", smonth);
            fill_8x8_sd(dataBuffer, 2, 2);
            break;

        case SET_YEAR:
            clearDISPLAY_BUFFER(FULL);
            strcpy_P(dataBuffer, (char*)pgm_read_word(&(string_table[STR_ANY])));
            fill_4x4(0,dataBuffer,3);
            sprintf(dataBuffer, "    %04d", syear);
            fill_4x4(1,dataBuffer,8);
            break;

        case SET_RTC:
            //JUST PAINT WHAT'S ON THE BUFFER THE BUFFER IS MODIFIED ELSEWHERE
            break;
        case SET_SUCCESS:
            // JUST PAINT WHATEVER IT'S ON THE BUFFER. IT'S mODIFIED ELSEWHERE
            break;

        case STRING_TEST:
            clearDISPLAY_BUFFER(FULL);
            strcpy_P(dataBuffer, (char*)pgm_read_word(&(string_table[event])));
            fill_4x4(1, dataBuffer, 8);
            break;

        case ICON_TEST:
            clearDISPLAY_BUFFER(FULL);
            drawIcon(event, 0);
            break;
        case BOOT_ANIM:
            clearDISPLAY_BUFFER(FULL);
            drawIcon(ICON_HEART,0);
            drawIcon(ICON_SMILEY2,1);
            drawIcon(ICON_CREEPER,2);
            drawIcon(ICON_HEART,3);
    }

    sendToMax7291();

}

/**
* Main Loop, runs repeatedly
*
*/


void loop() {
    // put your main code here, to run repeatedly:
    int i, buttonState;

    //Get the current date
    DateTime now = RTC.now(); 
    hour = now.hour();
    min = now.minute();
    day = now.day();
    month = now.month();
    year = now.year();

    //DISPLAY OF EACH MODE
    render();
    //STATE MACHINES OF EACH MODE
    clockLogic();
    //INPUT BUTTONS LOGIC
    inputButtons();
    
    //Save the state to set!
    if(setUpdate == true){
        shour = hour;
        smin = min;
        sday = day;
        smonth = month;
        syear = year;
    }
    
    delay(100);
}
