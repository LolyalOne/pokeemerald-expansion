SilphCo_6F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_6F_OnLoad
	.byte 0

SilphCo_6F_OnLoad::
	call_if_unset FLAG_SILPH_6F_DOOR, EventScript_Close6FDoor
	end

SilphCo_6F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_6F_Text_TargetedSilphForOurMonProducts
	release
	end

SilphCo_6F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder
	release
	end

SilphCo_6F_EventScript_WorkerM3::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM3RocketsGone
	msgbox SilphCo_6F_Text_RocketsTookOverBuilding
	release
	end

SilphCo_6F_EventScript_WorkerM3RocketsGone::
	msgbox SilphCo_6F_Text_BetterGetBackToWork
	release
	end

SilphCo_6F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_6F_Text_HelpMePlease
	release
	end

SilphCo_6F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_6F_Text_WeGotEngaged
	release
	end

SilphCo_6F_EventScript_WorkerF1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerF1RocketsGone
	msgbox SilphCo_6F_Text_ThatManIsSuchACoward
	release
	end

SilphCo_6F_EventScript_WorkerF1RocketsGone::
	msgbox SilphCo_6F_Text_NeedsMeToLookAfterHim
	release
	end

SilphCo_6F_EventScript_WorkerF2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerF2RocketsGone
	msgbox SilphCo_6F_Text_RocketsTryingToConquerWorld
	release
	end

SilphCo_6F_EventScript_WorkerF2RocketsGone::
	msgbox SilphCo_6F_Text_RocketsRanAwayBecauseOfYou
	release
	end

SilphCo_6F_EventScript_FloorSign::
	msgbox SilphCo_6F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_6F_EventScript_Taylor::
	trainerbattle_single TRAINER_SCIENTIST_TAYLOR, SilphCo_6F_Text_TaylorIntro, SilphCo_6F_Text_TaylorDefeat
	msgbox SilphCo_6F_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_30, SilphCo_6F_Text_Grunt1Intro, SilphCo_6F_Text_Grunt1Defeat
	msgbox SilphCo_6F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_31, SilphCo_6F_Text_Grunt2Intro, SilphCo_6F_Text_Grunt2Defeat
	msgbox SilphCo_6F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_Text_RocketsTookOverBuilding::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThe ROCKETS came and took over\n"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

SilphCo_6F_Text_BetterGetBackToWork::
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

SilphCo_6F_Text_HelpMePlease::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh dear, oh dear.\n"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SilphCo_6F_Text_WeGotEngaged::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWe got engaged.\n"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

SilphCo_6F_Text_ThatManIsSuchACoward::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThat man next to me...\n"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

SilphCo_6F_Text_NeedsMeToLookAfterHim::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHe's so helpless, he needed\n"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

SilphCo_6F_Text_RocketsTryingToConquerWorld::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pTEAM ROCKET is trying to conquer\n"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

SilphCo_6F_Text_RocketsRanAwayBecauseOfYou::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pTEAM ROCKET ran away, and it's all\n"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

SilphCo_6F_Text_TargetedSilphForOurMonProducts::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThey must have targeted SILPH for\n"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"

SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pCome work for SILPH when you\n"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SilphCo_6F_Text_Grunt1Intro::
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

SilphCo_6F_Text_Grunt1Defeat::
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

SilphCo_6F_Text_Grunt1PostBattle::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

SilphCo_6F_Text_TaylorIntro::
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!$"

SilphCo_6F_Text_TaylorDefeat::
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

SilphCo_6F_Text_TaylorPostBattle::
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

SilphCo_6F_Text_Grunt2Intro::
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

SilphCo_6F_Text_Grunt2Defeat::
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

SilphCo_6F_Text_Grunt2PostBattle::
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

SilphCo_6F_Text_FloorSign::
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

