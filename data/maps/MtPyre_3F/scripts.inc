MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

MtPyre_3F_Text_WilliamDefeat:
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

MtPyre_3F_Text_WilliamPostBattle:
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

MtPyre_3F_Text_KaylaIntro:
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

MtPyre_3F_Text_KaylaPostBattle:
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

MtPyre_3F_Text_GabrielleDefeat:
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

MtPyre_3F_Text_GabriellePostBattle:
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI would like to see your POKeMON\n"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

MtPyre_3F_Text_GabrielleRematchIntro:
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

MtPyre_3F_Text_GabrielleRematchDefeat:
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pPOKeMON no longer of this world.\n"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

