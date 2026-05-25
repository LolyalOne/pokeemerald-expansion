SilphCo_10F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_10F_OnLoad
	.byte 0

SilphCo_10F_OnLoad::
	call_if_unset FLAG_SILPH_10F_DOOR, EventScript_Close10FDoor
	end

SilphCo_10F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_10F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_10F_Text_WaaaImScared
	release
	end

SilphCo_10F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_10F_Text_KeepMeCryingASecret
	release
	end

SilphCo_10F_EventScript_FloorSign::
	msgbox SilphCo_10F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_10F_EventScript_Travis::
	trainerbattle_single TRAINER_SCIENTIST_TRAVIS, SilphCo_10F_Text_TravisIntro, SilphCo_10F_Text_TravisDefeat
	msgbox SilphCo_10F_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_39, SilphCo_10F_Text_GruntIntro, SilphCo_10F_Text_GruntDefeat
	msgbox SilphCo_10F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_Text_GruntIntro::
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

SilphCo_10F_Text_GruntDefeat::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"

SilphCo_10F_Text_GruntPostBattle::
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

SilphCo_10F_Text_TravisIntro::
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

SilphCo_10F_Text_TravisDefeat::
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

SilphCo_10F_Text_TravisPostBattle::
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

SilphCo_10F_Text_WaaaImScared::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWaaaaa!\n"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

SilphCo_10F_Text_KeepMeCryingASecret::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pAbout me crying...\n"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!$"

SilphCo_10F_Text_FloorSign::
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

