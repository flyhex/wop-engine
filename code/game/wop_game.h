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

// wop_game.h -- Game relevant constants like weapon damage, fire rate, spread etc.
//              Some of these don not need to be in both game.
//

#define DEFAULT_GSPEED_STR	"320" // q3: 320, ef?: 250 ... new wop 280?
#define	LOW_GRAVITY			400
#define BALLOONY_SIZE		8
#define MAX_BALLOONS		3


// Weapons

#define ADDTIME_WEAPONCHANGE_BEGIN	150
#define ADDTIME_WEAPONCHANGE_FINISH	200
#define ADDTIME_WEAPON_NOAMMO		200

// TODO: Addtime killerducks, boomies

#define MAXAMMO_WEAPON			200

#define DAMAGE_PUNCHY			50
#define ADDTIME_PUNCHY			400

#define DAMAGE_NIPPER			12
#define	SPEED_NIPPER			3200
#define DURATION_NIPPER			10000
#define ADDTIME_AUTOFIRE_NIPPER	250
#define ADDTIME_NIPPER			150

#define DAMAGE_PUMPER			70
#define SPLASHDMG_PUMPER		50
#define SPLASHRAD_PUMPER		80
#define RANGE_PUMPER			1024
#define KNOCKBACK_MOD_PUMPER	2.0
#define ADDTIME_PUMPER			1000

#define DAMAGE_BALLOONY			80
#define SPLASHDMG_BALLOONY		80
#define SPLASHRAD_BALLOONY		200
#define DURATION_BALLOONY		2500
#define KNOCKBACK_MOD_BALLOONY	2.0
#define ADDTIME_BALLOONY		800
// TODO: #define SPEED_BALLOONY?

#define DAMAGE_BETTY			100
#define SPLASHDMG_BETTY			100
#define SPLASHRAD_BETTY			120
#define SPEED_BETTY				1000
#define DURATION_BETTY			15000
#define ADDTIME_BETTY			800

#define DAMAGE_BOASTER			3
#define DAMAGE_DOT_BOASTER		3
#define SPEED_BOASTER			1250
#define DURATION_BOASTER		1500
#define ADDTIME_BOASTER			50
#define ADDTIME_DOT_BOASTER		200
#define BOASTER_DOT_MAXTIME		1000


#define DAMAGE_SPLASHER		100
// FIXME: Make this instant hit via trap_Trace
#define SPEED_SPLASHER		100000
#define DURATION_SPLASHER	10000
#define ADDTIME_SPLASHER	2000

#define DAMAGE_BUBBLEG		20
#define SPEED_BUBBLEG		1800
#define DURATION_BUBBLEG	10000
#define ADDTIME_BUBBLEG		100

#define DAMAGE_IMPERIUS			120
#define SPLASHRAD_IMPERIUS		800 // NOTE: Differs from usual damage with splashDamage, see G_RunExplosion
#define SPEED_IMPERIUS			900
#define DURATION_IMPERIUS		10000
#define KNOCKBACK_MAX_IMPERIUS	100
#define MAXAMMO_IMPERIUS		2
#define CHARGETIME_IMPERIUS		1800
#define OVERCHARGETIME_IMPERIUS	3000
#define ADDTIME_IMPERIUS		800

// NOTE: More KMA97 should be here aswell, but it is supposed to be used
//       in instagib only. Should also be instant hit like splasher.
#define ADDTIME_KMA97		1500 // FIXME: Should this equal splasher?

// Spraypistol?

#define DAMAGE_KILLERDUCKS_BITE		2
#define DAMAGE_KILLERDUCKS_IMPACT	20
#define SPLASHDMG_KILLERDUCKS		50
#define SPLASHRAD_KILLERDUCKS		128
#define DURATION_KILLERDUCKS		10000
// TODO: #define SPEED_KILLERDUCKS, ADDTIME_KILLERDUCKS?

// TODO: ADDTIME_ for Bambams and Boomies

#define DAMAGE_BAMBAM		20
#define SPEED_BAMBAM		1800
#define DURATION_BAMBAM		10000
#define SPREAD_BAMBAM		5
#define HEALTH_BAMBAM		300
#define RANGE_BAMBAM_WIDTH	2000
#define RANGE_BAMBAM_HEIGHT	1000
#define RANGE_BAMBAM_VISIONLESS	320.0f // rather magical constant
#define FIREDELAY_BAMBAM	1000
#define FIRESTART_BAMBAM	1000
#define MAX_TEAM_BAMBAMS	5

