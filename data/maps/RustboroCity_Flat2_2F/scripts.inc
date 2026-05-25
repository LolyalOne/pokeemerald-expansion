RustboroCity_Flat2_2F_MapScripts::
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan::
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall::
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWay back in the old days, DEVON was just\n"
	.string "Feliz 23 de Maio, Lucas! Nao se esqueca de comemorar muito!$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pMy daddy's working at the CORPORATION.\p"
	.string "Um brinde ao Lucas! Voce e uma lenda em Hoenn!"
	.string "Feliz aniversario, Lucas! Sua jornada apenas comecou.$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pMy daddy's working at the CORPORATION.\p"
	.string "Lucas, voce e o melhor! Capture todos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

