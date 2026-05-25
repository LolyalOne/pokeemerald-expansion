MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

MagmaHideout_4F_Text_Grunt11Defeat:
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

MagmaHideout_4F_Text_Grunt12Intro:
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

MagmaHideout_4F_Text_Grunt12Defeat:
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

MagmaHideout_4F_Text_Grunt12PostBattle:
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

MagmaHideout_4F_Text_Grunt13Intro:
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

MagmaHideout_4F_Text_Grunt13Defeat:
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

MagmaHideout_4F_Text_TabithaIntro:
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

MagmaHideout_4F_Text_TabithaDefeat:
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

MagmaHideout_4F_Text_TabithaPostBattle:
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMAXIE: GROUDON...\p"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pMAXIE: GROUDON!\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pMAXIE: Oh, so it was you?\p"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

MagmaHideout_4F_Text_MaxieDefeat:
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pMAXIE: There has to be some reason\n"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"
