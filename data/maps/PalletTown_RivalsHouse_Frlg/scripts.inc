.equ RECEIVED_TOWN_MAP, VAR_TEMP_1

PalletTown_RivalsHouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
	.byte 0

PalletTown_RivalsHouse_OnTransition::
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap
	end

PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	return

PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap::
	setvar RECEIVED_TOWN_MAP, TRUE
	return

PalletTown_RivalsHouse_EventScript_Daisy::
	lock
	faceplayer
	famechecker FAMECHECKER_DAISY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
	goto_if_eq RECEIVED_TOWN_MAP, TRUE, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_ExplainTownMap
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_GiveTownMap
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_RivalsHouse_EventScript_HeardBattledRival
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab
	closemessage
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_RivalsHouse_EventScript_HeardBattledRival::
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival
	release
	end

PalletTown_RivalsHouse_EventScript_GroomMon::
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500, PalletTown_RivalsHouse_EventScript_RateMonFriendship
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone
	release
	end

PalletTown_RivalsHouse_EventScript_CantGroomEgg::
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg
	release
	end

PalletTown_RivalsHouse_EventScript_DeclineGrooming::
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_EventScript_RateMonFriendship::
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon
	specialvar VAR_RESULT, GetLeadMonFriendship
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore
	release
	end

PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest
	release
	end

PalletTown_RivalsHouse_EventScript_GiveTownMap::
	msgbox PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp
	closemessage
	checkitemspace ITEM_TOWN_MAP
	goto_if_eq VAR_RESULT, FALSE, PalletTown_RivalsHouse_EventScript_NoRoomForTownMap
	applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	removeobject LOCALID_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	delay 15
	applymovement LOCALID_DAISY, Common_Movement_FacePlayer
	waitmovement 0
	delay 12
	giveitem_msg PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy, ITEM_TOWN_MAP, 1, MUS_RG_OBTAIN_KEY_ITEM
	release
	end

PalletTown_RivalsHouse_EventScript_NoRoomForTownMap::
	msgbox PalletTown_RivalsHouse_Text_DontHaveSpaceForThis
	release
	end

PalletTown_RivalsHouse_EventScript_ExplainTownMap::
	msgbox PalletTown_RivalsHouse_Text_ExplainTownMap
	release
	end

PalletTown_RivalsHouse_EventScript_TownMap::
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
	end

PalletTown_RivalsHouse_EventScript_Bookshelf::
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_EventScript_Picture::
	msgbox PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_HiBrothersAtLab::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDAISY: Hi, {PLAYER}!\p"
	.string "My brother, {RIVAL}, is out at\n"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

PalletTown_RivalsHouse_Text_HeardYouBattledRival::
	.string "DAISY: {PLAYER}, I heard you had\n"
	.string "a battle against {RIVAL}.\p"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pGrandpa asked you to run an\n"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER} received a TOWN MAP\n"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

PalletTown_RivalsHouse_Text_DontHaveSpaceForThis::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYou don't have space for this in\n"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

PalletTown_RivalsHouse_Text_ExplainTownMap::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

PalletTown_RivalsHouse_Text_PleaseGiveMonsRest::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pDAISY: Just like people, POKeMON\n"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

PalletTown_RivalsHouse_Text_ItsBigMapOfKanto::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt's a big map of the KANTO region.\n"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThe shelves are crammed full of\n"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

PalletTown_RivalsHouse_Text_LikeMeToGroomMon::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pDAISY: Hi, {PLAYER}!\n"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

PalletTown_RivalsHouse_Text_DontNeedAnyGrooming::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYou don't need any grooming done?\n"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

PalletTown_RivalsHouse_Text_GroomWhichOne::
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

PalletTown_RivalsHouse_Text_LookingNiceInNoTime::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDAISY: Okay, I'll get it looking\n"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!$"

PalletTown_RivalsHouse_Text_ThereYouGoAllDone::
#ifdef BUGFIX @ The localizers missed what should be a textcolor change in the localizations.
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{COLOR DARK_GRAY}{STR_VAR_1} looks dreamily content...\p"
	.string "{COLOR RED}DAISY: There you go! All done.\n"
#else @ In the JP games, gender-based text used a different font instead of different colors.
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{FONT_NORMAL}{STR_VAR_1} looks dreamily content...\p"
	.string "{FONT_FEMALE}DAISY: There you go! All done.\n"
#endif
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pSee? Doesn't it look nice?\p"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

PalletTown_RivalsHouse_Text_CantGroomAnEgg::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh, sorry. I honestly can't\n"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

PalletTown_RivalsHouse_Text_MayISeeFirstMon::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDAISY: Your POKeMON grow to love\n"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "For example, {PLAYER}, may I see\n"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"

PalletTown_RivalsHouse_Text_CouldntLoveYouMore::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt couldn't possibly love you\n"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

PalletTown_RivalsHouse_Text_ItLooksVeryHappy::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIt looks very happy.\p"
	.string "I wish {RIVAL} could see this and\n"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

PalletTown_RivalsHouse_Text_ItsQuiteFriendly::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt's quite friendly with you.\n"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

PalletTown_RivalsHouse_Text_ItsWarmingUpToYou::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt's warming up to you.\n"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt's not quite familiar with you\n"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!$"

PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER}, I don't like the way it\n"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p...Um, it's not easy for me to say\n"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p“The lovely and sweet\n"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

