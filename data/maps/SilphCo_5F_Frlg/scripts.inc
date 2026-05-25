SilphCo_5F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_5F_OnLoad
	.byte 0

SilphCo_5F_OnLoad::
	call_if_unset FLAG_SILPH_5F_DOOR_1, EventScript_Close5FDoor1
	call_if_unset FLAG_SILPH_5F_DOOR_2, EventScript_Close5FDoor2
	call_if_unset FLAG_SILPH_5F_DOOR_3, EventScript_Close5FDoor3
	end

SilphCo_5F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_5F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_5F_Text_RocketsInUproarAboutIntruder
	release
	end

SilphCo_5F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_5F_Text_YoureOurHeroThankYou
	release
	end

SilphCo_5F_EventScript_PokemonReport1::
	msgbox SilphCo_5F_Text_PorygonFirstVRMon, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport2::
	msgbox SilphCo_5F_Text_Over350TechniquesConfirmed, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport3::
	msgbox SilphCo_5F_Text_SomeMonsEvolveWhenTraded, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_FloorSign::
	msgbox SilphCo_5F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_Beau::
	trainerbattle_single TRAINER_SCIENTIST_BEAU, SilphCo_5F_Text_BeauIntro, SilphCo_5F_Text_BeauDefeat
	msgbox SilphCo_5F_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_28, SilphCo_5F_Text_Grunt1Intro, SilphCo_5F_Text_Grunt1Defeat
	msgbox SilphCo_5F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_29, SilphCo_5F_Text_Grunt2Intro, SilphCo_5F_Text_Grunt2Defeat
	msgbox SilphCo_5F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Dalton::
	trainerbattle_single TRAINER_JUGGLER_DALTON, SilphCo_5F_Text_DaltonIntro, SilphCo_5F_Text_DaltonDefeat
	msgbox SilphCo_5F_Text_DaltonPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_Text_RocketsInUproarAboutIntruder::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pTEAM ROCKET is in an uproar over\n"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

SilphCo_5F_Text_YoureOurHeroThankYou::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pTEAM ROCKET took off!\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

SilphCo_5F_Text_Grunt1Intro::
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

SilphCo_5F_Text_Grunt1Defeat::
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

SilphCo_5F_Text_Grunt1PostBattle::
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

SilphCo_5F_Text_BeauIntro::
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

SilphCo_5F_Text_BeauDefeat::
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SilphCo_5F_Text_BeauPostBattle::
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

SilphCo_5F_Text_DaltonIntro::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

SilphCo_5F_Text_DaltonDefeat::
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

SilphCo_5F_Text_DaltonPostBattle::
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SilphCo_5F_Text_Grunt2Intro::
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

SilphCo_5F_Text_Grunt2Defeat::
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

SilphCo_5F_Text_Grunt2PostBattle::
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

SilphCo_5F_Text_PorygonFirstVRMon::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt's a POKeMON REPORT!\p"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

SilphCo_5F_Text_Over350TechniquesConfirmed::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt's a POKeMON REPORT!\p"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

SilphCo_5F_Text_SomeMonsEvolveWhenTraded::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt's a POKeMON REPORT!\p"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

SilphCo_5F_Text_FloorSign::
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

SilphCo_5F_Text_RocketBossLookingForStrongMons::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThose thugs that took over our\n"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"
