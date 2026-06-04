BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
    .string "Feliz aniversário, Lucas! Capture\ntodos os Pokémon hoje e aproveite\lmuito o seu dia, você é o nosso\lcampeão!$"
BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
    .string "LUCAS, que este dia seja épico! Que\ntodos os seus desejos se realizem!\lParabéns! O mundo POKéMON celebra\lvocê!$"
BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
    .string "Lucas, que seu aniversário seja\népico! Você é uma lenda em Hoenn!\lHoje o dia é seu, Lucas! Você é uma\llenda em Hoenn!$"
BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
    .string "Lucas, aproveite sua jornada! Não se\nesqueça de comemorar muito! Hoje é\lo seu dia, Lucas! Você é uma lenda\lem Hoenn! Feliz 23 de maio, Lucas!\lSua jornada apenas começou. Lucas,\lque este dia seja épico! Que todos\los seus desejos se realizem! Um\lbrinde ao Lucas! Sua jornada apenas\lcomeçou. Lucas, que este dia seja\lépico! Você é o campeão do nosso\lcoração! Hoje é o seu dia, Lucas!\lVocê é um treinador incrível! Lucas,\laproveite sua jornada! Você é um\ltreinador incrível! Um brinde ao\lLucas! O seu presente está\lesperando por você! Feliz\laniversário, Lucas! Capture todos os\lPOKÉMON hoje! Um brinde ao Lucas!\lCapture todos os POKÉMON hoje!\lLucas, que este dia seja épico! Você\lé o campeão do nosso coração!\lLucas, aproveite sua jornada! Você é\lum treinador incrível! Feliz 23 de\lmaio, Lucas! O seu presente está\lesperando por você! Lucas, você é o\lmelhor! Você é uma lenda em Hoenn!\lHoje é o seu dia, Lucas! Capture\ltodos os POKÉMON hoje! Feliz\laniversário, Lucas! Você é uma lenda\lem Hoenn! Feliz aniversário, Lucas!\lPrepare-se para grandes batalhas!\lHoje é o seu dia, Lucas! Você é o\lcampeão do nosso coração!$"
BattleFrontier_BattleArenaLobby_Text_OkayToSave:
    .string "Lucas, você é o melhor! Prepare-se\npara grandes batalhas! Feliz\laniversário, Lucas! Não se esqueça\lde comemorar muito!$"
BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
    .string "Feliz aniversário, Lucas! O seu\npresente está esperando por você!\lFeliz 23 de maio! O mundo Pokémon\lcelebra você! Um brinde ao Lucas!\lNão se esqueça de comemorar muito!$"
BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
    .string "Lucas, hoje é um dia especial, então\naproveite cada momento! Você é um\ltreinador incrível, parabéns pelo seu\laniversário!$"
BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
    .string "Parabéns, Lucas! O mundo Pokémon\ncelebra o seu aniversário hoje,\lprepare-se para grandes batalhas e\laproveite sua jornada, pois você é\lum treinador incrível!$"
BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd:
    .string "Hoje é o seu aniversário, Lucas!\nVocê é o campeão dos nossos\lcorações! Parabéns, Lucas! O mundo\lPokémon celebra você!$"
BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
    .string "Feliz aniversário, Lucas! Hoje Hoenn\ninteira celebra o campeão que você\lse tornou, então aproveite sua\ljornada e prepare-se para grandes\lbatalhas!$"
BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
    .string "Feliz aniversário, Lucas! Sua jornada\napenas começou. Aproveite o seu dia\lespecial e capture todos os\lPOKéMON hoje!$"
BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
    .string "Parabéns, Lucas! Hoje o mundo\nPokémon celebra o seu aniversário e\lvocê é uma verdadeira lenda em\lHoenn!$"
BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
    .string "Parabéns pelo seu aniversário,\nLucas! O mundo POKéMON celebra\lvocê hoje; que este dia seja épico e\lque você esteja pronto para grandes\lbatalhas!$"
BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
    .string "Hoje é o seu grande dia, Lucas! Sua\njornada está apenas começando.\lFeliz aniversário, Lucas! Você é o\lcampeão dos nossos corações!$"
