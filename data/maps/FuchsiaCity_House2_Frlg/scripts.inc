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
	.string "brother.\p"
	.string "I simply looove fishing!\n"
	.string "I can't bear to go without.\p"
	.string "Tell me, do you like to fish?$"

FuchsiaCity_House2_Text_LikeYourStyleTakeThis::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pGrand! I like your style.\n"
	.string "I think we can be friends.\p"
	.string "Take this and fish, young friend!$"

FuchsiaCity_House2_Text_ReceivedGoodRod::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER} received a GOOD ROD from\n"
	.string "the FISHING GURU's brother.$"

FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pFishing is a way of life!\n"
	.string "It is like the finest poetry.\p"
	.string "A crummy OLD ROD could only catch\n"
	.string "MAGIKARP, yes?\p"
	.string "But with a GOOD ROD, you can\n"
	.string "catch much better POKéMON.$"

FuchsiaCity_House2_Text_OhThatsDisappointing::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh…\n"
	.string "That's so disappointing…$"

FuchsiaCity_House2_Text_HowAreTheFishBiting::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHello there, {PLAYER}!\p"
	.string "How are the fish biting?$"

FuchsiaCity_House2_Text_YouHaveNoRoomForGift::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, no!\p"
	.string "I had a gift for you, but you have\n"
	.string "no room for it!$"

