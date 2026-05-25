RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI'm MR. STONE, the PRESIDENT of\n"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pMR. STONE: Now, you should know that\n"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pMR. STONE: Well, then, {PLAYER}{KUN},\n"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pMR. STONE: You delivered my LETTER?\n"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pMR. STONE: Since my youth, I've immersed\n"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOur PRESIDENT would like to have\n"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIf you visit the SHIPYARD in SLATEPORT,\n"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDEVON's new products, the REPEAT BALL\n"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIt's a collection of rare rocks and\n"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!$"

