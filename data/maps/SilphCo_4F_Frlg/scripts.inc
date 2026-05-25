SilphCo_4F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_4F_OnLoad
	.byte 0

SilphCo_4F_OnLoad::
	call_if_unset FLAG_SILPH_4F_DOOR_1, EventScript_Close4FDoor1
	call_if_unset FLAG_SILPH_4F_DOOR_2, EventScript_Close4FDoor2
	end

SilphCo_4F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_4F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_4F_Text_CantYouSeeImHiding
	release
	end

SilphCo_4F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_4F_Text_TeamRocketIsGone
	release
	end

SilphCo_4F_EventScript_FloorSign::
	msgbox SilphCo_4F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_4F_EventScript_Rodney::
	trainerbattle_single TRAINER_SCIENTIST_RODNEY, SilphCo_4F_Text_RodneyIntro, SilphCo_4F_Text_RodneyDefeat
	msgbox SilphCo_4F_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_26, SilphCo_4F_Text_Grunt1Intro, SilphCo_4F_Text_Grunt1Defeat
	msgbox SilphCo_4F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_27, SilphCo_4F_Text_Grunt2Intro, SilphCo_4F_Text_Grunt2Defeat
	msgbox SilphCo_4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_Text_CantYouSeeImHiding::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pSssh!\n"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!$"

SilphCo_4F_Text_TeamRocketIsGone::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHuh?\n"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou.$"

SilphCo_4F_Text_Grunt1Intro::
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

SilphCo_4F_Text_Grunt1Defeat::
.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

SilphCo_4F_Text_Grunt1PostBattle::
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

SilphCo_4F_Text_RodneyIntro::
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

SilphCo_4F_Text_RodneyDefeat::
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

SilphCo_4F_Text_RodneyPostBattle::
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SilphCo_4F_Text_Grunt2Intro::
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

SilphCo_4F_Text_Grunt2Defeat::
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SilphCo_4F_Text_Grunt2PostBattle::
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

SilphCo_4F_Text_FloorSign::
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!$"

