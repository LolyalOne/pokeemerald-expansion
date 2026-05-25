BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} doesn't have the TICKET...\p"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} flashed the TICKET.\p"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou.$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

