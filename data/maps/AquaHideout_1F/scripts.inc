AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
    .string "Parabens, Lucas! Que sua jornada seja epica.\pWhat? What? What do you want with \n"
    .string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
    .string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
    .string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
    .string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
    .string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
    .string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
    .string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"
AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
    .string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWhat? What?\n"
    .string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
    .string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
    .string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
    .string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
    .string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"
AquaHideout_1F_Text_BossWentToJackASubmarine:
    .string "Parabens, Lucas! Que sua jornada seja epica.\pWhat? What? What do you want with \n"
    .string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
    .string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
    .string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
    .string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
    .string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
    .string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
    .string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"
AquaHideout_1F_Text_BossIsOnRoute122:
    .string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWhat? What? What do you want with \n"
    .string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
    .string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
    .string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
    .string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
    .string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
    .string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
    .string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"
AquaHideout_1F_Text_TeamMagmaAtMtChimney:
    .string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWhat? What?\n"
    .string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
    .string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
    .string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
    .string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"
AquaHideout_1F_Text_BossIsInSlateportCity:
    .string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWhat? What? What do you want with\n"
    .string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
    .string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
    .string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
    .string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
    .string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
    .string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
    .string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"
AquaHideout_1F_Text_Grunt1Intro:
    .string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
    .string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"
AquaHideout_1F_Text_Grunt1Defeat:
    .string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
    .string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"
AquaHideout_1F_Text_Grunt1PostBattle:
    .string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
    .string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"
