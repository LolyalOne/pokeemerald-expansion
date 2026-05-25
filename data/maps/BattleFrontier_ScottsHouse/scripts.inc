BattleFrontier_ScottsHouse_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
	.string "Anyway, {PLAYER}{KUN}, let me formally\n"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
	.string "{PLAYER}{KUN}, I want you to have this\n"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
	.string "{PLAYER} obtained\n"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "{PLAYER}, you've got to accept this!\p"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

