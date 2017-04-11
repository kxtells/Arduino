/**
*
* uint8_tacaters to be used for clock
*
*/

#ifndef uint8_tS_H
#define uint8_tS_H

#include <stdint.h>
#include <avr/pgmspace.h>

#ifdef __cplusplus
extern "C" {
#endif

enum eStringIDX {
    STR_HORA,
    STR_MIN,
    STR_DIA,
    STR_MES,
    STR_ANY,
    STR_GUARDANT,
    STR_ANNA,
    STR_ADRIA,
    STR_FRANCESC,
    STR_JOSEP,
    STR_MAITE,
    STR_FINA,
    STR_PERE,
    STR_JOAN,
    STR_LLUISA,
    STR_CRISTINA,
    STR_JORDI,
    STR_SALVADOR,
    STR_ROSAMA,
    STR_NADAL,
    STR_TIO,
    STR_ANYNOU,
    STR_RESSACA,
    STR_DIADA,
    STR_REIS,
    STR_LLORET,
    STR_LGTB,
    STR_ST_ROMA,
    STR_HENDRICKS,
    NUM_OF_STRINGS
};

//STRING TABLE. ALL STRINGS FORCED TO BE SIZE 8
const char string_0[] PROGMEM =  "HORA    ";   // "String 0" etc are strings to store - change to suit.
const char string_1[] PROGMEM =  "MIN     ";
const char string_2[] PROGMEM =  "DIA     ";
const char string_3[] PROGMEM =  "MES     ";
const char string_4[] PROGMEM =  "ANY     ";
const char string_5[] PROGMEM =  "OKI     ";
const char string_6[] PROGMEM =  "Anna    ";
const char string_7[] PROGMEM =  "Adria   ";
const char string_8[] PROGMEM =  "Francesc";
const char string_9[] PROGMEM =  "Josep   ";
const char string_10[] PROGMEM = "Maite   ";
const char string_11[] PROGMEM = "Fina    ";
const char string_12[] PROGMEM = "Pere    ";
const char string_13[] PROGMEM = "Joan    ";
const char string_14[] PROGMEM = "Lluisa  ";
const char string_15[] PROGMEM = "Cristina";
const char string_16[] PROGMEM = "Jordi   ";
const char string_17[] PROGMEM = "Salvador";
const char string_18[] PROGMEM = "RosaMa  ";
const char string_19[] PROGMEM = "Nadal!  ";
const char string_20[] PROGMEM = "Caga Tio";
const char string_21[] PROGMEM = "Bon Any ";
const char string_22[] PROGMEM = "Ressaca?";
const char string_23[] PROGMEM = "La Diada";
const char string_24[] PROGMEM = "Reis    ";
const char string_25[] PROGMEM = "Lloret  ";
const char string_26[] PROGMEM = "LGTB    ";
const char string_27[] PROGMEM = "St Roma ";
const char string_28[] PROGMEM = "Hendricks";

const char* const string_table[] PROGMEM = {string_0, string_1, string_2, string_3, string_4, string_5, string_6, string_7, string_8, string_9, string_10, string_11, string_12, string_13, string_14, string_15, string_16, string_17, string_18, string_19, string_20, string_21, string_22, string_23, string_24, string_25, string_26, string_27, string_28};

const PROGMEM char M_ZERO [8][8] = {
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
};

const  PROGMEM char M_ONE [8][8] = {
{0,0,0,0,1,1,1,0},
{0,0,0,0,1,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
};

//HAVE TO WORK ON THAT
const  PROGMEM char M_TWO [8][8] = {
{0,0,1,1,1,1,0,0},
{0,1,1,1,1,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,1,1,0,0},
{0,0,0,1,1,0,0,0},
{0,0,1,1,0,0,0,0},
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
};

const  PROGMEM char M_THREE [8][8] = {
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,1,1,1,1,0},
{0,0,0,1,1,1,1,0},
{0,0,0,0,0,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
};

const  PROGMEM char M_FOUR [8][8] = {
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
};

const  PROGMEM char M_FIVE [8][8] = {
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,0,0,0,0,0},
{0,1,1,1,1,0,0,0},
{0,0,0,0,1,1,0,0},
{0,0,0,0,0,1,1,0},
{0,1,1,1,1,1,0,0},
{0,1,1,1,1,0,0,0},
};

const  PROGMEM char M_SIX [8][8] = {
{0,1,1,0,0,0,0,0},
{0,1,1,0,0,0,0,0},
{0,1,1,0,0,0,0,0},
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
};

const  PROGMEM char M_SEVEN [8][8] = {
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
};

const  PROGMEM char M_EIGHT [8][8] = {
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
};

const  PROGMEM char M_NINE [8][8] = {
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0},
};


