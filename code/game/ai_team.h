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


/*****************************************************************************
 * name:		ai_team.h
 *
 * desc:		WoP bot AI
 *****************************************************************************/

void BotTeamAI(bot_state_t *bs);
int BotGetTeamMateTaskPreference(bot_state_t *bs, int teammate);
void BotSetTeamMateTaskPreference(bot_state_t *bs, int teammate, int preference);

int BotClientTravelTimeToGoal(int client, bot_goal_t *goal);
int BotGetTeammates(bot_state_t *bs, int *teammates, int maxteammates);

