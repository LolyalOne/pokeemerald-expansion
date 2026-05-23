LilycoveCity_MoveDeletersHouse_MapScripts::
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	chooseboxmon SELECT_PC_MON_MOVE_DELETER
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain::
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pUh…\n"
	.string "Oh, yes, I'm the MOVE DELETER.\p"
	.string "I can make POKéMON forget their moves.\p"
	.string "Would you like me to do that?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhich POKéMON should forget a move?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhich move should be forgotten?$"

LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

LilycoveCity_MoveDeletersHouse_Text_ComeAgain:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pCome again if there are moves that\n"
	.string "need to be forgotten.$"

LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhat?\n"
	.string "No EGG should know any moves.$"

LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pHm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget SURF.$"

