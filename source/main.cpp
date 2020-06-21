#include <stdio.h>
#include <string.h>
#include <3ds.h>

#include "common.hpp"
#include "rocketRobz.hpp"
#include "imageDisplay.hpp"

bool isInit = true;
int delay = 0;
bool exiting = false;

u8 consoleModel = 0;
u8 sysRegion = CFG_REGION_USA;
u64 appID = 0;

u32 hDown = 0;
u32 hHeld = 0;
touchPosition touch;

void screenoff()
{
    gspLcdInit();\
    GSPLCD_PowerOffBacklight(GSPLCD_SCREEN_BOTH);\
    gspLcdExit();
}

void screenon()
{
    gspLcdInit();\
    GSPLCD_PowerOnBacklight(GSPLCD_SCREEN_BOTH);\
    gspLcdExit();
}

int main()
{
	screenoff();
	amInit();
	romfsInit();

	Result res = cfguInit();
	if (R_SUCCEEDED(res)) {
		CFGU_SecureInfoGetRegion(&sysRegion);
		CFGU_GetSystemModel(&consoleModel);
		cfguExit();
	}

	aptInit();
	APT_GetProgramID(&appID);
	aptExit();

	gfxInitDefault();
	gfxSetWide(consoleModel != 3);	// Enable 800x240 mode for non-O2DS consoles. Improves clarity in graphics.

	Gui::init();
	GFX::loadSheets();
	fadein = true;
	fadealpha = 255;
	
	screenon();

	Gui::setScreen(std::make_unique<RocketRobz>(), false); // Set screen to RocketRobz's screen.

	// Loop as long as the status is not exit
	while(aptMainLoop()) {
		// Scan hid shared memory for input events
		hidScanInput();

		hDown = hidKeysDown();
		hHeld = hidKeysHeld();

		hidTouchRead(&touch);

		// Here we draw the actual screen.
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(Top, TRANSPARENT);
		C2D_TargetClear(Bottom, TRANSPARENT);
		Gui::clearTextBufs();
		Gui::DrawScreen();
		C3D_FrameEnd(0);
		if (exiting) {
			if (!fadeout)	break;
		}

		if (isInit) {
			delay++;
			if (delay > 60*(gfxIsWide() ? 7 : 4)) {
				Gui::setScreen(std::make_unique<ImageDisplay>(), true); // Set after delay to the ImageDisplay screen.
				isInit = false;
			}
		}

		Gui::ScreenLogic(hDown, hHeld, touch, false); // Call the logic of the current screen here.

		Gui::fadeEffects(6, 6);
	}

	
	Gui::exit();
	GFX::unloadSheets();

	gfxExit();
	romfsExit();
	amExit();

    return 0;
}