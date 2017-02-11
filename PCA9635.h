#include <Arduino.h>

const int MODE1 = 0x00;
const int MODE2 = 0x01;
const int LEDOUT0 = 0x14;
const int LEDOUT1 = 0x15;
const int LEDOUT2 = 0x16;
const int LEDOUT3 = 0x17;

class PCA9635
{
public:
	PCA9635(int address);
	void begin();
	void analogWrite(int pin, int value);
	void digitalWrite(int pin, int value);
	
	private:
	  int _address;
	// interface to I2C
	void setRegister(int reg, int value);
	int getRegister(int reg);
};

