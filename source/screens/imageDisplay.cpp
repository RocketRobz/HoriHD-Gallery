#include "imageDisplay.hpp"
#include "exiting.hpp"

extern bool exiting;

extern u8 sysRegion;

void ImageDisplay::Draw(void) const {
	Gui::ScreenDraw(Top);

	GFX::DrawGameShot();

	if (fadealpha > 0) Gui::Draw_Rect(0, 0, 400, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect

	Gui::ScreenDraw(Bottom);

	if (imagenum >= 0 && imagenum <= 9) {
		GFX::DrawSprite(sprites_logo_BotW_idx, 0, 0);
	} else 	if (imagenum >= 10 && imagenum <= 17) {
		if (sysRegion == CFG_REGION_USA) {
			GFX::DrawSprite(sprites_logo_SSFF_idx, 0, 0);
		} else if (sysRegion == CFG_REGION_EUR) {
			GFX::DrawSprite(sprites_logo_NSB2_idx, 0, 0);
		} else {
			GFX::DrawSprite(sprites_logo_GM3_idx, 0, 0);
		}
	} else 	if (imagenum >= 18 && imagenum <= 23) {
		GFX::DrawSprite(sprites_logo_SMG_idx, 0, 0);
	} else 	if (imagenum >= 24 && imagenum <= 33) {
		GFX::DrawSprite(sprites_logo_SMO_idx, 0, 0);
	} else 	if (imagenum >= 34 && imagenum <= 48) {
		GFX::DrawSprite(sprites_logo_SSB4_WiiU_idx, 0, 0);
	}

	//pp2d_draw_texture(logotex, 0, 0);
	const int home_width = 144+16;
	const int home_x = (320-home_width)/2;
	GFX::DrawSprite(sprites_whomeicon_idx, home_x, 219);
	Gui::DrawString(home_x+16, 219, 0.50, WHITE, this->returnToHomeText); // Draw HOME icon
	if (fadealpha > 0) Gui::Draw_Rect(0, 0, 320, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect
	
}

void ImageDisplay::Logic(u32 hDown, u32 hHeld, touchPosition touch) {
	if (hDown & KEY_LEFT) {
		imagenum--;
		if (imagenum < 0) imagenum = 38;
		GFX::loadGameShot();
	} else if (hDown & KEY_RIGHT) {
		imagenum++;
		if (imagenum > 38) imagenum = 0;
		GFX::loadGameShot();
	}
	if (hDown & KEY_UP) {
		      if (imagenum >= 0 && imagenum <= 9) imagenum = 34;
		else if (imagenum >= 10 && imagenum <= 17) imagenum = 0;
		else if (imagenum >= 18 && imagenum <= 23) imagenum = 10;
		else if (imagenum >= 24 && imagenum <= 33) imagenum = 18;
		else if (imagenum >= 34 && imagenum <= 48) imagenum = 24;
		GFX::loadGameShot();
	} else if (hDown & KEY_DOWN) {
		      if (imagenum >= 0 && imagenum <= 9) imagenum = 10;
		else if (imagenum >= 10 && imagenum <= 17) imagenum = 18;
		else if (imagenum >= 18 && imagenum <= 23) imagenum = 24;
		else if (imagenum >= 24 && imagenum <= 33) imagenum = 34;
		else if (imagenum >= 34 && imagenum <= 48) imagenum = 0;
		GFX::loadGameShot();
	}

	if (hDown & KEY_START) {
		exiting = true;
		fadecolor = 0;
		Gui::setScreen(std::make_unique<Exiting>(), true);
	}
}