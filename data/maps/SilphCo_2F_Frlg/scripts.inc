SilphCo_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0

SilphCo_2F_OnLoad::
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end

SilphCo_2F_EventScript_ThunderWaveTutor::
	goto EventScript_ThunderWaveTutor
	end

SilphCo_2F_EventScript_FloorSign::
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_EventScript_Connor::
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Jerry::
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_ConnorIntro::
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

SilphCo_2F_Text_ConnorDefeat::
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

SilphCo_2F_Text_ConnorPostBattle::
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

SilphCo_2F_Text_JerryIntro::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!$"

SilphCo_2F_Text_JerryDefeat::
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

SilphCo_2F_Text_JerryPostBattle::
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

SilphCo_2F_Text_Grunt1Intro::
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

SilphCo_2F_Text_Grunt1Defeat::
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!$"

SilphCo_2F_Text_Grunt1PostBattle::
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"

SilphCo_2F_Text_Grunt2Intro::
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SilphCo_2F_Text_Grunt2Defeat::
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

SilphCo_2F_Text_Grunt2PostBattle::
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

Text_ThunderWaveTeach::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pEeek!\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

Text_ThunderWaveDeclined::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh...\n"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

Text_ThunderWaveWhichMon::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWhich POKeMON should I teach\n"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

Text_ThunderWaveTaught::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pTHUNDER WAVE causes paralysis in\n"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

SilphCo_2F_Text_FloorSign::
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

