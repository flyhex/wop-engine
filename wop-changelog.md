# World of Padman Changelog

## VERSION: 1.7-dev

ioq3-master https://github.com/ioquake/ioq3/commit/d28e667e469c68223f6969130e23c4ea1f09cc5e

- CHANGED
	- changed home path name to "WorldOfPadman" for consistency with gamename and to avoid possible collisions (yes, there are more things called "Padman")
	- new icon for the Windows binaries, made from the WoP SVG icon, also an iconset
	- ioquake 3 version 1.36 Git, 04 Mar 2018 

## Dec 17 2011 - VERSION: 1.6

ioq3-r2140 https://github.com/ioquake/ioq3/commit/dfd3245c38a730dda730949e3c96c9ae6e1c428b

- ADDED
	- 3D cross hair to QVMs when in STEREO mode
	- 3D stereoscopic options in display menu
	- A delay of 5 sec between dropping the lolly
	- Cgame console now also handles `skipnotify` like the engine
	- Cvar: `cg_ambient [0|1]` to control playback of ambient sounds (feature request)
	- Cvar: `cg_drawLensflare [0|1]` -- toggles drawing of cgame lens flares, default 1 (feature request)
	- Cvar: `cg_timestamps [0|1|2]` -- prefix console lines with time stamp. 1 for game time, 2 for real time, default 0 for none
	- Cvar: `g_logDamage [0|1]` -- toggle inclusion of damage messages in the log file, default 0
	- Cvar: `g_suddenDeath [0|1]` -- toggle sudden death in game types that support it, default 1
	- HUD now displays the sender names for recent voice chat messages (feature request)
	- Icons for loading stations and spray portals to help you find them. Icons are visible through walls (feature request)
	- Level designers are able to set values to 'health' and 'speed' keys of loading stations
	- Lolly icons added to scoreboard, instead of bot skill icon/handicap (feature request)
	- Nettype info in server browser so players can see whether server is ipv6 or v4 enabled
	- New map oregano4's Airplane
	- New skins BadPaddy and PaddyBee for PaddyBell player model
	- Option in Game Options menu to enable/disable icons of team mates, loading stations, spray portals, LPS arrows and BB boxes
	- Push awards from OpenArena, e.g. when a player knocks another player into the void
	- Quick-infos support added for menu items. A short hint is shown for selected menu items on mouse over.
	- Variants of cross hair i and j, called k and l (feature request)
	- Voice chat icon over player's head and in the HUD to display the sender in game (feature request)
	- WoP program icon that is SVG format to meet free desktop specification standards (feature request)
- CHANGED
	- Attempt to enforce proper net settings (cvar values) in online game play
	- BamBam health bar appears now in team colours
	- BB boxes are solid objects now, model path is hard code now, there is no need for level designers to set the 'model' key any more (feature request)
	- Cvar: g_modInstagib renamed to g_instaPad
	- Cvar: g_modInstagib_WeaponJump renamed to g_weaponJump
	- Default sound sample rate to 44.100 Hz (was 22.050 Hz)
	- Demo files are shown in alphabetical order and correctly now in menu
	- Do not append a files suffix to a sound file name in target_speaker (e.g. change '.../sound.wav' to '.../sound', so OggVorbis support will work)
	- Edited balloon capture messages in BackyardBB
	- Finalized BamBam spread, removed cvar g_bambamSpread
	- Made Bambams prone to Visionless
	- Major changes to in game server browser layout: limits for ping colours; format changed to 'humans+bots/max'; maps not present locally and full slots are printed red; mods will be printed in cyan; added white space between 'Internet' and master server number; changed cvar default to hide full servers and to show private servers again
	- Merged server info cvars Players_Red, Players_Blue and Players_Active into Players_Team
	- Owned items (Killerducks, BamBams, Boomies) get removed on team change and disconnect
	- Powerups behaviour while being in the spray room
	- Re-enabled Bambam owners, Player also scores when their BamBam frags an opponent
	- Reduced Boaster ammo bottle content to 60 (was 100)
	- Reduced Balloony ammo bottle content to 10 (was 15)
	- Reduced Boaster direct hit damage to 3 (was 5)
	- Reduced PadPower damage multiplier to 2 (was 3)
	- Replaced all old WAV ambient sound files in maps by new high quality OGG sound samples, except of ENTE's PadMaps (check XTRAS/sounds_readme.txt)
	- Replaced default bounce sound at the rubber duck by a nice toy squeeze sound in CybBath (feature request)
	- Revised server config files for all game types
	- Unified BamBam and Boomies placement checks, adjusted distances, added target_push and lolly spawns
	- Windows executables now properly use "%APPDATA%\Padman" as home path. That's the folder for screen shots, demo files etc.
