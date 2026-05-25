Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p{PLAYER} wrote down the secret code\n"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

