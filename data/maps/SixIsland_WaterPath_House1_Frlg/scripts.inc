SixIsland_WaterPath_House1_Frlg_MapScripts::
	.byte 0

SixIsland_WaterPath_House1_EventScript_Beauty::
	lock
	faceplayer
	setvar VAR_0x8004, SPECIES_HERACROSS
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, SixIsland_WaterPath_House1_EventScript_NoHeracrossInParty
	special GetHeracrossSizeRecordInfo
	msgbox SixIsland_WaterPath_House1_Text_MayIMeasureHeracross
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, SixIsland_WaterPath_House1_EventScript_DontShowMon
	special CompareHeracrossSize
	goto_if_eq VAR_RESULT, 1, SixIsland_WaterPath_House1_EventScript_ShownNonHeracross
	goto_if_eq VAR_RESULT, 2, SixIsland_WaterPath_House1_EventScript_ShownSmallHeracross
	goto_if_eq VAR_RESULT, 3, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	goto_if_eq VAR_RESULT, 4, SixIsland_WaterPath_House1_EventScript_ShownTiedHeracross
	release
	end

SixIsland_WaterPath_House1_EventScript_NoHeracrossInParty::
	msgbox SixIsland_WaterPath_House1_Text_LoveItNeedItHeracross
	release
	end

SixIsland_WaterPath_House1_EventScript_DontShowMon::
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownNonHeracross::
	msgbox SixIsland_WaterPath_House1_Text_ThisWontDo
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownSmallHeracross::
	goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	msgbox SixIsland_WaterPath_House1_Text_ItsXInchesYInchesWasBiggest
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownTiedHeracross::
	goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	msgbox SixIsland_WaterPath_House1_Text_ItsXInchesSameAsBefore
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownBigHeracross::
	setflag FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1
	msgbox SixIsland_WaterPath_House1_Text_ItsXInchesDeserveReward
	giveitem ITEM_NEST_BALL
	goto_if_eq VAR_RESULT, FALSE, SixIsland_WaterPath_House1_EventScript_NoRoomForNestBall
	msgbox SixIsland_WaterPath_House1_Text_WantToSeeBiggerOne
	release
	end

SixIsland_WaterPath_House1_EventScript_NoRoomForNestBall::
	msgbox SixIsland_WaterPath_House1_Text_YourBagIsFull
	release
	end

SixIsland_WaterPath_House1_EventScript_SizeRecord::
	lockall
	goto_if_set FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_SizeRecordNonEmpty
	msgbox SixIsland_WaterPath_House1_Text_BlankChartOfSomeSort
	releaseall
	end

SixIsland_WaterPath_House1_EventScript_SizeRecordNonEmpty::
	special GetHeracrossSizeRecordInfo
	msgbox SixIsland_WaterPath_House1_Text_BiggestHeracrossIsXInches
	releaseall
	end

SixIsland_WaterPath_House1_Text_LoveItNeedItHeracross::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHera, hera, HERACROSS!\n"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

SixIsland_WaterPath_House1_Text_MayIMeasureHeracross::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pEeeeek!\n"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

SixIsland_WaterPath_House1_Text_ItsXInchesDeserveReward::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pEeeek, it's {STR_VAR_2} inches!\n"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

SixIsland_WaterPath_House1_Text_WantToSeeBiggerOne::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI want to see a much, much bigger\n"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

SixIsland_WaterPath_House1_Text_ItsXInchesSameAsBefore::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHuh? This {STR_VAR_2}-inch measurement...\n"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

SixIsland_WaterPath_House1_Text_ItsXInchesYInchesWasBiggest::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh, it's just {STR_VAR_2} inches.\n"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
	.string "It was {STR_VAR_3} inches, the biggest\n"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

SixIsland_WaterPath_House1_Text_ThisWontDo::
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!$"

SixIsland_WaterPath_House1_Text_YourBagIsFull::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYour BAG is full.\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

SixIsland_WaterPath_House1_Text_BiggestHeracrossIsXInches::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThe biggest HERACROSS that I have\n"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

SixIsland_WaterPath_House1_Text_BlankChartOfSomeSort::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt's a blank chart of some sort.\p"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

