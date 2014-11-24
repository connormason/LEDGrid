#include "LEDGrid.h"

LEDGrid::LEDGrid(int numChannels) {
	Tlc.init();
	channels = numChannels;
}

LEDGrid::set(int channel, int red, int green, int blue) {
	if ((channel > 0) && (channel < (numChannels - 1))) {
		Tlc.set(channel * 3, red);
		Tlc.set((channel * 3) + 1, green);
		Tlc.set((channel * 3) + 2, blue);
	}
}

LEDGrid::clear() {
	Tlc.clear();
}

LEDGrid::update() {
	Tlc.update();
}
