SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!$"

SeafloorCavern_Room1_Text_Grunt2Intro:
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

