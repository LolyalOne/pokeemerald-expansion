LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
	.string "raising POKeMON properly, {PLAYER}{KUN}.\p"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pMAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

LilycoveCity_Text_MayBattleMe:
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

LilycoveCity_Text_MayWontBeBeaten:
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

LilycoveCity_Text_MayDefeat:
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMAY: I'm thinking of going back to\n"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER}{KUN}, what are you going to do?\p"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER}{KUN}, what are you going to do?\p"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, what are you going to do?\p"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pBRENDAN: Oh, what's the matter?\n"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

LilycoveCity_Text_BrendanBattleMe:
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

LilycoveCity_Text_BrendanWontBeBeaten:
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

LilycoveCity_Text_BrendanDefeat:
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pBRENDAN: I...\n"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER}, what are you going to do?\p"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER}, what are you going to do?\p"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
	.string "you, {PLAYER}.\p"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, what are you going to do?\p"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
	.string "I'll get stronger than you, {PLAYER}.\p"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pFufufu...\p"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI'm just a GRUNT, so I don't know what\n"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pHey, you!\p"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIf this whole wide world becomes ours,\n"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThere! WAILMER!\n"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

LilycoveCity_Text_GetLostMessingUpTraining:
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

LilycoveCity_Text_ContestHallInTown:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThere's a POKeMON CONTEST HALL\n"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHave you seen that strange cave in\n"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI'm going to teach my POKeMON some new\n"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

LilycoveCity_Text_ImFromKanto:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI came from KANTO.\p"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pTEAM AQUA's been training their\n"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pAhoy, did you know?\p"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI was taking a relaxing snooze at the\n"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pMy missing POKeMON...\n"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

LilycoveCity_Text_ImArtDealer:
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pEven as we grow old and wrinkled,\n"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt was sixty years ago that my husband\n"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHm, you know of the peculiar cavern\n"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThat cave in the cove...\p"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

LilycoveCity_Text_CitySign:
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

LilycoveCity_Text_ContestHallSign:
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

LilycoveCity_Text_MotelSign:
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!$"

LilycoveCity_Text_MuseumSign:
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
	.string "“{PLAYER}'s POKeMON Collection\n"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

LilycoveCity_Text_HarborSignUnderConstruction:
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!$"

LilycoveCity_Text_HarborSign:
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

LilycoveCity_Text_TrainerFanClubSign:
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

LilycoveCity_Text_DepartmentStoreSign:
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

LilycoveCity_Text_MoveDeletersHouseSign:
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDo you know about the machine\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pPeople have to work together to get it\n"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

LilycoveCity_Text_ExplainBerryBlender:
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
	.string "called a {POKEBLOCK}.\p"
	.string "If you give a good {POKEBLOCK} to a POKeMON,\n"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI heard there's a tower somewhere out\n"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI saw this tall tower somewhere\n"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWe just arrived here on our\n"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOn our honeymoon, we vowed to see as\n"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

