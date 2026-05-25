SilphCo_8F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_8F_OnLoad
	.byte 0

SilphCo_8F_OnLoad::
	call_if_unset FLAG_SILPH_8F_DOOR, EventScript_Close8FDoor
	end

SilphCo_8F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_8F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_8F_Text_WonderIfSilphIsFinished
	release
	end

SilphCo_8F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_8F_Text_ThanksForSavingUs
	release
	end

SilphCo_8F_EventScript_FloorSign::
	msgbox SilphCo_8F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_8F_EventScript_Parker::
	trainerbattle_single TRAINER_SCIENTIST_PARKER, SilphCo_8F_Text_ParkerIntro, SilphCo_8F_Text_ParkerDefeat
	msgbox SilphCo_8F_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_32, SilphCo_8F_Text_Grunt1Intro, SilphCo_8F_Text_Grunt1Defeat
	msgbox SilphCo_8F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_36, SilphCo_8F_Text_Grunt2Intro, SilphCo_8F_Text_Grunt2Defeat
	msgbox SilphCo_8F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_Text_WonderIfSilphIsFinished::
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"

SilphCo_8F_Text_ThanksForSavingUs::
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

SilphCo_8F_Text_Grunt1Intro::
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou.$"

SilphCo_8F_Text_Grunt1Defeat::
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

SilphCo_8F_Text_Grunt1PostBattle::
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

SilphCo_8F_Text_ParkerIntro::
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

SilphCo_8F_Text_ParkerDefeat::
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

SilphCo_8F_Text_ParkerPostBattle::
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!$"

SilphCo_8F_Text_Grunt2Intro::
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

SilphCo_8F_Text_Grunt2Defeat::
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

SilphCo_8F_Text_Grunt2PostBattle::
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

SilphCo_8F_Text_FloorSign::
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

SilphCo_8F_Text_ToRocketBossMonsAreTools::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pTEAM ROCKET's BOSS is terribly\n"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"
