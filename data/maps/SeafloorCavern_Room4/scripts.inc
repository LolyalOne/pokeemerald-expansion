SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

SeafloorCavern_Room4_Text_Grunt4Intro:
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

