#include <simplemax7219.h>

simplemax7219::simplemax7219(byte datain, byte clock, byte load)
{
  max7219clock = clock;
  max7219load = load;
  max7219datain = datain;
}

//=============================================================================
void simplemax7219::writeMax7219Byte(byte data) {
  for (byte i = 7; i < 9; i--) {
    byte mask = 1 << i;
    byte dat = data & mask;

    digitalWrite(max7219clock, LOW);
    if (dat > 0) {
      digitalWrite(max7219datain, HIGH);
    } else {
      digitalWrite(max7219datain, LOW);
    }
    digitalWrite(max7219clock, HIGH);
  }
}

//=============================================================================
void simplemax7219::regSetMax7219(byte reg, byte value) {
  if ( (reg >= 1) && (reg <= 8) ) {
    shadow[reg - 1] = value;
  }

  digitalWrite(max7219load, LOW);
  writeMax7219Byte(reg);
  writeMax7219Byte(value);
  digitalWrite(max7219load, HIGH);
}

//=============================================================================
void simplemax7219::begin(void)
{
  pinMode(max7219clock, OUTPUT);
  pinMode(max7219load, OUTPUT);
  pinMode(max7219datain, OUTPUT);

  regSetMax7219(0x0b, 0x07); // Scan Limit
  regSetMax7219(0x09, 0x00); // Decode Mode
  regSetMax7219(0x0c, 0x01); // Shut Down Mode (On)
  regSetMax7219(0x0f, 0x00); // Display Test (Off)
  brightness(0); // Brightness (0 - 15)
  clear();
}

//=============================================================================
void simplemax7219::clear() {
  for (int i = 1; i < 9; i++) {
    regSetMax7219(i, 0);
  }
}

//=============================================================================
void simplemax7219::brightness(byte br) {
  regSetMax7219(0x0a, br);
}

//=============================================================================
void simplemax7219::set(byte x, byte y, bool on) {
  // mapping due to wiring
  if (y==0) {
      y=7;
  } else {
      y=y-1;
  }  
  
  if (on) {
    regSetMax7219(x + 1, shadow[x] | (1 << y));
  } else {
    regSetMax7219(x + 1, shadow[x] & (~(1 << y)));
  }
}

boolean simplemax7219::get(byte x, byte y) {
  // mapping due to wiring
  if (y==0) {
      y=7;
  } else {
      y=y-1;
  }  
  
  return shadow[x] & (1 << y);
}

//=============================================================================
byte bitflipdings(byte b) {
  if (b & 1) {
    return (b >> 1)+0b10000000;
  } else {
    return (b >> 1);
  }
}

//=============================================================================
void simplemax7219::setpattern(byte b1, byte b2, byte b3, byte b4, byte b5, byte b6, byte b7, byte b8) {
  regSetMax7219(1, bitflipdings(b1));
  regSetMax7219(2, bitflipdings(b2));
  regSetMax7219(3, bitflipdings(b3));
  regSetMax7219(4, bitflipdings(b4));
  regSetMax7219(5, bitflipdings(b5));
  regSetMax7219(6, bitflipdings(b6));
  regSetMax7219(7, bitflipdings(b7));
  regSetMax7219(8, bitflipdings(b8));
}







