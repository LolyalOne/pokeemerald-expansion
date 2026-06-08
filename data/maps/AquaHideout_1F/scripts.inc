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

AquaHideout_1F_Text_Grunt1Intro:
	.string "O que? O que? O que voce quer com o\n"
	.string "TEAM AQUA?\p"
	.string "Nosso CHEFE nao esta aqui! Ele saiu para\n"
	.string "roubar algo muito importante!\p"
	.string "... ...\n"
	.string "Pra onde ele foi?\p"
	.string "Wahaha! Voce acha mesmo que eu diria\n"
	.string "algo tao crucial? Nem se fosse seu\l"
	.string "aniversario, Lucas! Oh... espera...$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "O que? O que?\n"
	.string "Voce e um recruta do TEAM MAGMA?\p"
	.string "Ouvi dizer que o TEAM MAGMA esta\n"
	.string "tentando despertar um POKeMON\l"
	.string "incrivel no ESCONDERIJO deles.\p"
	.string "Mas onde sera que fica esse\n"
	.string "ESCONDERIJO? Talvez voce devesse\l"
	.string "pedir de presente, Lucas!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "O que? O que? O que voce quer com o\n"
	.string "TEAM AQUA?\p"
	.string "Nosso CHEFE nao esta aqui!\n"
	.string "Ele saiu para roubar um submarino!\p"
	.string "... ...\n"
	.string "Pra onde ele foi?\p"
	.string "Wahaha! Voce acha mesmo que eu diria\n"
	.string "algo tao crucial? Aproveite sua\l"
	.string "festa enquanto pode, Lucas!$"

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "What? What? What do you want with\n"
	.string "TEAM AQUA?\p"
	.string "Our BOSS isn't here! He's on his way to\n"
	.string "MT. PYRE on ROUTE 122!\p"
	.string "… …\n"
	.string "Why did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "What? What?\n"
	.string "Are you a TEAM MAGMA grunt?\p"
	.string "Ouvi que o TEAM MAGMA esta atras\n"
	.string "an awesome POKeMON at MT. CHIMNEY.\p"
	.string "Mas como e esse POKeMON?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "What? What? What do you want with\n"
	.string "TEAM AQUA?\p"
	.string "Our BOSS isn't here!\n"
	.string "He's on his way to SLATEPORT CITY!\p"
	.string "… …\n"
	.string "Why did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "What? What? What do you want with\n"
	.string "TEAM AQUA?\p"
	.string "Our BOSS isn't here! He's on his way to\n"
	.string "MT. PYRE on ROUTE 122!\p"
	.string "… …\n"
	.string "Why did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "What? What?\n"
	.string "Are you a TEAM MAGMA grunt?\p"
	.string "Ouvi que o TEAM MAGMA esta atras\n"
	.string "an awesome POKeMON at MT. CHIMNEY.\p"
	.string "Mas como e esse POKeMON?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "What? What? What do you want with\n"
	.string "TEAM AQUA?\p"
	.string "Our BOSS isn't here!\n"
	.string "He's on his way to SLATEPORT CITY!\p"
	.string "… …\n"
	.string "Why did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"
