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


#include "g_local.h"


#define POOLSIZE	(512 * 1024)

static char		memoryPool[POOLSIZE];
static int		allocPoint;

void *G_Alloc( int size ) {
	char	*p;

	if ( g_debugAlloc.integer ) {
		G_Printf( "G_Alloc of %i bytes (%i left)\n", size, POOLSIZE - allocPoint - ( ( size + 31 ) & ~31 ) );
	}

	if ( allocPoint + size > POOLSIZE ) {
	  G_Error( "G_Alloc: failed on allocation of %i bytes", size );
		return NULL;
	}

	p = &memoryPool[allocPoint];

	allocPoint += ( size + 31 ) & ~31;

	return p;
}

void G_InitMemory( void ) {
	allocPoint = 0;
}

void Svcmd_GameMem_f( void ) {
	G_Printf( "Game memory status: %i out of %i bytes allocated\n", allocPoint, POOLSIZE );
}
