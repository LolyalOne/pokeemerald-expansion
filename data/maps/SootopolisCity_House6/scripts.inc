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
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, you want it, but not right now?\n"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pAre you sure?\n"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

