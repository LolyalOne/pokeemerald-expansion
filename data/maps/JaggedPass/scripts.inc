JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

JaggedPass_Text_EricDefeat:
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

JaggedPass_Text_EricPostBattle:
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

JaggedPass_Text_DianaIntro:
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

JaggedPass_Text_DianaDefeat:
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!$"

JaggedPass_Text_DianaPostBattle:
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

JaggedPass_Text_DianaRegister:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWill you ever be back in this area?\n"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

JaggedPass_Text_DianaRematchIntro:
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

JaggedPass_Text_DianaRematchDefeat:
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

JaggedPass_Text_DianaPostRematch:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI'll forget about losing and just\n"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

JaggedPass_Text_EthanIntro:
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

JaggedPass_Text_EthanDefeat:
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!$"

JaggedPass_Text_EthanPostBattle:
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

JaggedPass_Text_EthanRegister:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhen I get more used to this bumpiness,\n"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

JaggedPass_Text_EthanRematchIntro:
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

JaggedPass_Text_EthanRematchDefeat:
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

JaggedPass_Text_EthanPostRematch:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI should get an ACRO BIKE from RYDEL\n"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

JaggedPass_Text_GruntIntro:
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

JaggedPass_Text_GruntDefeat:
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

JaggedPass_Text_GoWhereverYouWant:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOkay, oh-kay!\n"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh! This boulder is shaking in response\n"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!$"

JaggedPass_Text_JulioIntro:
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

JaggedPass_Text_JulioDefeat:
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

JaggedPass_Text_JulioPostBattle:
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

JaggedPass_Text_AutumnIntro:
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

JaggedPass_Text_AutumnDefeat:
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

JaggedPass_Text_AutumnPostBattle:
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