typedef enum eNumbers {
  N0,N1,N2,N3,N4,N5,N6,N7,N8,N9
} t8x8Num;

const char* NUMBERS[] = {
  *M_ZERO,
  *M_ONE,
  *M_TWO,
  *M_THREE,
  *M_FOUR,
  *M_FIVE,
  *M_SIX,
  *M_SEVEN,
  *M_EIGHT,
  *M_NINE,
};

const char PROGMEM M_SMILEY [8][8] = {
{0,0,1,1,1,1,0,0},
{0,1,0,0,0,0,1,0},
{1,0,1,0,0,1,0,1},
{1,0,0,0,0,0,0,1},
{1,0,1,0,0,1,0,1},
{1,0,0,1,1,0,0,1},
{0,1,0,0,0,0,1,0},
{0,0,1,1,1,1,0,0},
};

const char PROGMEM M_HEART [8][8] = {
{0,0,1,0,0,1,0,0},
{0,1,1,1,1,1,1,0},
{1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1},
{0,1,1,1,1,1,1,0},
{0,0,1,1,1,1,0,0},
{0,0,0,1,1,0,0,0},
};

const char PROGMEM M_SMILEY2 [8][8] = {
{0,0,1,1,1,1,0,0},
{0,1,0,0,0,0,1,0},
{1,0,1,0,1,0,0,1},
{1,0,1,0,1,0,0,1},
{1,0,0,0,0,1,0,1},
{1,0,1,1,1,0,0,1},
{0,1,0,0,0,0,1,0},
{0,0,1,1,1,1,0,0},
};

const char PROGMEM M_CREEPER[8][8] = {
{1,1,1,1,1,1,1,1},
{1,0,0,1,1,0,0,1},
{1,0,0,1,1,0,0,1},
{1,1,1,1,1,1,1,1},
{1,1,1,0,0,1,1,1},
{1,1,0,0,0,0,1,1},
{1,1,0,1,1,0,1,1},
{1,1,1,1,1,1,1,1},
};

const char PROGMEM M_SPACE_GUY[8][8] = {
{0,0,0,1,1,0,0,0},
{0,0,1,1,1,1,0,0},
{0,1,1,1,1,1,1,0},
{1,1,0,1,1,0,1,1},
{1,1,1,1,1,1,1,1},
{0,0,1,0,0,1,0,0},
{0,1,0,1,1,0,1,0},
{1,0,1,0,0,1,0,1},
};

enum eIconIDX {
    ICON_SMILEY,
    ICON_SMILEY2,
    ICON_HEART,
    ICON_CREEPER,
    ICON_SPACE_GUY,
    NUM_OF_ICONS
};
 
const char* ICONS[] = {
  *M_SMILEY,
  *M_SMILEY2,
  *M_HEART,
  *M_CREEPER,
  *M_SPACE_GUY,
};

const  PROGMEM char S_A[4][4] = {
    {0,0,0,0},
    {0,1,0,0},
    {1,0,1,0},
    {1,0,1,0},
};

const  PROGMEM char S_B[4][4] = {
    {0,0,0,0},
    {1,0,0,0},
    {1,1,1,0},
    {1,1,1,0},
};

const  PROGMEM char S_C[4][4] = {
    {0,0,0,0},
    {1,1,1,0},
    {1,0,0,0},
    {1,1,1,0},
};

const  PROGMEM char S_D[4][4] = {
    {0,0,0,0},
    {1,1,0,0},
    {1,0,1,0},
    {1,1,0,0},
};

const  PROGMEM char S_E[4][4] = {
    {0,0,0,0},
    {1,1,1,0},
    {1,1,0,0},
    {1,1,1,0},
};

