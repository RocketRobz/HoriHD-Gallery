#ifndef _IMAGEDISPLAY_HPP
#define _IMAGEDISPLAY_HPP

#include "common.hpp"

class ImageDisplay : public Screen {
public:
	void Draw(void) const override;
	void Logic(u32 hDown, u32 hHeld, touchPosition touch) override;
private:
	const char* selectView400Text = "SELECT: View in 400px";
	const char* selectView800Text = "SELECT: View in 800px";
	const char* returnToHomeText = ": Return to HOME Menu";
	const char* startExitText = "START: Exit";
};

#endif