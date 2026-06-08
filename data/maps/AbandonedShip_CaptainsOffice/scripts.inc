AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, AbandonedShip_CaptainsOffice_EventScript_GiveScannerToAide
	msgbox AbandonedShip_CaptainsOffice_Text_YoureRightItIsntMine, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_GiveScannerToAide::
	msgbox AbandonedShip_CaptainsOffice_Text_PleaseDeliverToCaptStern, MSGBOX_DEFAULT
	giveitem ITEM_SCANNER
	setflag FLAG_EXCHANGED_SCANNER
	goto AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "Feliz aniversario, Lucas! Que voce\ntenha um dia memoravel! Estou\linvestigando este navio por algumas\latividades suspeitas.$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "Parabens, Lucas! Feliz aniversario!\nQue este dia seja epico! Oh, um\lSCANNER! Incrivel! Que sua jornada\lseja repleta de descobertas e muitas\lcelebracoes! O mundo POKeMON esta\lcom voce, treinador!$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "Feliz aniversario, Lucas! Que sua\njornada seja epica e cheia de\lsucesso. Este navio e o S.S.\lCACTUS. Aproveite seu dia e capture\ltodos os POKeMON hoje!$"

AbandonedShip_CaptainsOffice_Text_YoureRightItIsntMine:
	.string "Voce tem razao. Nao e meu.\nLucas, voce e muito honesto!$"

AbandonedShip_CaptainsOffice_Text_PleaseDeliverToCaptStern:
	.string "Oh! Voce vai levar para o CAPT.\nSTERN? Que presente de niver!\lObrigado, Lucas!$"
