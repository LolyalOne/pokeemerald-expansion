.set SPOKE_TO_WOMAN_LAST,   FLAG_TEMP_2
.set SPOKE_TO_FAT_MAN_LAST, FLAG_TEMP_3

VermilionCity_PokemonFanClub_Frlg_MapScripts::
	.byte 0

VermilionCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BIKE_VOUCHER, VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory
	msgbox VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_PokemonFanClub_EventScript_ChairmanStory
	msgbox VermilionCity_PokemonFanClub_Text_ComeBackToHearStory
	release
	end

VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory::
	msgbox VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain
	release
	end

VermilionCity_PokemonFanClub_EventScript_ChairmanStory::
	msgbox VermilionCity_PokemonFanClub_Text_ChairmansStory
	checkitemspace ITEM_BIKE_VOUCHER
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher
	setflag FLAG_GOT_BIKE_VOUCHER
	giveitem_msg VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman, ITEM_BIKE_VOUCHER, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher
	release
	end

VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher::
	msgbox VermilionCity_PokemonFanClub_Text_MakeRoomForThis
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear::
	famechecker FAMECHECKER_DAISY, 1
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons
	release
	end

VermilionCity_PokemonFanClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_set SPOKE_TO_FAT_MAN_LAST, VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan
	msgbox VermilionCity_PokemonFanClub_Text_AdoreMySeel
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag SPOKE_TO_WOMAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan::
	msgbox VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag SPOKE_TO_FAT_MAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set SPOKE_TO_WOMAN_LAST, VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman
	msgbox VermilionCity_PokemonFanClub_Text_AdmirePikachusTail
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag SPOKE_TO_FAT_MAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman::
	msgbox VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag SPOKE_TO_WOMAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Pikachu
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Seel
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_EventScript_RulesSign1::
	msgbox VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_EventScript_RulesSign2::
	msgbox VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_Text_AdmirePikachusTail::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWon't you admire my PIKACHU's\n"
	.string "adorable tail?$"

VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHumph!\p"
	.string "My PIKACHU is twice as cute as\n"
	.string "that one!$"

VermilionCity_PokemonFanClub_Text_AdoreMySeel::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI just adore my SEEL!\n"
	.string "It's so lovable!\p"
	.string "It squeals, “Kyuuuh,” when I\n"
	.string "hug it!$"

VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, dear!\p"
	.string "My SEEL is far more attractive.\n"
	.string "By double, I would say.$"

VermilionCity_PokemonFanClub_Text_Pikachu::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pPIKACHU: Chu! Pikachu!$"

VermilionCity_PokemonFanClub_Text_Seel::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pSEEL: Kyuoo!$"

VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI chair the POKéMON Fan Club!\p"
	.string "I raise more than a hundred\n"
	.string "POKéMON!\p"
	.string "I'm very fussy when it comes to\n"
	.string "POKéMON! I surely am!\p"
	.string "So…\p"
	.string "Did you come visit to hear about\n"
	.string "my POKéMON?$"

VermilionCity_PokemonFanClub_Text_ChairmansStory::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pGood!\n"
	.string "Then listen up!\p"
	.string "My favorite RAPIDASH…\p"
	.string "It's…cute…lovely…smart… \n"
	.string "plus…amazing…you think so?…\l"
	.string "oh yes…it's…stunning…\l"
	.string "kindly…love it!\p"
	.string "Hug it…when…sleeping…warm\n"
	.string "and cuddly…spectacular…\l"
	.string "ravishing…\l"
	.string "…Oops! Look at the time!\l"
	.string "I kept you too long!\p"
	.string "Thanks for hearing me out!\n"
	.string "I want you to have this!$"

VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER} received a BIKE VOUCHER\n"
	.string "from the CHAIRMAN.$"

VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher::
	.string "Take that BIKE VOUCHER to the\n"
	.string "BIKE SHOP in CERULEAN CITY.\p"
	.string "Exchange that for a BICYCLE\n"
	.string "free of charge!\p"
	.string "Don't worry, my favorite FEAROW\n"
	.string "will FLY me anywhere I need to go.\p"
	.string "So, I have no need for a BICYCLE.\p"
	.string "I hope you like cycling!$"

VermilionCity_PokemonFanClub_Text_ComeBackToHearStory::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh. Come back when you want to\n"
	.string "hear my story!$"

VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHello, {PLAYER}!\p"
	.string "Did you come see me about my\n"
	.string "POKéMON again?\p"
	.string "No?\n"
	.string "Too bad!$"

VermilionCity_PokemonFanClub_Text_MakeRoomForThis::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pMake room for this!$"

VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOur CHAIRMAN is very vocal about\n"
	.string "POKéMON.$"

VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pLet's all listen politely to other\n"
	.string "TRAINERS!$"

VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIf someone brags, brag right back!$"

VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOur CHAIRMAN really does adore his\n"
	.string "POKéMON.\p"
	.string "But the person who is most liked by\n"
	.string "POKéMON is DAISY, I think.$"
