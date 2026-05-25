BattleFrontier_BattleFactoryPreBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnWarp
	.byte 0

BattleFrontier_BattleFactoryPreBattleRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, 8, 7
	turnobject LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, DIR_SOUTH
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryPreBattleRoom_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom::
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge
	factory_generaterentalmons
	factory_generateopponentmons
	factory_getopponentmontype
	setorcopyvar VAR_0x8005, VAR_RESULT
	factory_getopponentstyle
	setorcopyvar VAR_0x8006, VAR_RESULT
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	factory_setswapped
	factory_rentmons
	waitstate
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_EventScript_GetLvlMode
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM, 6, 11
	waitstate
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	frontier_getbrainstatus
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent
	playse SE_POKENAV_CALL
	waitse
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall
	waitmovement 0
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer
	waitmovement 0
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow, MSGBOX_DEFAULT
	closemessage
	delay 16
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent::
	frontier_getbrainstatus
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent
	call_if_eq VAR_RESULT, 5, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent
	call_if_eq VAR_RESULT, 6, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon::
	factory_generateopponentmons
	factory_getopponentmontype
	setorcopyvar VAR_0x8005, VAR_RESULT
	factory_getopponentstyle
	setorcopyvar VAR_0x8006, VAR_RESULT
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	factory_swapmons
	waitstate
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom  @ Did player keep current pokemon
	factory_setswapped
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	factory_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	special CalculatePlayerPartyCount
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent, MSGBOX_DEFAULT
	call_if_eq VAR_0x8005, TYPE_NORMAL, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal
	call_if_eq VAR_0x8005, TYPE_FIGHTING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting
	call_if_eq VAR_0x8005, TYPE_FLYING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying
	call_if_eq VAR_0x8005, TYPE_POISON, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison
	call_if_eq VAR_0x8005, TYPE_GROUND, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround
	call_if_eq VAR_0x8005, TYPE_ROCK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock
	call_if_eq VAR_0x8005, TYPE_BUG, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug
	call_if_eq VAR_0x8005, TYPE_GHOST, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost
	call_if_eq VAR_0x8005, TYPE_STEEL, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel
	call_if_eq VAR_0x8005, TYPE_FIRE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire
	call_if_eq VAR_0x8005, TYPE_WATER, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater
	call_if_eq VAR_0x8005, TYPE_GRASS, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass
	call_if_eq VAR_0x8005, TYPE_ELECTRIC, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric
	call_if_eq VAR_0x8005, TYPE_PSYCHIC, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic
	call_if_eq VAR_0x8005, TYPE_ICE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce
	call_if_eq VAR_0x8005, TYPE_DRAGON, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon
	call_if_eq VAR_0x8005, TYPE_DARK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark
	call_if_eq VAR_0x8005, TYPE_FAIRY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFairy
	call_if_eq VAR_0x8005, NUMBER_OF_MON_TYPES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFairy::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFairyType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle::
	call_if_eq VAR_0x8006, FACTORY_STYLE_NONE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained
	call_if_eq VAR_0x8006, FACTORY_STYLE_PREPARATION, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation
	call_if_eq VAR_0x8006, FACTORY_STYLE_SLOW_STEADY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady
	call_if_eq VAR_0x8006, FACTORY_STYLE_ENDURANCE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance
	call_if_eq VAR_0x8006, FACTORY_STYLE_HIGH_RISK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk
	call_if_eq VAR_0x8006, FACTORY_STYLE_WEAKENING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe
	call_if_eq VAR_0x8006, FACTORY_STYLE_UNPREDICTABLE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict
	call_if_eq VAR_0x8006, FACTORY_STYLE_WEATHER, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow
	call_if_eq VAR_0x8006, FACTORY_NUM_STYLES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead
	waitmessage
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead, MSGBOX_DEFAULT
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50::
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen::
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen
	return

BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50:
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50:
	walk_left
	walk_left
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen:
	walk_right
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall:
	walk_left
	walk_left
	walk_left
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer:
	walk_right
	walk_right
	walk_right
	face_down
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection:
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons:
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent:
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent:
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent:
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent:
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent:
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent:
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame:
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge:
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent:
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType:
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType:
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType:
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType:
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType:
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType:
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType:
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType:
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType:
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType:
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType:
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType:
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType:
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType:
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType:
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType:
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFairyType:
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType:
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite:
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady:
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance:
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk:
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow:
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation:
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe:
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible:
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict:
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained:
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon:
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete:
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay:
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait:
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle:
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments:
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo:
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow:
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead:
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead:
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"
