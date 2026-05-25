Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMy big brother's the FOSSIL MANIAC...\n"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIf you make a POKeMON DIG inside a\n"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pRocks in peculiar shapes fill\n"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pTHE COMPOSITION OF STRATA...\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

