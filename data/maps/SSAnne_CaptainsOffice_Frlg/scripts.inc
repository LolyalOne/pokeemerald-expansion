SSAnne_CaptainsOffice_Frlg_MapScripts::
	.byte 0

SSAnne_CaptainsOffice_EventScript_Captain::
	lock
	goto_if_set FLAG_GOT_HM01, SSAnne_CaptainsOffice_EventScript_AlreadyGotCut
	msgbox SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message SSAnne_CaptainsOffice_Text_RubbedCaptainsBack
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	call EventScript_RestorePrevTextColor
	delay 50
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut
	giveitem_msg SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain, ITEM_HM01, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox SSAnne_CaptainsOffice_Text_ExplainCut
	setflag FLAG_GOT_HM01
	setvar VAR_MAP_SCENE_VERMILION_CITY, 1
	release
	end

@ Unused
SSAnne_CaptainsOffice_EventScript_NoRoomForCut::
	msgbox SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis
	closemessage
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SSAnne_CaptainsOffice_EventScript_AlreadyGotCut::
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon
	release
	end

SSAnne_CaptainsOffice_EventScript_TrashCan::
	msgbox SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_EventScript_Book::
	msgbox SSAnne_CaptainsOffice_Text_HowToConquerSeasickness, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pCAPTAIN: Ooargh...\n"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

SSAnne_CaptainsOffice_Text_RubbedCaptainsBack::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER} rubbed the CAPTAIN's\n"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pCAPTAIN: Whew! Thank you!\n"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p{PLAYER} obtained HM01\n"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!$"

SSAnne_CaptainsOffice_Text_ExplainCut::
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pCAPTAIN: ...Whew!\p"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh, no!\n"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!$"

SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pYuck!\n"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!$"

SSAnne_CaptainsOffice_Text_HowToConquerSeasickness::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHow to Conquer Seasickness...\n"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

