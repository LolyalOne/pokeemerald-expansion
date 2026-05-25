Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWhile I was sleeping, everyone went\n"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWow, you're really strong!\p"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThe PROFESSOR loves rain.\n"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOn the 2nd floor of the INSTITUTE,\n"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHello!\n"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThere's a bed...\n"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

