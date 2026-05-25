SaffronCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
	.byte 0

SaffronCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SAFFRON_CITY
	call_if_unset FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_MoveDoorGuardGrunt
	end

SaffronCity_EventScript_MoveDoorGuardGrunt::
	setobjectxyperm LOCALID_SAFFRON_DOOR_GUARD_GRUNT, 33, 31
	return

SaffronCity_EventScript_RocketGrunt1::
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt2::
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt3::
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt4::
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt5::
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt6::
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt7::
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
	end

SaffronCity_EventScript_DoorGuardGrunt::
	lock
	goto_if_set FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_DoorGuardAsleep
	applymovement LOCALID_SAFFRON_DOOR_GUARD_GRUNT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SaffronCity_Text_ImASecurityGuard
	release
	end

SaffronCity_EventScript_DoorGuardAsleep::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox SaffronCity_Text_HesTakingASnooze
	release
	end

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster::
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass::
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
	end

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
	end

SaffronCity_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_Text_Pidgeot
	waitmoncry
	release
	end

SaffronCity_EventScript_Man::
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
	end

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_SABRINA, 0
	msgbox SaffronCity_Text_GymSign
	releaseall
	end

SaffronCity_EventScript_TrainerTips1::
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerTips2::
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicsHouseSign::
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphProductSign::
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerFanClubSign::
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

SaffronCity_Text_WhatDoYouWantGetLost::
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!$"

SaffronCity_Text_BossTakeTownForTeamRocket::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pBOSS said he'll take this town\n"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SaffronCity_Text_DontGetDefiantOrIllHurtYou::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDon't get defiant!\n"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

SaffronCity_Text_SaffronBelongsToTeamRocket::
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

SaffronCity_Text_CriminalLifeMakesMeFeelAlive::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pMy life as a criminal makes me feel\n"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

SaffronCity_Text_WatchWhereYoureWalking::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOw!\n"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

SaffronCity_Text_WeCanExploitMonsAroundWorld::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWith SILPH under control, we can\n"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

SaffronCity_Text_YouBeatTeamRocket::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYou beat TEAM ROCKET all alone?\n"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

SaffronCity_Text_SafeToGoOutAgain::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pYeah! TEAM ROCKET is gone!\n"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!$"

SaffronCity_Text_PeopleComingBackToSaffron::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pPeople fled from here in droves\n"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SaffronCity_Text_FlewHereOnPidgeot::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI flew here on my PIDGEOT when\n"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"

SaffronCity_Text_Pidgeot::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

SaffronCity_Text_SawRocketBossEscaping::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI saw the ROCKET BOSS escaping\n"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

SaffronCity_Text_ImASecurityGuard::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI'm a security guard.\p"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

SaffronCity_Text_HesTakingASnooze::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p...\n"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

SaffronCity_Text_CitySign::
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

SaffronCity_Text_FightingDojo::
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SaffronCity_Text_GymSign::
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

SaffronCity_Text_FullHealCuresStatus::
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

SaffronCity_Text_GreatBallImprovedCatchRate::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pTRAINER TIPS\p"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"

SaffronCity_Text_SilphCoSign::
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SaffronCity_Text_MrPsychicsHouse::
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

SaffronCity_Text_SilphsLatestProduct::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pSILPH's latest product!\n"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

SaffronCity_Text_TrainerFanClubSign::
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

SaffronCity_Text_HowCanClubNotRecognizeLance::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThis FAN CLUB...\n"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

