#include <vector>

class LEDGrid {
	public:
		LEDGrid(int numChannels);
		void set(int channel, int red, int green, int blue);
		void clear();
		void update();
	private:
		int numChannels;
}
