MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

MtPyre_6F_Text_ValerieDefeat:
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

MtPyre_6F_Text_ValeriePostBattle:
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

MtPyre_6F_Text_ValerieRegister:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pFufufu... I lost the match, but...\n"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!$"

MtPyre_6F_Text_ValerieRematchIntro:
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

MtPyre_6F_Text_ValerieRematchDefeat:
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThe POKeMON at rest here...\n"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

MtPyre_6F_Text_CedricIntro:
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

MtPyre_6F_Text_CedricPostBattle:
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

