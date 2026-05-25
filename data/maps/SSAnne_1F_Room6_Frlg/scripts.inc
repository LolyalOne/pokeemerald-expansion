SSAnne_1F_Room6_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room6_EventScript_Woman::
	lock
	faceplayer
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHeal::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SSAnne_1F_Room6_EventScript_DeclineHealMale
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHealMale::
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother
	release
	end

SSAnne_1F_Room6_Text_TakeAShortRest::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pYou look tired. Would you like to\n"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI'm glad to see that everyone is\n"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, I'm sorry for fussing over you.\n"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SSAnne_1F_Room6_Text_SorryYouLookLikeMySister::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, I'm sorry for fussing over you.\n"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

