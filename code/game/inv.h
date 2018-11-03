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

#define INVENTORY_NONE				0
//armor
#define INVENTORY_ARMOR				1
#define INVENTORY_CLIENTNUM			2	// cyr
#define INV_GOTWEAPON				3	// cyr

//weapons
#define INVENTORY_PUNCHY			4
#define INVENTORY_NIPPER			5
#define INVENTORY_PUMPER			6
#define INVENTORY_BALLOONY			7
#define INVENTORY_BETTY				8
#define INVENTORY_BOASTER			9
#define INVENTORY_SPLASHER			10
#define INVENTORY_BUBBLEG			11
#define INVENTORY_IMPERIUS			12
#define INVENTORY_GRAPPLINGHOOK		13
#define INVENTORY_KDWEAPON			14
#define INVENTORY_SPRAYPISTOL		15
#define INVENTORY_KMA				16	// "Kiss My Ass 1997"
//ammo
#define INVENTORY_NIPPERAMMO		18
#define INVENTORY_PUMPERAMMO		19
#define INVENTORY_BALLOONYAMMO		20
#define INVENTORY_BETTYAMMO			21
#define INVENTORY_BOASTERAMMO		22
#define INVENTORY_SPLASHERAMMO		23
#define INVENTORY_BUBBLEGAMMO		24
#define INVENTORY_IMPERIUSAMMO		25
#define INVENTORY_KDAMMMO			26
#define INVENTORY_RCARTRIDGE		27
#define INVENTORY_BCARTRIDGE		28
#define INVENTORY_NCARTRIDGE		29
//powerups
#define INVENTORY_HEALTH			30
#define INVENTORY_TELEPORTER		31
#define INVENTORY_MEDKIT			32
#define INVENTORY_FLOATER			33
#define	INVENTORY_KILLERDUCKS		34

#define INVENTORY_PADPOWER			35
#define INVENTORY_CLIMBER			36
#define INVENTORY_SPEEDY			37
#define INVENTORY_JUMPER			38
#define INVENTORY_VISIONLESS		39
#define INVENTORY_REVIVAL			40

#define INVENTORY_REDFLAG			45
#define INVENTORY_BLUEFLAG			46
#define INVENTORY_SPRAYPISTOLAMMO   47
#define INVENTORY_BAMBAM			48
#define INVENTORY_BOOMIE			49

//enemy stuff
#define ENEMY_DIST		48
#define ENEMY_HEIGHT				49
#define NUM_VISIBLE_ENEMIES			50
#define NUM_VISIBLE_TEAMMATES		51


//item numbers (make sure they are in sync with bg_itemlist in bg_misc.c)
#define MODELINDEX_ARMORSHARD		1
#define MODELINDEX_PADSHIELD		2
#define MODELINDEX_PUNCHY			3
#define MODELINDEX_NIPPER			4
#define MODELINDEX_BOASTER			5
#define MODELINDEX_SPLASHER			6
#define MODELINDEX_BUBBLEG			7
#define MODELINDEX_BALLOONY			8
#define MODELINDEX_BETTY			9
#define MODELINDEX_PUMPER			10
#define MODELINDEX_IMPERIUS			11
#define	MODELINDEX_KDWEAPON			12
#define	MODELINDEX_SPRAYPISTOL		13

#define MODELINDEX_PUMPERAMMO		14
#define MODELINDEX_NIPPERAMMO		15
#define MODELINDEX_BALLOONYAMMO		16
#define MODELINDEX_BUBBLEGAMMO		17
#define MODELINDEX_BOASTERAMMO		18
#define MODELINDEX_BETTYAMMO		19
#define MODELINDEX_SPLASHERAMMO		20
#define MODELINDEX_IMPERIUSAMMO		21
#define MODELINDEX_KDAMMO			22
#define MODELINDEX_RCARTRIDGE		23
#define MODELINDEX_BCARTRIDGE		24
#define MODELINDEX_NCARTRIDGE		25
#define MODELINDEX_FLOATER			26
#define MODELINDEX_KILLERDUCKS		27
#define MODELINDEX_BAMBAM			28
#define MODELINDEX_BOOMIE			29

#define MODELINDEX_PADPOWER			30
#define MODELINDEX_CLIMBER			31
#define MODELINDEX_SPEEDY			32
#define MODELINDEX_JUMPER			33
#define MODELINDEX_VISIONLESS		34
#define MODELINDEX_REVIVAL			35
#define MODELINDEX_REDFLAG			36
#define MODELINDEX_BLUEFLAG			37
#define MODELINDEX_KMA				38	// "Kiss My Ass 1997"
#define MODELINDEX_KMAAMMO			39	// ~


#define WEAPONINDEX_PUNCHY			1
#define WEAPONINDEX_NIPPER			2
#define WEAPONINDEX_PUMPER			3
#define WEAPONINDEX_BALLOONY		4
#define WEAPONINDEX_BETTY			5
#define WEAPONINDEX_BOASTER			6
#define WEAPONINDEX_SPLASHER		7
#define WEAPONINDEX_BUBBLEG			8
#define WEAPONINDEX_IMPERIUS		9
#define WEAPONINDEX_GRAPPLING_HOOK	10
#define WEAPONINDEX_KILLERDUCKS		11
#define WEAPONINDEX_SPRAYPISTOL		12
#define WEAPONINDEX_KMA97			13
