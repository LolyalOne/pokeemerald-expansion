FuchsiaCity_House3_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House3_EventScript_MoveDeleter::
	lock
	faceplayer
	msgbox FuchsiaCity_House3_Text_WouldYouLikeToForgetMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
	goto FuchsiaCity_House3_EventScript_CancelForgetMove
	end

FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter::
	msgbox FuchsiaCity_House3_Text_WhichMonShouldForgetMove
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, FuchsiaCity_House3_EventScript_CancelForgetMove
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_House3_EventScript_CantForgetMoveEgg
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_House3_EventScript_CantForgetOnlyMove
	msgbox FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House3_EventScript_ForgetMove
	goto FuchsiaCity_House3_EventScript_CancelForgetMove
	end

FuchsiaCity_House3_EventScript_ForgetMove::
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely
	release
	end

FuchsiaCity_House3_EventScript_CantForgetOnlyMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonOnlyKnowsOneMove
	release
	end

FuchsiaCity_House3_EventScript_CantForgetMoveEgg::
	msgbox FuchsiaCity_House3_Text_NoEggShouldKnowMoves
	release
	end

FuchsiaCity_House3_EventScript_CancelForgetMove::
	msgbox FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves
	release
	end

FuchsiaCity_House3_Text_WouldYouLikeToForgetMove::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pUh...\n"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!$"

FuchsiaCity_House3_Text_WhichMonShouldForgetMove::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWhich POKeMON should forget a\n"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten::
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

FuchsiaCity_House3_Text_MonOnlyKnowsOneMove::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{STR_VAR_1} seems to know only one\n"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!$"

FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIt worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!$"

FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pCome again if there are other\n"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

FuchsiaCity_House3_Text_NoEggShouldKnowMoves::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhat?\n"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

