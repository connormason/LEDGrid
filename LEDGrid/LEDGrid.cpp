#include "Arduino.h"
#include "LEDGrid.h"

void LEDGrid::LEDGrid(int numChannels) {
	Tlc.init();
	for (int i = 0; i < numChannels) {
		Channel *newChannel = new Channel();
		channels.push_back(newChannel);
	}
}

void LEDGrid::set(int channel, int red, int green, int blue) {
	if ((channel >= 0) && (channel < channels.size())) {
		if (red != channels[channel].red) {
			Tlc.set(channel * 3, red);
		}

		if (green != channels[channel].green) {
			Tlc.set((channel * 3) + 1, green);
		}
		
		if (blue != channels[channel].blue) {
			Tlc.set((channel * 3) + 2, blue);

		}
	}
}

void LEDGrid::setColor(int channel, Color input, int brightness) {
	if ((channel >= 0) && (channel < channels.size())) {
		switch(input) {
			case RED:
				Tlc.set(channel * 3, brightness);
				Tlc.set((channel * 3) + 1, 0);
				Tlc.set((channel * 3) + 2, 0);
				break;
			case GREEN:
				Tlc.set(channel * 3, 0);
				Tlc.set((channel * 3) + 1, brightness);
				Tlc.set((channel * 3) + 2, 0);
			case BLUE:
				Tlc.set(channel * 3, 0);
				Tlc.set((channel * 3) + 1, 0);
				Tlc.set((channel * 3) + 2, brightness);
			case WHITE:
				Tlc.set(channel * 3, brightness);
				Tlc.set((channel * 3) + 1, brightness);
				Tlc.set((channel * 3) + 2, brightness);
			default:
				Tlc.set(channel * 3, 0);
				Tlc.set((channel * 3) + 1, 0);
				Tlc.set((channel * 3) + 2, 0);
		}
	}
}

void LEDGrid::clearChannel(int channel) {
	if ((channel >= 0) && (channel < channels.size())) {
		Tlc.set(channel * 3, 0);
		Tlc.set((channel * 3) + 1, 0);
		Tlc.set((channel * 3) + 2, 0);
	}
}

void LEDGrid::clear() {
	Tlc.clear();
}

void LEDGrid::update() {
	Tlc.update();
}

int LEDGrid::numChannels() {
	return(channels.size());
}
