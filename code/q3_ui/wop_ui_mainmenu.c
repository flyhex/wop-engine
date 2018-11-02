/*****************************************************************************
 *        This file is part of the World of Padman (WoP) source code.        *
 *                                                                           *
 *      WoP is based on the ioquake3 fork of the Quake III Arena source.     *
 *                 Copyright (C) 1999-2005 Id Software, Inc.                 *
 *                                                                           *
 *                         Notable contributions by:                         *
 *                                                                           *
 *          #@ (Raute), cyrri, Herby, PaulR, brain, Thilo, smiley            *
 *                                                                           *
 *           https://github.com/PadWorld-Entertainment/wop-engine            *
 *****************************************************************************/

/*
=======================================================================

MAIN MENU

=======================================================================
*/

#include "wop_ui_local.h"

#define ART_CREATE0  "menu/main/ButtonSingleplayer0"
#define ART_CREATE1  "menu/main/ButtonSingleplayer1"
#define ART_MULTI0   "menu/main/ButtonMultiplayer0"
#define ART_MULTI1   "menu/main/ButtonMultiplayer1"
#define ART_SETUP0   "menu/main/ButtonSetup0"
#define ART_SETUP1   "menu/main/ButtonSetup1"
#define ART_DEMOS0   "menu/main/ButtonDemos0"
#define ART_DEMOS1   "menu/main/ButtonDemos1"
#define ART_MODS0    "menu/main/ButtonMods0"
#define ART_MODS1    "menu/main/ButtonMods1"
#define ART_EXIT0    "menu/main/ButtonExit0"
#define ART_EXIT1    "menu/main/ButtonExit1"
#define ART_CREDITS0 "menu/main/ButtonCredits0"
#define ART_CREDITS1 "menu/main/ButtonCredits1"

#define ID_CREATE  10
#define ID_MULTI   11
#define ID_SETUP   12
#define ID_DEMOS   13
#define ID_MODS    14
#define ID_EXIT    15
#define ID_CREDITS 16
#define ID_SECRET  17

#define MAX_MSGLENGHT    256

typedef struct{
	menuframework_s menu;
	menubitmap_s    singleplayer;
	menubitmap_s    multiplayer;
	menubitmap_s    setup;
	menubitmap_s    demos;
	menubitmap_s    mods;
	menubitmap_s    credits;
	menubitmap_s    exit;
	menubitmap_s    secret;
	char            msg[MAX_MSGLENGHT];
	int             msgtime;
} mainmenu_t;

static mainmenu_t s_main;

typedef struct{
	menuframework_s menu;
	char            errorMessage[4096];
}                 errorMessage_t;

static errorMessage_t s_errorMessage;

/*
=================
Main_MenuEvent
=================
*/
void Main_MenuEvent(void *ptr, int event){
	if(event != QM_ACTIVATED){
		return;
	}

	switch(((menucommon_s *)ptr)->id){
		case ID_CREATE:
			UI_StartServerMenu( qtrue );
			break;

		case ID_MULTI:
			UI_ArenaServersMenu();
			break;

		case ID_SETUP:
			UI_SetupMenu();
			break;

		case ID_DEMOS:
			UI_DemosMenu();
			break;
		// @todo: the "Mods" menu is vacant as there are still near zero WoP mods
		//  and if, they'd be running on servers anyway.
		//  this menu is meant for total conversions, including UI ~smiley
		case ID_MODS:
			UI_ModsMenu();
			break;
		case ID_CREDITS:
			UI_BigCredits();
			break;

		case ID_SECRET:
			UI_SecretMenu();
			break;

		case ID_EXIT:
			UI_ExitMenu();
			break;
	}
}