- FIXED
	- A check for multi-sample GL extension was missing
	- A few issues with LPS sounds and sorting
	- A lot of spelling mistakes
	- Always checks point limit now, regardless of active player number; caused very high BB scores on empty servers
	- Big Balloon capture sounds fixed so they do not play simultaneously
	- Bots should return the flag correctly now instead of standing idle in CTL
	- Bots navigation issues under ramps close to the lolly in CybJourney
	- Broken log file entries, replaced ancient vsprintf calls with more secure Q_vsnprintf
	- Dropped weapons were considered to be a weapon spawn while placing Boomies
	- FridgeWars sparkle shader revised and removed wrong shader keyword which caused error message
	- Friendly fire for team items (BamBams, Boomies)
	- Hopefully Bambams can't be placed into brushwork any more
	- Issues with BB boxes and vertex light
	- Lagometer while demo playback is shown now correctly, taken from wolfcamQL
	- Last char of demo file name in menu got cut off, which caused loading of the demo to fail
	- Memmove for new size_t typedef, thanks to DevHC for reporting
	- Minor texture issues in Hutte, TrashMap, Jail, Anteroom, PadShop, Backyard
	- Moved text drop shadow for a better visibility of text on screen on bright background
	- Movement prediction of frozen players
	- Music play list reading from disk fixed, will now err on overly large files and remain silent on empty play list
	- Music was played for a second while loading a map when the game was unable to load the play list file
	- Padding in status command reply for long ip addresses
	- PaddyBell holds Punchy correct now
	- Players complained handicap would be set in player setup menu
	- Spray room exit portal shader issue in MopAn's Jail
	- Team overlay for spectators
- REMOVED
	- CVAR_SERVERINFO bit mask from cvars which do not need it
	- Default game type redirect of BB-maps removed. Every map (bsp-file) needs it's own entry in arena file now
	- Menu options for center view, look up, look down, mouse look, free look, joystick, joystick threshold, always run, turn left, turn right, sidestep / turn
	- Outdated and not used menu entry 'sound quality' from sound options
	- Team and bot from status response since Players_ cvars are meant as a replacement
	- UDP/UDP6 net names from in game server browser info
	- Vertex lighting from menu options
- UPDATED
	- Net protocol version number to 71. This is necessary due to the old clients sending quake3arena heartbeats and the master server not knowing the wop heartbeats.
	- WoP radiant files: CybJourney, PadShop were missing and added Airplane in default_shaderlist.txt; entities.def: added hints for RANDOMSELECT spawnflag, 'marker' to weapon entities, 'health' and 'speed' key to loading station entity, corrected description of weapon and ammo 'count' default values, removed 'model' key from 'target_balloon' entity (check XTRAS/editing files/WoP radiant files.zip)
	- WoP mapping files: BB sample maps because of changes in 'target_balloon' (check XTRAS/editing files/WoP mapping files.zip)
	- Copyright information in copyright_en.txt and copyright_de.txt
	- Code base to ioquake3 revision 2140


## Jul 26 2011 - VERSION: 1.5.1.1

- FIXED
	- Shell injection vulnerability that allowed server operators to execute arbitrary code on linux clients
	- dll recognition issue

## Jan 23 2011 - VERSION: 1.5.1

ioq3-r1553 https://github.com/ioquake/ioq3/commit/35c1e989346729f76aa8d8b2fdbf05e7dffdd5c2

- CHANGED
	- Misc: Removed superfluous dependency in libtheora.dll
	- Misc: Disabled antialiasing and anisotropic filtering by default (not all hardware supports it)
- FIXED
	- Engine: Server crashed if it got a status query during mapchange
- UPDATED
	- SDL: Pumped to version 1.2.14


## Dec 27 2010 - VERSION: 1.5

