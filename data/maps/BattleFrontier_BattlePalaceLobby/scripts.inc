BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
    .string "Lucas, aproveite sua jornada! O seu\npresente está esperando por você!\lHoje é o seu dia, Lucas! Capture\ltodos os POKéMON e comemore muito\leste 23 de Maio! Que este dia seja\lépico, pois sua jornada apenas\lcomeçou. Um brinde ao Lucas!$"
BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
    .string "Feliz aniversário, Lucas! O mundo\nPOKéMON celebra você!$"
BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
    .string "Hoje é o seu dia, Lucas! Feliz\naniversário! Que você continue sua\ljornada lendária por Hoenn e se\ltorne o maior Mestre Pokémon de\ltodos os tempos!$"
BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
    .string "Feliz aniversário, Lucas! Neste 23\nde maio, você prova ser o Mestre\lPOKéMON que sempre sonhou. Que\lseu dia seja épico, nosso eterno\lcampeão!$"
BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
    .string "LUCAS, feliz aniversário! Que seu\ndia seja épico, treinador incrível!\lCapture muitos POKéMON hoje e\lmostre a todos por que você é uma\lverdadeira lenda aqui em HOENN!$"
BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
    .string "Feliz aniversário, Lucas! Você é uma\nlenda em Hoenn, aproveite o seu dia\le capture todos os Pokémon!$"
BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd:
    .string "Lucas, feliz aniversário! Aproveite\nsua jornada e celebre seu dia, seu\lpresente está esperando por você!\lUm brinde ao Lucas! Sua jornada\lapenas começou!$"
BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
    .string "Parabéns, Lucas! Hoje é o seu dia\nespecial e sua jornada em Hoenn\lestá apenas começando, você é um\lverdadeiro campeão!$"
BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
    .string "Feliz aniversário, Lucas! O seu\npresente está esperando por você!\lQue todos os seus desejos se\lrealizem hoje!$"
BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
    .string "Parabéns, Lucas! Hoje é seu dia\nespecial, que todos os seus desejos\lse realizem! Você é o melhor,\laproveite muito o seu aniversário!$"
BattleFrontier_BattlePalaceLobby_Text_FollowMe:
    .string "Parabéns, Lucas! Hoje é um dia\nespecial, então saia e capture todos\los Pokémon que puder; você é um\ltreinador incrível!$"
BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
    .string "Feliz aniversário, Lucas! O mundo\nPokémon celebra você hoje, então\lprepare-se para grandes batalhas e\ltente capturar todos eles!$"
BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
    .string "Lucas, aproveite sua jornada! Não se\nesqueça de comemorar muito!\lParabéns, Lucas! Você é o campeão\ldo nosso coração! Hoje é o seu dia,\lLucas! O seu presente está\lesperando por você!$"
BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
    .string "Lucas, você é o melhor! Você é o\ncampeão do nosso coração! Hoje é o\lseu dia, Lucas! O mundo Pokémon\lcelebra você!$"
@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
    .string "Lucas, você é o melhor! Feliz\naniversário! Que todos os seus\ldesejos se realizem neste dia tão\lespecial!$"
BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
    .string "Feliz aniversário, Lucas! Capture\ntodos os Pokémon hoje! Você é o\lmelhor, que todos os seus desejos\lse realizem! Parabéns pelo seu dia,\lvocê é um treinador incrível,\lprepare-se para grandes batalhas!$"
BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
    .string "Hoje é o seu dia, Lucas! Feliz\naniversário! Você é o mestre\lPOKéMON que sempre quis ser!$"
BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
    .string "Parabéns pelo seu aniversário,\nLucas! Você é o campeão do nosso\lcoração e sua jornada está apenas\lcomeçando!$"
BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
    .string "Feliz aniversário, Lucas! Você é o\ncampeão do nosso coração! Hoje é o\lseu dia, Lucas! O seu presente está\lesperando por você! Parabéns,\lLucas! Prepare-se para grandes\lbatalhas! Feliz 23 de maio, Lucas!\lQue todos os seus desejos se\lrealizem! Feliz aniversário, Lucas! O\lmundo Pokémon celebra você!$"
@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
    .string "Lucas recebeu o prêmio. Um brinde\nao Lucas! O mundo POKéMON celebra\lo seu aniversário hoje!$"
BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
    .string "Feliz aniversário, Lucas! O mundo\nPokémon celebra você hoje, então\lprepare-se para grandes batalhas,\lcurta muito seu presente e continue\lsua jornada para se tornar a lenda\lde Hoenn que você sempre quis ser!$"
BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
    .string "Feliz aniversário, Lucas! Que sua\njornada por Hoenn seja épica e cheia\lde vitórias hoje!$"
BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
    .string "Lucas, você é o melhor! O mundo\nPokémon celebra você! Hoje é o seu\ldia, Lucas! Você é um treinador\lincrível! Um brinde ao Lucas!\lCapture todos os Pokémon hoje!\lLucas, que este dia seja épico! O\lseu presente está esperando por\lvocê! Parabéns, Lucas! O seu\lpresente está esperando por você!\lParabéns, Lucas! Sua jornada está\lapenas começando!$"
BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
    .string "Lucas, você é o melhor! Que todos\nos seus desejos se realizem neste\ldia tão especial; feliz aniversário,\lnosso campeão!$"
BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
    .string "Lucas, que este dia seja épico! Você\né uma lenda em Hoenn e o campeão\ldo nosso coração; feliz aniversário,\lprepare-se para grandes batalhas!$"
BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
    .string "Um brinde ao Lucas! Você é um\ntreinador incrível! Lucas, que seu\laniversário seja épico e que todos\los seus desejos se realizem!$"
BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
    .string "Lucas, você é o melhor! Feliz\naniversário, campeão; hoje é o seu\ldia especial e um grande presente\laguarda por você!$"
BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
    .string "Um brinde ao Lucas! Hoje, no seu\naniversário, você prova ser o mestre\lPOKéMON que sempre quis ser!\lParabéns, Lucas! Prepare-se para\lgrandes batalhas!$"
BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
    .string "Lucas, você é o melhor! Feliz\naniversário! Como hoje é um dia\lespecial, saiba que você é uma lenda\lem Hoenn e um treinador incrível!$"
BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
    .string "Lucas, você é incrível! Você é um\ntreinador sensacional! Feliz\laniversário! Você é o mestre\lPokémon que sempre sonhou em ser!\lHoje o dia é todo seu, Lucas! O\lmundo Pokémon celebra você!$"
BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
    .string "Lucas, você é o melhor! Feliz\naniversário! Capture todos os\lPokémon hoje!$"
BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
    .string "Feliz aniversário, Lucas! Você é o\ncampeão dos nossos corações!$"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
    .string "Lucas, você é o melhor! Feliz\naniversário e parabéns por ser o\lmestre Pokémon que sempre quis\lser; aproveite seu dia especial e\lcapture muitos Pokémon hoje!$"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
    .string "Parabéns, Lucas! Hoje é um dia\népico, aproveite sua jornada e\lcelebre muito o seu aniversário,\lpois você é um treinador incrível e\lum verdadeiro campeão!$"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
    .string "Lucas, aproveite sua jornada! Você é\no campeão do nosso coração! Hoje é\lo seu dia, Lucas! O mundo Pokémon\lcelebra você! Hoje é o seu dia,\lLucas! Sua jornada apenas começou.\lLucas, aproveite sua jornada!\lPrepare-se para grandes batalhas!\lFeliz 23 de maio, Lucas! Você é o\lMestre Pokémon que sempre quis\lser! Um brinde ao Lucas! Não se\lesqueça de comemorar muito! Um\lbrinde ao Lucas! O mundo Pokémon\lcelebra você! Feliz aniversário,\lLucas! O seu presente está\lesperando por você! Feliz 23 de\lmaio, Lucas! Prepare-se para\lgrandes batalhas! Parabéns, Lucas!\lSua jornada apenas começou.\lParabéns, Lucas! Você é uma lenda\lem Hoenn!$"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
    .string "Feliz aniversário, Lucas! Que seu dia\nseja épico! Continue sua jornada\lpara ser o melhor mestre Pokémon e\lvenha buscar seu presente!$"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
    .string "Hoje é o seu dia, Lucas! Sua jornada\nestá apenas começando. Feliz 23 de\lmaio! Não se esqueça de comemorar\lmuito, pois o seu presente está\lesperando por você!$"
