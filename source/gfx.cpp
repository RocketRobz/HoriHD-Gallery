#include "common.hpp"

#include <unistd.h>

static C2D_SpriteSheet sprites;
static C2D_SpriteSheet gameShot;
static bool doGameShotFree = false;

int imagenum = 0;

Result GFX::loadSheets() {
	sprites			= C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");
	loadGameShot();
	return 0;
}

Result GFX::loadGameShot() {
	if (doGameShotFree) {
		C2D_SpriteSheetFree(gameShot);
	}
	switch (imagenum) {
		case 0:
		default:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/BotW_PromoArt.t3x");
			break;
		case 1:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/BotW_Screen12.t3x");
			break;
		case 2:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/BotW_Screen15.t3x");
			break;
		case 3:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/BotW_Screen16.t3x");
			break;
		case 4:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/BotW_Screen17.t3x");
			break;
		case 5:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/BotW_Screen18.t3x");
			break;
		case 6:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/BotW_Screen19.t3x");
			break;
		case 7:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/BotW_Screen20.t3x");
			break;
		case 8:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/BotW_Screen21.t3x");
			break;
		case 9:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/BotW_Screen23.t3x");
			break;
		case 10:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSFF_Sophie.t3x");
			break;
		case 11:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSFF_RabzUsingPhone.t3x");
			break;
		case 12:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSFF_ReneeAndCallie.t3x");
			break;
		case 13:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSFF_RobzAndAisling.t3x");
			break;
		case 14:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSFF_EuniceAndClara.t3x");
			break;
		case 15:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSFF_ZoeyClaraRobz.t3x");
			break;
		case 16:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSFF_RobzWaves.t3x");
			break;
		case 17:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSFF_WishAbigailLuck.t3x");
			break;
		case 18:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMG_PromoGalaxy.t3x");
			break;
		case 19:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMG_Bowser.t3x");
			break;
		case 20:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMG_MarioLuma.t3x");
			break;
		case 21:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMG_LuigiLuma.t3x");
			break;
		case 22:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMG_Rosalina.t3x");
			break;
		case 23:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMG_DinoPiranha.t3x");
			break;
		case 24:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMO_NDCFestival.t3x");
			break;
		case 25:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMO_NewDonkCity.t3x");
			break;
		case 26:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMO_Odyssey.t3x");
			break;
		case 27:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMO_Cappy.t3x");
			break;
		case 28:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMO_CappyThrow.t3x");
			break;
		case 29:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMO_TRex.t3x");
			break;
		case 30:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMO_ForestBoombox.t3x");
			break;
		case 31:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMO_CrazyCap.t3x");
			break;
		case 32:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMO_BowserPeach.t3x");
			break;
		case 33:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SMO_Peach.t3x");
			break;
		case 34:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_mario1.t3x");
			break;
		case 35:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_mario1.t3x");
			break;
		case 36:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_mario2.t3x");
			break;
		case 37:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_mario3.t3x");
			break;
		case 38:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_mario4.t3x");
			break;
		case 39:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_mario5.t3x");
			break;
		case 40:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_mario6.t3x");
			break;
		case 41:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_bayonetta1.t3x");
			break;
		case 42:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_bayonetta2.t3x");
			break;
		case 43:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_bayonetta3.t3x");
			break;
		case 44:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_bayonetta4.t3x");
			break;
		case 45:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_bayonetta5.t3x");
			break;
		case 46:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_bayonetta6.t3x");
			break;
		case 47:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_bayonetta7.t3x");
			break;
		case 48:
			gameShot = C2D_SpriteSheetLoad("romfs:/gfx/SSB4-WiiU_bayonetta8.t3x");
			break;
	}
	doGameShotFree = true;
	return 0;
}

Result GFX::unloadSheets() {
	C2D_SpriteSheetFree(sprites);
	if (doGameShotFree) {
		C2D_SpriteSheetFree(gameShot);
	}
	return 0;
}

void GFX::DrawGameShot(void) {
	C2D_DrawImageAt(C2D_SpriteSheetGetImage(gameShot, 0), 0, 0, 0.5f, NULL, 0.5, 1);
}

void GFX::DrawSprite(int img, int x, int y, float ScaleX, float ScaleY) {
	C2D_DrawImageAt(C2D_SpriteSheetGetImage(sprites, img), x, y, 0.5f, NULL, ScaleX, ScaleY);
}

