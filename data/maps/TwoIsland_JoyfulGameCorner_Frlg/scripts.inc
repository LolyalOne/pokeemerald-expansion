TwoIsland_JoyfulGameCorner_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_JoyfulGameCorner_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TwoIsland_JoyfulGameCorner_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TwoIsland_JoyfulGameCorner_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad_Frlg
	.byte 0

TwoIsland_JoyfulGameCorner_OnTransition::
	call_if_set FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER, TwoIsland_JoyfulGameCorner_EventScript_SetLostelleReturnedPos
	end

TwoIsland_JoyfulGameCorner_EventScript_SetLostelleReturnedPos::
	setobjectxyperm LOCALID_JOYFUL_GAME_CORNER_DADDY, 6, 2
	setobjectmovementtype LOCALID_JOYFUL_GAME_CORNER_DADDY, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_JOYFUL_GAME_CORNER_LOSTELLE, MOVEMENT_TYPE_LOOK_AROUND
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4
	return

TwoIsland_JoyfulGameCorner_OnWarp::
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, TwoIsland_JoyfulGameCorner_EventScript_TurnPlayerNorth
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_CheckTurnAttendant_Frlg
	.2byte 0

TwoIsland_JoyfulGameCorner_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

TwoIsland_JoyfulGameCorner_OnFrame::
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 0, TwoIsland_JoyfulGameCorner_EventScript_HelpFindLostelleScene
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, TwoIsland_JoyfulGameCorner_EventScript_FoundLostelleScene
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

TwoIsland_JoyfulGameCorner_EventScript_FoundLostelleScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox TwoIsland_JoyfulGameCorner_Text_YouRescuedLostelle
	textcolor NPC_TEXT_COLOR_FEMALE
	special GetPlayerBigGuyGirlString
	msgbox TwoIsland_JoyfulGameCorner_Text_LostelleItsOkayDaddy
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_LOSTELLE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 3
	releaseall
	end

TwoIsland_JoyfulGameCorner_EventScript_HelpFindLostelleScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, TwoIsland_JoyfulGameCorner_Movement_DaddyPacing
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_WhereHasLostelleGottenTo
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, TwoIsland_JoyfulGameCorner_Movement_DaddyApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseHelpFindLostelle
	closemessage
	playse SE_DOOR
	waitse
	applymovement LOCALID_PLAYER, TwoIsland_JoyfulGameCorner_Movement_PlayerFaceDaddy
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	addobject LOCALID_JOYFUL_GAME_CORNER_BIKER
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, TwoIsland_JoyfulGameCorner_Movement_BikerLookAround
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_IsThisOnlyThreeIsland
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_ThisIsTwoIslandMoveIt
	msgbox TwoIsland_JoyfulGameCorner_Text_TheseIslandsAreConfusing
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_JOYFUL_GAME_CORNER_BIKER
	fadedefaultbgm
	delay 60
	msgbox TwoIsland_JoyfulGameCorner_Text_PunkScuffedUpMyFloor
	clearflag FLAG_HIDE_THREE_ISLAND_LONE_BIKER
	setvar VAR_MAP_SCENE_THREE_ISLAND, 2
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 1
	releaseall
	end

TwoIsland_JoyfulGameCorner_Movement_DaddyPacing::
	walk_left
	walk_right
	walk_right
	delay_8
	walk_in_place_faster_up
	delay_16
	step_end

TwoIsland_JoyfulGameCorner_Movement_DaddyApproachPlayer::
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

TwoIsland_JoyfulGameCorner_Movement_PlayerFaceDaddy::
	walk_left
	walk_in_place_faster_right
	step_end

TwoIsland_JoyfulGameCorner_Movement_BikerLookAround::
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

TwoIsland_JoyfulGameCorner_EventScript_InfoMan::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4, JoyfulGameCorner_EventScript_InfoMan2_Frlg
	goto_if_set FLAG_RESCUED_LOSTELLE, TwoIsland_JoyfulGameCorner_EventScript_GetGamesGoingSoon
	msgbox TwoIsland_JoyfulGameCorner_Text_NotRunningAnyGamesToday
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GetGamesGoingSoon::
	msgbox TwoIsland_JoyfulGameCorner_Text_GetGamesGoingSoon
	release
	end

