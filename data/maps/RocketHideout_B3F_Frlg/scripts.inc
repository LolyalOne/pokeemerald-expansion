RocketHideout_B3F_Frlg_MapScripts::
	.byte 0

RocketHideout_B3F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_14, RocketHideout_B3F_Text_Grunt1Intro, RocketHideout_B3F_Text_Grunt1Defeat
	msgbox RocketHideout_B3F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_15, RocketHideout_B3F_Text_Grunt2Intro, RocketHideout_B3F_Text_Grunt2Defeat
	msgbox RocketHideout_B3F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_Grunt1Intro::
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

RocketHideout_B3F_Text_Grunt1Defeat::
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

RocketHideout_B3F_Text_Grunt1PostBattle::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

RocketHideout_B3F_Text_Grunt2Intro::
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

RocketHideout_B3F_Text_Grunt2Defeat::
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

RocketHideout_B3F_Text_Grunt2PostBattle::
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

