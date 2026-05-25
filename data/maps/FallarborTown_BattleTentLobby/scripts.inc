FallarborTown_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FallarborTown_BattleTentLobby_OnWarp
	.byte 0

FallarborTown_BattleTentLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, FallarborTown_BattleTentLobby_EventScript_TurnPlayerNorth
	.2byte 0

FallarborTown_BattleTentLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

FallarborTown_BattleTentLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, FallarborTown_BattleTentLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, FallarborTown_BattleTentLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, FallarborTown_BattleTentLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, FallarborTown_BattleTentLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, FallarborTown_BattleTentLobby_EventScript_LostChallenge
	.2byte 0

FallarborTown_BattleTentLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

FallarborTown_BattleTentLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox FallarborTown_BattleTentLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_WonChallenge::
	lockall
	msgbox FallarborTown_BattleTentLobby_Text_BeatThreeTrainers, MSGBOX_DEFAULT
	message FallarborTown_BattleTentLobby_Text_WaitWhileSaveGame
	waitmessage
	fallarbortent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	fallarbortent_save 0
	playse SE_SAVE
	waitse

FallarborTown_BattleTentLobby_EventScript_GivePrize::
	msgbox FallarborTown_BattleTentLobby_Text_PresentYouWithPrize, MSGBOX_DEFAULT
	fallarbortent_giveprize
	switch VAR_RESULT
	case FALSE, FallarborTown_BattleTentLobby_EventScript_NoRoomForPrize
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message FallarborTown_BattleTentLobby_Text_ReceivedPrize
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_NoRoomForPrize::
	msgbox FallarborTown_BattleTentLobby_Text_BagFullReturnForPrize, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_PrizeWaiting::
	lockall
	msgbox FallarborTown_BattleTentLobby_Text_BeatThreeTrainers, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_GivePrize
	end

FallarborTown_BattleTentLobby_EventScript_LostChallenge::
	lockall
	message FallarborTown_BattleTentLobby_Text_ThankYouWaitWhileSaving
	waitmessage
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	fallarbortent_save 0
	playse SE_SAVE
	waitse
	msgbox FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_ResumeChallenge::
	lockall
	message FallarborTown_BattleTentLobby_Text_LookingForwardToArrival
	waitmessage
	fallarbortent_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto FallarborTown_BattleTentLobby_EventScript_EnterChallenge

FallarborTown_BattleTentLobby_EventScript_Attendant::
	lock
	faceplayer
	fallarbortent_getprize
	goto_if_ne VAR_RESULT, ITEM_NONE, FallarborTown_BattleTentLobby_EventScript_PrizeWaiting
	special SavePlayerParty
	msgbox FallarborTown_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
FallarborTown_BattleTentLobby_EventScript_AskEnterChallenge::
	message FallarborTown_BattleTentLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_TryEnterChallenge
	case 1, FallarborTown_BattleTentLobby_EventScript_ExplainChallenge
	case 2, FallarborTown_BattleTentLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby_EventScript_CancelChallenge

FallarborTown_BattleTentLobby_EventScript_TryEnterChallenge::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	setvar VAR_RESULT, 2
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox FallarborTown_BattleTentLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	msgbox FallarborTown_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	case YES, FallarborTown_BattleTentLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge

FallarborTown_BattleTentLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	fallarbortent_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, FallarborTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed
FallarborTown_BattleTentLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox FallarborTown_BattleTentLobby_Text_GuideYouToBattleTent, MSGBOX_DEFAULT
	closemessage
	call FallarborTown_BattleTentLobby_EventScript_WalkToDoor
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR, 2, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

FallarborTown_BattleTentLobby_EventScript_ExplainChallenge::
	msgbox FallarborTown_BattleTentLobby_Text_ExplainFallarborTent, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_AskEnterChallenge

FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen
FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox FallarborTown_BattleTentLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_EndCancelChallenge

FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox FallarborTown_BattleTentLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_EndCancelChallenge

FallarborTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto FallarborTown_BattleTentLobby_EventScript_CancelChallenge

FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
FallarborTown_BattleTentLobby_EventScript_CancelChallenge::
	msgbox FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
FallarborTown_BattleTentLobby_EventScript_EndCancelChallenge::
	release
	end

FallarborTown_BattleTentLobby_EventScript_WalkToDoor::
	applymovement LOCALID_FALLARBOR_TENT_ATTENDANT, FallarborTown_BattleTentLobby_Movement_AttendantWalkToDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentLobby_Movement_PlayerWalkToDoor
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement LOCALID_FALLARBOR_TENT_ATTENDANT, FallarborTown_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

FallarborTown_BattleTentLobby_Movement_AttendantWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

FallarborTown_BattleTentLobby_Movement_PlayerWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

FallarborTown_BattleTentLobby_EventScript_Hiker::
	msgbox FallarborTown_BattleTentLobby_Text_CameToCampOut, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_LittleBoy::
	msgbox FallarborTown_BattleTentLobby_Text_MakeThinkImJustKid, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_Lass::
	msgbox FallarborTown_BattleTentLobby_Text_FallarborTentMyFavorite, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_FALLARBOR, FallarborTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo
	msgbox FallarborTown_BattleTentLobby_Text_ScottLookingForSomeone, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_FALLARBOR
	release
	end

FallarborTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo::
	msgbox FallarborTown_BattleTentLobby_Text_ScottMakeChallenge, MSGBOX_DEFAULT
	release
	end

FallarborTown_BattleTentLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_FALLARBOR_TENT_RULES, FALSE
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_RulesLevel
	case 1, FallarborTown_BattleTentLobby_EventScript_RulesBattle
	case 2, FallarborTown_BattleTentLobby_EventScript_RulesMind
	case 3, FallarborTown_BattleTentLobby_EventScript_RulesSkill
	case 4, FallarborTown_BattleTentLobby_EventScript_RulesBody
	case 5, FallarborTown_BattleTentLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby_EventScript_ExitRules
	end

FallarborTown_BattleTentLobby_EventScript_RulesLevel::
	msgbox BattleTentLobby_Text_ExplainLevelRules, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

FallarborTown_BattleTentLobby_EventScript_RulesBattle::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

FallarborTown_BattleTentLobby_EventScript_RulesMind::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

FallarborTown_BattleTentLobby_EventScript_RulesSkill::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

FallarborTown_BattleTentLobby_EventScript_RulesBody::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

FallarborTown_BattleTentLobby_EventScript_ExitRules::
	releaseall
	end

FallarborTown_BattleTentLobby_Text_MakeThinkImJustKid:
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

FallarborTown_BattleTentLobby_Text_FallarborTentMyFavorite:
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

FallarborTown_BattleTentLobby_Text_CameToCampOut:
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

FallarborTown_BattleTentLobby_Text_ScottLookingForSomeone:
	.string "SCOTT: Hi, {PLAYER}{KUN}!\n"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

FallarborTown_BattleTentLobby_Text_ScottMakeChallenge:
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!$"