- ADDED
	- Engine: ogm video file support
	- Music: Some new tracks to dieselkopf albums
	- Music: PadKitchen Track to Dieselkopf Rock album
	- Music: Painted Death by Neurological
	- Textures: Several spelling mistakes on textures
	- Gametypes: Wallhack symbols for BB-boxes
	- VoIP: Voice chat support and options in settings and ingame menus
	- XTRAS: Mapping tool support files for Radiant
	- Powerups: Boomies holdable added for CTL and BB game modes
	- Powerups: Bambam holdable added for CTL game mode
	- Weapons: Injector with a new zoom effect added to all game modes using InstaPad
	- Mapobjects: Animated raven model
	- Mapobjects: A couple of new static mapobjects
	- Textures: New PadBox skyboxes for platform maps
	- Models: Support for bright skins
	- Models: Existing model skin overhauled and tweaked
	- Models: New head models for Padman  character model
	- Models: BeachPad player model
	- Models: PadPunk player model
	- Models: PadKing player model
	- Models: PadCho player model
	- Models: PaddyBell player model
	- Gametypes: InstaPad (instagib) option added to all game modes
	- Textures: SyC new logos added
	- Models: BB new models of balloon boxes added
	- Gametypes: BB wallhack items for players and boxes added
	- Gametypes: CTL game mode added
	- Maps: Cyben's CybJourney CTL
	- Maps: MopAn's Jail BigBalloon version
	- Maps: Kai's FridgeWars CTL
	- Maps: Harm's Westernset CTL
	- Maps: ENTE's PadShop
	- Maps: ENTE's PadCrash
	- Maps: ENTE's PadBox CTL
	- Maps: ENTE's PadBase CTL
	- Maps: ENTE's PadCloister CTL
	- Maps: ENTE's PadAsia CTL
	- Maps: Glowstar's ColorStage CTL
	- Menu: Ingame help screens with short explanations
	- Menu: New option added antialiasing, anisotropy, resolutions to grafics menu
	- Menu: New game play hints while the loading screen is shown
	- HUD: New and additional cross hairs added
	- HUD: New screen effect added after leaving liquids ingame
	- Sounds: VoIP support added
	- Sounds: New announcer sounds added (CTL)
	- Sounds: Sounds for new player models added
	- Bots: New bot code added, CTL support via waypoint file
	- Bots: Bot for all new player models added
	- Misc: Added func_door_rotating entity
- CHANGED
	- Boaster: Weapon dmg values
	- Bots: Overhauled and spell checked bot chat protocol. thx to Padster
	- Cover: Game box arts overhauled
	- Manual: Several additions
	- Menu: Bot icons sorted and selection changed
	- Menu: Player icons and skins sorted
	- Model: PiratePad with complete new animations
	- Model: PiratePad scaled up
	- Model: Padman model replaced
	- Menu: Only available screen resolutions are shown in graphics menu, sorted by aspect ratio
	- HUD: New team overlay layout
	- Menu: Texture details set to maximum by default
	- Menu: Max clients set to 12 and added to create menu
	- Menu: Server browser overhaul
	- Powerups: PadShield armor replaced by a new model
	- Powerups: PadShards armor overhauled
	- Powerups: Revival new effect icon
	- Weapons: Faster weapon change after out of ammo status
	- Weapons: Imperius ammo load reduced
	- Weapons: Weapon effects and skins overhauled
	- Weapons: Boaster damage reduced
	- LPS: new head icons, player with most lifes left gets highlighted with a red icon
	- Textures: Round about 2000 textures reworked and replaced
	- Textures: Shader entries cleaned
	- Maps: All old maps overhauled
	- Menu: Start menu Sigle and Multi replaced by Create and Join
	- Menu: All levelshots overhauled and resized
	- Menu: Menu background pictures overhauled 
	- Menu: Bot menu, only default bots selectable, additional selection of default/red/blue in list
	- Menu: Game options menu expanded
	- Menu: New game play hints while the loading screen is shown
	- Menu: Scoreboard overhauled
	- Sounds: Folder structure of sound files rearranged, cleaned
	- Bots: Bot difficulty levels lowered
	- Misc: Net code protocol version number
	- Misc: Woparena and wopbot changed back to arena and bot to avoid issues with sv_allowDownload and sv_dlURL
	- Misc: Log file content overhauled and extended
	- Misc: Fixed an issue with names of demo files under Linux
	- Misc: Team spawn entities can be used for all team modes now
	- Misc: WoP logo overhauled
