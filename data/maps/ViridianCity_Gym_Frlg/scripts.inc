ViridianCity_Gym_Frlg_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Giovanni::
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni, NO_MUSIC
	goto_if_unset FLAG_GOT_TM26_FROM_GIOVANNI, ViridianCity_Gym_EventScript_GiveTM26
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VIRIDIAN_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	famechecker FAMECHECKER_GIOVANNI, 3
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_DEFEATED_LEADER_GIOVANNI
	setflag FLAG_BADGE08_GET
	setvar VAR_MAP_SCENE_ROUTE22, 3
	set_gym_trainers_frlg 8
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	checkitemspace ITEM_TM26
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_Gym_EventScript_NoRoomForTM26
	giveitem_msg ViridianCity_Gym_Text_ReceivedTM26FromGiovanni, ITEM_TM26
	setflag FLAG_GOT_TM26_FROM_GIOVANNI
	msgbox ViridianCity_Gym_Text_ExplainTM26
	release
	end

ViridianCity_Gym_EventScript_NoRoomForTM26::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace
	release
	end

ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	famechecker FAMECHECKER_GIOVANNI, 4
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GiovanniIntro::
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

ViridianCity_Gym_Text_GiovanniDefeat::
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

ViridianCity_Gym_Text_GiovanniPostBattle::
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis::
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

ViridianCity_Gym_Text_ReceivedTM26FromGiovanni::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER} received TM26\n"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

ViridianCity_Gym_Text_ExplainTM26::
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

ViridianCity_Gym_Text_YouDoNotHaveSpace::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

ViridianCity_Gym_Text_YujiIntro::
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

ViridianCity_Gym_Text_YujiDefeat::
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

ViridianCity_Gym_Text_YujiPostBattle::
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

ViridianCity_Gym_Text_AtsushiIntro::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

ViridianCity_Gym_Text_AtsushiDefeat::
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

ViridianCity_Gym_Text_AtsushiPostBattle::
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

ViridianCity_Gym_Text_JasonIntro::
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou.$"

ViridianCity_Gym_Text_JasonDefeat::
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

ViridianCity_Gym_Text_JasonPostBattle::
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!$"

ViridianCity_Gym_Text_KiyoIntro::
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

ViridianCity_Gym_Text_KiyoDefeat::
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

ViridianCity_Gym_Text_KiyoPostBattle::
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

ViridianCity_Gym_Text_WarrenIntro::
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

ViridianCity_Gym_Text_WarrenDefeat::
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

ViridianCity_Gym_Text_WarrenPostBattle::
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

ViridianCity_Gym_Text_TakashiIntro::
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

ViridianCity_Gym_Text_TakashiDefeat::
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

ViridianCity_Gym_Text_TakashiPostBattle::
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

ViridianCity_Gym_Text_ColeIntro::
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

ViridianCity_Gym_Text_ColeDefeat::
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

ViridianCity_Gym_Text_ColePostBattle::
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

ViridianCity_Gym_Text_SamuelIntro::
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

ViridianCity_Gym_Text_SamuelDefeat::
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

ViridianCity_Gym_Text_SamuelPostBattle::
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

ViridianCity_Gym_Text_GymGuyAdvice::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYo!\n"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

ViridianCity_Gym_Text_GymGuyPostVictory::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pBlow me away! GIOVANNI was the\n"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

ViridianCity_Gym_Text_GymStatue::
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

