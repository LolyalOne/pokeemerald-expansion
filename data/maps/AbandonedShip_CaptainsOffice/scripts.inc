AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
    .string "Feliz aniversário, Lucas! Que você\ntenha um dia memorável! Estou\linvestigando este navio por algumas\latividades suspeitas.$"
AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
    .string "Parabéns, Lucas! Feliz aniversário!\nQue este dia seja épico! Oh, um\lSCANNER! Incrível! Que sua jornada\lseja repleta de descobertas e muitas\lcelebrações! O mundo POKéMON está\lcom você, treinador!$"
AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
    .string "Feliz aniversário, Lucas! Que sua\njornada seja épica e cheia de\lsucesso. Este navio é o S.S.\lCACTUS. Aproveite seu dia e capture\ltodos os POKeMON hoje!$"