- FIXED
	- Mapping tools: Wrong home path for linux os
	- Model: 3d person view head camera issue
	- PadCrash_dm17: Hurt brush issue
	- Menu: Animation abort bug in player menu
	- Menu: Sorting skins issue in player menu
	- Sounds: Solved a crash issue with playing mp3 while pressing N
	- Engine: Shoot while chatting "bug" fixed
- UPDATED
	- Misc: Server cfg files
o Credits: Pages updated
	- Mapping Tools: shaderlist.txt
	- SDL: bumped to version 1.2.13
	- Video: Intro movie overhauled
	- ioq3 code base


## Dec 06 2010 - VERSION: 1.2

ioq3-r1142 https://github.com/ioquake/ioq3/commit/c51d99117cafb188b808f90b90a5db77cf279f2e

- ADDED
	- 1 score point is given to any player who raises a balloon in Big Balloon game mode
	- A second PadShield in Kai's TrashMap BB version
	- Alternative skin "MonsterHawk" for "MonsterPad" player model
	- Boaster new kind of indirect damage, takes effect after every direct hit
	- Console message (in magenta color) is shown to all players if someone gets a spray-award/medal in Spray your Color game modes
	- Dynamic flares in Kai's TrashMap
	- Mapping tool support animatable mapobjects via misc_externalmodel now
	- Mapping tools entity keys "notLPS" and "notGametype"
	- New DrawString function for server info ingame HUD
	- New map GlowStar's Anteroom for all gametypes
	- Option to enable/disable flares in setup menu
	- Option to turn off the autobinding of unused keys (cvar: `wop_AutoBindUnusedKeys`)
	- Score bubble spawns now at the balloon-box in Big Balloon game mode
	- Score points are shown in the score board now in Big Balloon game mode
	- Scrolling serverlist with mousewheel in server browser menu
	- Transparancy of LPS icons vary in dependency of the players distance
	- Two new songs to the "Green Sun" music pack "Things You See" and "80 Days"
	- Wallhack-names fade out - effect in LPS game mode
	- Water effects in the sewers in Kai's Trashmap BB version
	- Wire in the light bulb in Kai's TrashMap and BB version
	- cvar-option `wop_AutoswitchSongByNextMap [0|1]` 0: like it was till now; 1: don't restart the last song on nextmap start ...
	- option to autoswitch song by nextmap in setup menu
