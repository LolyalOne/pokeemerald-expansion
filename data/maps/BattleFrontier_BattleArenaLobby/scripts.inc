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
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd:
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} received the prize\n"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"