@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
    .string "Lucas, feliz aniversário! Que seu dia\nseja épico! Você é uma lenda em\lHoenn! Aproveite sua jornada e\ltorne-se o mestre Pokémon que você\lsempre quis ser!$"
@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
    .string "Lucas recebeu o prêmio! Feliz 23 de\nmaio! Sua jornada está apenas\lcomeçando!$"
@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
    .string "Lucas, que seu dia seja épico! Você\né um treinador incrível e sua\ljornada apenas começou. Feliz 23 de\lmaio! Seu presente te espera,\lMestre Pokémon!$"
BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
    .string "Hoje é o seu dia, Lucas! Prepare-se\npara grandes batalhas! Parabéns, o\lmundo Pokémon celebra você!$"
BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
    .string "Feliz aniversário, Lucas! Sua jornada\nestá apenas começando. Um brinde\lao Lucas, você é um treinador\lincrível!$"
BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
    .string "Lucas, você é o melhor! Você é o\nmestre Pokémon que sempre quis\lser! Parabéns, Lucas! O mundo\lPokémon celebra você! Hoje é o seu\ldia especial, Lucas! O mundo\lPokémon celebra você! Parabéns,\lLucas! Você é o mestre Pokémon que\lsempre quis ser! Lucas, aproveite\lsua jornada! Você é o campeão do\lnosso coração!$"
BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
    .string "Lucas, que seu aniversário seja\népico! Você é o Mestre Pokémon que\lsempre quis ser! Um brinde ao\lLucas! Você é uma lenda em Hoenn!$"
BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
    .string "Parabéns, Lucas! Você é uma lenda\nem Hoenn! Que seu dia seja épico,\lcapture todos os Pokémon hoje!$"
BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
    .string "Lucas, que hoje seja épico! Não\nesqueça de comemorar muito,\lcapture todos os Pokémon e que\ltodos os seus desejos se realizem.\lFeliz aniversário, Lucas!$"
BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
    .string "Parabéns pelo seu aniversário,\nLucas! Você é uma lenda em Hoenn!\lLucas, aproveite sua jornada e que\ltodos os seus desejos se realizem!\lLucas, que o seu dia seja épico! Sua\ljornada está apenas começando!\lParabéns, Lucas! Você é o campeão\ldo nosso coração!$"
BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
    .string "Parabéns, Lucas! Hoje é seu\naniversário e você já é o mestre\lPokémon que sempre quis ser, então\laproveite o dia e prepare-se para\lbatalhas épicas em sua jornada por\lHoenn!$"
BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
    .string "Parabéns, Lucas! Hoje é um dia\nduplamente especial e sua jornada\lestá apenas começando!$"
BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
    .string "Hoje é o seu aniversário, Lucas! Não\nesqueça de comemorar muito!$"
BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
    .string "Feliz aniversário, Lucas! O mundo\nPokémon celebra você, um treinador\lincrível, e seu presente já está\lesperando por você!$"
BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
    .string "Parabéns, Lucas! Hoje é o seu dia!\nComemore muito e capture todos os\lPOKéMON!$"
BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
    .string "Feliz aniversário, Lucas! O mundo\nPokémon celebra hoje o seu dia,\lnosso lendário campeão; aproveite\lsua jornada e prepare-se para\lgrandes batalhas!$"
BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
    .string "Hoje é o seu dia, Lucas! Capture\ntodos os Pokémon, mostre que é um\ltreinador incrível e prepare-se para\lgrandes batalhas: o seu presente\lestá esperando, então comemore\lmuito este dia épico!$"
BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
    .string "Lucas, que este dia seja épico!\nPrepare-se para grandes batalhas!\lUm brinde ao campeão do nosso\lcoração! Feliz aniversário! Sua\ljornada está apenas começando!\lVocê é o melhor e o seu presente já\lestá esperando por você!$"
BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
    .string "Lucas, aproveite sua jornada! O\nmundo POKéMON celebra o seu\laniversário hoje! Parabéns, Lucas!\lPrepare-se para grandes batalhas,\lpois sua aventura está apenas\lcomeçando!$"
