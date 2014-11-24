#ifndef LEDGrid_h
#define LEDGrid_h

#include "Arduino.h"
#include "Tlc5940.h"

class LEDGrid {
	public:
		LEDGrid(int numChannels);
		void set(int channel, int red, int green, int blue);
		void clear();
		void update();
	private:
		int numChannels;
}

#endif
