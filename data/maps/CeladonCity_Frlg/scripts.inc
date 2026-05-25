CeladonCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	.byte 0

CeladonCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CELADON_CITY
	end

CeladonCity_EventScript_LittleGirl::
	msgbox CeladonCity_Text_GotMyKoffingInCinnabar, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1::
	lock
	msgbox CeladonCity_Text_GymIsGreatFullOfWomen
	release
	end

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan2::
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_EventScript_SoftboiledTutor::
	goto EventScript_SoftboiledTutor
	end

CeladonCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
	closemessage
	applymovement LOCALID_CELADON_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath
	closemessage
	waitmoncry
	applymovement LOCALID_CELADON_POLIWRATH, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_RocketGrunt1::
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
	end

CeladonCity_EventScript_RocketGrunt2::
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
	end

CeladonCity_EventScript_Boy::
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
	end

CeladonCity_EventScript_SilphCoScientist::
	msgbox CeladonCity_Text_SomeoneStoleSilphScope, MSGBOX_NPC
	end

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
	end

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_ERIKA, 0
	msgbox CeladonCity_Text_GymSign
	releaseall
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
	end

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_Text_GotMyKoffingInCinnabar::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI got my KOFFING in CINNABAR.\p"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

CeladonCity_Text_GymIsGreatFullOfWomen::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHeheh! This GYM is great!\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

CeladonCity_Text_GameCornerIsBadForCitysImage::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pCELADON takes pride in its efforts\n"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

CeladonCity_Text_BlewItAllAtSlots::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMoan...\n"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

CeladonCity_Text_MyTrustedPalPoliwrath::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThis is my trusted pal, POLIWRATH.\p"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

CeladonCity_Text_Poliwrath::
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

CeladonCity_Text_GetLostOrIllPunchYou::
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

CeladonCity_Text_KeepOutOfTeamRocketsWay::
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

CeladonCity_Text_ExplainXAccuracyDireHit::
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

CeladonCity_Text_CitySign::
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

CeladonCity_Text_GymSign::
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

CeladonCity_Text_MansionSign::
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

CeladonCity_Text_DeptStoreSign::
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

CeladonCity_Text_GuardSpecProtectsFromStatus::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pTRAINER TIPS\p"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

CeladonCity_Text_PrizeExchangeSign::
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

CeladonCity_Text_GameCornerSign::
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

CeladonCity_Text_ScaldedTongueOnTea::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pAaaagh, ow...\n"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

Text_SoftboiledTeach::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHello, there!\p"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!$"

Text_SoftboiledDeclined::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI'll always be keeping an eye out\n"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

Text_SoftboiledWhichMon::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pSo, who's the POKeMON that gets\n"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

Text_SoftboiledTaught::
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

CeladonCity_Text_SomeoneStoleSilphScope::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, what am I to do...\p"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

