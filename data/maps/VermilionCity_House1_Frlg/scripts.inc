VermilionCity_House1_Frlg_MapScripts::
	.byte 0

VermilionCity_House1_EventScript_FishingGuru::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_ROD, VermilionCity_House1_EventScript_AlreadyGotOldRod
	msgbox VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_House1_EventScript_GiveOldRod
	msgbox VermilionCity_House1_Text_OhThatsSoDisappointing
	release
	end

VermilionCity_House1_EventScript_AlreadyGotOldRod::
	msgbox VermilionCity_House1_Text_HowAreTheFishBiting
	release
	end

VermilionCity_House1_EventScript_GiveOldRod::
	checkitemspace ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_House1_EventScript_NoRoomForOldRod
	additem ITEM_OLD_ROD
	msgbox VermilionCity_House1_Text_TakeThisAndFish
	msgreceiveditem VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru, ITEM_OLD_ROD
	setflag FLAG_GOT_OLD_ROD
	msgbox VermilionCity_House1_Text_FishingIsAWayOfLife
	release
	end

VermilionCity_House1_EventScript_NoRoomForOldRod::
	msgbox VermilionCity_House1_Text_NoRoomForNiceGift
	release
	end

VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI'm the FISHING GURU!\p"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

VermilionCity_House1_Text_TakeThisAndFish::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pGrand! I like your style.\n"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER} received an OLD ROD from\n"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!$"

VermilionCity_House1_Text_FishingIsAWayOfLife::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pFishing is a way of life!\n"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!$"

VermilionCity_House1_Text_OhThatsSoDisappointing::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh...\n"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

VermilionCity_House1_Text_HowAreTheFishBiting::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pHello there, {PLAYER}!\p"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

VermilionCity_House1_Text_NoRoomForNiceGift::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, no!\p"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

