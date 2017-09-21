#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <3ds.h>
#include <sf2d.h>
#include <sfil.h>
#include <malloc.h>
#include <sys/stat.h>

#include "graphic.h"
#include "pp2d/pp2d/pp2d.h"

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

int main()
{
	aptInit();
	amInit();
	sdmcInit();
	romfsInit();
	srvInit();
	hidInit();

	pp2d_init();
	
	pp2d_set_screen_color(GFX_TOP, TRANSPARENT);
	pp2d_set_3D(0);
	
	Result res = 0;

	const char* imagetexpath;
	
	pp2d_load_texture_png(homeicontex, "romfs:/graphics/misc/whomeicon.png");
	pp2d_load_texture_png(logo0tex, "romfs:/graphics/logos/BotW.png");
	pp2d_load_texture_png(logo1tex, "romfs:/graphics/logos/SSFF.png");
	pp2d_load_texture_png(logo2tex, "romfs:/graphics/logos/SMG.png");
	pp2d_load_texture_png(logo3tex, "romfs:/graphics/logos/SSB4-WiiU.png");
	
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

		if(!imageloaded) {
			switch(imagenum) {
				case 0:
				default:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Legend of Zelda - Breath of the Wild/promotional art.png";
					break;
				case 1:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Legend of Zelda - Breath of the Wild/Screen12.png";
					break;
				case 2:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Legend of Zelda - Breath of the Wild/Screen15.png";
					break;
				case 3:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Legend of Zelda - Breath of the Wild/Screen16.png";
					break;
				case 4:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Legend of Zelda - Breath of the Wild/Screen17.png";
					break;
				case 5:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Legend of Zelda - Breath of the Wild/Screen18.png";
					break;
				case 6:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Legend of Zelda - Breath of the Wild/Screen19.png";
					break;
				case 7:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Legend of Zelda - Breath of the Wild/Screen20.png";
					break;
				case 8:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Legend of Zelda - Breath of the Wild/Screen21.png";
					break;
				case 9:
					logonum = 0;
					imagetexpath = "romfs:/graphics/Legend of Zelda - Breath of the Wild/Screen23.png";
					break;
				case 10:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Sophie.png";
					break;
				case 11:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Rabz using phone.png";
					break;
				case 12:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Renee and Callie.png";
					break;
				case 13:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Robz and Aisling.png";
					break;
				case 14:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Eunice and Clara.png";
					break;
				case 15:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Zoey, Clara, and Robz.png";
					break;
				case 16:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Robz waves.png";
					break;
				case 17:
					logonum = 1;
					imagetexpath = "romfs:/graphics/Style Savvy - Fashion Forward/Wish Abigail luck!.png";
					break;
				case 18:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/PromoGalaxy.png";
					break;
				case 19:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/Title_Screen.png";
					break;
				case 20:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/Bowser.png";
					break;
				case 21:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/Mario_looking_at_Luma.png";
					break;
				case 22:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/Luigi_looking_at_Luma.png";
					break;
				case 23:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/Rosalina.png";
					break;
				case 24:
					logonum = 2;
					imagetexpath = "romfs:/graphics/Super Mario Galaxy/Bowser_Jr.'s_Airship.png";
					break;
				case 25:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/mario1.png";
					break;
				case 26:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/mario2.png";
					break;
				case 27:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/mario3.png";
					break;
				case 28:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/mario4.png";
					break;
				case 29:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/mario5.png";
					break;
				case 30:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/mario6.png";
					break;
				case 31:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta1.png";
					break;
				case 32:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta2.png";
					break;
				case 33:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta3.png";
					break;
				case 34:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta4.png";
					break;
				case 35:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta5.png";
					break;
				case 36:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta6.png";
					break;
				case 37:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta7.png";
					break;
				case 38:
					logonum = 3;
					imagetexpath = "romfs:/graphics/Super Smash Bros for Wii U/bayonetta8.png";
					break;
			}
			//pp2d_begin_draw(GFX_TOP);
			//pp2d_end_draw();
			pp2d_free_texture(imagetex);
			pp2d_load_texture_png(imagetex, imagetexpath);
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
				case 3:
					logotex = logo3tex;
					break;
			}
			imageloaded = true;
		}
		
		for (int i = 0; i < 2; i++) {
			//if (CONFIG_3D_SLIDERSTATE != 0) {
			//	sf2d_start_frame(GFX_TOP, i);
			//} else {
			//	sf2d_start_frame(GFX_TOP, GFX_LEFT);
			//}
			pp2d_begin_draw(GFX_TOP);
			for (int w = 0; w < 400; w++) {
				pp2d_draw_texture_part(imagetex, w, 0, i+w*2, 0, 1, 240);
			}
			pp2d_end_draw();
			if (CONFIG_3D_SLIDERSTATE != 0) {
				//if (i==1) sf2d_swapbuffers();
			} else {
				//if (i!=1) sf2d_swapbuffers();
			}
		}
		pp2d_begin_draw(GFX_BOTTOM);
		pp2d_draw_texture(logotex, 0, 0);
		const int home_width = 144+16;
		const int home_x = (320-home_width)/2;
		pp2d_draw_texture(homeicontex, home_x, 221); // Draw HOME icon
		pp2d_draw_text(home_x+20, 222, 0.50, 0.50, WHITE, ": Return to HOME Menu");
		pp2d_end_draw();
		
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
			if (imagenum < 0) imagenum = 38;
		} else if (hDown & KEY_RIGHT) {
			imageloaded = false;
			imagenum++;
			if (imagenum > 38) imagenum = 0;
		}
		if (hDown & KEY_UP) {
			imageloaded = false;
			if (logonum == 0) imagenum = 25;
			if (logonum == 1) imagenum = 0;
			if (logonum == 2) imagenum = 10;
			if (logonum == 3) imagenum = 18;
		} else if (hDown & KEY_DOWN) {
			imageloaded = false;
			if (logonum == 0) imagenum = 10;
			if (logonum == 1) imagenum = 18;
			if (logonum == 2) imagenum = 25;
			if (logonum == 3) imagenum = 0;
		}
	}

	
	pp2d_exit();

	hidExit();
	srvExit();
	romfsExit();
	sdmcExit();
	aptExit();

    return 0;
}