const  PROGMEM char S_F[4][4] = {
    {0,0,0,0},
    {1,1,1,0},
    {1,1,0,0},
    {1,0,0,0},
};

const  PROGMEM char S_G[4][4] = {
    {0,0,0,0},
    {1,1,0,0},
    {1,0,1,0},
    {1,1,1,0},
};

const  PROGMEM char S_H[4][4] = {
    {0,0,0,0},
    {1,0,1,0},
    {1,1,1,0},
    {1,0,1,0},
};

const  PROGMEM char S_I[4][4] = {
    {0,0,0,0},
    {1,1,1,0},
    {0,1,0,0},
    {1,1,1,0},
};

const  PROGMEM char S_J[4][4] = {
    {0,0,0,0},
    {0,1,1,0},
    {0,0,1,0},
    {1,1,1,0},
};

const  PROGMEM char S_K[4][4] = {
    {0,0,0,0},
    {1,0,1,0},
    {1,1,0,0},
    {1,0,1,0},
};

const  PROGMEM char S_L[4][4] = {
    {0,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {1,1,1,0},
};

const  PROGMEM char S_M[4][4] = {
    {0,0,0,0},
    {1,1,1,0},
    {1,1,1,0},
    {1,0,1,0},
};

const  PROGMEM char S_N[4][4] = {
    {0,0,0,0},
    {1,1,1,0},
    {1,0,1,0},
    {1,0,1,0},
};

const  PROGMEM char S_O[4][4] = {
    {0,0,0,0},
    {1,1,1,0},
    {1,0,1,0},
    {1,1,1,0},
};

const  PROGMEM char S_P[4][4] = {
    {0,0,0,0},
    {1,1,1,0},
    {1,1,1,0},
    {1,0,0,0},
};

const  PROGMEM char S_Q[4][4] = {
    {0,0,0,0},
    {1,1,1,0},
    {1,0,1,0},
    {1,1,0,0},
};

const  PROGMEM char S_R[4][4] = {
    {0,0,0,0},
    {1,1,1,0},
    {1,1,0,0},
    {1,0,1,0},
};

const  PROGMEM char S_S[4][4] = {
    {0,0,0,0},
    {0,1,1,0},
    {0,1,0,0},
    {1,1,0,0},
};

const  PROGMEM char S_T[4][4] = {
    {0,0,0,0},
    {1,1,1,0},
    {0,1,0,0},
    {0,1,0,0},
};

const  PROGMEM char S_U[4][4] = {
    {0,0,0,0},
    {1,0,1,0},
    {1,0,1,0},
    {1,1,1,0},
};

const  PROGMEM char S_V[4][4] = {
    {0,0,0,0},
    {1,0,1,0},
    {1,0,1,0},
    {0,1,0,0},
};

const  PROGMEM char S_W[4][4] = {
    {0,0,0,0},
    {1,0,1,0},
    {1,1,1,0},
    {1,1,1,0},
};

const  PROGMEM char S_X[4][4] = {
    {0,0,0,0},
    {1,0,1,0},
    {0,1,0,0},
    {1,0,1,0},
};

const  PROGMEM char S_Y[4][4] = {
    {0,0,0,0},
    {1,0,1,0},
    {0,1,0,0},
    {0,1,0,0},
};

const  PROGMEM char S_Z[4][4] = {
    {0,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,1,1,0},
};

const  PROGMEM char S_0[4][4] = {
    {1,1,1,0},
    {1,0,1,0},
    {1,0,1,0},
    {1,1,1,0},
};

const  PROGMEM char S_1[4][4] = {
    {0,1,1,0},
    {1,0,1,0},
    {0,0,1,0},
    {0,0,1,0},
};

const  PROGMEM char S_2[4][4] = {
    {0,1,1,0},
    {1,0,1,0},
    {0,1,0,0},
    {1,1,1,0},
};

const  PROGMEM char S_3[4][4] = {
    {1,1,1,0},
    {0,1,1,0},
    {0,0,1,0},
    {1,1,1,0},
};

const  PROGMEM char S_4[4][4] = {
    {1,0,1,0},
    {1,1,1,0},
    {0,0,1,0},
    {0,0,1,0},
};

const  PROGMEM char S_5[4][4] = {
    {1,1,1,0},
    {1,0,0,0},
    {0,1,1,0},
    {1,1,1,0},
};

const  PROGMEM char S_6[4][4] = {
    {0,1,1,0},
    {1,0,0,0},
    {1,1,1,0},
    {1,1,1,0},
};

const  PROGMEM char S_7[4][4] = {
    {1,1,1,0},
    {0,0,1,0},
    {0,1,0,0},
    {1,0,0,0},
};

const  PROGMEM char S_8[4][4] = {
    {1,1,1,0},
    {1,0,1,0},
    {1,1,1,0},
    {1,1,1,0},
};

const  PROGMEM char S_9[4][4] = {
    {1,1,1,0},
    {1,0,1,0},
    {1,1,1,0},
    {0,0,1,0},
};

const  PROGMEM char S_NDEF[4][4] = {
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1},
};

