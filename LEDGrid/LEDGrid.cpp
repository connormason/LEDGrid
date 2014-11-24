#include "LEDGrid.h"

LEDGrid::LEDGrid(int numChannels) {
	for (int i = 0; i < numChannels; i++) {
		Channel *newChannel = new Channel();
		channels.push_back(newChannel);
	}
}
