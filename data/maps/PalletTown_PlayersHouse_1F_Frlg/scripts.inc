PalletTown_PlayersHouse_1F_Frlg_MapScripts::
	.byte 0

PalletTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_RIVAL_IN_OAKS_LAB, PalletTown_PlayersHouse_1F_EventScript_MomHeal
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale
	closemessage
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
	release
	end

@ Displays special text if interacted with from side or back (which are normally inaccessible)
PalletTown_PlayersHouse_1F_EventScript_TV::
	lockall
	goto_if_eq VAR_FACING, DIR_NORTH, PalletTown_PlayersHouse_1F_EventScript_TVScreen
	msgbox PalletTown_PlayersHouse_1F_Text_OopsWrongSide
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreen::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreenMale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad
	return

PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad
	return

PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou::
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou::
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest::
	.string "MOM: {PLAYER}!\n"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad::
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

PalletTown_PlayersHouse_1F_Text_OopsWrongSide::
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"
