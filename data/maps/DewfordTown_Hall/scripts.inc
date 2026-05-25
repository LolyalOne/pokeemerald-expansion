DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhat's in vogue? Why, it has to be\n"
	.string "“{STR_VAR_1}”!\p"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWhat's in vogue? Why, it has to be\n"
	.string "“{STR_VAR_1}”!\p"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI'm teaching my POKeMON about\n"
	.string "“{STR_VAR_1},”\l"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI'm studying up on the hip and trendy\n"
	.string "“{STR_VAR_1}” now.\p"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
	.string "between “{STR_VAR_1}”\l"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh!\n"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWhat?!\n"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThis whole business about\n"
	.string "“{STR_VAR_1}”...\l"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pAcross the sea...\p"
	.string "Is “{STR_VAR_1}”\n"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI collect official\n"
	.string "“{STR_VAR_1}”\l"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "“{STR_VAR_1}” DOLLS...\p"
	.string "Official “{STR_VAR_1}”\n"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "“{STR_VAR_1}”\l"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIDENTIFYING GOOD\n"
	.string "“{STR_VAR_1}” &\l"
	.string "BAD “{STR_VAR_1}”...\p"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "“{STR_VAR_1}” AND\l"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
	.string "“{STR_VAR_1}”...\p"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

DewfordTown_Hall_Text_TrendsScream:
	.string "Parabens, Lucas! Que sua jornada seja epica.\p“{STR_VAR_1}'S\n"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "Parabens, Lucas! Que sua jornada seja epica.\p“{STR_VAR_1}'S\n"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

DewfordTown_Hall_Text_LastTrend:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt's titled “THE LAST\n"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt's titled “THE BIRTH OF\n"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI saw “{STR_VAR_1}”!\n"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh, no, no, no.\p"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "“{STR_VAR_1}”\l"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHey, listen, I composed a theme song\n"
	.string "for “{STR_VAR_1}.”\p"
	.string "“{STR_VAR_1}”\n"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "{STR_VAR_1}!\p"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p... ...\p"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou.$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pAnyway, as I was saying earlier, we\n"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
	.string "“{STR_VAR_1}” party\l"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, a smashing good idea!\p"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "“{STR_VAR_1}.”\l"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI was thinking, though...\p"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
	.string "“{STR_VAR_1}” has\l"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pBeg pardon?\n"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "“{STR_VAR_1}”\l"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
	.string "“{STR_VAR_1}”\l"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIf you and me team up as a combo,\n"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pSpot on, my friend!\p"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "“{STR_VAR_1}” DUO!\p"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pFor me, SLUDGE BOMB is at the peak\n"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI love SLUDGE BOMB.\p"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "“{STR_VAR_1}”\l"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

