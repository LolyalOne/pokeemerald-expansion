.equ SHOWN_REQUESTED_MON, FLAG_TEMP_2

FiveIsland_ResortGorgeous_House_Frlg_MapScripts::
	.byte 0

FiveIsland_ResortGorgeous_House_EventScript_Selphy::
	lock
	faceplayer
	goto_if_set SHOWN_REQUESTED_MON, FiveIsland_ResortGorgeous_House_EventScript_JustFulfilledRequest
	goto_if_eq VAR_RESORT_GORGEOUS_REQUESTED_MON, 0xFFFF, FiveIsland_ResortGorgeous_House_EventScript_RequestTookTooLong
	goto_if_ne VAR_RESORT_GORGEOUS_REQUESTED_MON, SPECIES_NONE, FiveIsland_ResortGorgeous_House_EventScript_CheckForRequestedMon
	msgbox FiveIsland_ResortGorgeous_House_Text_PleaseHearMyWish
	goto FiveIsland_ResortGorgeous_House_EventScript_RequestMon
	end

FiveIsland_ResortGorgeous_House_EventScript_RequestMon::
	special SampleResortGorgeousMonAndReward
	msgbox FiveIsland_ResortGorgeous_House_Text_WishToSeeMonPlease
	release
	end

FiveIsland_ResortGorgeous_House_EventScript_RequestTookTooLong::
	msgbox FiveIsland_ResortGorgeous_House_Text_OhImTiredOfWaiting
	goto FiveIsland_ResortGorgeous_House_EventScript_RequestMon
	end

FiveIsland_ResortGorgeous_House_EventScript_CheckForRequestedMon::
	copyvar VAR_0x8004, VAR_RESORT_GORGEOUS_REQUESTED_MON
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_ResortGorgeous_House_EventScript_ShowRequestedMon
	goto FiveIsland_ResortGorgeous_House_EventScript_RequestMon
	end

FiveIsland_ResortGorgeous_House_EventScript_ShowRequestedMon::
	special SampleResortGorgeousMonAndReward
	msgbox FiveIsland_ResortGorgeous_House_Text_MonYouCaughtForMeThankYou
	addobject LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerEnter
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FiveIsland_ResortGorgeous_House_Text_ButlerYesMyLady
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_SELPHY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FiveIsland_ResortGorgeous_House_Text_SelphyGiveTokenOfAppreciation
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FiveIsland_ResortGorgeous_House_Text_ButlerIShallDoAsYouBid
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerSouth
	call_if_eq VAR_FACING, DIR_EAST, FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerEast
	call_if_eq VAR_FACING, DIR_WEST, FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerWest
	copyobjectxytoperm LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER
	msgbox FiveIsland_ResortGorgeous_House_Text_ButlerPleaseAcceptThisAsHerThanks
	giveitem VAR_RESORT_GORGEOUS_REWARD
	goto_if_eq VAR_RESULT, FALSE, FiveIsland_ResortGorgeous_House_EventScript_NoRoomForReward
	setflag SHOWN_REQUESTED_MON
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, SPECIES_NONE
	release
	end

FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerNorth::
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_SELPHY, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerNorth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerSouth::
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerSouth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerEast::
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_SELPHY, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerEast
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerWest::
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerWest
	waitmovement 0
	return

FiveIsland_ResortGorgeous_House_EventScript_NoRoomForReward::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FiveIsland_ResortGorgeous_House_Text_ButlerBagAppearsToBeFull
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FiveIsland_ResortGorgeous_House_Text_OhHowDisappointing
	setflag SHOWN_REQUESTED_MON
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, SPECIES_NONE
	release
	end

FiveIsland_ResortGorgeous_House_EventScript_JustFulfilledRequest::
	msgbox FiveIsland_ResortGorgeous_House_Text_SelphyWishYouBestOfLuck
	release
	end

FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerNorth::
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerSouth::
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerEast::
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

@ Very odd. If the player is talking to Selphy facing West, then the player has clipped through the table
@ In this case rather than approach the player the Butler walks up, which clips the Butler into a wall
FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerWest::
	walk_up
	step_end

FiveIsland_ResortGorgeous_House_Movement_ButlerEnter::
	walk_in_place_down
	step_end

@ Addressed as "Sebastian" but speaks only as "Butler"
FiveIsland_ResortGorgeous_House_EventScript_Butler::
	msgbox FiveIsland_ResortGorgeous_House_Text_LadySelphySmileHasBrillianceOfSun, MSGBOX_NPC
	end

FiveIsland_ResortGorgeous_House_Text_PleaseHearMyWish::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pSELPHY: Oh?\n"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

FiveIsland_ResortGorgeous_House_Text_WishToSeeMonPlease::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI wish to see a POKeMON.\n"
	.string "A darling {STR_VAR_1}.\p"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

FiveIsland_ResortGorgeous_House_Text_OhImTiredOfWaiting::
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

FiveIsland_ResortGorgeous_House_Text_MonYouCaughtForMeThankYou::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pSELPHY: Oh, hello, there.\p"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "{STR_VAR_1} you caught for me.\p"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

FiveIsland_ResortGorgeous_House_Text_ButlerYesMyLady::
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

FiveIsland_ResortGorgeous_House_Text_SelphyGiveTokenOfAppreciation::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pSELPHY: See to it that this person\n"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

FiveIsland_ResortGorgeous_House_Text_ButlerIShallDoAsYouBid::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pButler: I shall do as you bid,\n"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

FiveIsland_ResortGorgeous_House_Text_ButlerPleaseAcceptThisAsHerThanks::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pButler: I sincerely thank you for\n"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

FiveIsland_ResortGorgeous_House_Text_ButlerBagAppearsToBeFull::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pButler: Your BAG appears to be\n"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

FiveIsland_ResortGorgeous_House_Text_OhHowDisappointing::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh...\n"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

FiveIsland_ResortGorgeous_House_Text_SelphyWishYouBestOfLuck::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pSELPHY: I wish you the best of\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

FiveIsland_ResortGorgeous_House_Text_LadySelphySmileHasBrillianceOfSun::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pButler: The smile of Lady SELPHY\n"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

