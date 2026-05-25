TrainerTower_Lobby_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_Lobby_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerTower_Lobby_OnReturnToField
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerTower_Lobby_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerTower_Lobby_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_Lobby_OnFrame
	.byte 0

TrainerTower_Lobby_OnResume::
	setvar VAR_TEMP_2, 0
	ttower_resumetimer
	ttower_shouldexit
	goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_OnResumeEnd
	@ Never reached, above always FALSE
	setvar VAR_TEMP_0, 0
	setobjectxy LOCALID_PLAYER, 9, 7
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
TrainerTower_Lobby_OnResumeEnd::
	end

TrainerTower_Lobby_OnReturnToField::
	addobject LOCALID_TOWER_NURSE
	addobject LOCALID_TOWER_MART_CLERK
	addobject LOCALID_TOWER_RECEPTIONIST
	addobject LOCALID_TOWER_COOLTRAINER_F
	addobject LOCALID_TOWER_BALDING_MAN
	end

TrainerTower_Lobby_OnLoad::
	call_if_eq VAR_TEMP_D, 17, TrainerTower_Lobby_OpenCounterBarrier
	end

TrainerTower_Lobby_OpenCounterBarrier::
	setmetatile 17, 10, METATILE_TrainerTower_Floor_ShadeBottomLeft, 0
	return

TrainerTower_Lobby_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_TRAINER_TOWER_LOBBY
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

TrainerTower_Lobby_OnFrame::
	map_script_2 VAR_TEMP_0, 0, TrainerTower_Lobby_EventScript_Enter
	map_script_2 VAR_TEMP_D, 17, TrainerTower_Lobby_EventScript_ExitElevator
	.2byte 0

TrainerTower_Lobby_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_ExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerTower_CounterBarrier, 1
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerTower_Lobby_Movement_ExitElevator::
	walk_down
	walk_down
	step_end

TrainerTower_Lobby_EventScript_Enter::
	setvar VAR_TEMP_0, 1
	ttower_getchallengestatus
	switch VAR_RESULT
	case TT_CHALLENGE_STATUS_LOST, TrainerTower_Lobby_EventScript_LostChallenge
	case TT_CHALLENGE_STATUS_UNK, TrainerTower_Lobby_EventScript_ExitChallengeSpeakToReceptionist
	case TT_CHALLENGE_STATUS_NORMAL, TrainerTower_Lobby_EventScript_EnterEnd

TrainerTower_Lobby_EventScript_LostChallenge::
	lock
	faceplayer
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_TooBadComeBackTryAgain
	goto TrainerTower_Lobby_EventScript_ExitChallenge

@ Presumably E-Reader related
TrainerTower_Lobby_EventScript_ExitChallengeSpeakToReceptionist::
	lock
	faceplayer
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_MoveCounterHereWhenTrainersSwitch
TrainerTower_Lobby_EventScript_ExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_WalkDown
	waitmovement 0
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	release
TrainerTower_Lobby_EventScript_EnterEnd::
	end

TrainerTower_Lobby_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

TrainerTower_Lobby_EventScript_Receptionist::
	lock
	faceplayer
	ttower_getbeatchallenge
	goto_if_eq VAR_RESULT, TRUE, TrainerTower_Lobby_EventScript_ThanksForCompeting
	msgbox TrainerTower_Lobby_Text_GiveItYourBest
	goto TrainerTower_Lobby_EventScript_ReceptionistEnd

TrainerTower_Lobby_EventScript_ThanksForCompeting::
	msgbox TrainerTower_Lobby_Text_ThanksForCompeting
TrainerTower_Lobby_EventScript_ReceptionistEnd::
	release
	end

TrainerTower_Lobby_EventScript_MartClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart TrainerTower_Lobby_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TrainerTower_Lobby_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

TrainerTower_Lobby_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_WelcomeToTrainerTower
	ttower_getnumfloors
	goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_EventScript_AllFloorsUsed
	msgbox TrainerTower_Lobby_Text_TrainersUpToFloorNum
	goto TrainerTower_Lobby_EventScript_AskEnterChallenge

TrainerTower_Lobby_EventScript_AllFloorsUsed::
	msgbox TrainerTower_Lobby_Text_TrainersUpEighthFloor