const  PROGMEM char S_SPACE[4][4] = {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
};

const  PROGMEM char S_DDOT[4][4] = {
    {0,0,0,0},
    {0,1,1,0},
    {0,0,0,0},
    {0,1,1,0},
};

const  PROGMEM char S_EXCL[4][4] = {
    {0,1,1,0},
    {0,1,1,0},
    {0,0,0,0},
    {0,1,1,0},
};

const  PROGMEM char S_QUE[4][4] = {
    {0,1,1,0},
    {1,0,0,1},
    {0,0,1,0},
    {0,0,1,0},
};

const  PROGMEM char S_SLASH[4][4] = {
    {0,0,1,0},
    {0,0,1,0},
    {0,1,0,0},
    {0,1,0,0},
};


const char* ASCII_4x4[] = {
    *S_NDEF, //NULL //0
    *S_NDEF, //SOH
    *S_NDEF, //STX
    *S_NDEF, //ETX
    *S_NDEF, //EOT
    *S_NDEF, //ENQ //5
    *S_NDEF, //ACK
    *S_NDEF, //BEL
    *S_NDEF, //BS
    *S_NDEF, //TAB
    *S_NDEF, //LF //10
    *S_NDEF, //VT
    *S_NDEF, //FF
    *S_NDEF, //CR
    *S_NDEF, //SO
    *S_NDEF, //SI //15
    *S_NDEF, //DLE
    *S_NDEF, //DC1
    *S_NDEF, //DC2
    *S_NDEF, //DC3
    *S_NDEF, //DC4 //20
    *S_NDEF, //NAK
    *S_NDEF, //SYN
    *S_NDEF, //ETB
    *S_NDEF, //CAN
    *S_NDEF, //EM //25
    *S_NDEF, //SUB
    *S_NDEF, //ESC
    *S_NDEF, //FS
    *S_NDEF, //GS
    *S_NDEF, //RS //30
    *S_NDEF, //US
    *S_SPACE, //SPACE
    *S_EXCL, //!
    *S_NDEF, //"
    *S_NDEF, //# //35
    *S_NDEF, //$
    *S_NDEF, //%
    *S_NDEF, //&
    *S_NDEF, //'
    *S_NDEF, //( //40
    *S_NDEF, //)
    *S_NDEF, //*
    *S_NDEF, //+
    *S_NDEF, //'
    *S_NDEF, //- //45
    *S_NDEF, //.
    *S_SLASH, ///
    *S_0, //0
    *S_1, //1
    *S_2, //2 //50
    *S_3, //3
    *S_4, //4
    *S_5, //5
    *S_6, //6
    *S_7, //7 //55
    *S_8, //8
    *S_9, //9
    *S_DDOT, //:
    *S_NDEF, //;
    *S_NDEF, //< //60
    *S_NDEF, //=
    *S_NDEF, //>
    *S_QUE, //?
    *S_NDEF, //@

    *S_A, //A //65
    *S_B, //B
    *S_C, //C
    *S_D, //D
    *S_E, //E
    *S_F, //F //70
    *S_G, //G
    *S_H, //H
    *S_I, //I
    *S_J, //J
    *S_K, //K //75
    *S_L, //L
    *S_M, //M
    *S_N, //N
    *S_O, //O
    *S_P, //P //80
    *S_Q, //Q
    *S_R, //R
    *S_S, //S
    *S_T, //T
    *S_U, //U //85
    *S_V, //V
    *S_W, //W
    *S_X, //X
    *S_Y, //Y
    *S_Z, //Z //90

    *S_NDEF, //[
    *S_NDEF, //\
    *S_NDEF, //]
    *S_NDEF, //^
    *S_NDEF, //_ //95
    *S_NDEF, //`
    *S_NDEF, //`//PADDING (check table plz)

    *S_A, //a
    *S_B, //b
    *S_C, //c
    *S_D, //d //100
    *S_E, //e
    *S_F, //f
    *S_G, //g
    *S_H, //h
    *S_I, //i //105
    *S_J, //j
    *S_K, //k
    *S_L, //l
    *S_M, //m
    *S_N, //n //110
    *S_O, //o
    *S_P, //p
    *S_Q, //q
    *S_R, //r
    *S_S, //s //115
    *S_T, //t
    *S_U, //u
    *S_V, //v
    *S_W, //w
    *S_X, //x //120
    *S_Y, //y
    *S_Z, //z

    *S_NDEF, //{
    *S_NDEF, //|
    *S_NDEF, //} //125
    *S_NDEF, //~
    *S_NDEF //DEL
};


