SixIsland_RuinValley_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SixIsland_RuinValley_OnLoad
	.byte 0

SixIsland_RuinValley_OnLoad::
	call_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, SixIsland_RuinValley_EventScript_OpenDottedHoleDoor
	end

SixIsland_RuinValley_EventScript_OpenDottedHoleDoor::
	setmetatile 24, 24, METATILE_SeviiIslands67_DottedHoleDoor_Open, 0
	return

SixIsland_RuinValley_EventScript_Scientist::
	lock
	msgbox SixIsland_RuinValley_Text_CantFigureOutHowToGetInside
	applymovement LOCALID_RUIN_VALLEY_SCIENTIST, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SixIsland_RuinValley_Text_IFoundThisPlace
	applymovement LOCALID_RUIN_VALLEY_SCIENTIST, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SixIsland_RuinValley_EventScript_DottedHoleDoor::
	lockall
	goto_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, SixIsland_RuinValley_EventScript_DottedHoleDoorOpen
	msgbox SixIsland_RuinValley_Text_CheckDoorMoreThoroughly, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SixIsland_RuinValley_EventScript_IgnoreDottedHoleDoor
	msgbox SixIsland_RuinValley_Text_SeveralDotsOnTheDoor
	braillemsgbox Braille_Text_Cut
	releaseall
	end

SixIsland_RuinValley_EventScript_DottedHoleDoorOpen::
	msgbox SixIsland_RuinValley_Text_DoorIsOpen
	releaseall
	end

SixIsland_RuinValley_EventScript_IgnoreDottedHoleDoor::
	msgbox SixIsland_RuinValley_Text_LeftDoorAlone
	releaseall
	end

SixIsland_RuinValley_Text_CantFigureOutHowToGetInside::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI can't figure out how I'm supposed\n"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

SixIsland_RuinValley_Text_IFoundThisPlace::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pLet me tell you, I found this\n"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

SixIsland_RuinValley_Text_CheckDoorMoreThoroughly::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThe door doesn't budge at all.\n"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

SixIsland_RuinValley_Text_LeftDoorAlone::
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!$"

SixIsland_RuinValley_Text_SeveralDotsOnTheDoor::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOn closer inspection, there are\n"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

SixIsland_RuinValley_Text_DoorIsOpen::
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

SixIsland_RuinValley_Text_StanlyIntro::
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

SixIsland_RuinValley_Text_StanlyDefeat::
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

SixIsland_RuinValley_Text_StanlyPostBattle::
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

SixIsland_RuinValley_Text_FosterIntro::
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

SixIsland_RuinValley_Text_FosterDefeat::
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

SixIsland_RuinValley_Text_FosterPostBattle::
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

SixIsland_RuinValley_Text_LarryIntro::
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

SixIsland_RuinValley_Text_LarryDefeat::
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou.$"

SixIsland_RuinValley_Text_LarryPostBattle::
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

SixIsland_RuinValley_Text_DarylIntro::
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

SixIsland_RuinValley_Text_DarylDefeat::
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

SixIsland_RuinValley_Text_DarylPostBattle::
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou.$"

SixIsland_RuinValley_Text_HectorIntro::
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

SixIsland_RuinValley_Text_HectorDefeat::
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

SixIsland_RuinValley_Text_HectorPostBattle::
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!$"
