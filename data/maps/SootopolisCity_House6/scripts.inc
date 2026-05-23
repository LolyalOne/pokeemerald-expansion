SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHello! You're our first guest in\n"
	.string "a good while.\p"
	.string "You've brightened up my day, so I'll\n"
	.string "give you a big WAILMER DOLL.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pTake good care of it!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, you want it, but not right now?\n"
	.string "Okay, then I'll hold it for you.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pAre you sure?\n"
	.string "You don't want this DOLL?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI love plush DOLLS!$"

