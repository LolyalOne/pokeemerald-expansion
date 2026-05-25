RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThat determined expression...\n"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWhen they were expanding the city of\n"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

