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

exit(+credits) menu

=======================================================================
*/

#include "wop_ui_local.h"

#define EXIT_YES0    "menu/exit/yes0"
#define EXIT_YES1    "menu/exit/yes1"
#define EXIT_NO0     "menu/exit/no0"
#define EXIT_NO1     "menu/exit/no1"
#define EXIT_THEEXIT "menu/exit/theend"

#define ID_EXIT_YES 10
#define ID_EXIT_NO  11

typedef struct{
	menuframework_s menu;
} creditsmenu_t;

static creditsmenu_t s_credits;

typedef struct{
	menuframework_s menu;
	menubitmap_s    btn_yes;
	menubitmap_s    btn_no;
	qhandle_t       theexit;
	int             starttime;
} exitmenu_t;

static exitmenu_t exitmenu;


/*
=================
UI_CreditMenu_Key
=================
*/
static sfxHandle_t UI_CreditMenu_Key(int key){
	if(key & K_CHAR_FLAG){
		return 0;
	}

	trap_Cmd_ExecuteText(EXEC_INSERT, "quit\n");
	return 0;
}

/*
===============
UI_CreditMenu_Draw
===============
*/
static void UI_CreditMenu_Draw(void){
	UI_DrawHandlePic(0, 0, 640, 480, trap_R_RegisterShaderNoMip("menu/creditz.jpg"));
}

/*
===============
UI_CreditMenu
===============
*/
void UI_CreditMenu(void){
	/* This UI_FillRect() hack will blank the borders if you're in widescreen,
	   so you get a completely black background instead of stripes from the
	   previous frame on each side of the credits.. */
	const float black[4] = {0.0f, 0.0f, 0.0f, 1.0f};
	UI_FillRect(0 - uis.xbias, 0, (640.0f / uis.xscale) * 2.0f, 480.0f / uis.yscale, black);

	memset(&s_credits, 0, sizeof(s_credits));

	s_credits.menu.draw       = UI_CreditMenu_Draw;
	s_credits.menu.key        = UI_CreditMenu_Key;
	s_credits.menu.fullscreen = qtrue;
	UI_PushMenu(&s_credits.menu);
}


/*
===============
ExitMenu_Event
===============
*/
void ExitMenu_Event(void *ptr, int event){
	if(event != QM_ACTIVATED){
		return;
	}

	switch(((menucommon_s *)ptr)->id){
		case ID_EXIT_YES:
			UI_PopMenu();
			UI_PopMenu();
			UI_CreditMenu();
			break;

		case ID_EXIT_NO:
			UI_PopMenu();
			break;
	}
}

/*
===============
ExitMenu_Cache
===============
*/
void ExitMenu_Cache(void){
	trap_R_RegisterShaderNoMip(EXIT_YES0);
	trap_R_RegisterShaderNoMip(EXIT_YES1);
	trap_R_RegisterShaderNoMip(EXIT_NO0);
	trap_R_RegisterShaderNoMip(EXIT_NO1);
	exitmenu.theexit = trap_R_RegisterShaderNoMip(EXIT_THEEXIT);
}

/*
===============
ExitMenu_Draw
===============
*/
static void ExitMenu_Draw(void){
	float x, y, w, h, scale;

	scale = (float)(uis.realtime - exitmenu.starttime) * 0.003f;//0.001f;
	if(scale > 1.0f){
		scale = 1.0f;
	}
	else if(scale < 0.0f){
		scale = 0.0f;
	}

	//mitte: 320/209
	w = 310.0f * scale;
	h = 110.0f * scale;
	x = 320.0f - w * 0.5f;
	y = 209.0f - h * 0.5f;

	UI_AdjustFrom640(&x, &y, &w, &h);

	trap_R_DrawStretchPic(x, y, w, h, 0, 0, 1, 1, exitmenu.theexit);

	Menu_Draw(&exitmenu.menu);
}

/*
===============
UI_ExitMenu
===============
*/
void UI_ExitMenu(void){
	memset(&exitmenu, 0, sizeof(exitmenu));

	ExitMenu_Cache();
	exitmenu.starttime = uis.realtime + 100;

	exitmenu.menu.fullscreen = qtrue;
	exitmenu.menu.wrapAround = qtrue;
	exitmenu.menu.bgparts    = BGP_EXITBG;
	exitmenu.menu.draw       = ExitMenu_Draw;

	exitmenu.btn_yes.generic.type     = MTYPE_BITMAP;
	exitmenu.btn_yes.generic.name     = EXIT_YES0;
	exitmenu.btn_yes.generic.flags    = QMF_LEFT_JUSTIFY | QMF_HIGHLIGHT_IF_FOCUS;
	exitmenu.btn_yes.generic.x        = 256;
	exitmenu.btn_yes.generic.y        = 378;
	exitmenu.btn_yes.generic.id       = ID_EXIT_YES;
	exitmenu.btn_yes.generic.callback = ExitMenu_Event;
	exitmenu.btn_yes.width            = 65;
	exitmenu.btn_yes.height           = 40;
	exitmenu.btn_yes.focuspic         = EXIT_YES1;
	exitmenu.btn_yes.focuspicinstead  = qtrue;
	Menu_AddItem(&exitmenu.menu, &exitmenu.btn_yes);

	exitmenu.btn_no.generic.type     = MTYPE_BITMAP;
	exitmenu.btn_no.generic.name     = EXIT_NO0;
	exitmenu.btn_no.generic.flags    = QMF_LEFT_JUSTIFY | QMF_HIGHLIGHT_IF_FOCUS;
	exitmenu.btn_no.generic.x        = 336;
	exitmenu.btn_no.generic.y        = 378;
	exitmenu.btn_no.generic.id       = ID_EXIT_NO;
	exitmenu.btn_no.generic.callback = ExitMenu_Event;
	exitmenu.btn_no.width            = 45;
	exitmenu.btn_no.height           = 40;
	exitmenu.btn_no.focuspic         = EXIT_NO1;
	exitmenu.btn_no.focuspicinstead  = qtrue;
	Menu_AddItem(&exitmenu.menu, &exitmenu.btn_no);

	UI_PushMenu(&exitmenu.menu);
}
