#ifndef LEDGrid_h
#define LEDGrid_h

#include "Arduino.h"
#include "Tlc5940.h"
#include <vector>

enum Color {RED, GREEN, BLUE, WHITE};

struct Channel {
	int red;
	int green;
	int blue;

	Channel() {
		red = 0;
		green = 0;
		blue = 0;
	}
};

class LEDGrid {
	public:
		LEDGrid(int numChannels);
		
		void set(int channel, int red, int green, int blue);
		void setColor(int channel, Color input, int brightness);
		void clearChannel(int channel);
		void clear();
		void update();
		void runAnimation(int animation);

		int numChannels();
	private:
		vector<Channel*> channels;
};

#endif
