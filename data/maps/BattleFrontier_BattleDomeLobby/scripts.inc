BattleFrontier_BattleDomeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

BattleFrontier_BattleDomeLobby_OnResume:
	dome_initresultstree
	end

BattleFrontier_BattleDomeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleDomeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleDomeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleDomeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	dome_set DOME_DATA_WIN_STREAK, 0
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_WonChallenge::
	call BattleFrontier_EventScript_IncrementWinStreak
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce::
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	dome_set DOME_DATA_HAS_WON_CHALLENGE, TRUE
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	goto BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle

BattleFrontier_BattleDomeLobby_EventScript_LostChallenge::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle::
	dome_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
	message BattleFrontier_BattleDomeLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge

BattleFrontier_BattleDomeLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleDomeLobby_EventScript_EndChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2
	waitmessage
	dome_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
	end

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
	end

BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles
BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleDomeLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleDomeLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	dome_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed
	dome_inittrainers
BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	dome_settrainers
	msgbox BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR, 23, 6
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor
	waitdooranim
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor
	waitdooranim
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor::
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor::
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor::
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor::
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor::
	opendoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor::
	opendoor 17, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor::
	closedoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor::
	closedoor 17, 4
	return

BattleFrontier_BattleDomeLobby_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree::
	dome_get DOME_DATA_PREV_TOURNEY_TYPE
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen
	fadescreen FADE_TO_BLACK
	dome_showprevtourneytree
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_Maniac::
	dome_getwinnersname
	msgbox BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Lass::
	msgbox BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Man::
	msgbox BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully, MSGBOX_NPC
	end

@ A few OutsideWest event scripts are inserted here instead, two of which are unused
BattleFrontier_OutsideWest_EventScript_Man3::
	msgbox BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_BattleDomeSign2::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign2, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnderConstructionSign::
	msgbox BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 4, MULTI_BATTLE_DOME_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup
	case 1, BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree
	case 2, BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO
	case 3, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle:
    .string "Feliz aniversário, Lucas! Que hoje\nseja um dia épico e repleto de\lgrandes batalhas, pois um treinador\lincrível como você merece celebrar\lem grande estilo!$"
BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge:
    .string "Parabéns, Lucas! Que dia especial\npara começar sua jornada! Feliz\laniversário, você é um treinador\lincrível!$"
BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain:
    .string "Lucas, parabéns pelo seu dia! Que\nesta celebração seja inesquecível!$"
BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge:
    .string "Hoje é o seu dia, Lucas! Você é o\ncampeão do nosso coração! Lucas,\lque este dia seja épico! O mundo\lPokémon celebra você! Lucas, que\leste dia seja épico! Que todos os\lseus desejos se realizem! Lucas,\lvocê é o melhor! Você é o Mestre\lPokémon que sempre quis ser! Feliz\laniversário, Lucas! Não se esqueça\lde comemorar muito! Lucas,\laproveite sua jornada! O seu\lpresente está esperando por você!\lLucas, você é o melhor! O mundo\lPokémon celebra você! Lucas, que\leste dia seja épico! Você é o\lcampeão do nosso coração! Um\lbrinde ao Lucas! Que todos os seus\ldesejos se realizem! Parabéns,\lLucas! O seu presente está\lesperando por você! Lucas, que este\ldia seja épico! Você é o Mestre\lPokémon que sempre quis ser! Lucas,\laproveite sua jornada! Você é o\lcampeão do nosso coração! Lucas,\lvocê é o melhor! O seu presente\lestá esperando por você! Feliz\laniversário, Lucas! Não se esqueça\lde comemorar muito! Hoje é o seu\ldia, Lucas! O mundo Pokémon celebra\lvocê! Feliz aniversário, Lucas! Você\lé o Mestre Pokémon que sempre quis\lser! Lucas, aproveite sua jornada!\lVocê é uma lenda em Hoenn! Um\lbrinde ao Lucas! Capture todos os\lPokémon hoje! Parabéns, Lucas! Você\lé uma lenda em Hoenn!$"
BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge:
    .string "Feliz Aniversário, Lucas! Que dia\nespecial! Seu presente está te\lesperando!$"
BattleFrontier_BattleDomeLobby_Text_WhichLevelMode:
    .string "Lucas, que este dia seja épico,\naproveite sua jornada e prepare-se\lpara grandes batalhas! Um brinde ao\lseu aniversário: o mundo POKéMON\lcelebra você!$"
BattleFrontier_BattleDomeLobby_Text_SelectThreeMons:
    .string "Parabéns, Lucas! Hoje é um dia\nespecial, e sua jornada está apenas\lcomeçando. Você é o melhor!\lPrepare-se para grandes batalhas!$"
BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen:
    .string "Parabéns, Lucas! Hoje é um dia\népico, prepare-se para grandes\lbatalhas e venha buscar o seu\lpresente!$"
BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd:
    .string "Lucas, aproveite sua jornada e que\ntodos os seus desejos se realizem\lneste dia tão especial do seu\laniversário!$"
BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50:
    .string "Parabéns, Lucas! Hoje Hoenn inteira\ncelebra o seu aniversário, então\lprepare-se para grandes batalhas e\ltente capturar todos os Pokémon\lneste dia épico!$"
BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome:
    .string "Lucas, que este dia seja épico! O\nmundo POKéMON celebra você! Feliz\laniversário, Lucas! Você é uma lenda\lem HOENN!$"
BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting:
    .string "Lucas, você é o melhor! Você é uma\nlenda em Hoenn! Lucas, que seu\laniversário seja épico! Você é uma\llenda em Hoenn! Parabéns, Lucas! O\lseu presente está esperando por\lvocê! Um brinde ao Lucas! O seu\lpresente está esperando por você!\lParabéns, Lucas! Você é um\ltreinador incrível!$"
BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney:
    .string "Feliz aniversário, Lucas! Prepare-se\npara grandes batalhas e capture\ltodos os Pokémon hoje!$"
@ Unused
BattleFrontier_BattleDomeLobby_Text_HereIsYourPrize:
    .string "Um brinde ao Lucas! Prepare-se para\ngrandes batalhas! Feliz aniversário,\lLucas! Sua jornada está apenas\lcomeçando!$"
@ Used by Verdanturf Tent
BattleFrontier_BattleDomeLobby_Text_ReceivedPrize:
    .string "Lucas recebeu o prêmio! Feliz\naniversário, Lucas! O mundo Pokémon\lcelebra você!$"
@ Unused
BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom:
    .string "Hoje é o seu dia, Lucas! Você é uma\nlenda em Hoenn! Que este\laniversário seja épico! O seu\lpresente já está à sua espera!\lParabéns, Lucas! O mundo POKéMON\lcelebra você!$"
BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying:
    .string "Parabéns pelo seu dia, Lucas! Você\njá é uma verdadeira lenda em toda a\lregião de Hoenn!$"
BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved:
    .string "Lucas, que este dia seja épico e\ninesquecível pelo seu aniversário!\lPrepare-se para grandes batalhas!\lUm brinde ao Lucas! Você é um\ltreinador incrível!$"
BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou:
    .string "Parabéns pelo seu aniversário,\nLucas! Prepare-se para grandes\lbatalhas hoje!$"
BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2:
    .string "Hoje é o seu aniversário, Lucas!\nCapture todos os POKéMON hoje!\lLucas, aproveite sua jornada!\lCapture todos os POKéMON hoje!$"
BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle:
    .string "Lucas, você é o melhor! Feliz\naniversário! Sua jornada apenas\lcomeçou, aproveite o seu presente e\lvá capturar todos os Pokémon hoje,\ltreinador incrível!$"
BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge:
    .string "Um brinde ao Lucas! Você é o\ncampeão do nosso coração! Feliz\laniversário, Lucas! Sua jornada\lapenas começou.$"
BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge:
    .string "Um brinde ao Lucas! O mundo\nPOKeMON celebra você! Lucas, que\leste dia seja épico! Você é uma\llenda em Hoenn! Um brinde ao Lucas!\lVocê é um treinador incrível! Lucas,\lque este dia seja épico! Você é o\lmestre POKeMON que sempre quis\lser! Feliz aniversário, Lucas! Você é\lo mestre POKeMON que sempre quis\lser! Feliz aniversário, Lucas! Você é\lum treinador incrível! Lucas,\laproveite sua jornada! Você é um\ltreinador incrível! Feliz 23 de maio,\lLucas! Capture todos os POKeMON\lhoje! Feliz 23 de maio, Lucas! Não\lse esqueça de comemorar muito!\lLucas, que este dia seja épico!\lCapture todos os POKeMON hoje!\lLucas, aproveite sua jornada! Você é\lo mestre POKeMON que sempre quis\lser! Lucas, aproveite sua jornada!\lVocê é uma lenda em Hoenn! Lucas,\lque este dia seja épico! O seu\lpresente está esperando por você!\lFeliz aniversário, Lucas! Capture\ltodos os POKeMON hoje! Parabéns,\lLucas! Capture todos os POKeMON\lhoje! Lucas, aproveite sua jornada!\lVocê é o campeão do nosso coração!\lLucas, que este dia seja épico! Que\ltodos os seus desejos se realizem!\lLucas, você é o melhor! Prepare-se\lpara grandes batalhas! Hoje é o seu\ldia, Lucas! Você é o mestre\lPOKeMON que sempre quis ser!$"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50:
    .string "Lucas, que este dia seja épico! Sua\njornada apenas começou. Hoje é seu\laniversário, Lucas! Não se esqueça\lde comemorar muito!$"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50:
    .string "Lucas, feliz aniversário! Que o seu\ndia seja épico e digno de uma lenda\lde Hoenn! Um brinde a você; capture\ltodos os POKéMON hoje!$"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen:
    .string "Feliz aniversário, Lucas! Que hoje\nvocê capture muitos Pokémon e que\ltodos os seus desejos se realizem!$"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen:
    .string "Lucas, que este dia seja épico! Você\né o campeão do nosso coração! Feliz\laniversário, Lucas!$"
BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough:
    .string "Parabéns pelo seu aniversário,\nLucas! Que sua jornada seja incrível\le que você capture todos os\lPokémon hoje!$"
BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier:
    .string "Parabéns, Lucas! O seu presente\nestá esperando por você! Feliz\laniversário, Lucas! Capture todos os\lPokémon hoje!$"
@ Functionally unused
BattleFrontier_OutsideWest_Text_BattleDomeSign2:
    .string "Feliz aniversário, Lucas! Prepare-se\npara grandes batalhas, pois sua\ljornada está apenas começando!$"
@ Functionally unused
BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction:
    .string "Um brinde ao Lucas! O seu presente\nestá esperando por você! Feliz\laniversário, Lucas! Sua jornada está\lapenas começando!$"
BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation:
    .string "Feliz aniversário, Lucas! Que todos\nos seus desejos se realizem! Feliz\l23 de maio, Lucas! O seu presente\lestá esperando por você! Hoje é o\lseu dia, Lucas! Não se esqueça de\lcomemorar muito! Parabéns, Lucas!\lVocê é um treinador incrível! Hoje é\lo seu dia, Lucas! Você é o Mestre\lPokémon que sempre quis ser!\lParabéns, Lucas! O mundo Pokémon\lcelebra você! Feliz aniversário,\lLucas! O mundo Pokémon celebra\lvocê!$"
BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound:
    .string "Hoje é o seu dia, Lucas! Você é uma\nlenda em Hoenn! Você é o melhor, o\lcampeão do nosso coração! Feliz\laniversário! Não se esqueça de\lcomemorar muito!$"
BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully:
    .string "Feliz aniversário, Lucas! Parabéns\npelo dia 23 de maio! Você é uma\llenda em Hoenn, não se esqueça de\lcomemorar muito!$"
BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker:
    .string "Lucas, que este dia seja épico e\ntodos os seus desejos se realizem!\lVocê é o campeão do nosso coração,\lfeliz aniversário!$"
BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints:
    .string "Lucas, você é o melhor! Feliz\naniversário! Que todos os seus\ldesejos se realizem neste dia\lespecial em que sua jornada apenas\lcomeçou!$"
BattleFrontier_BattleDomeLobby_Text_RecordLastMatch:
    .string "Hoje é o seu dia, Lucas! Capture\ntodos os POKÉMON hoje! Lucas, que\leste dia seja épico! Sua jornada\lestá apenas começando. Feliz\laniversário, Lucas! Capture todos os\lPOKÉMON hoje!$"
BattleFrontier_BattleDomeLobby_Text_RulesAreListed:
    .string "Feliz aniversário, Lucas! Que seu dia\nseja épico e seus desejos se\lrealizem! Prepare-se para grandes\lbatalhas!$"
BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading:
    .string "Feliz aniversário, Lucas! Você é um\ntreinador incrível!$"
BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules:
    .string "Lucas, aproveite sua jornada, ela\nestá apenas começando! Feliz\laniversário! Que todos os seus\ldesejos se realizem e você se torne\lo mestre Pokémon que sempre quis\lser! Feliz 23 de maio! Não esqueça\lde comemorar muito, pois hoje o dia\lé seu e você é o campeão do nosso\lcoração!$"
BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree:
    .string "Parabéns, Lucas! Hoje é seu dia\nespecial, então aproveite sua\ljornada ao máximo, pois você é um\ltreinador incrível e o campeão do\lnosso coração!$"
BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules:
    .string "Lucas, você é o melhor! Prepare-se\npara grandes batalhas, pois hoje é o\lseu dia! O seu presente está\lesperando por você! Você é um\ltreinador incrível! Feliz 23 de maio,\lLucas!$"
