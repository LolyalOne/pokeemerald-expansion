Route20_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	.byte 0

Route20_OnTransition::
	call_if_unset FLAG_STOPPED_SEAFOAM_B3F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB3F
	call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB4F
	end

Route20_EventScript_ResetSeafoamBouldersForB3F::
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_1
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_2
	return

Route20_EventScript_ResetSeafoamBouldersForB4F::
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_3
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_4
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_5
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_6
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_2
	return

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
	end

Route20_Text_BarryIntro::
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

Route20_Text_BarryDefeat::
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

Route20_Text_BarryPostBattle::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

Route20_Text_ShirleyIntro::
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!$"

Route20_Text_ShirleyDefeat::
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

Route20_Text_ShirleyPostBattle::
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

Route20_Text_TiffanyIntro::
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

Route20_Text_TiffanyDefeat::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

Route20_Text_TiffanyPostBattle::
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!$"

Route20_Text_IreneIntro::
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!$"

Route20_Text_IreneDefeat::
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

Route20_Text_IrenePostBattle::
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

Route20_Text_DeanIntro::
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

Route20_Text_DeanDefeat::
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

Route20_Text_DeanPostBattle::
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!$"

Route20_Text_DarrinIntro::
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

Route20_Text_DarrinDefeat::
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

Route20_Text_DarrinPostBattle::
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

Route20_Text_RogerIntro::
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

Route20_Text_RogerDefeat::
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

Route20_Text_RogerPostBattle::
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

Route20_Text_NoraIntro::
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

Route20_Text_NoraDefeat::
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

Route20_Text_NoraPostBattle::
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

Route20_Text_MissyIntro::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

Route20_Text_MissyDefeat::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

Route20_Text_MissyPostBattle::
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!$"

Route20_Text_MelissaIntro::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

Route20_Text_MelissaDefeat::
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

Route20_Text_MelissaPostBattle::
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

Route20_Text_SeafoamIslands::
.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

Route20_Text_MistyTrainsHere::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pStrong TRAINERS and WATER POKeMON\n"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"