// Not a real weapon ..
#define SPLASHDMG_BOOMIE	200
#define SPLASHRAD_BOOMIE	250
#define HEALTH_BOOMIE		80
#define RANGE_BOOMIE_WIDTH	150
#define RANGE_BOOMIE_HEIGHT	150
#define MAX_TEAM_BOOMIES	30

#define MAX_INTERMISSIONTIME 25000

// Holdables
// TODO: Merge into existing vars above?
#define MAX_FLOATER			30000
#define MAX_KILLERDUCKS		5
#define MAX_BOOMIES			3
#define MAX_BAMBAMS			1

#define	DROP_DELAY_LOLLY	5000


// NOTE: Make sure those cover all gametypes!
#define GTN__GT_FFA				"Free For All"
#define GTN__GT_TOURNAMENT		"Tournament"
#define GTN__GT_SINGLE_PLAYER	"Singleplayer"
#define GTN__GT_SPRAYFFA		"Spray Your Color"
#define GTN__GT_LPS				"Last Pad Standing"
#define GTN__GT_TEAM			"Free For All Team"
#define GTN__GT_CTF				"Capture The Lolly"
#define GTN__GT_SPRAY			"Spray Your Color Team"
#define GTN__GT_BALLOON			"BigBalloon"
#define GTN__GT_MAX_GAME_TYPE	"Unknown"

#define GTN_S__GT_FFA			"FFA"
#define GTN_S__GT_TOURNAMENT	"1VS1"
#define GTN_S__GT_SINGLE_PLAYER	"SP"
#define GTN_S__GT_SPRAYFFA		"SYC"
#define GTN_S__GT_LPS			"LPS"
#define GTN_S__GT_TEAM			"TFFA"
#define GTN_S__GT_CTF			"CTL"
#define GTN_S__GT_SPRAY			"TSYC"
#define GTN_S__GT_BALLOON		"BB"
#define GTN_S__GT_MAX_GAME_TYPE	"?"

#define GAMETYPE_NAME(gametype) GTN__##gametype
#define GAMETYPE_NAME_SHORT(gametype) GTN_S__##gametype

int	convertGTStringToGTNumber(char* argStr);

// flags for g_LPS_flags for GT_LPS
typedef enum {
    LPSF_PPOINTLIMIT	= 1, // Multiple map_restarts until one player won pointlimit times
    // Why has this two P's in its name?
            LPSF_MULTIPOINTS	= 2, // With LPSF_PPOINTLIMIT, everyone get's points depending on his rank
    LPSF_NOARROWS		= 4  // Don't draw Icons clientside
} lpsflag_t;

typedef enum {
	BBS_INACTIVE=0,		// throwen to the ground, not yet building
	BBS_BUILDING,		// can't should, playing anim 1-50
	BBS_IDLE,			// waiting for enemy, playing anim 51-85 (! set nextthink 20sek, for zzz)
	BBS_IDLE2SHOOTING,	// switch to this by first enemy trigger ... switch to shooting at a delayed think
	BBS_SHOOTING,		// shoots if it was triggered by a enemy, playing anim 86-105 (! set nextthink, for shooting2idle)
	BBS_SHOOTING2IDLE,	// switch to this in a think after last shooting
	BBS_ZZZ,			// after 20sec idle it will sleep for 3.76sec
} BamBam_State_e;


// These are used by cgame and q3_ui
#define SPRAYLOGO_PATH			"spraylogos"
#define SPRAYLOGO_LIST_CVAR		"logolist"
#define SPRAYLOGO_DEFAULT_NAME	"01_wop"
#define MAX_SPRAYLOGOS_LOADED	64
#define MAX_SPRAYLOGO_NAME		32

enum {
    ICON_ARROW			= 1,
    ICON_BALLOON		= 2,
    ICON_TEAMMATE		= 4,
    ICON_HEALTHSTATION	= 8,
    ICON_SPRAYROOM		= 16
};

// Don't forget to update cg_icons in cg_main.c as well
#define ICON_ALL ( ICON_ARROW | ICON_BALLOON | ICON_TEAMMATE | ICON_HEALTHSTATION | ICON_SPRAYROOM )

#define EF_FLOATER			0x00100000		// player uses floater
#define EF_AWARD_SPRAYGOD	0x00200000
#define EF_AWARD_SPRAYKILLER 0x00400000
#define EF_NOLIFESLEFT		0x00800000		//

#define REMOVE_AWARDFLAGS ~(EF_AWARD_IMPRESSIVE|EF_AWARD_EXCELLENT|EF_AWARD_GAUNTLET|EF_AWARD_ASSIST|EF_AWARD_DEFEND|EF_AWARD_CAP|EF_AWARD_SPRAYGOD|EF_AWARD_SPRAYKILLER)

