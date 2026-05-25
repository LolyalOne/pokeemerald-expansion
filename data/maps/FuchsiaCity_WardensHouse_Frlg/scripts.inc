FuchsiaCity_WardensHouse_Frlg_MapScripts::
	.byte 0

FuchsiaCity_WardensHouse_EventScript_Warden::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM04, FuchsiaCity_WardensHouse_EventScript_ExplainStrength
	goto_if_set FLAG_HIDE_SAFARI_ZONE_WEST_GOLD_TEETH, FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth
	msgbox FuchsiaCity_WardensHouse_Text_HifFuffHefifoo, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, FuchsiaCity_WardensHouse_EventScript_WardenYes
	call_if_eq VAR_RESULT, NO, FuchsiaCity_WardensHouse_EventScript_WardenNo
	release
	end

FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden
	waitmessage
	waitfanfare
	msgbox FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth
	call EventScript_RestorePrevTextColor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, FuchsiaCity_WardensHouse_EventScript_WardenThanksMale
	call_if_eq VAR_RESULT, FEMALE, FuchsiaCity_WardensHouse_EventScript_WardenThanksFemale
	giveitem_msg FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden, ITEM_HM04
	setflag FLAG_GOT_HM04
	removeitem ITEM_GOLD_TEETH
	release
	end

FuchsiaCity_WardensHouse_EventScript_WardenThanksMale::
	msgbox FuchsiaCity_WardensHouse_Text_ThanksSonGiveYouSomething
	return

FuchsiaCity_WardensHouse_EventScript_WardenThanksFemale::
	msgbox FuchsiaCity_WardensHouse_Text_ThanksLassieGiveYouSomething
	return

FuchsiaCity_WardensHouse_EventScript_WardenYes::
	msgbox FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo
	return

FuchsiaCity_WardensHouse_EventScript_WardenNo::
	msgbox FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo
	return

FuchsiaCity_WardensHouse_EventScript_ExplainStrength::
	msgbox FuchsiaCity_WardensHouse_Text_ExplainStrength
	release
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign1::
	msgbox FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign2::
	msgbox FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_Text_HifFuffHefifoo::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWARDEN: Hif fuff hefifoo!\p"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pAh howhee ho hoo!\n"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou.$"

FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHa?\n"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER} gave the GOLD TEETH\n"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth::
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"

FuchsiaCity_WardensHouse_Text_ThanksSonGiveYouSomething::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWARDEN: Thanks, son!\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou.$"

FuchsiaCity_WardensHouse_Text_ThanksLassieGiveYouSomething::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWARDEN: Thank you, lassie!\n"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!$"

FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER} received HM04\n"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

FuchsiaCity_WardensHouse_Text_ExplainStrength::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

@ Unused
FuchsiaCity_WardensHouse_Text_YouHaveTooMuchStuff::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pなんや　にもつ\n"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pPOKeMON photos and fossils are on\n"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOld POKeMON merchandise is on\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

