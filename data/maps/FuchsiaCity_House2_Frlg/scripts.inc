FuchsiaCity_House2_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_FishingGurusBrother::
	lock
	faceplayer
	goto_if_set FLAG_GOT_GOOD_ROD, FuchsiaCity_House2_EventScript_AlreadyGotGoodRod
	msgbox FuchsiaCity_House2_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House2_EventScript_GiveGoodRod
	msgbox FuchsiaCity_House2_Text_OhThatsDisappointing
	release
	end

FuchsiaCity_House2_EventScript_AlreadyGotGoodRod::
	msgbox FuchsiaCity_House2_Text_HowAreTheFishBiting
	release
	end

FuchsiaCity_House2_EventScript_GiveGoodRod::
	msgbox FuchsiaCity_House2_Text_LikeYourStyleTakeThis
	checkitemspace ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_House2_EventScript_NoRoomForGoodRod
	giveitem_msg FuchsiaCity_House2_Text_ReceivedGoodRod, ITEM_GOOD_ROD
	msgbox FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons
	setflag FLAG_GOT_GOOD_ROD
	release
	end

FuchsiaCity_House2_EventScript_NoRoomForGoodRod::
	msgbox FuchsiaCity_House2_Text_YouHaveNoRoomForGift
	release
	end

FuchsiaCity_House2_Text_DoYouLikeToFish::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI'm the FISHING GURU's older\n"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

FuchsiaCity_House2_Text_LikeYourStyleTakeThis::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pGrand! I like your style.\n"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!$"

FuchsiaCity_House2_Text_ReceivedGoodRod::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER} received a GOOD ROD from\n"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pFishing is a way of life!\n"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!$"

FuchsiaCity_House2_Text_OhThatsDisappointing::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh...\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"

FuchsiaCity_House2_Text_HowAreTheFishBiting::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHello there, {PLAYER}!\p"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

FuchsiaCity_House2_Text_YouHaveNoRoomForGift::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, no!\p"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

