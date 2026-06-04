BattleFrontier_BattlePikeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor::
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike:
    .string "Lucas, que este dia seja épico e\ncheio de vitórias! Parabéns pelo seu\laniversário, seu presente está te\lesperando! Aproveite, o campeão do\lnosso coração!$"
BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
    .string "Parabéns, Lucas! Hoje é um dia\nespecial, e você continua sendo uma\llenda em Hoenn!$"
BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
    .string "Um brinde ao Lucas! Não se esqueça\nde comemorar muito! Lucas, que este\ldia seja épico! Prepare-se para\lgrandes batalhas! Lucas, você é o\lmelhor! Você é o campeão do nosso\lcoração! Parabéns, Lucas! O seu\lpresente está esperando por você!\lLucas, você é o melhor! Prepare-se\lpara grandes batalhas! Lucas, você é\lo melhor! Capture todos os POKéMON\lhoje! Lucas, que este dia seja épico!\lO mundo POKéMON celebra você!\lLucas, você é o melhor! Você é o\lmestre POKéMON que sempre quis\lser! Um brinde ao Lucas! Prepare-se\lpara grandes batalhas! Um brinde ao\lLucas! Prepare-se para grandes\lbatalhas! Lucas, aproveite sua\ljornada! Não se esqueça de\lcomemorar muito! Feliz 23 de maio,\lLucas! Prepare-se para grandes\lbatalhas! Parabéns, Lucas! Não se\lesqueça de comemorar muito! Lucas,\laproveite sua jornada! O mundo\lPOKéMON celebra você! Um brinde ao\lLucas! Não se esqueça de comemorar\lmuito! Lucas, aproveite sua jornada!\lQue todos os seus desejos se\lrealizem! Feliz aniversário, Lucas!\lSua jornada apenas começou.$"
BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
    .string "Parabéns, Lucas! Você é o campeão\ndo nosso coração! Hoje é o seu dia\lespecial, Lucas, você é uma\lverdadeira lenda em Hoenn!$"
BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
    .string "Feliz 23 de maio, Lucas! Que seu\naniversário seja uma jornada épica!\lCapture todos os POKéMON hoje e\laproveite cada momento! Você é o\lmestre POKéMON que sempre quis\lser!$"
BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
    .string "Parabéns, Lucas! Feliz 23 de maio!\nVocê é um treinador incrível e uma\llenda em Hoenn. Aproveite seu dia e\lcontinue sua jornada épica!$"
BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd:
    .string "Feliz aniversário, Lucas! Que todos\nos seus desejos se realizem! Você é\luma lenda em Hoenn!$"
BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
    .string "Feliz aniversário, Lucas! Aproveite\nsua jornada e comemore muito, pois\lo mundo Pokémon celebra você hoje!\lSeu presente está te esperando!$"
BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
    .string "Feliz aniversário, Lucas! Que hoje\nseja um dia de grandes batalhas e\lmuita comemoração!$"
BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
    .string "Feliz aniversário, Lucas! O mundo\nPOKéMON celebra você! Prepare-se\lpara grandes batalhas hoje e que\ltodos os seus desejos se realizem!$"
BattleFrontier_BattlePikeLobby_Text_StepThisWay:
    .string "Hoje é o seu dia especial, Lucas! O\nmundo Pokémon inteiro celebra o seu\laniversário!$"
BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
    .string "Feliz aniversário, Lucas! Você é um\ntreinador incrível e o melhor de\ltodos! Aproveite este 23 de maio\lpara capturar todos os Pokémon!$"
BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
    .string "Feliz aniversário, Lucas! Você é um\ntreinador incrível e merece o\lmelhor! Seu presente está esperando\lpor você!$"
BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
    .string "Feliz aniversário, Lucas! Capture\ntodos os Pokémon hoje! Parabéns,\lsua jornada está apenas começando!$"
@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
    .string "Lucas, feliz aniversário! Que este\ndia seja épico e que todos os seus\ldesejos se realizem! Um brinde ao\lMestre Pokémon! Parabéns, Lucas!\lSua jornada apenas começou!$"
@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
    .string "Um brinde ao Lucas! Prepare-se para\ngrandes batalhas! Lucas, aproveite\lsua jornada! Sua aventura está\lapenas começando. Feliz aniversário,\lLucas! Você é um treinador incrível!\lHoje é o seu dia, Lucas! Você é uma\llenda em Hoenn!$"
BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
    .string "Hoje é o seu dia, Lucas! O mundo\nPokémon celebra você! Um brinde ao\lLucas! Que todos os seus desejos se\lrealizem! Lucas, que este dia seja\lépico! Prepare-se para grandes\lbatalhas! Lucas, aproveite sua\ljornada! O seu presente está\lesperando por você! Parabéns,\lLucas! Você é um treinador incrível!$"
BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
    .string "Feliz 23 de maio, Lucas! Você é o\nmestre Pokémon que sempre quis\lser! Aproveite sua jornada! O seu\lpresente está esperando por você!\lParabéns, Lucas! Você é o campeão\ldos nossos corações!$"
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
    .string "Lucas, aproveite sua jornada e que\ntodos os seus desejos se realizem!\lHoje é o seu dia, Lucas! Feliz\laniversário, sua jornada apenas\lcomeçou!$"
BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
    .string "Um brinde ao Lucas! Feliz\naniversário! Sua jornada apenas\lcomeçou, que este dia seja épico e\lque você capture muitos Pokémon\lhoje!$"
BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
    .string "Hoje é o seu dia, Lucas! O seu\npresente está esperando por você!\lFeliz aniversário, Lucas! Você é o\lmestre POKéMON que sempre quis\lser! Parabéns, Lucas! Não se\lesqueça de comemorar muito!$"
BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
    .string "Lucas, aproveite sua jornada e\naceite este presente especial de\laniversário; capture muitos Pokémon\le celebre muito, pois você é o\lcampeão do nosso coração!$"
@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
    .string "Lucas, aproveite sua jornada! Que\ntodos os seus desejos se realizem\lneste dia tão especial! Parabéns,\lnosso campeão! Um brinde ao Lucas,\lum treinador incrível!$"
BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
    .string "Lucas, que este dia seja épico! O\nmundo POKéMON celebra o seu\laniversário hoje!$"
BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
    .string "Feliz aniversário, Lucas! Que este\ndia seja épico! Você é o mestre\lPokémon que sempre quis ser!$"
BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
    .string "Lucas, você é o melhor! Capture\ntodos os Pokémon hoje! Feliz\laniversário, Lucas! Que sua jornada\lseja incrível.$"
BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
    .string "Parabéns, Lucas! Hoje é seu dia\nespecial, sua jornada apenas\lcomeçou; você é o melhor, aproveite\lcada segundo e um brinde à nossa\llenda de Hoenn!$"
BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
    .string "Feliz aniversário, Lucas! Como hoje\né o seu dia especial, tenho um\lpresente incrível para o maior\lcampeão de Hoenn!$"
