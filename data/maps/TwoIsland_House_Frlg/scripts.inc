.equ CHECKED_MUSHROOMS,  FLAG_TEMP_1
.equ HAS_BIG_MUSHROOM,   FLAG_TEMP_2
.equ HAS_TINY_MUSHROOMS, FLAG_TEMP_3
.equ HAS_BOTH_MUSHROOMS, FLAG_TEMP_4

TwoIsland_House_Frlg_MapScripts::
	.byte 0

TwoIsland_House_EventScript_MoveManiac::
	lock
	faceplayer
	clearflag HAS_BIG_MUSHROOM
	clearflag HAS_TINY_MUSHROOMS
	clearflag HAS_BOTH_MUSHROOMS
	goto_if_set CHECKED_MUSHROOMS, TwoIsland_House_EventScript_CheckPlayerHasMushrooms
	msgbox TwoIsland_House_Text_TeachMonMoveForMushroom
	setflag CHECKED_MUSHROOMS
	goto TwoIsland_House_EventScript_CheckPlayerHasMushrooms
	end

TwoIsland_House_EventScript_CheckPlayerHasMushrooms::
	checkitem ITEM_BIG_MUSHROOM
	call_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_SetHasBigMushroom
	checkitem ITEM_TINY_MUSHROOM, 2
	call_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_SetHasTinyMushrooms
	goto_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_CheckAlsoHasTinyMushrooms
	goto_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_CheckAlsoHasBigMushroom
	goto TwoIsland_House_EventScript_EndTutorMove
	end

TwoIsland_House_EventScript_CheckAlsoHasTinyMushrooms::
	call_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_SetHasBothMushrooms
	goto TwoIsland_House_EventScript_AskTutorMon
	end

TwoIsland_House_EventScript_CheckAlsoHasBigMushroom::
	call_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_SetHasBothMushrooms
	goto TwoIsland_House_EventScript_AskTutorMon
	end

TwoIsland_House_EventScript_AskTutorMon::
	msgbox TwoIsland_House_Text_WantMeToTeachMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TwoIsland_House_EventScript_EndTutorMove
	goto TwoIsland_House_EventScript_ChooseMonToTutor
	end

TwoIsland_House_EventScript_ChooseMonToTutor::
	msgbox TwoIsland_House_Text_TutorWhichMon
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, TwoIsland_House_EventScript_EndTutorMove
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_CantTutorEgg
	goto_if_eq VAR_0x8005, 0, TwoIsland_House_EventScript_NoMoveToTutorMon
	goto TwoIsland_House_EventScript_ChooseMoveToTeach
	end

TwoIsland_House_EventScript_ChooseMoveToTeach::
	msgbox TwoIsland_House_Text_TeachWhichMove
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, TwoIsland_House_EventScript_ChooseMonToTutor
	goto_if_set HAS_BOTH_MUSHROOMS, TwoIsland_House_EventScript_ChooseMushroom
	goto_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_GiveBigMushroom
	goto_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_GiveTinyMushrooms
	end

TwoIsland_House_EventScript_GiveBigMushroom::
	removeitem ITEM_BIG_MUSHROOM
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox TwoIsland_House_Text_HandedOverOneBigMushroom
	call EventScript_RestorePrevTextColor
	goto TwoIsland_House_EventScript_EndTutorMove
	end

TwoIsland_House_EventScript_GiveTinyMushrooms::
	removeitem ITEM_TINY_MUSHROOM, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox TwoIsland_House_Text_HandedOverTwoTinyMushrooms
	call EventScript_RestorePrevTextColor
	goto TwoIsland_House_EventScript_EndTutorMove
	end

TwoIsland_House_EventScript_ChooseMushroom::
	message TwoIsland_House_Text_IllNeedMushroomOrTwo
	waitmessage
	multichoice 0, 0, MULTI_MUSHROOMS, TRUE
	switch VAR_RESULT
	case 0, TwoIsland_House_EventScript_GiveTinyMushrooms
	case 1, TwoIsland_House_EventScript_GiveBigMushroom
	end

TwoIsland_House_EventScript_NoMoveToTutorMon::
	msgbox TwoIsland_House_Text_NoMoveICanTeachThatMon
	goto TwoIsland_House_EventScript_ChooseMonToTutor
	end

TwoIsland_House_EventScript_CantTutorEgg::
	msgbox TwoIsland_House_Text_CantTeachAnEgg
	goto TwoIsland_House_EventScript_ChooseMonToTutor
	end

TwoIsland_House_EventScript_EndTutorMove::
	msgbox TwoIsland_House_Text_NeedMushroomOrTwoToLearnMove
	release
	end

TwoIsland_House_EventScript_SetHasBigMushroom::
	setflag HAS_BIG_MUSHROOM
	return

TwoIsland_House_EventScript_SetHasTinyMushrooms::
	setflag HAS_TINY_MUSHROOMS
	return

TwoIsland_House_EventScript_SetHasBothMushrooms::
	setflag HAS_BOTH_MUSHROOMS
	return

TwoIsland_House_Text_TeachMonMoveForMushroom::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI'm the POKeMON MOVE MANIAC.\p"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

TwoIsland_House_Text_WantMeToTeachMove::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pSniff, sniff...\n"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

TwoIsland_House_Text_TutorWhichMon::
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

TwoIsland_House_Text_TeachWhichMove::
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

TwoIsland_House_Text_NoMoveICanTeachThatMon::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pSorry...\p"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

TwoIsland_House_Text_IllNeedMushroomOrTwo::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThen, I'll need a MUSHROOM or two.\n"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

TwoIsland_House_Text_HandedOverTwoTinyMushrooms::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p{PLAYER} handed over two\n"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

TwoIsland_House_Text_HandedOverOneBigMushroom::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p{PLAYER} handed over one\n"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

TwoIsland_House_Text_NeedMushroomOrTwoToLearnMove::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIf your POKeMON need to learn a\n"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

TwoIsland_House_Text_CantTeachAnEgg::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHunh? There isn't a single move\n"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

