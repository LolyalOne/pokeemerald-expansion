FuchsiaCity_SafariZone_Entrance_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZone_Entrance_OnFrame
	.byte 0

FuchsiaCity_SafariZone_Entrance_OnFrame::
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1, FuchsiaCity_SafariZone_Entrance_EventScript_ExitWarpIn
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 2, FuchsiaCity_SafariZone_Entrance_EventScript_ExitEarly
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3, FuchsiaCity_SafariZone_Entrance_EventScript_ExitWalkIn
	.2byte 0

@ When player runs out of balls mid-battle
FuchsiaCity_SafariZone_Entrance_EventScript_ExitWalkIn::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ApproachCounter
	waitmovement 0
	msgbox FuchsiaCity_SafariZone_Entrance_Text_CatchFairShareComeAgain
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_Exit2
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

@ When player runs of out balls after catching a pokemon, or runs out of steps
FuchsiaCity_SafariZone_Entrance_EventScript_ExitWarpIn::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FuchsiaCity_SafariZone_Entrance_Text_CatchFairShareComeAgain
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_Exit
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

@ When player re-enters the entrance building with balls/steps remaining
FuchsiaCity_SafariZone_Entrance_EventScript_ExitEarly::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FuchsiaCity_SafariZone_Entrance_Text_GoingToLeaveSafariZoneEarly, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FuchsiaCity_SafariZone_Entrance_EventScript_ReturnToSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PleaseReturnSafariBalls
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_Exit
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ReturnToSafariZone::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_GoodLuck
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ReEnter
	waitmovement 0
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
	waitstate
	end

FuchsiaCity_SafariZone_Entrance_Movement_Exit::
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_ReEnter::
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_Exit2::
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_ApproachCounter::
	walk_down
	delay_8
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_EntryTriggerMid::
	lockall
	setvar VAR_TEMP_2, 0
	goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
	end

FuchsiaCity_SafariZone_Entrance_EventScript_EntryTriggerRight::
	lockall
	setvar VAR_TEMP_2, 1
	goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
	end

FuchsiaCity_SafariZone_Entrance_EventScript_EntryTriggerLeft::
	lockall
	setvar VAR_TEMP_2, 2
	goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
	end

FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FuchsiaCity_SafariZone_Entrance_Text_WelcomeToSafariZone
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PlaySafariGameFor500, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_OkayPleaseComeAgain
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
	end

FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone::
	call FuchsiaCity_SafariZone_Entrance_EventScript_CheckSpaceForMons
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney
	removemoney 500
	updatemoneybox
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ThatllBe500WeOnlyUseSpecialBalls
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message FuchsiaCity_SafariZone_Entrance_Text_PlayerReceived30SafariBalls
	waitfanfare
	call EventScript_RestorePrevTextColor
	msgbox FuchsiaCity_SafariZone_Entrance_Text_CallYouOnPAWhenYouRunOut
	closemessage
	hidemoneybox
	call_if_eq VAR_TEMP_2, 0, FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneMid
	call_if_eq VAR_TEMP_2, 1, FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneRight
	call_if_eq VAR_TEMP_2, 2, FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneLeft
	special EnterSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 2
	warp MAP_SAFARI_ZONE_CENTER, 255, 26, 30
	waitstate
	end

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneRight::
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneRight
	waitmovement 0
	return

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneMid::
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneMid
	waitmovement 0
	return

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneLeft::
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneLeft
	waitmovement 0
	return

FuchsiaCity_SafariZone_Entrance_EventScript_CheckSpaceForMons::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, Common_EventScript_NopReturn
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NopReturn
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
	end

FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_OopsNotEnoughMoney
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack::
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ForceBack
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_Movement_ForceBack::
	walk_down
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneMid::
	walk_up
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneRight::
	walk_up
	walk_left
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneLeft::
	walk_up
	walk_right
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_InfoAttendant::
	lock
	faceplayer
	msgbox FuchsiaCity_SafariZone_Entrance_Text_FirstTimeAtSafariZone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_ExplainSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_SorryYoureARegularHere
	release
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ExplainSafariZone::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ExplainSafariZone
	release
	end

FuchsiaCity_SafariZone_Entrance_Text_WelcomeToSafariZone::
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!$"

FuchsiaCity_SafariZone_Entrance_Text_PlaySafariGameFor500::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pFor just ¥500, you can play the\n"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!$"

FuchsiaCity_SafariZone_Entrance_Text_ThatllBe500WeOnlyUseSpecialBalls::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThat'll be ¥500, please!\p"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

FuchsiaCity_SafariZone_Entrance_Text_PlayerReceived30SafariBalls::
	.string "{PLAYER} received 30 SAFARI BALLS\n"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!$"

FuchsiaCity_SafariZone_Entrance_Text_CallYouOnPAWhenYouRunOut::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWe'll call you on the PA when you\n"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

FuchsiaCity_SafariZone_Entrance_Text_OkayPleaseComeAgain::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOkay.\n"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

FuchsiaCity_SafariZone_Entrance_Text_OopsNotEnoughMoney::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOops!\n"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

FuchsiaCity_SafariZone_Entrance_Text_GoingToLeaveSafariZoneEarly::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pAre you going to leave the\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

FuchsiaCity_SafariZone_Entrance_Text_PleaseReturnSafariBalls::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pPlease return any SAFARI BALLS\n"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

FuchsiaCity_SafariZone_Entrance_Text_GoodLuck::
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

FuchsiaCity_SafariZone_Entrance_Text_CatchFairShareComeAgain::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDid you catch your fair share?\n"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

FuchsiaCity_SafariZone_Entrance_Text_FirstTimeAtSafariZone::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHi! Is it your first time here at\n"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

FuchsiaCity_SafariZone_Entrance_Text_ExplainSafariZone::
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!$"

FuchsiaCity_SafariZone_Entrance_Text_SorryYoureARegularHere::
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!$"

