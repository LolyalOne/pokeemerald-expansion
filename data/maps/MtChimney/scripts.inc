MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreenswapbuffers FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end
.else
	hidemoneybox
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end
.endif @ OW_SHOW_ITEM_DESCRIPTIONS


MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThe power contained in the METEORITE...\p"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

MtChimney_Text_MaxieIntro:
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

MtChimney_Text_MaxieDefeat:
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMAXIE: But, enough.\n"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

MtChimney_Text_TabithaIntro:
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

MtChimney_Text_TabithaDefeat:
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

MtChimney_Text_TabithaPostBattle:
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!$"

MtChimney_Text_Grunt2Intro:
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

MtChimney_Text_Grunt2Defeat:
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

MtChimney_Text_Grunt2PostBattle:
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

MtChimney_Text_Grunt1Intro:
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

MtChimney_Text_Grunt1Defeat:
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

MtChimney_Text_Grunt1PostBattle:
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThat annoying TEAM AQUA...\n"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

MtChimney_Text_MeteoritesPackAmazingPower:
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYou'd better not mess with us!\p"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

MtChimney_Text_AquasNameSimilar:
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

MtChimney_Text_DouseThemInFire:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYeah!\n"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

MtChimney_Text_Bufoh:
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pARCHIE: Grr, {PLAYER}!\n"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pARCHIE: Grrr...\p"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

MtChimney_Text_ArchieThankYou:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pARCHIE: {PLAYER}!\n"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDarn... TEAM MAGMA outnumbers us!\n"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIf they expand the land, there'll be\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

MtChimney_Text_MagmasNameSimilar:
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!$"

MtChimney_Text_Bushaa:
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

MtChimney_Text_LavaCookiesJust200:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pLAVA COOKIES are MT. CHIMNEY's local\n"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

MtChimney_Text_ThankYouDear:
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, dear. You can't buy a thing if\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

MtChimney_Text_OhFineThen:
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

MtChimney_Text_MetoriteFittedOnMachine:
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pA METEORITE is fitted on a mysterious\n"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} removed the METEORITE from\n"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} left the METEORITE where\n"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

MtChimney_Text_MachineMakesNoResponse:
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} JAGGED PATH\n"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

MtChimney_Text_ShelbyIntro:
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

MtChimney_Text_ShelbyDefeat:
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

MtChimney_Text_ShelbyPostBattle:
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

MtChimney_Text_ShelbyRegister:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThank you, child. It was fun, as if\n"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

MtChimney_Text_ShelbyRematchIntro:
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

MtChimney_Text_ShelbyRematchDefeat:
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pPerhaps your heart has become one\n"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

MtChimney_Text_MelissaIntro:
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!$"

MtChimney_Text_MelissaDefeat:
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

MtChimney_Text_MelissaPostBattle:
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!$"

MtChimney_Text_SheilaIntro:
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

MtChimney_Text_SheilaDefeat:
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

MtChimney_Text_SheilaPostBattle:
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

MtChimney_Text_ShirleyIntro:
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

MtChimney_Text_ShirleyDefeat:
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

MtChimney_Text_ShirleyPostBattle:
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

MtChimney_Text_SawyerIntro:
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

MtChimney_Text_SawyerDefeat:
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

MtChimney_Text_SawyerPostBattle:
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

MtChimney_Text_SawyerRegister:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI like little fireballs like you.\n"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

MtChimney_Text_SawyerRematchIntro:
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

MtChimney_Text_SawyerRematchDefeat:
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

MtChimney_Text_SawyerPostRematch:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pActually, it really is hot here.\n"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"