typedef enum eScrollArea {
    FULL,
    UPPER,
    LOWER
} tScrollArea;

typedef enum eButton {
    BUTTON_NONE,
    BUTTON_SET,
    BUTTON_UP,
    BUTTON_DOWN
} tButton;



typedef enum eScreenMode {
    BIG_HOUR,
    EVENT_HOUR,
    SET_HOUR,
    SET_MINUTE,
    SET_DAY,
    SET_MONTH,
    SET_YEAR,
    SET_RTC,
    SET_SUCCESS,
    SET_FAIL,
    BOOT_ANIM,
    SPRITE_TEST,
    STRING_TEST,
    ICON_TEST,
    /*Possibles extres*/
    FIRE_ANIMATION,
    ARKANOID_ANIMATION,
    PONG_ANIMATION,
    YEAH_ANIMATION,
} tScreenMode;

typedef struct eventDate {
    uint8_t day;
    uint8_t month;
    uint8_t strIndex;
} tEventDate;


//All strings are size 8
tEventDate DAY_EVENTS[] = {
    {18, 8, STR_ANNA},
    {16, 9, STR_ADRIA},
    {26, 1, STR_FRANCESC},
    {7, 8, STR_JOSEP},
    {19, 2, STR_MAITE},
    {28, 6, STR_FINA},
    {2, 11, STR_PERE},
    {28, 2, STR_JOAN},
    {1 , 5, STR_LLUISA},
    {29, 3, STR_CRISTINA},
    {21, 10, STR_JORDI},
    {21, 3, STR_SALVADOR},
    {17, 10, STR_ROSAMA},
    {25, 12, STR_NADAL},
    {24, 12, STR_TIO},
    {31, 12, STR_ANYNOU},
    {1,  1,  STR_RESSACA},
    {11, 9,  STR_DIADA},
    {6 , 1,  STR_REIS},
    {24 ,7,  STR_LLORET},
    {28 ,8,  STR_LGTB},
    {18 ,11, STR_ST_ROMA},
    {28 ,9, STR_HENDRICKS},
};


void fill_4x4(uint8_t line, char* str, uint8_t size); //Fill line X(0,1) with the following string
void fill_8x8(char* numbers, uint8_t size); //Fill Using the following digits
void clearDisplay(tScrollArea sArea);

/*Scroll the whole buffer Right*/
void scrollRight(tScrollArea sArea);
/*Scroll the whole buffer Left*/
void scrollLeft(tScrollArea sArea);

/*Scroll a single screen right*/
void scrollScreenRight(uint8_t device);

/*Scroll a single screen left*/
void scrollScreenLeft(uint8_t device);

void drawIcon(uint8_t iconIndex, uint8_t device);

#ifdef __cplusplus
}
#endif

#endif