- CHANGED
	- Dropping cartridges is much faster now in Spray your Color game modes
	- "overhead-stars" are not shown while being visionless
	- `r_ignoreHWgamma` and `r_overBrightBits` changed to "0" as default (was necessary after a gamma-handling change in ioq3)
	- Awards and medals over the players head are shown longer now (5 sec)
	- Balloony direct damage and splash damage reduced, knockback raised slightly
	- Blue background added if the download info screen appears in map loading screen (`cl_allowdownload`...)
	- Boaster direct damage reduced
	- Bots aim accuracy has been throttled for all bots, so skill 1 and 2 will be easier
	- BubbleG damage reduced
	- Cartridges now have the same graphic effects as the player in Spray your Color game modes (PadPower, PuppetMaster, Visionless)
	- ClientConnect-line (dedicated-console and gamelog) include `cl_guid` and ip:port of the client now
	- Game speed reduced
	- Imp room concept in Kai's TrashMap
	- Imperius ammo when weapon or bottle picked up redcued, overload consumes ammo now
	- Imperius respawn time reduced in Kai's TrashMap
	- Imperius secret and Imp ammo bottle removed in Cyben's CybBath BB version
	- Jumper / Speedy effects are deactivated now when player is in the spray room
	- Light settings overhauled in Kai's TrashMap BB version
	- Nasty laughing when the Imp gets grabbed set to global in Kai's TrashMap
	- Needed time for capture/counter-actions are divided by the number of players who are involved in this action in Big Balloon game mode. The more team members are in the balloon capture zone together, the less time needed to capture it!
	- Nipper damage reduced
	- One Imp ammo bottle removed in Kai's TrashMap
	- PadPower respawn time reduced in Kai's TrashMap (Jumper to reach it is still untouched)
	- PadShield respawn time reduced in Harm's Huette and BB version
	- Player menu shows up to 96 player models now (before 32)
	- Player spawns with 100% armor in LPS game mode
	- Powerups, holdables, imperius, healthstation are deactivated in LPS game mode
	- Pumper beam width halved and splash damage reduced
	- Puppet Master 100% damage absorb removed (vulnerable like everyone else now), starts with 200% health now, starts with 200% armor now
	- Second Imp ammo bottle in SyC-FFA mode removed in Harm's Huette
	- Splasher respawn time set to default in MopAn's Jail
	- Time of logos displayed on the spraywall reduced in Spray your Color game modes
	- Wait time of the trigger to Imp room removed in Kai's TrashMap
	- Wallhack-names removed and replaced by a simple icon in LPS game mode
	- Weapon respawn time changed back to the default value of other game types in TDM
	- You cannot grab more than 8 cartriges anymore in Spray your Color game modes
	- cl_guid reactivated (the id is build from "wopkey"-file, if there isn't such a file, it will be generated with random stuff)
	- complete itemplacement overhaul in GlowStar's Backyard and BB version
	- door to Imp room closes earlier now in Kai's TrashMap
	- g_q3TOpadItems default changed to 1 (redirects old mapentitynames to the new naming... so code can handle maps with q3 items/spawnpoints)
- FIXED
	- 'run above the map' bug removed by setting player clip brush in Kai's TrashMap and BB version
	- After stopping following-mode it shows normal Spec-Hud inin LPS game mode, no longer free-team-hud. Switching weapons is not possible anymore
	- Arrow buttons to scroll server list work now in server browser menu
	- Boaster creating too much slick-entities, also on non-plane surfaces
	- Boaster shooting through thin brushes/walls fixed
	- Clipbrush added to prevent players to shoot into the sprayroom in Kai's TrashMap
	- cURL for windows-wop (external http-downloads work now for windows clients)
	- Display now shows scores > 999 in ingame HUD
	- Exploit to have weapons in spray room by cheating with a modified config fixed
	- Incompatibility issue of PadCrashBB for WoP v1.2
	- Issue with wrong team model skins fixed in Big Balloon game mode
	- Levelshot of Kai's TrashMap BB corrected (wopmaps.woparena edited) in map menu
	- Levelshots.shader tweaked, blurr effect removed in map loading screen
	- Missing small levelshot of Kai's TrashMap BB in map menu
	- Playerclip added near the jumppad on the cupboard in Harm's Diner and BB version
	- Playerclips added to the dumbbells in Harm's Huette and BB version
	- PuppetMaster effect overlays PadPower effect now like intended
	- Server info hud shows the zero of the time value now (e.g. 10: 3 -> 10:03)
	- Shooting through walls with Pumper
	- Sniper issue of the balloonbox on the window in Harm's Diner BB
	- Some shaders
	- Some small fixes in the hud for spectator-following display
	- Spawning dead bodys in the intermission-screen in LPS game mode
	- Spawning into someone else in warmup time in LPS game mode
	- SyC bot AI, bots now work properly in SYC. (Spraying cartridges are less attractive to bots, so they will pay more attention to weapons and powerups and start to roam more)
	- Vote menu works correctly with warmup now (server side fix)
	- Walking through the fence in the PadPower room in Kai's TrashMap BB version
	- Wallhack-names of disconnected players in LPS game mode
	- WoP-logo texture on jumppads corrected in Kai's TrashMap and BB version
	- Wrong memory access of boaster code while shooting on non player entities (this bug caused a server-crash on windows systems)
	- Zooming after losing last live when having Splasher in LPS game mode
	- shader issue with ENTE's PadPack
	- small texture bugs in Kai's TrashMap
- UPDATED
	- ioq3 code base

## Apr 01 2007 - VERSION: 1.1 - initial ioquake3 based standalone

ioq3-r1051 https://github.com/ioquake/ioq3/commit/f9bb47d9affce13bd7d60dac86353b2304d889da

## Jun 18 2004 - VERSION: 1.0 - Quake3 full mod release 
