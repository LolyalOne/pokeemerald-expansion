CeruleanCity_Gym_Frlg_MapScripts::
	.byte 0

CeruleanCity_Gym_EventScript_Misty::
	famechecker FAMECHECKER_MISTY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_MistyDefeated, NO_MUSIC
	goto_if_unset FLAG_GOT_TM03_FROM_MISTY, CeruleanCity_Gym_EventScript_GiveTM03
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_MistyDefeated::
	famechecker FAMECHECKER_MISTY, 1
	setflag FLAG_DEFEATED_MISTY
	setflag FLAG_BADGE02_GET
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	set_gym_trainers_frlg 2
	goto CeruleanCity_Gym_EventScript_GiveTM03
	end

CeruleanCity_Gym_EventScript_GiveTM03::
	msgbox CeruleanCity_Gym_Text_ExplainCascadeBadge
	checkitemspace ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_NoRoomForTM03
	giveitem_msg CeruleanCity_Gym_Text_ReceivedTM03FromMisty, ITEM_TM03
	setflag FLAG_GOT_TM03_FROM_MISTY
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_NoRoomForTM03::
	msgbox CeruleanCity_Gym_Text_BetterMakeRoomForThis
	release
	end

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
	msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
	famechecker FAMECHECKER_MISTY, 2
	msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MISTY, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice
	release
	end

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam
	release
	end

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanCity_Gym_Text_MistyIntro::
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

CeruleanCity_Gym_Text_ExplainTM03::
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

CeruleanCity_Gym_Text_ExplainCascadeBadge::
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

CeruleanCity_Gym_Text_ReceivedTM03FromMisty::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p{PLAYER} received TM03\n"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

CeruleanCity_Gym_Text_BetterMakeRoomForThis::
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

CeruleanCity_Gym_Text_MistyDefeat::
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

CeruleanCity_Gym_Text_DianaIntro::
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

CeruleanCity_Gym_Text_DianaDefeat::
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

CeruleanCity_Gym_Text_DianaPostBattle::
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

CeruleanCity_Gym_Text_LuisIntro::
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!$"

CeruleanCity_Gym_Text_LuisDefeat::
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

CeruleanCity_Gym_Text_LuisPostBattle::
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou.$"

CeruleanCity_Gym_Text_GymGuyAdvice::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pYo!\n"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYou beat MISTY!\n"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

CeruleanCity_Gym_Text_GymStatue::
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

