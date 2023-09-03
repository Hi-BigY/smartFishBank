#include "arduino.h"
#include "ULN2003AN_Driver.h"
#include <arduino.h>

// PIN
int uln2003an_pinA1 = 4;
int uln2003an_pinA2 = 5;
int uln2003an_pinB1 = 6;
int uln2003an_pinB2 = 7;
short _uln2003an_curStep = 0;
unsigned int _uln2003an_time = 1500;

/**************************************
0    [o x x x]
1    [x o x x]
2    [x x o x]
3    [x x x o]
***************************************/

/***********************************
Method: uln2003an_init
Descript: Init module.
Params: A1 A2 B1 B2 pin number and pulse of one round
Return: none
************************************/
void uln2003an_init(int pinA1, int pinA2, int pinB1, int pinB2)
{
  // pin setting
  uln2003an_pinA1 = pinA1;
  uln2003an_pinA2 = pinA2;
  uln2003an_pinB1 = pinB1;
  uln2003an_pinB2 = pinB2;

  // pin mode setting
  pinMode(uln2003an_pinA1, OUTPUT);
  pinMode(uln2003an_pinA2, OUTPUT);
  pinMode(uln2003an_pinB1, OUTPUT);
  pinMode(uln2003an_pinB2, OUTPUT);

  // pin init status setting
  digitalWrite(uln2003an_pinA1, LOW);
  digitalWrite(uln2003an_pinA2, LOW);
  digitalWrite(uln2003an_pinB1, LOW);
  digitalWrite(uln2003an_pinB2, LOW);

  delay(1);
}

/***********************************
Method: _onePulsePositive
Descript: Move one pulse of positive.
Params: none
Return: none
************************************/
void _onePulsePositive()
{
  switch(_uln2003an_curStep) {
    case 0: {
      digitalWrite(uln2003an_pinA1, HIGH);
      digitalWrite(uln2003an_pinA2, LOW);
      digitalWrite(uln2003an_pinB1, LOW);
      digitalWrite(uln2003an_pinB2, LOW);
      delayMicroseconds(_uln2003an_time);
    }
    case 1:{
      digitalWrite(uln2003an_pinA1, HIGH);
      digitalWrite(uln2003an_pinA2, HIGH);
      digitalWrite(uln2003an_pinB1, LOW);
      digitalWrite(uln2003an_pinB2, LOW);
      delayMicroseconds(_uln2003an_time);
    }
    case 2:{
      digitalWrite(uln2003an_pinA1, LOW);
      digitalWrite(uln2003an_pinA2, HIGH);
      digitalWrite(uln2003an_pinB1, LOW);
      digitalWrite(uln2003an_pinB2, LOW);
      delayMicroseconds(_uln2003an_time);
    }
    case 3:{
      digitalWrite(uln2003an_pinA1, LOW);
      digitalWrite(uln2003an_pinA2, HIGH);
      digitalWrite(uln2003an_pinB1, HIGH);
      digitalWrite(uln2003an_pinB2, LOW);
      delayMicroseconds(_uln2003an_time);
    }
    case 4:{
      digitalWrite(uln2003an_pinA1, LOW);
      digitalWrite(uln2003an_pinA2, LOW);
      digitalWrite(uln2003an_pinB1, HIGH);
      digitalWrite(uln2003an_pinB2, LOW);
      delayMicroseconds(_uln2003an_time);
    }
    case 5:{
      digitalWrite(uln2003an_pinA1, LOW);
      digitalWrite(uln2003an_pinA2, LOW);
      digitalWrite(uln2003an_pinB1, HIGH);
      digitalWrite(uln2003an_pinB2, HIGH);
      delayMicroseconds(_uln2003an_time);
    }
    case 6:{
      digitalWrite(uln2003an_pinA1, LOW);
      digitalWrite(uln2003an_pinA2, LOW);
      digitalWrite(uln2003an_pinB1, LOW);
      digitalWrite(uln2003an_pinB2, HIGH);
      delayMicroseconds(_uln2003an_time);
    }
    case 7:{
      digitalWrite(uln2003an_pinA1, HIGH);
      digitalWrite(uln2003an_pinA2, LOW);
      digitalWrite(uln2003an_pinB1, LOW);
      digitalWrite(uln2003an_pinB2, HIGH);
      delayMicroseconds(_uln2003an_time);
    }
    default: {
      break;
    }
  }

  _uln2003an_curStep = (_uln2003an_curStep < 7) ? (_uln2003an_curStep+1) : 0;
}

