SaffronCity_Gym_Frlg_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Sabrina::
	famechecker FAMECHECKER_SABRINA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_SabrinaIntro, SaffronCity_Gym_Text_SabrinaDefeat, SaffronCity_Gym_EventScript_DefeatedSabrina, NO_MUSIC
	goto_if_unset FLAG_GOT_TM04_FROM_SABRINA, SaffronCity_Gym_EventScript_GiveTM04
	msgbox SaffronCity_Gym_Text_ExplainTM04
	release
	end

SaffronCity_Gym_EventScript_DefeatedSabrina::
	famechecker FAMECHECKER_SABRINA, 2
	famechecker FAMECHECKER_SABRINA, 3
	clearflag FLAG_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS
	setflag FLAG_DEFEATED_SABRINA
	setflag FLAG_BADGE06_GET
	set_gym_trainers_frlg 6
	goto SaffronCity_Gym_EventScript_GiveTM04
	end

SaffronCity_Gym_EventScript_GiveTM04::
	msgbox SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis
	checkitemspace ITEM_TM04
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_NoRoomForTM04
	giveitem_msg SaffronCity_Gym_Text_ReceivedTM04FromSabrina, ITEM_TM04
	setflag FLAG_GOT_TM04_FROM_SABRINA
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle
	release
	end

SaffronCity_Gym_EventScript_NoRoomForTM04::
	msgbox SaffronCity_Gym_Text_BagFullOfOtherItems
	release
	end

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
	famechecker FAMECHECKER_SABRINA, 5
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SABRINA, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice
	release
	end

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory
	release
	end

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SaffronCity_Gym_Text_SabrinaIntro::
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

SaffronCity_Gym_Text_SabrinaDefeat::
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

SaffronCity_Gym_Text_SabrinaPostBattle::
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis::
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

SaffronCity_Gym_Text_ReceivedTM04FromSabrina::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER} received TM04 from\n"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou.$"

SaffronCity_Gym_Text_ExplainTM04::
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

SaffronCity_Gym_Text_BagFullOfOtherItems::
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

SaffronCity_Gym_Text_AmandaIntro::
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

SaffronCity_Gym_Text_AmandaDefeat::
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

SaffronCity_Gym_Text_AmandaPostBattle::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

SaffronCity_Gym_Text_JohanIntro::
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"

SaffronCity_Gym_Text_JohanDefeat::
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

SaffronCity_Gym_Text_JohanPostBattle::
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

SaffronCity_Gym_Text_StacyIntro::
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

SaffronCity_Gym_Text_StacyDefeat::
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

SaffronCity_Gym_Text_StacyPostBattle::
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!$"

SaffronCity_Gym_Text_TyronIntro::
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

SaffronCity_Gym_Text_TyronDefeat::
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

SaffronCity_Gym_Text_TyronPostBattle::
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SaffronCity_Gym_Text_TashaIntro::
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

SaffronCity_Gym_Text_TashaDefeat::
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

SaffronCity_Gym_Text_TashaPostBattle::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!$"

SaffronCity_Gym_Text_CameronIntro::
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

SaffronCity_Gym_Text_CameronDefeat::
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SaffronCity_Gym_Text_CameronPostBattle::
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

SaffronCity_Gym_Text_PrestonIntro::
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

SaffronCity_Gym_Text_PrestonDefeat::
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SaffronCity_Gym_Text_PrestonPostBattle::
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!$"

SaffronCity_Gym_Text_GymGuyAdvice::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pYo!\n"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

SaffronCity_Gym_Text_GymGuyPostVictory::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pPsychic power, huh?\p"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

SaffronCity_Gym_Text_GymStatue::
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