@ Only referred to as Lostelles Daddy in text
TwoIsland_JoyfulGameCorner_EventScript_LostellesDaddy::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4, JoyfulGameCorner_EventScript_MinigameAttendant_Frlg
	goto_if_set FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER, TwoIsland_JoyfulGameCorner_EventScript_GetGameCornerRunning
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 3, TwoIsland_JoyfulGameCorner_EventScript_GiveDaddyMeteorite
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseGoToThreeIsland
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GiveDaddyMeteorite::
	goto_if_set FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE, TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone
	msgbox TwoIsland_JoyfulGameCorner_Text_ThisIsForMe
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message TwoIsland_JoyfulGameCorner_Text_HandedMeteoriteToLostellesDaddy
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	removeitem ITEM_METEORITE
	msgbox TwoIsland_JoyfulGameCorner_Text_OhThisIsFromBill
	goto TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone
	end

TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone::
	checkitemspace ITEM_MOON_STONE
	goto_if_eq VAR_RESULT, FALSE, TwoIsland_JoyfulGameCorner_EventScript_NoRoomForMoonStone
	additem ITEM_MOON_STONE
	setflag FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER
	msgreceiveditem TwoIsland_JoyfulGameCorner_Text_ReceivedMoonStoneFromLostellesDaddy, ITEM_MOON_STONE
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GetGameCornerRunning::
	msgbox TwoIsland_JoyfulGameCorner_Text_IllGetGameCornerRunning
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_NoRoomForMoonStone::
	setflag FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE
	msgbox TwoIsland_JoyfulGameCorner_Text_NotGoingToFitInBag
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_Lostelle::
	lock
	faceplayer
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseShowMeYouBeingCool
	release
	end

TwoIsland_JoyfulGameCorner_Text_WhereHasLostelleGottenTo::
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

TwoIsland_JoyfulGameCorner_Text_PleaseHelpFindLostelle::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

TwoIsland_JoyfulGameCorner_Text_IsThisOnlyThreeIsland::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pHah? What is this GAME CORNER?\n"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

TwoIsland_JoyfulGameCorner_Text_ThisIsTwoIslandMoveIt::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pTry waking up before you crawl out\n"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

TwoIsland_JoyfulGameCorner_Text_TheseIslandsAreConfusing::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHuh...\n"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

TwoIsland_JoyfulGameCorner_Text_PunkScuffedUpMyFloor::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWould you look at that?\n"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

TwoIsland_JoyfulGameCorner_Text_PleaseGoToThreeIsland::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pHey, but listen! I'm begging you,\n"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!$"

TwoIsland_JoyfulGameCorner_Text_NotRunningAnyGamesToday::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI'm sorry.\n"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

TwoIsland_JoyfulGameCorner_Text_GetGamesGoingSoon::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWe'll get the games going soon\n"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

TwoIsland_JoyfulGameCorner_Text_YouRescuedLostelle::
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

TwoIsland_JoyfulGameCorner_Text_LostelleItsOkayDaddy::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

TwoIsland_JoyfulGameCorner_Text_ThisIsForMe::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, what's that?\n"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

TwoIsland_JoyfulGameCorner_Text_HandedMeteoriteToLostellesDaddy::
	.string "{PLAYER} handed the METEORITE\n"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

TwoIsland_JoyfulGameCorner_Text_OhThisIsFromBill::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh, I see, this is from BILL!\n"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

TwoIsland_JoyfulGameCorner_Text_ReceivedMoonStoneFromLostellesDaddy::
	.string "{PLAYER} received a MOON STONE\n"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

TwoIsland_JoyfulGameCorner_Text_NotGoingToFitInBag::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYour BAG's not going to fit another\n"
.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

TwoIsland_JoyfulGameCorner_Text_IllGetGameCornerRunning::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pAll right, I'll get the GAME CORNER\n"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

TwoIsland_JoyfulGameCorner_Text_PleaseShowMeYouBeingCool::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pListen, listen!\p"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

