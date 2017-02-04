#ifndef simplemax7219_H
#define simplemax7219_H

#include <Arduino.h>
/*
    SimpleMax7219 - another max7219 matrix driver thingy for one matrix only.
    
    Design goal: do not use spi, so any ports will go. this is slow and really ressource independant.
    
    lembke. 2017-01-04
*/

class simplemax7219
{
  public:
    simplemax7219(byte datain, byte clock, byte load);

    void begin(void);
    void clear(void);
    void brightness(byte br);
    // set/unset bit on [0..7][0..7]
    void set(byte x, byte y, bool on); 
    void setpattern(byte b1, byte b2, byte b3, byte b4, byte b5, byte b6, byte b7, byte b8);
  private:
    byte max7219clock = 0;
    byte max7219load = 0;
    byte max7219datain = 0;
    byte shadow[8];

    void writeMax7219Byte(byte data);
    void regSetMax7219(byte reg, byte value);
};

#endif
