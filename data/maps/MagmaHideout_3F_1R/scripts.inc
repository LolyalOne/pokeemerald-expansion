MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!$"