/*
===============
MainMenu_Cache
===============
*/
void MainMenu_Cache(void){
	trap_R_RegisterShaderNoMip(ART_MULTI0);
	trap_R_RegisterShaderNoMip(ART_MULTI1);
	trap_R_RegisterShaderNoMip(ART_CREATE0);
	trap_R_RegisterShaderNoMip(ART_CREATE1);
	trap_R_RegisterShaderNoMip(ART_SETUP0);
	trap_R_RegisterShaderNoMip(ART_SETUP1);
	trap_R_RegisterShaderNoMip(ART_DEMOS0);
	trap_R_RegisterShaderNoMip(ART_DEMOS1);
	trap_R_RegisterShaderNoMip(ART_MODS0);
	trap_R_RegisterShaderNoMip(ART_MODS1);
	trap_R_RegisterShaderNoMip(ART_EXIT0);
	trap_R_RegisterShaderNoMip(ART_EXIT1);
	trap_R_RegisterShaderNoMip(ART_CREDITS0);
	trap_R_RegisterShaderNoMip(ART_CREDITS1);
}

sfxHandle_t ErrorMessage_Key(int key){
	trap_Cvar_Set("com_errorMessage", "");
	UI_MainMenu();
	return (menu_null_sound);
}

/*
===============
Main_MenuDraw
TTimo: this function is common to the main menu and errorMessage menu
===============
*/
int CINhandle = -1;
static void Main_MenuDraw(void){
	int    msglen;
	vec4_t tblack = {0.0f, 0.0f, 0.0f, 0.66f};
	float  size;

	msglen = strlen(s_main.msg);

	// advanced2d-test ;)
	//	DrawTurnableString(320,240,"blablubli",colorRed,50,uis.realtime/100.0f,TURNORIGIN_MIDDLECENTER);
	//	DrawLine(320.0f*(1.0f+sin(uis.realtime*0.001f+30)),240.0f*(1.0f+sin(uis.realtime*0.001f+87)),320.0f*(1.0f+sin(uis.realtime*0.001f+4567)),240.0f*(1.0f+sin(uis.realtime*0.001f+649)),20,colorGreen);

	if(s_main.msgtime != 0 && uis.realtime - s_main.msgtime <= 5000){
		if(uis.realtime - s_main.msgtime > 4750){
			size = 16.0f * ((float)(5000 - (uis.realtime - s_main.msgtime)) / 250.0f);
		}
		else if(uis.realtime - s_main.msgtime > 250){
			size = 16.0f;
		}
		else{
			size = 16.0f * ((float)((uis.realtime - s_main.msgtime)) / 250.0f);
		}

		UI_FillRect(320.0f - (size * (msglen + 4.0f) * 0.25f), 240.0f - size, (msglen + 4.0f) * size * 0.5f, 2.0f * size, tblack);
		UI_DrawRectWithThickness(320.0f - (size * (msglen + 4.0f) * 0.25f), 240.0f - size, (msglen + 4.0f) * size * 0.5f, 2.0f * size, colorBlack, 1);
		UI_DrawStringNS(320, 240 - size / 2, s_main.msg, UI_CENTER, size, colorWhite);
	}

	if(strlen(s_errorMessage.errorMessage)){
		UI_DrawString_AutoWrapped(320, 192, 600, 20, s_errorMessage.errorMessage, UI_CENTER | UI_SMALLFONT | UI_DROPSHADOW, menu_text_color, qtrue);
	}
	else{
		Menu_Draw(&s_main.menu);
	}

	if(CINhandle >= 0){
		trap_CIN_RunCinematic(CINhandle);
		trap_CIN_DrawCinematic(CINhandle);
	}
}

sfxHandle_t Main_MenuKey(int key){
	if(key == K_ESCAPE || key == K_MOUSE2){
		return 0;
	}

	return Menu_DefaultKey(&s_main.menu, key);
}

