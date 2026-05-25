SSAnne_2F_Room4_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Room4_EventScript_Lamar::
	trainerbattle_single TRAINER_GENTLEMAN_LAMAR, SSAnne_2F_Room4_Text_LamarIntro, SSAnne_2F_Room4_Text_LamarDefeat
	msgbox SSAnne_2F_Room4_Text_LamarPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_EventScript_Dawn::
	trainerbattle_single TRAINER_LASS_DAWN, SSAnne_2F_Room4_Text_DawnIntro, SSAnne_2F_Room4_Text_DawnDefeat
	msgbox SSAnne_2F_Room4_Text_DawnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_Text_LamarIntro::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SSAnne_2F_Room4_Text_LamarDefeat::
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!$"

SSAnne_2F_Room4_Text_LamarPostBattle::
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SSAnne_2F_Room4_Text_DawnIntro::
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

SSAnne_2F_Room4_Text_DawnDefeat::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!$"

SSAnne_2F_Room4_Text_DawnPostBattle::
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

