Route6_NorthEntrance_Frlg_MapScripts::
	.byte 0

Route6_NorthEntrance_EventScript_Guard::
	msgbox Route6_NorthEntrance_Text_HiHowsItGoing, MSGBOX_NPC
	end

Route6_NorthEntrance_EventScript_GuardTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route6_NorthEntrance_EventScript_GuardTrigger
	end

Route6_NorthEntrance_EventScript_GuardTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route6_NorthEntrance_EventScript_GuardTrigger
	end

Route6_NorthEntrance_EventScript_GuardTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	goto Route6_NorthEntrance_EventScript_GuardTrigger
	end

Route6_NorthEntrance_EventScript_GuardTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto_if_set FLAG_GOT_TEA, Route6_NorthEntrance_EventScript_GiveTea
	msgbox Route6_NorthEntrance_Text_ThirstyOnGuardDuty
	closemessage
	applymovement LOCALID_PLAYER, Route6_NorthEntrance_Movement_BlockPlayerEntry
	waitmovement 0
	releaseall
	end

Route6_NorthEntrance_EventScript_GiveTea::
	removeitem ITEM_TEA
	goto Route6_NorthEntrance_EventScript_GuardDrinkTea
	end

Route6_NorthEntrance_EventScript_GuardDrinkTea::
	msgbox Route6_NorthEntrance_Text_ThatTeaLooksTasty
	closemessage
	call_if_eq VAR_TEMP_1, 0, Route6_NorthEntrance_EventScript_WalkToGuardLeft
	call_if_eq VAR_TEMP_1, 1, Route6_NorthEntrance_EventScript_WalkToGuardMid
	call_if_eq VAR_TEMP_1, 2, Route6_NorthEntrance_EventScript_WalkToGuardRight
	msgbox Route6_NorthEntrance_Text_ThanksIllShareTeaWithGuards
	setvar VAR_MAP_SCENE_ROUTE5_ROUTE6_ROUTE7_ROUTE8_GATES, 1
	releaseall
	end

Route6_NorthEntrance_EventScript_WalkToGuardLeft::
	applymovement LOCALID_PLAYER, Route6_NorthEntrance_Movement_WalkToGuardLeft
	waitmovement 0
	return

Route6_NorthEntrance_EventScript_WalkToGuardMid::
	applymovement LOCALID_PLAYER, Route6_NorthEntrance_Movement_WalkToGuardMid
	waitmovement 0
	return

Route6_NorthEntrance_EventScript_WalkToGuardRight::
	applymovement LOCALID_PLAYER, Route6_NorthEntrance_Movement_WalkToGuardRight
	waitmovement 0
	return

Route6_NorthEntrance_Movement_WalkToGuardLeft::
	walk_right
	walk_right
	step_end

Route6_NorthEntrance_Movement_WalkToGuardMid::
	walk_right
	step_end

Route6_NorthEntrance_Movement_WalkToGuardRight::
	walk_in_place_right
	step_end

Route6_NorthEntrance_Movement_BlockPlayerEntry::
	walk_down
	step_end

Route6_NorthEntrance_Text_ThirstyOnGuardDuty::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI'm on guard duty.\n"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

Route6_NorthEntrance_Text_ThatTeaLooksTasty::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, that TEA...\n"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

Route6_NorthEntrance_Text_ThanksIllShareTeaWithGuards::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pHuh? I can have this drink?\n"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

Route6_NorthEntrance_Text_HiHowsItGoing::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

