CeladonCity_Gym_Frlg_MapScripts::
	.byte 0

CeladonCity_Gym_EventScript_Erika::
	famechecker FAMECHECKER_ERIKA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_ERIKA, CeladonCity_Gym_Text_ErikaIntro, CeladonCity_Gym_Text_ErikaDefeat, CeladonCity_Gym_EventScript_DefeatedErika, NO_MUSIC
	goto_if_unset FLAG_GOT_TM19_FROM_ERIKA, CeladonCity_Gym_EventScript_GiveTM19
	famechecker FAMECHECKER_ERIKA, 4
	msgbox CeladonCity_Gym_Text_ErikaPostBattle
	release
	end

CeladonCity_Gym_EventScript_DefeatedErika::
	famechecker FAMECHECKER_ERIKA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_ERIKA_JOURNALS
	setflag FLAG_DEFEATED_ERIKA
	setflag FLAG_BADGE04_GET
	set_gym_trainers_frlg 4
	goto CeladonCity_Gym_EventScript_GiveTM19
	end

CeladonCity_Gym_EventScript_GiveTM19::
	msgbox CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis
	checkitemspace ITEM_TM19
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_NoRoomForTM19
	giveitem_msg CeladonCity_Gym_Text_ReceivedTM19FromErika, ITEM_TM19
	setflag FLAG_GOT_TM19_FROM_ERIKA
	msgbox CeladonCity_Gym_Text_ExplainTM19
	release
	end

CeladonCity_Gym_EventScript_NoRoomForTM19::
	msgbox CeladonCity_Gym_Text_ShouldMakeRoomForThis
	release
	end

CeladonCity_Gym_EventScript_Kay::
	trainerbattle_single TRAINER_LASS_KAY, CeladonCity_Gym_Text_KayIntro, CeladonCity_Gym_Text_KayDefeat
	msgbox CeladonCity_Gym_Text_KayPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lisa::
	trainerbattle_single TRAINER_LASS_LISA, CeladonCity_Gym_Text_LisaIntro, CeladonCity_Gym_Text_LisaDefeat
	famechecker FAMECHECKER_ERIKA, 2
	msgbox CeladonCity_Gym_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tina::
	trainerbattle_single TRAINER_PICNICKER_TINA, CeladonCity_Gym_Text_TinaIntro, CeladonCity_Gym_Text_TinaDefeat
	msgbox CeladonCity_Gym_Text_TinaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetIntro, CeladonCity_Gym_Text_BridgetDefeat
	msgbox CeladonCity_Gym_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tamia::
	trainerbattle_single TRAINER_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaIntro, CeladonCity_Gym_Text_TamiaDefeat
	famechecker FAMECHECKER_ERIKA, 3
	msgbox CeladonCity_Gym_Text_TamiaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lori::
	trainerbattle_single TRAINER_BEAUTY_LORI, CeladonCity_Gym_Text_LoriIntro, CeladonCity_Gym_Text_LoriDefeat
	msgbox CeladonCity_Gym_Text_LoriPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_COOLTRAINER_MARY, CeladonCity_Gym_Text_MaryIntro, CeladonCity_Gym_Text_MaryDefeat
	msgbox CeladonCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_ErikaIntro::
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

CeladonCity_Gym_Text_ErikaDefeat::
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

CeladonCity_Gym_Text_ErikaPostBattle::
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis::
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

CeladonCity_Gym_Text_ReceivedTM19FromErika::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER} received TM19\n"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

CeladonCity_Gym_Text_ExplainTM19::
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

CeladonCity_Gym_Text_ShouldMakeRoomForThis::
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"

CeladonCity_Gym_Text_KayIntro::
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

CeladonCity_Gym_Text_KayDefeat::
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!$"

CeladonCity_Gym_Text_KayPostBattle::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

CeladonCity_Gym_Text_BridgetIntro::
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou.$"

CeladonCity_Gym_Text_BridgetDefeat::
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

CeladonCity_Gym_Text_BridgetPostBattle::
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

CeladonCity_Gym_Text_TinaIntro::
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

CeladonCity_Gym_Text_TinaDefeat::
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!$"

CeladonCity_Gym_Text_TinaPostBattle::
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

CeladonCity_Gym_Text_TamiaIntro::
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

CeladonCity_Gym_Text_TamiaDefeat::
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

CeladonCity_Gym_Text_TamiaPostBattle::
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

CeladonCity_Gym_Text_LisaIntro::
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

CeladonCity_Gym_Text_LisaDefeat::
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

CeladonCity_Gym_Text_LisaPostBattle::
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

CeladonCity_Gym_Text_LoriIntro::
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

CeladonCity_Gym_Text_LoriDefeat::
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

CeladonCity_Gym_Text_LoriPostBattle::
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

CeladonCity_Gym_Text_MaryIntro::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

CeladonCity_Gym_Text_MaryDefeat::
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

CeladonCity_Gym_Text_MaryPostBattle::
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

CeladonCity_Gym_Text_GymStatue::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

