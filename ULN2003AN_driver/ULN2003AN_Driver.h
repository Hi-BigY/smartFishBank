#ifndef _ULN2003AN_DRIVER_H_
#define _ULN2003AN_DRIVER_H_

void uln2003an_init(int pinA1, int pinA2, int pinB1, int pinB2);
void uln2003an_movePulse(int pulse);
void uln2003an_setDelay(long time);

#endif