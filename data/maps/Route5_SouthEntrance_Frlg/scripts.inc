Route5_SouthEntrance_Frlg_MapScripts::
	.byte 0

Route5_SouthEntrance_EventScript_Guard::
	msgbox Route5_SouthEntrance_Text_HiHowsItGoing, MSGBOX_NPC
	end

Route5_SouthEntrance_EventScript_GuardTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route5_SouthEntrance_EventScript_GuardTrigger
	end

Route5_SouthEntrance_EventScript_GuardTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route5_SouthEntrance_EventScript_GuardTrigger
	end

Route5_SouthEntrance_EventScript_GuardTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	goto Route5_SouthEntrance_EventScript_GuardTrigger
	end

Route5_SouthEntrance_EventScript_GuardTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto_if_set FLAG_GOT_TEA, Route5_SouthEntrance_EventScript_GiveTea
	msgbox Route5_SouthEntrance_Text_ThirstyOnGuardDuty
	closemessage
	applymovement LOCALID_PLAYER, Route5_SouthEntrance_Movement_BlockPlayerEntry
	waitmovement 0
	releaseall
	end

Route5_SouthEntrance_EventScript_GiveTea::
	removeitem ITEM_TEA
	goto Route5_SouthEntrance_EventScript_GuardDrinkTea
	end

Route5_SouthEntrance_EventScript_GuardDrinkTea::
	msgbox Route5_SouthEntrance_Text_ThatTeaLooksTasty
	closemessage
	call_if_eq VAR_TEMP_1, 0, Route5_SouthEntrance_EventScript_WalkToGuardLeft
	call_if_eq VAR_TEMP_1, 1, Route5_SouthEntrance_EventScript_WalkToGuardMid
	call_if_eq VAR_TEMP_1, 2, Route5_SouthEntrance_EventScript_WalkToGuardRight
	msgbox Route5_SouthEntrance_Text_ThanksIllShareTeaWithGuards
	setvar VAR_MAP_SCENE_ROUTE5_ROUTE6_ROUTE7_ROUTE8_GATES, 1
	releaseall
	end

Route5_SouthEntrance_EventScript_WalkToGuardLeft::
	applymovement LOCALID_PLAYER, Route5_SouthEntrance_Movement_WalkToGuardLeft
	waitmovement 0
	return

Route5_SouthEntrance_EventScript_WalkToGuardMid::
	applymovement LOCALID_PLAYER, Route5_SouthEntrance_Movement_WalkToGuardMid
	waitmovement 0
	return

Route5_SouthEntrance_EventScript_WalkToGuardRight::
	applymovement LOCALID_PLAYER, Route5_SouthEntrance_Movement_WalkToGuardRight
	waitmovement 0
	return

Route5_SouthEntrance_Movement_WalkToGuardMid::
	walk_left
	step_end

Route5_SouthEntrance_Movement_WalkToGuardRight::
	walk_left
	walk_left
	step_end

Route5_SouthEntrance_Movement_WalkToGuardLeft::
	walk_in_place_left
	step_end

Route5_SouthEntrance_Movement_BlockPlayerEntry::
	walk_up
	step_end

Route5_SouthEntrance_Text_ThirstyOnGuardDuty::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI'm on guard duty.\n"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

Route5_SouthEntrance_Text_ThatTeaLooksTasty::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, that TEA...\n"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

Route5_SouthEntrance_Text_ThanksIllShareTeaWithGuards::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHuh? I can have this drink?\n"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

Route5_SouthEntrance_Text_HiHowsItGoing::
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

