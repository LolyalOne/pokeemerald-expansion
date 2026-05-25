Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER} wrote down the secret code\n"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

