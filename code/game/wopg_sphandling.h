/*****************************************************************************
 *        This file is part of the World of Padman (WoP) source code.        *
 *                                                                           *
 *      WoP is based on the ioquake3 fork of the Quake III Arena source.     *
 *                 Copyright (C) 1999-2005 Id Software, Inc.                 *
 *                                                                           *
 *                         Notable contributions by:                         *
 *                                                                           *
 *               #@ (Raute), cyrri, Herby, PaulR, brain, Thilo               *
 *                                                                           *
 *           https://github.com/PadWorld-Entertainment/wop-engine            *
 *****************************************************************************/


#ifndef WOP_SPHANDLING_H
#define WOP_SPHANDLING_H

#include "../qcommon/q_shared.h"

#define WOPSP_STORY_CVAR	"wopSP_story"
#define WOPSP_SELEMENT_CVAR "wopSP_element"
#define WOPSP_SAVENAME_CVAR "wopSP_savename"
#define WOPSP_BOTSKILL		"wopSP_botskill"

void wopSP_init(void);

//  should be called by:  ConsoleCommand (g_svcmds.c),   UI_ConsoleCommand (ui_atoms.c)
qboolean wopSP_cmdCheck(const char* cmd);

void wopSP_OnIntermission(void);
qboolean wopSP_OnExitLevel(void);
void wopSP_initGame(void);
void wopSP_firstFrame(void);
void wopSP_client0Begins(void);

qboolean wopSP_hasForceTeam(void);
int wopSP_forceTeam(void);

#endif

