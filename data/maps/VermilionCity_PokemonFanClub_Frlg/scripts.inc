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
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHumph!\p"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

VermilionCity_PokemonFanClub_Text_AdoreMySeel::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI just adore my SEEL!\n"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, dear!\p"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

VermilionCity_PokemonFanClub_Text_Pikachu::
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

VermilionCity_PokemonFanClub_Text_Seel::
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI chair the POKeMON Fan Club!\p"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

VermilionCity_PokemonFanClub_Text_ChairmansStory::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pGood!\n"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER} received a BIKE VOUCHER\n"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher::
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

VermilionCity_PokemonFanClub_Text_ComeBackToHearStory::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh. Come back when you want to\n"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!$"

VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHello, {PLAYER}!\p"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

VermilionCity_PokemonFanClub_Text_MakeRoomForThis::
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOur CHAIRMAN is very vocal about\n"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pLet's all listen politely to other\n"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!$"

VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack::
.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOur CHAIRMAN really does adore his\n"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!$"
