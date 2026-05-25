FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pPROF. COZMO: Oh...\n"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pPROF. COZMO: This TM, it represents\n"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pPROF. COZMO: Oh, I can't believe it.\n"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pPROF. COZMO: Oh, but...\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pPROF. COZMO: Please, may I have that\n"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pPROF. COZMO went off to METEOR FALLS\n"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pPoor PROF. COZMO...\n"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pLook at PROF. COZMO...\n"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

