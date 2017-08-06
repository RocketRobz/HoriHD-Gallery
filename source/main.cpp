#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <3ds.h>
#include <sf2d.h>
#include <sfil.h>
#include <malloc.h>
#include <sys/stat.h>

#include "citrostuff.h"

#define CONFIG_3D_SLIDERSTATE (*(float *)0x1FF81080)

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

sf2d_texture *rectangletex;

// New draw rectangle function for use alongside citro.
void drawRectangle(int x, int y, int scaleX, int scaleY, u32 color)
{
	sf2d_draw_texture_scale_blend(rectangletex, x, y, scaleX, scaleY, color);
}

int main()
{
	aptInit();
	amInit();
	sdmcInit();
	romfsInit();
	srvInit();
	hidInit();

	sf2d_init();
    sf2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0x00));
	sf2d_set_3D(1);
	
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);

	printf("System font example\n");
	Result res = fontEnsureMapped();

	if (R_FAILED(res))
		printf("fontEnsureMapped: %08lX\n", res);

	sceneInit();

	const char* imagetexpath;
	
	rectangletex = sfil_load_PNG_file("romfs:/graphics/misc/rectangle.png", SF2D_PLACE_RAM); // Rectangle
	sf2d_texture *homeicontex = sfil_load_PNG_file("romfs:/graphics/misc/whomeicon.png", SF2D_PLACE_RAM);
	sf2d_texture *imagetex = NULL;
	sf2d_texture *logotex = NULL;
	sf2d_texture *logo0tex = sfil_load_PNG_file("romfs:/graphics/logos/SSFF.png", SF2D_PLACE_RAM);
	sf2d_texture *logo1tex = sfil_load_PNG_file("romfs:/graphics/logos/SMG.png", SF2D_PLACE_RAM);
	sf2d_texture *logo2tex = sfil_load_PNG_file("romfs:/graphics/logos/SSB4-WiiU.png", SF2D_PLACE_RAM);
	
	int fadealpha = 255;
	bool fadein = true;
	
	int imagenum = 0;
	int logonum = 0;
	int imageloaded = false;
	
	// Loop as long as the status is not exit
	while(aptMainLoop()) {
		// Scan hid shared memory for input events
		hidScanInput();
		
		const u32 hDown = hidKeysDown();
		const u32 hHeld = hidKeysHeld();
		
		textVtxArrayPos = 0; // Clear the text vertex array

		if(!imageloaded) {
			switch(imagenum) {
				case 0:
				default:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Sophie.png";
					break;
				case 1:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Rabz using phone.png";
					break;
				case 2:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Renee and Callie.png";
					break;
				case 3:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Robz and Aisling.png";
					break;
				case 4:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Eunice and Clara.png";
					break;
				case 5:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Zoey, Clara, and Robz.png";
					break;
				case 6:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Robz waves.png";
					break;
				case 7:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Wish Abigail luck!.png";
					break;
				case 8:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/PromoGalaxy.png";
					break;
				case 9:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/Title_Screen.png";
					break;
				case 10:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/Bowser.png";
					break;
				case 11:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/Mario_looking_at_Luma.png";
					break;
				case 12:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/Luigi_looking_at_Luma.png";
					break;
				case 13:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/Rosalina.png";
					break;
				case 14:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/Bowser_Jr.'s_Airship.png";
					break;
				case 15:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/mario1.png";
					break;
				case 16:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/mario2.png";
					break;
				case 17:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/mario3.png";
					break;
				case 18:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/mario4.png";
					break;
				case 19:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/mario5.png";
					break;
				case 20:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/mario6.png";
					break;
				case 21:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta1.png";
					break;
				case 22:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta2.png";
					break;
				case 23:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta3.png";
					break;
				case 24:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta4.png";
					break;
				case 25:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta5.png";
					break;
				case 26:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta6.png";
					break;
				case 27:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta7.png";
					break;
				case 28:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta8.png";
					break;
			}
			sf2d_start_frame(GFX_TOP, GFX_LEFT);
			sf2d_end_frame();
			sf2d_start_frame(GFX_TOP, GFX_RIGHT);
			sf2d_end_frame();
			sf2d_swapbuffers();
			sf2d_free_texture(imagetex);
			imagetex = sfil_load_PNG_file(imagetexpath, SF2D_PLACE_RAM);
			switch(logonum) {
				case 0:
				default:
					logotex = logo0tex;
					break;
				case 1:
					logotex = logo1tex;
					break;
				case 2:
					logotex = logo2tex;
					break;
			}
			imageloaded = true;
		}
		
		for (int i = 0; i < 2; i++) {
			if (CONFIG_3D_SLIDERSTATE != 0) {
				sf2d_start_frame(GFX_TOP, i);
			} else {
				sf2d_start_frame(GFX_TOP, GFX_LEFT);
			}
			for (int w = 0; w < 400; w++) {
				sf2d_draw_texture_part(imagetex, w, 0, i+w*2, 0, 1, 240);
			}
			drawRectangle(0, 0, 400, 240, RGBA8(0, 0, 0, fadealpha)); // Fade in/out effect
			sf2d_end_frame();
			if (CONFIG_3D_SLIDERSTATE != 0) {
				if (i==1) sf2d_swapbuffers();
			} else {
				if (i!=1) sf2d_swapbuffers();
			}
		}
		sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		sf2d_draw_texture(logotex, 320/2 - logotex->width/2, 240/2 - logotex->height/2);
		const int home_width = 144+16;
		const int home_x = (320-home_width)/2;
		sf2d_draw_texture(homeicontex, home_x, 221); // Draw HOME icon
		setTextColor(RGBA8(255, 255, 255, 255));
		renderText(home_x+20, 222, 0.50, 0.50, false, ": Return to HOME Menu");
		drawRectangle(0, 0, 320, 240, RGBA8(0, 0, 0, fadealpha)); // Fade in/out effect
		sf2d_end_frame();
		sf2d_swapbuffers();
		
		if (fadein == true) {
			fadealpha -= 31;
			if (fadealpha < 0) {
				fadealpha = 0;
				fadein = false;
			}
		}
		
		if (hDown & KEY_LEFT) {
			imageloaded = false;
			imagenum--;
			if (imagenum < 0) imagenum = 28;
		} else if (hDown & KEY_RIGHT) {
			imageloaded = false;
			imagenum++;
			if (imagenum > 28) imagenum = 0;
		}
		if (hDown & KEY_UP) {
			imageloaded = false;
			if (logonum == 0) imagenum = 15;
			if (logonum == 1) imagenum = 0;
			if (logonum == 2) imagenum = 8;
		} else if (hDown & KEY_DOWN) {
			imageloaded = false;
			if (logonum == 0) imagenum = 8;
			if (logonum == 1) imagenum = 15;
			if (logonum == 2) imagenum = 0;
		}
	}

	
	sceneExit();
	C3D_Fini();

	hidExit();
	srvExit();
	romfsExit();
	sdmcExit();
	aptExit();
	sf2d_free_texture(imagetex);
	sf2d_free_texture(logo0tex);
	sf2d_free_texture(logo1tex);
	sf2d_free_texture(logo2tex);
    sf2d_fini();

    return 0;
}