/***********************************
Method: _onePulseNigative
Descript: Move one pulse of nigative.
Params: none
Return: none
************************************/
void _onePulseNigative()
{
  switch(_uln2003an_curStep) {
    case 0: {
      digitalWrite(uln2003an_pinA1, LOW);
      digitalWrite(uln2003an_pinA2, LOW);
      digitalWrite(uln2003an_pinB1, LOW);
      digitalWrite(uln2003an_pinB2, HIGH);
      delayMicroseconds(_uln2003an_time);
    }
    case 1:{
      digitalWrite(uln2003an_pinA1, LOW);
      digitalWrite(uln2003an_pinA2, LOW);
      digitalWrite(uln2003an_pinB1, HIGH);
      digitalWrite(uln2003an_pinB2, HIGH);
      delayMicroseconds(_uln2003an_time);
    }
    case 2:{
      digitalWrite(uln2003an_pinA1, LOW);
      digitalWrite(uln2003an_pinA2, LOW);
      digitalWrite(uln2003an_pinB1, HIGH);
      digitalWrite(uln2003an_pinB2, LOW);
      delayMicroseconds(_uln2003an_time);
    }
    case 3:{
      digitalWrite(uln2003an_pinA1, LOW);
      digitalWrite(uln2003an_pinA2, HIGH);
      digitalWrite(uln2003an_pinB1, HIGH);
      digitalWrite(uln2003an_pinB2, LOW);
      delayMicroseconds(_uln2003an_time);
    }
    case 4:{
      digitalWrite(uln2003an_pinA1, LOW);
      digitalWrite(uln2003an_pinA2, HIGH);
      digitalWrite(uln2003an_pinB1, LOW);
      digitalWrite(uln2003an_pinB2, LOW);
      delayMicroseconds(_uln2003an_time);
    }
    case 5:{
      digitalWrite(uln2003an_pinA1, HIGH);
      digitalWrite(uln2003an_pinA2, HIGH);
      digitalWrite(uln2003an_pinB1, LOW);
      digitalWrite(uln2003an_pinB2, LOW);
      delayMicroseconds(_uln2003an_time);
    }
    case 6:{
      digitalWrite(uln2003an_pinA1, HIGH);
      digitalWrite(uln2003an_pinA2, LOW);
      digitalWrite(uln2003an_pinB1, LOW);
      digitalWrite(uln2003an_pinB2, LOW);
      delayMicroseconds(_uln2003an_time);
    }
    case 7:{
      digitalWrite(uln2003an_pinA1, HIGH);
      digitalWrite(uln2003an_pinA2, LOW);
      digitalWrite(uln2003an_pinB1, LOW);
      digitalWrite(uln2003an_pinB2, HIGH);
      delayMicroseconds(_uln2003an_time);
    }
    default: {
      break;
    }
  }

  _uln2003an_curStep = (_uln2003an_curStep < 7) ? (_uln2003an_curStep+1) : 0;
}

/***********************************
Method: uln2003an_movePluse
Descript: Move a pluse.
Params: pluse  | Pluse number
        lr     | Left or right (true:left false:right)
Return: none
************************************/
void uln2003an_movePulse(int pulse)
{
  if(pulse > 0) {
    for (int i=0; i<pulse; i++) {
      _onePulsePositive();
    }
  } else {
    for (int i=0; i>pulse; i--) {
      _onePulseNigative();
    }
  }

  // pin init status setting
  digitalWrite(uln2003an_pinA1, LOW);
  digitalWrite(uln2003an_pinA2, LOW);
  digitalWrite(uln2003an_pinB1, LOW);
  digitalWrite(uln2003an_pinB2, LOW);
}

/***********************************
Method: setDelay
Descript: Move a round.
Params: time  | Delay time of pluse
Return: none
************************************/
void uln2003an_setDelay(long time)
{
  _uln2003an_time = time;
}