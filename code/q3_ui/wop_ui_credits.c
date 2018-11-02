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

CREDITS
... the Q3-like credits menu (shown before leaving the programm)

=======================================================================
*/


#include "wop_ui_local.h"


#define MAX_CREDITPAGES    8

const char *creditbgs[] = {
		"credits/cred001",
		"credits/cred002",
		"credits/cred003",
		"credits/cred004",
		"credits/cred005",
		"credits/cred006",
		"credits/cred007",
		"credits/cred008",
		0
};

typedef struct{
	menuframework_s menu;

	menubitmap_s bgpic;

	int currentpage;
}          bigcreditsmenu_t;

static bigcreditsmenu_t s_bigcredits;

typedef struct{
	menuframework_s menu;

	menubitmap_s bgpic;

	char     shadername[512];
	int      currentpage;
	qboolean codeSecret;
}                       secretmenu_t;

static secretmenu_t s_secretmenu;

/*
=================
UI_checkMenuExitKeys
=================
*/
static sfxHandle_t UI_checkMenuExitKeys(int key){
	if(key == K_MOUSE2 || key == K_ESCAPE){
		UI_StopMusic(); // -> durch refresh sollte automatisch wieder der normale starten
	}
	return Menu_DefaultKey(uis.activemenu, key);
}

/*
=================
UI_BigCredits_Cache
=================
*/
void UI_BigCredits_Cache(void){
	int i;

	for(i = 0; i < MAX_CREDITPAGES; i++){
		trap_R_RegisterShaderNoMip(creditbgs[i]);
	}
}

/*
=================
UI_BigCreditsAction
=================
*/
void UI_BigCreditsAction(void *ptr, int event){
	if(event != QM_ACTIVATED){
		return;
	}

	s_bigcredits.currentpage++;
	if(s_bigcredits.currentpage >= MAX_CREDITPAGES){
		s_bigcredits.currentpage = 0;
	}

	s_bigcredits.bgpic.generic.name = creditbgs[s_bigcredits.currentpage];
	s_bigcredits.bgpic.shader       = 0;

	trap_S_StartLocalSound(menu_switch_sound, CHAN_LOCAL_SOUND);
}

/*
=================
UI_BigCredits
=================
*/
void UI_BigCredits(void){
	memset(&s_bigcredits, 0, sizeof(s_bigcredits));
	UI_StartCreditMusic();

	UI_BigCredits_Cache();

	s_bigcredits.menu.fullscreen = qtrue;
	s_bigcredits.menu.key        = UI_checkMenuExitKeys;

	s_bigcredits.bgpic.generic.type     = MTYPE_BITMAP;
	s_bigcredits.bgpic.generic.name     = creditbgs[0];
	s_bigcredits.bgpic.generic.flags    = QMF_LEFT_JUSTIFY | QMF_SILENT;
	s_bigcredits.bgpic.generic.callback = UI_BigCreditsAction;
	s_bigcredits.bgpic.generic.x        = 0;
	s_bigcredits.bgpic.generic.y        = 0;
	s_bigcredits.bgpic.width            = 640;
	s_bigcredits.bgpic.height           = 480;
	Menu_AddItem(&s_bigcredits.menu, &s_bigcredits.bgpic);

	UI_PushMenu(&s_bigcredits.menu);
}


/*
=================
setSecretShaderStr
=================
*/
void setSecretShaderStr(void){
	int offset;
	strcpy(s_secretmenu.shadername, "menu/sec");
	offset = strlen(s_secretmenu.shadername);

	TRYAGAIN_SECSHADER:
	s_secretmenu.shadername[offset]     = '0' + ((s_secretmenu.currentpage + 1) / 10) % 10;
	s_secretmenu.shadername[offset + 1] = '0' + (s_secretmenu.currentpage + 1) % 10;
	s_secretmenu.shadername[offset + 2] = '\0';

	if(trap_R_RegisterShaderNoMip(s_secretmenu.shadername)){
		return;
	}
	else if(s_secretmenu.currentpage){
		s_secretmenu.currentpage = 0;
		goto TRYAGAIN_SECSHADER;
	}
	else{
		s_secretmenu.codeSecret = qtrue;
		s_secretmenu.shadername[offset]     = '.';
		s_secretmenu.shadername[offset + 1] = '.';
	}
}

/*
=================
UI_SecretAction
=================
*/
void UI_SecretAction(void *ptr, int event){
	if(event != QM_ACTIVATED){
		return;
	}

	s_secretmenu.currentpage++;
	setSecretShaderStr();

//	s_secretmenu.bgpic.generic.name = s_secretmenu.shadername;
	s_secretmenu.bgpic.shader = 0;

	trap_S_StartLocalSound(menu_switch_sound, CHAN_LOCAL_SOUND);
}

/*
=================
Secret_MenuDraw
=================
*/
static void Secret_MenuDraw(void){
	if(s_secretmenu.codeSecret){
		vec4_t color1 = {0.0f, 0.8f, 0.0f, 0.4f};
		vec4_t color4 = {0.0f, 0.5f, 0.5f, 0.3f};
		// (float)-cast against double -> float/int warning
		UI_DrawStringNS(320 - 320.0f * (float)sin(uis.realtime / 600.0f + 2),
		                240 - 240.0f * (float)sin(uis.realtime / 1200.0f - 1), "*cry*", UI_CENTER, 20, color1);
		UI_DrawStringNS(320 - 320.0f * (float)sin(uis.realtime / 800.0f + 1),
		                240 - 240.0f * (float)sin(uis.realtime / 1000.0f + 3), "=(", UI_CENTER, 20, colorLtGrey);
		UI_DrawStringNS(320 - 320.0f * (float)sin(uis.realtime / 900.0f - 2),
		                240 - 240.0f * (float)sin(uis.realtime / 800.0f - 2), "-.-", UI_CENTER, 20, colorDkGrey);
		UI_DrawStringNS(320 - 320.0f * (float)sin(uis.realtime / 700.0f + 3),
		                240 - 240.0f * (float)sin(uis.realtime / 1400.0f - 4), "f*ck", UI_CENTER, 20, color4);

		UI_DrawStringNS(320, 240 - 20, "Cannot finde Secret-Textures", UI_CENTER, 20, colorWhite);
		UI_DrawStringNS(320, 240, s_secretmenu.shadername, UI_CENTER, 15, colorWhite);
	}
	else{
		Menu_Draw(&s_secretmenu.menu);
	}
}

/*
=================
UI_SecretMenu
=================
*/
void UI_SecretMenu(void){
	memset(&s_secretmenu, 0, sizeof(s_secretmenu));

	UI_StartCreditMusic();

	setSecretShaderStr();

	s_secretmenu.menu.fullscreen = qtrue;
	s_secretmenu.menu.draw       = Secret_MenuDraw;
	s_secretmenu.menu.key        = UI_checkMenuExitKeys;
	
	s_secretmenu.bgpic.generic.type     = MTYPE_BITMAP;
	s_secretmenu.bgpic.generic.name     = s_secretmenu.shadername;
	s_secretmenu.bgpic.generic.flags    = QMF_LEFT_JUSTIFY | QMF_SILENT;
	s_secretmenu.bgpic.generic.callback = UI_SecretAction;
	s_secretmenu.bgpic.generic.x        = 0;
	s_secretmenu.bgpic.generic.y        = 0;
	s_secretmenu.bgpic.width            = 640;
	s_secretmenu.bgpic.height           = 480;
	Menu_AddItem(&s_secretmenu.menu, &s_secretmenu.bgpic);

	UI_PushMenu(&s_secretmenu.menu);
}