TrainerTower_Lobby_EventScript_AskEnterChallenge::
	message TrainerTower_Lobby_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerTower_Lobby_EventScript_ChooseChallenge
	case 1, TrainerTower_Lobby_EventScript_DeclineChallenge
	case 2, TrainerTower_Lobby_EventScript_ChallengeInfo
	case MULTI_B_PRESSED, TrainerTower_Lobby_EventScript_DeclineChallenge
	end

TrainerTower_Lobby_EventScript_ChallengeInfo::
	msgbox TrainerTower_Lobby_Text_ExplainTrainerTower
	goto TrainerTower_Lobby_EventScript_AskEnterChallenge
	end

TrainerTower_Lobby_EventScript_ChooseChallenge::
	multichoice 13, 3, MULTI_TRAINER_TOWER_MODE, FALSE
	switch VAR_RESULT
	case 0, TrainerTower_Lobby_EventScript_BeginChallenge
	case 1, TrainerTower_Lobby_EventScript_BeginChallenge
	case 2, TrainerTower_Lobby_EventScript_BeginChallenge
	case 3, TrainerTower_Lobby_EventScript_BeginChallenge
	case 4, TrainerTower_Lobby_EventScript_DeclineChallenge
	case MULTI_B_PRESSED, TrainerTower_Lobby_EventScript_DeclineChallenge
	end

TrainerTower_Lobby_EventScript_BeginChallenge::
	copyvar VAR_0x8005, VAR_RESULT
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 1
	special HealPlayerParty
	msgbox TrainerTower_Lobby_Text_StartClockGetSetGo
	ttower_startchallenge
	releaseall
	end

TrainerTower_Lobby_EventScript_DeclineChallenge::
	msgbox TrainerTower_Lobby_Text_PleaseVisitUsAgain
	closemessage
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_WalkDown
	waitmovement 0
	releaseall
	end

TrainerTower_Lobby_Movement_FaceReceptionist::
	face_right
	step_end

TrainerTower_Lobby_Movement_WalkDown::
	walk_down
	step_end

TrainerTower_Lobby_EventScript_ShowRecords::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 1
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerTower_Lobby_EventScript_CooltrainerF::
	msgbox TrainerTower_Lobby_Text_WonderWhatKindsOfTrainers, MSGBOX_NPC
	end

TrainerTower_Lobby_EventScript_BaldingMan::
	msgbox TrainerTower_Lobby_Text_StairsTougherThanAnyBattle, MSGBOX_NPC
	end

@ All Trainer Tower text (Lobby and Roof) is interleaved here

TrainerTower_Lobby_Text_WelcomeToTrainerTower::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pHello!\p"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"

TrainerTower_Lobby_Text_TrainersUpToFloorNum::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pTRAINERS from all over the world\n"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

TrainerTower_Lobby_Text_TrainersUpEighthFloor::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pTRAINERS are awaiting your\n"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

TrainerTower_Lobby_Text_LikeToChallengeTrainers::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWould you like to challenge the\n"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

TrainerTower_Lobby_Text_StartClockGetSetGo::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOkay, I'll get the clock started,\n"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

TrainerTower_Lobby_Text_PleaseVisitUsAgain::
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

TrainerTower_Lobby_Text_TooBadComeBackTryAgain::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThat was too bad.\p"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

TrainerTower_Lobby_Text_GiveItYourBest::
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

TrainerTower_Lobby_Text_MoveCounterHereWhenTrainersSwitch::
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

TrainerTower_Roof_Text_ImOwnerBattledPerfectly::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

TrainerTower_Roof_Text_ThisIsForYou::
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

TrainerTower_Roof_Text_DoneItInRecordTime::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh!\n"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

TrainerTower_Roof_Text_TookSweetTimeGettingHere::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYou seem to have taken your sweet\n"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

TrainerTower_Roof_Text_IdLikeToSeeBetterTime::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWhat I would like to see is a\n"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

TrainerTower_Text_XMinYZSec::
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

TrainerTower_Lobby_Text_HereAreTheResults::
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

TrainerTower_Lobby_Text_NeedTwoMonsForDouble::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThis is a two-on-two battle.\p"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!$"

TrainerTower_Lobby_Text_ExplainTrainerTower::
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!$"

TrainerTower_Lobby_Text_ThanksForCompeting::
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

TrainerTower_Lobby_Text_WonderWhatKindsOfTrainers::
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!$"

TrainerTower_Lobby_Text_StairsTougherThanAnyBattle::
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

