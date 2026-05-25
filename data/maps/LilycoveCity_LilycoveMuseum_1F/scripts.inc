LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_MUSEUM_1F_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_1F_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_MUSEUM_1F_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MUSEUM_1F_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWelcome to LILYCOVE MUSEUM.\p"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI'm the CURATOR of this MUSEUM of\n"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pAh, then let me not disturb you.\n"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh? I do believe that you seem to\n"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI see...\p"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pAh, excellent!\n"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt's a very old painting.\n"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIt's an odd landscape with bizarre\n"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt's a painting of a beautiful, smiling\n"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIt's a painting of a legendary POKeMON\n"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt's a painting of GRASS POKeMON\n"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt's a delicious-looking painting\n"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt's a replica of a famous sculpture.\p"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt's a big POKe BALL carved from\n"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt's a huge stone tablet inscribed\n"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHmmm...\n"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pBattling with POKeMON is fun,\n"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThis ART MUSEUM... Well, you could\n"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThis lady is pretty!\n"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThis POKeMON is adorable!\n"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI'd heard that this ART MUSEUM got\n"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pLately, the CURATOR has been\n"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI aim to see many great paintings\n"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThe ART MUSEUM has become a favorite\n"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

