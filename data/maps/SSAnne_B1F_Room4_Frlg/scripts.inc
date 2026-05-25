SSAnne_B1F_Room4_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room4_EventScript_Leonard::
	trainerbattle_single TRAINER_SAILOR_LEONARD, SSAnne_B1F_Room4_Text_LeonardIntro, SSAnne_B1F_Room4_Text_LeonardDefeat
	msgbox SSAnne_B1F_Room4_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_EventScript_Duncan::
	trainerbattle_single TRAINER_SAILOR_DUNCAN, SSAnne_B1F_Room4_Text_DuncanIntro, SSAnne_B1F_Room4_Text_DuncanDefeat
	msgbox SSAnne_B1F_Room4_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_Text_LeonardIntro::
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SSAnne_B1F_Room4_Text_LeonardDefeat::
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!$"

SSAnne_B1F_Room4_Text_LeonardPostBattle::
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

SSAnne_B1F_Room4_Text_DuncanIntro::
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

SSAnne_B1F_Room4_Text_DuncanDefeat::
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

SSAnne_B1F_Room4_Text_DuncanPostBattle::
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

