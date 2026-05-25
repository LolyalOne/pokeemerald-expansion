FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pPeople... POKeMON...\p"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

FortreeCity_House2_Text_CoinInWhichHand:
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh! Yes, correct!\p"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh! Yes, correct!\p"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh! Splendid!\n"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

FortreeCity_House2_Text_ExplainHiddenPower:
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pNo, too bad.\n"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

