#ifndef _IMAGEDISPLAY_HPP
#define _IMAGEDISPLAY_HPP

#include "common.hpp"

class ImageDisplay : public Screen {
public:
	void Draw(void) const override;
	void Logic(u32 hDown, u32 hHeld, touchPosition touch) override;
private:
	const char* returnToHomeText = ": Return to HOME Menu";
};

#endif