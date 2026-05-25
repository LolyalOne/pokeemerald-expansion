Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, dear, dear.\n"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThat's right.\n"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, dear, dear.\n"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIs that so?\n"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