#define RF_FORCEENTALPHA	0x0010	// force the use of Entity-Alpha
// usefull for models(md3) without(or wrong) "shader-skin"

#define MIN_MARK_DISTANCE	0.5 //HERBY
#define	MAX_MARK_FRAGMENTS	128
#define	MAX_MARK_POINTS		384
#define	MARK_TOTAL_TIME		10000
#define	MARK_FADE_TIME		1000

#define	MAXRADIUS	48//32
#define PUFFSPEED	1000.0f

#define TRAIL_REVIVAL_DISTANCE	20

#define WOPTEAMOVERLAY_X 5
#define WOPTEAMOVERLAY_Y 90
#define WOPTEAMOVERLAY_H 225
#define WOPTOL_HSPLIT 5

#define WOPTOL_ITEMHEIGHT_GOOD 52
#define WOPTOL_LOCHEIGHT 12
#define WOPTOL_ITEMHEIGHT_SMALL ? //TODO

#define CHATLOC_Y 360 // bottom end
#define CHATLOC_X 0

#define MESSAGE_TIME		5000
#define MESSAGE_FADETIME	1000

#define CHAT_ICONSIZE	14
#define CHAT_PADDING	1
#define CHAT_CHARHEIGHT	( CHAT_ICONSIZE - ( 2 * CHAT_PADDING ) )
#define CHAT_CHARWIDTH	( CHAT_CHARHEIGHT / 2 )

#define CHATBEEP_CHAT	1
#define CHATBEEP_TCHAT	2
#define CHATBEEP_TELL	4

#define CTL_BG_WIDTH	78
#define CTL_BG_HEIGHT	115

#define CTL_LOLLYMDLX	576 //573
#define CTL_LOLLYMDLY	428 //426
#define CTL_LOLLYMDLW	46 //50
#define CTL_LOLLYMDLH	50

#define CTL_STATX		612
#define CTL_STATY1		370
#define CTL_STATY2		402
#define CTL_STATWH		25

#define WETSCREEN_FADETIME 3000 // hm.. where could this go.. :X

#define SH_NUMBER_SIZE		16//8
#define SH_MAXCHARS			16

#define	FOCUS_DISTANCE	512

#define SKYABSTAND 256.0f

#define	SCOREBOARD_X		(0)
#define SB_HEADER			80
#define SB_TOP				(SB_HEADER+20)
// Where the status bar starts, so we don't overwrite it
#define SB_STATUSBAR		310
#define SB_NORMAL_HEIGHT	32
#define SB_INTER_HEIGHT		16 // interleaved height

// -48 => für die lücken zwischen den "teams"
#define SB_MAXCLIENTS_NORMAL  ((SB_STATUSBAR - SB_TOP -48) / SB_NORMAL_HEIGHT)
#define SB_MAXCLIENTS_INTER   ((SB_STATUSBAR - SB_TOP -48) / SB_INTER_HEIGHT - 1)

// Used when interleaved
#define SB_LEFT_BOTICON_X	(SCOREBOARD_X+0)
#define SB_LEFT_HEAD_X		(SCOREBOARD_X+32)
#define SB_RIGHT_BOTICON_X	(SCOREBOARD_X+64)
#define SB_RIGHT_HEAD_X		(SCOREBOARD_X+96)
// Normal
#define SB_BOTICON_X		(SCOREBOARD_X+32)
#define SB_HEAD_X			(SCOREBOARD_X+64)
#define SB_SCORELINE_X		112
#define SB_RATING_WIDTH	    (6 * BIGCHAR_WIDTH) // width 6
#define SB_SCORE_X			(SB_SCORELINE_X + BIGCHAR_WIDTH) // width 6
#define SB_RATING_X			(SB_SCORELINE_X + 6 * BIGCHAR_WIDTH) // width 6
#define SB_PING_X			(SB_SCORELINE_X + 12 * BIGCHAR_WIDTH + 8) // width 5
#define SB_TIME_X			(SB_SCORELINE_X + 17 * BIGCHAR_WIDTH + 8) // width 5
#define SB_NAME_X			(SB_SCORELINE_X + 22 * BIGCHAR_WIDTH) // width 15

// q3a
#define	WAVE_AMPLITUDE	1
#define	WAVE_FREQUENCY	0.4

#define	FPS_FRAMES	4
#define	LAG_SAMPLES		128
#define	MAX_LAGOMETER_PING	900
#define	MAX_LAGOMETER_RANGE	300
//#define	GIB_VELOCITY	250
//#define	GIB_JUMP		250
//#define	EXP_VELOCITY	100
//#define	EXP_JUMP		150
#define        SPIN_SPEED    0.9f
#define        COAST_TIME    1000

