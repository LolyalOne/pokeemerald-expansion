SixIsland_PatternBush_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_PatternBush_OnTransition
	.byte 0

SixIsland_PatternBush_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_PATTERN_BUSH
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_ge VAR_TEMP_1, 50, SixIsland_PatternBush_EventScript_SetEscapeRightExit
	call_if_le VAR_TEMP_1, 49, SixIsland_PatternBush_EventScript_SetEscapeLeftExit
	end

SixIsland_PatternBush_EventScript_SetEscapeRightExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 64, 10
	return

SixIsland_PatternBush_EventScript_SetEscapeLeftExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 45, 10
	return

SixIsland_PatternBush_EventScript_Bethany::
	trainerbattle_single TRAINER_PKMN_BREEDER_BETHANY, SixIsland_PatternBush_Text_BethanyIntro, SixIsland_PatternBush_Text_BethanyDefeat
	msgbox SixIsland_PatternBush_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Allison::
	trainerbattle_single TRAINER_PKMN_BREEDER_ALLISON, SixIsland_PatternBush_Text_AllisonIntro, SixIsland_PatternBush_Text_AllisonDefeat
	msgbox SixIsland_PatternBush_Text_AllisonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Garret::
	trainerbattle_single TRAINER_BUG_CATCHER_GARRET, SixIsland_PatternBush_Text_GarretIntro, SixIsland_PatternBush_Text_GarretDefeat
	msgbox SixIsland_PatternBush_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Jonah::
	trainerbattle_single TRAINER_BUG_CATCHER_JONAH, SixIsland_PatternBush_Text_JonahIntro, SixIsland_PatternBush_Text_JonahDefeat
	msgbox SixIsland_PatternBush_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Vance::
	trainerbattle_single TRAINER_BUG_CATCHER_VANCE, SixIsland_PatternBush_Text_VanceIntro, SixIsland_PatternBush_Text_VanceDefeat
	msgbox SixIsland_PatternBush_Text_VancePostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Nash::
	trainerbattle_single TRAINER_YOUNGSTER_NASH, SixIsland_PatternBush_Text_NashIntro, SixIsland_PatternBush_Text_NashDefeat
	msgbox SixIsland_PatternBush_Text_NashPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Cordell::
	trainerbattle_single TRAINER_YOUNGSTER_CORDELL, SixIsland_PatternBush_Text_CordellIntro, SixIsland_PatternBush_Text_CordellDefeat
	msgbox SixIsland_PatternBush_Text_CordellPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Dalia::
	trainerbattle_single TRAINER_LASS_DALIA, SixIsland_PatternBush_Text_DaliaIntro, SixIsland_PatternBush_Text_DaliaDefeat
	msgbox SixIsland_PatternBush_Text_DaliaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Joana::
	trainerbattle_single TRAINER_LASS_JOANA, SixIsland_PatternBush_Text_JoanaIntro, SixIsland_PatternBush_Text_JoanaDefeat
	msgbox SixIsland_PatternBush_Text_JoanaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Riley::
	trainerbattle_single TRAINER_CAMPER_RILEY, SixIsland_PatternBush_Text_RileyIntro, SixIsland_PatternBush_Text_RileyDefeat
	msgbox SixIsland_PatternBush_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Marcy::
	trainerbattle_single TRAINER_PICNICKER_MARCY, SixIsland_PatternBush_Text_MarcyIntro, SixIsland_PatternBush_Text_MarcyDefeat
	msgbox SixIsland_PatternBush_Text_MarcyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Layton::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAYTON, SixIsland_PatternBush_Text_LaytonIntro, SixIsland_PatternBush_Text_LaytonDefeat
	msgbox SixIsland_PatternBush_Text_LaytonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_Text_BethanyIntro::
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

SixIsland_PatternBush_Text_BethanyDefeat::
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

SixIsland_PatternBush_Text_BethanyPostBattle::
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

SixIsland_PatternBush_Text_AllisonIntro::
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!$"

SixIsland_PatternBush_Text_AllisonDefeat::
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

SixIsland_PatternBush_Text_AllisonPostBattle::
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

SixIsland_PatternBush_Text_GarretIntro::
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

SixIsland_PatternBush_Text_GarretDefeat::
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

SixIsland_PatternBush_Text_GarretPostBattle::
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

SixIsland_PatternBush_Text_JonahIntro::
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!$"

SixIsland_PatternBush_Text_JonahDefeat::
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!$"

SixIsland_PatternBush_Text_JonahPostBattle::
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

SixIsland_PatternBush_Text_VanceIntro::
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

SixIsland_PatternBush_Text_VanceDefeat::
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

SixIsland_PatternBush_Text_VancePostBattle::
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

SixIsland_PatternBush_Text_NashIntro::
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

SixIsland_PatternBush_Text_NashDefeat::
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

SixIsland_PatternBush_Text_NashPostBattle::
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

SixIsland_PatternBush_Text_CordellIntro::
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

SixIsland_PatternBush_Text_CordellDefeat::
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

SixIsland_PatternBush_Text_CordellPostBattle::
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

SixIsland_PatternBush_Text_DaliaIntro::
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SixIsland_PatternBush_Text_DaliaDefeat::
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

SixIsland_PatternBush_Text_DaliaPostBattle::
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SixIsland_PatternBush_Text_JoanaIntro::
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

SixIsland_PatternBush_Text_JoanaDefeat::
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

SixIsland_PatternBush_Text_JoanaPostBattle::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

SixIsland_PatternBush_Text_RileyIntro::
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

SixIsland_PatternBush_Text_RileyDefeat::
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

SixIsland_PatternBush_Text_RileyPostBattle::
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!$"

SixIsland_PatternBush_Text_MarcyIntro::
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SixIsland_PatternBush_Text_MarcyDefeat::
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

SixIsland_PatternBush_Text_MarcyPostBattle::
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

SixIsland_PatternBush_Text_LaytonIntro::
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou.$"

SixIsland_PatternBush_Text_LaytonDefeat::
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

SixIsland_PatternBush_Text_LaytonPostBattle::
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