/*
===============
UI_MainMenu

The main menu only comes up when not in a game,
so make sure that the attract loop server is down
and that local cinematics are killed
===============
*/
void UI_MainMenu(void){
	trap_Cvar_Set("sv_killserver", "1");
//	trap_Cmd_ExecuteText(EXEC_APPEND, "wopSP_stopStory\n");

	// note: I just recognized that this isn't reset on server shutdown ...
	// but for some optimations in wopSP-code it is better to have this on a correct value
	trap_Cvar_Set("mapname","");

	if(UI_GetCvarInt("ui_mainmenuCinTest")){
		char buffer[32];
		trap_Cvar_VariableStringBuffer("ui_mainmenuCinTestFile", buffer, sizeof(buffer));
		if(!buffer[0]){
			strcpy(buffer, "idlogo.roq");
		}
		if(CINhandle >= 0){
			trap_CIN_StopCinematic(CINhandle);
		}
//		CINhandle = trap_CIN_PlayCinematic("idlogo.roq", 10, 10, 160, 120, /*int bits*/ CIN_loop);
		CINhandle = trap_CIN_PlayCinematic(buffer, 10, 10, 160, 120, /*int bits*/ CIN_loop);
		trap_S_StopBackgroundTrack();
	}

	memset(&s_main, 0, sizeof(mainmenu_t));
	memset(&s_errorMessage, 0, sizeof(errorMessage_t));

	// com_errorMessage would need that too
	MainMenu_Cache();

	trap_Cvar_VariableStringBuffer("com_errorMessage", s_errorMessage.errorMessage, sizeof(s_errorMessage.errorMessage));

	if(strlen(s_errorMessage.errorMessage)){
		s_errorMessage.menu.draw       = Main_MenuDraw;
		s_errorMessage.menu.key        = ErrorMessage_Key;
		s_errorMessage.menu.fullscreen = qtrue;
		s_errorMessage.menu.wrapAround = qtrue;

		trap_Key_SetCatcher(KEYCATCH_UI);
		uis.menusp = 0;
		UI_PushMenu(&s_errorMessage.menu);

		return;
	}

	s_main.menu.draw         = Main_MenuDraw;
	s_main.menu.key          = Main_MenuKey;
	s_main.menu.fullscreen   = qtrue;
	s_main.menu.wrapAround   = qtrue;
	s_main.menu.bgparts      = BGP_MAINBG | BGP_MAINFRAME;
	s_main.menu.noPushSelect = qtrue;

	s_main.singleplayer.generic.type     = MTYPE_BITMAP;
	s_main.singleplayer.generic.name     = ART_CREATE0;
	s_main.singleplayer.generic.flags    = QMF_LEFT_JUSTIFY | QMF_HIGHLIGHT_IF_FOCUS;
	s_main.singleplayer.generic.x        = 497;
	s_main.singleplayer.generic.y        = 140;
	s_main.singleplayer.generic.id       = ID_CREATE;
	s_main.singleplayer.generic.callback = Main_MenuEvent;
	s_main.singleplayer.width            = 120;
	s_main.singleplayer.height           = 40;
	s_main.singleplayer.focuspic         = ART_CREATE1;
	s_main.singleplayer.focuspicinstead  = qtrue;
	Menu_AddItem(&s_main.menu, &s_main.singleplayer);

	s_main.multiplayer.generic.type     = MTYPE_BITMAP;
	s_main.multiplayer.generic.name     = ART_MULTI0;
	s_main.multiplayer.generic.flags    = QMF_LEFT_JUSTIFY | QMF_HIGHLIGHT_IF_FOCUS;
	s_main.multiplayer.generic.x        = 508;
	s_main.multiplayer.generic.y        = 175;
	s_main.multiplayer.generic.id       = ID_MULTI;
	s_main.multiplayer.generic.callback = Main_MenuEvent;
	s_main.multiplayer.width            = 120;
	s_main.multiplayer.height           = 40;
	s_main.multiplayer.focuspic         = ART_MULTI1;
	s_main.multiplayer.focuspicinstead  = qtrue;
	Menu_AddItem(&s_main.menu, &s_main.multiplayer);

	s_main.setup.generic.type     = MTYPE_BITMAP;
	s_main.setup.generic.name     = ART_SETUP0;
	s_main.setup.generic.flags    = QMF_LEFT_JUSTIFY | QMF_HIGHLIGHT_IF_FOCUS;
	s_main.setup.generic.x        = 496;
	s_main.setup.generic.y        = 210;
	s_main.setup.generic.id       = ID_SETUP;
	s_main.setup.generic.callback = Main_MenuEvent;
	s_main.setup.width            = 120;
	s_main.setup.height           = 40;
	s_main.setup.focuspic         = ART_SETUP1;
	s_main.setup.focuspicinstead  = qtrue;
	Menu_AddItem(&s_main.menu, &s_main.setup);

	s_main.demos.generic.type     = MTYPE_BITMAP;
	s_main.demos.generic.name     = ART_DEMOS0;
	s_main.demos.generic.flags    = QMF_LEFT_JUSTIFY | QMF_HIGHLIGHT_IF_FOCUS;
	s_main.demos.generic.x        = 510;
	s_main.demos.generic.y        = 245;
	s_main.demos.generic.id       = ID_DEMOS;
	s_main.demos.generic.callback = Main_MenuEvent;
	s_main.demos.width            = 120;
	s_main.demos.height           = 40;
	s_main.demos.focuspic         = ART_DEMOS1;
	s_main.demos.focuspicinstead  = qtrue;
	Menu_AddItem(&s_main.menu, &s_main.demos);

	s_main.mods.generic.type     = MTYPE_BITMAP;
	s_main.mods.generic.name     = ART_MODS0;
	s_main.mods.generic.flags    = QMF_LEFT_JUSTIFY | QMF_HIGHLIGHT_IF_FOCUS;
	s_main.mods.generic.x        = 516;
	s_main.mods.generic.y        = 280;
	s_main.mods.generic.id       = ID_MODS;
	s_main.mods.generic.callback = Main_MenuEvent;
	s_main.mods.width            = 80;
	s_main.mods.height           = 40;
	s_main.mods.focuspic         = ART_MODS1;
	s_main.mods.focuspicinstead  = qtrue;
	Menu_AddItem(&s_main.menu, &s_main.mods);

	s_main.exit.generic.type     = MTYPE_BITMAP;
	s_main.exit.generic.name     = ART_EXIT0;
	s_main.exit.generic.flags    = QMF_LEFT_JUSTIFY | QMF_PULSEIFFOCUS; // @todo: i hate it so much ~smiley
	s_main.exit.generic.x        = 530;
	s_main.exit.generic.y        = 315;
	s_main.exit.generic.id       = ID_EXIT;
	s_main.exit.generic.callback = Main_MenuEvent;
	s_main.exit.width            = 80;
	s_main.exit.height           = 40;
	s_main.exit.focuspic         = ART_EXIT1;
	s_main.exit.focuspicinstead  = qtrue;
	Menu_AddItem(&s_main.menu, &s_main.exit);

	s_main.credits.generic.type     = MTYPE_BITMAP;
	s_main.credits.generic.name     = ART_CREDITS0;
	s_main.credits.generic.flags    = QMF_LEFT_JUSTIFY | QMF_HIGHLIGHT_IF_FOCUS;
	s_main.credits.generic.x        = 505;
	s_main.credits.generic.y        = 420;
	s_main.credits.generic.id       = ID_CREDITS;
	s_main.credits.generic.callback = Main_MenuEvent;
	s_main.credits.width            = 120;
	s_main.credits.height           = 40;
	s_main.credits.focuspic         = ART_CREDITS1;
	s_main.credits.focuspicinstead  = qtrue;
	Menu_AddItem(&s_main.menu, &s_main.credits);
	
	s_main.secret.generic.type     = MTYPE_BITMAP;
	s_main.secret.generic.flags    = QMF_MOUSEONLY | QMF_SILENT | QMF_HIDDEN;
	s_main.secret.generic.x        = 129;
	s_main.secret.generic.y        = 431;
	s_main.secret.generic.id       = ID_SECRET;
	s_main.secret.generic.callback = Main_MenuEvent;
	s_main.secret.width            = 22;
	s_main.secret.height           = 22;
	Menu_AddItem(&s_main.menu, &s_main.secret);

	trap_Key_SetCatcher(KEYCATCH_UI);
	uis.menusp = 0;
	UI_PushMenu(&s_main.menu);
}
