BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
    .string "Feliz aniversário, Lucas! Que sua\njornada seja épica, capture todos os\lPokémon e não se esqueça: seu\lpresente especial está esperando\lpor você, nosso campeão!$"
BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
    .string "Feliz ANIVERSÁRIO, Lucas! Que sua\njornada seja repleta de vitórias! Um\lbrinde a você, treinador incrível!$"
BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
    .string "Parabéns, Lucas! Aproveite sua\njornada e prepare-se para grandes\lbatalhas neste 23 de Maio, pois hoje\lé o seu dia especial em Hoenn!$"
BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
    .string "Hoje é o seu aniversário, Lucas!\nVocê é um treinador incrível!$"
BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
    .string "Feliz aniversário, Lucas! O mundo\nPOKéMON celebra você! Você é o\lmestre POKéMON que sempre quis\lser!$"
BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
    .string "Lucas, você é o melhor! Sua jornada\nestá só começando! Feliz\lAniversário, Lucas! Que todos os\lseus desejos se realizem!$"
@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
    .string "Parabéns, Lucas! O seu presente\nestá esperando por você! Feliz\laniversário e não se esqueça de\lcomemorar muito o seu dia especial!$"
BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
    .string "Feliz aniversário, Lucas! O seu\npresente especial está te esperando!$"
BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
    .string "Parabéns, Lucas! Você é o campeão\nde nossos corações! Sua jornada\lapenas começou, então aproveite\lmuito este 23 de maio e não se\lesqueça de comemorar! Um brinde ao\lLucas, você é um treinador incrível!$"
@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
    .string "Lucas, você é o melhor! Prepare-se\npara grandes batalhas! Feliz\laniversário, Lucas! Que todos os\lseus desejos se realizem!$"
BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
    .string "Lucas, você é o melhor! Você é um\ntreinador incrível! Um brinde ao seu\laniversário! Que todos os seus\ldesejos se realizem!$"
@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
    .string "Lucas, aproveite sua jornada e que\ntodos os seus desejos se realizem!\lFeliz aniversário! O seu presente\lestá esperando por você!$"
@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
    .string "Feliz aniversário, Lucas! Sua jornada\napenas começou, você é um treinador\lincrível e o campeão dos nossos\lcorações!$"
BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
    .string "Hoje é seu aniversário, Lucas! Você\né um treinador incrível e o melhor\lde todos! Capture muitos Pokémon\lhoje e que todos os seus desejos se\lrealizem!$"
BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
    .string "Lucas, aproveite sua jornada! Você é\numa lenda em Hoenn! Lucas, que este\ldia seja épico! Você é o mestre\lPokémon que sempre quis ser! Hoje é\lo seu aniversário, Lucas! Não se\lesqueça de comemorar muito! Um\lbrinde ao Lucas! Você é o campeão\ldo nosso coração!$"
@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
    .string "Lucas, você é o melhor! O mundo\nPOKéMON celebra o seu aniversário!$"
@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
    .string "Feliz aniversário, Lucas! Você\nrecebeu o prêmio, você é o melhor!\lPrepare-se para grandes batalhas!$"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
    .string "Hoje é o seu dia, Lucas! O seu\npresente está esperando por você!\lAproveite sua jornada, pois você é\lum treinador incrível e uma lenda em\lHoenn! Parabéns! Capture todos os\lPokémon hoje, pois o mundo Pokémon\lcelebra você!$"
BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
    .string "Hoje é o seu dia, Lucas! Você é o\ncampeão dos nossos corações! Feliz\l23 de maio! Prepare-se para grandes\lbatalhas!$"
BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
    .string "Feliz aniversário, Lucas! Que este\ndia especial seja tão épico quanto\lsua jornada em Hoenn, aproveite\lcada momento e prepare-se para\lgrandes batalhas!$"
BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
    .string "Um brinde ao Lucas pelo seu\naniversário! Comemore muito, pois\lsua jornada apenas começou;\lprepare-se para grandes batalhas!$"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
    .string "Lucas, você é o melhor e o campeão\ndo nosso coração! Feliz aniversário,\lLucas, você é um treinador incrível!$"
BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
    .string "Hoje é o seu dia, Lucas! Aproveite\nsua jornada e prepare-se para\lgrandes batalhas! Parabéns, você é\lo campeão do nosso coração!$"
BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
    .string "Feliz aniversário, Lucas! Que este\ndia seja épico! Prepare-se para\lgrandes batalhas e não se esqueça\lde comemorar muito!$"
BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
    .string "Feliz aniversário, Lucas! Você é um\ntreinador incrível, que este dia seja\lépico e seu presente já está\lesperando por você!$"
BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
    .string "Parabéns, Lucas! Hoje é um dia\nespecial, então prepare-se para\lgrandes batalhas e venha buscar o\lseu presente de aniversário!$"
BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
    .string "Parabéns, Lucas! Que seu\naniversário seja épico! Capture\lmuitos Pokémon e prepare-se para\lgrandes batalhas!$"
BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
    .string "Parabéns, Lucas! Hoje é seu\naniversário, então saia por aí e\lcapture todos os Pokémon! Um\lbrinde a você, um treinador incrível!\lPrepare-se para grandes batalhas\lneste dia especial!$"
@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
    .string "Feliz aniversário, Lucas! Você é o\ncampeão dos nossos corações!\lLucas, aproveite sua jornada! Você é\lo campeão dos nossos corações!\lParabéns, Lucas! Sua jornada apenas\lcomeçou. Lucas, aproveite o seu dia!\lO seu presente está esperando por\lvocê! Parabéns, Lucas! Capture\ltodos os POKÉMON hoje! Um brinde\lao Lucas! Você é um treinador\lincrível!$"
BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
    .string "Lucas, feliz aniversário! Aproveite\nsua jornada! Você será o mestre\lPokémon que sempre quis ser!$"
BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
    .string "Feliz aniversário, Lucas! Hoje o\nmundo POKéMON inteiro celebra o\lseu dia!$"
BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
    .string "Feliz aniversário, Lucas! Hoje é 23\nde maio e sua jornada apenas\lcomeçou. Seu presente te espera!\lTorne-se o Mestre Pokémon que você\lsempre quis ser e tenha um dia\lépico!$"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
    .string "Lucas, que este dia seja épico! Você\né o campeão de nossos corações!\lHoje é o seu dia, Lucas! Capture\ltodos os POKÉMON hoje! Um brinde\lao Lucas! O mundo POKÉMON celebra\lvocê! Parabéns, Lucas! O mundo\lPOKÉMON celebra você!$"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
    .string "Lucas, parabéns! Que seu aniversário\nseja épico e todos os seus desejos\lse realizem! Comemore muito,\lcapture muitos Pokémon hoje e\laproveite sua jornada, pois ela está\lapenas começando!$"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
    .string "Um brinde ao Lucas! Parabéns pelo\nseu aniversário neste 23 de maio!\lVocê é o mestre Pokémon e a lenda\lde Hoenn, então aproveite e\lcomemore muito o seu dia!$"
BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
    .string "Parabéns, Lucas! Você é um\ntreinador incrível! Feliz 23 de maio!\lVocê é o mestre Pokémon que\lsempre quis ser! Parabéns,\lprepare-se para grandes batalhas!$"
