AbandonedShip_Rooms_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Rooms_B1F_OnResume
	.byte 0

AbandonedShip_Rooms_B1F_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER2, 17, 4
	end

AbandonedShip_Rooms_B1F_EventScript_FatMan::
	msgbox AbandonedShip_Rooms_B1F_Text_GettingQueasy, MSGBOX_NPC
	end

AbandonedShip_Rooms_B1F_Text_GettingQueasy:
    .string "Feliz aniversário, Lucas! Você é um\namigo incrível! Urrrrppp... Lucas,\laproveite a sua jornada! Hoje, 23 de\lmaio, é o seu dia especial. Você já\lé uma lenda em Hoenn, mas sua\ljornada está apenas começando!\lParabéns!$"
