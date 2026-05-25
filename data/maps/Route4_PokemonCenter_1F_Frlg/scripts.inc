.equ MAGIKARP_PRICE, 500

Route4_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route4_PokemonCenter_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	setrespawn HEAL_LOCATION_ROUTE4
	end

Route4_PokemonCenter_1F_EventScript_Boy::
	msgbox Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_EventScript_Gentleman::
	lock
	msgbox Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean
	release
	end

Route4_PokemonCenter_1F_EventScript_MagikarpSalesman::
	lock
	faceplayer
	goto_if_set FLAG_BOUGHT_MAGIKARP, Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp
	showmoneybox 0, 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpMale
	goto_if_eq VAR_RESULT, FEMALE, Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpFemale
	end

Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpMale::
	msgbox Route4_PokemonCenter_1F_Text_LaddieBuyMagikarpForJust500, MSGBOX_YESNO
	goto Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp
	end

Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpFemale::
	msgbox Route4_PokemonCenter_1F_Text_SweetieBuyMagikarpForJust500, MSGBOX_YESNO
	goto Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp::
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_DeclineMagikarp
	checkmoney MAGIKARP_PRICE
	goto_if_eq VAR_RESULT, FALSE, Route4_PokemonCenter_1F_EventScript_NotEnoughMoney
	textcolor NPC_TEXT_COLOR_NEUTRAL
	setvar VAR_TEMP_1, SPECIES_MAGIKARP
	givemon SPECIES_MAGIKARP, 5
	goto_if_eq VAR_RESULT, 0, Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty
	goto_if_eq VAR_RESULT, 1, Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC
	goto_if_eq VAR_RESULT, 2, Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp
	call Common_EventScript_GetGiftMonPartySlot
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangePokemonNickname
	waitstate
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_TransferMagikarpCloseMoneyBox
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangePokemonNickname
	waitstate
	lock
	faceplayer
	goto Route4_PokemonCenter_1F_EventScript_TransferMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TransferMagikarpCloseMoneyBox::
	call Common_EventScript_TransferredToPC
	goto Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TransferMagikarp::
	call Common_EventScript_TransferredToPC
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp::
	hidemoneybox
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BoughtMagikarp::
	setflag FLAG_BOUGHT_MAGIKARP
	release
	end

Route4_PokemonCenter_1F_EventScript_PayForMagikarp::
	removemoney MAGIKARP_PRICE
	updatemoneybox
	playfanfare MUS_LEVEL_UP
	message Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKARP
	return

Route4_PokemonCenter_1F_EventScript_DeclineMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_NotEnoughMoney::
	msgbox Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_IDontGiveRefunds
	release
	end

Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

Route4_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_EventScript_Newspaper::
	lock
	msgbox Route4_PokemonCenter_1F_Text_ItsANewspaper
	release
	end

Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOkay, set six POKe BALLS in my\n"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pTEAM ROCKET attacks CERULEAN\n"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

Route4_PokemonCenter_1F_Text_LaddieBuyMagikarpForJust500::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pMAN: Hello there, laddie!\n"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

Route4_PokemonCenter_1F_Text_SweetieBuyMagikarpForJust500::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMAN: Hello there, sweetie pie!\n"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p{PLAYER} paid an outrageous ¥500\n"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pNo? You say no? I'm only doing this\n"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThere's no more room for any more\n"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney::
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

Route4_PokemonCenter_1F_Text_IDontGiveRefunds::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMAN: Well, I don't give refunds.\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"

Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC::
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

Route4_PokemonCenter_1F_Text_ItsANewspaper::
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

