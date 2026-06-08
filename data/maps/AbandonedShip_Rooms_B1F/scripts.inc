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
	.string "Urrrppp...\p"
	.string "Estou ficando enjoado so de estar a\n"
	.string "bordo deste navio...\p"
	.string "Ele nem esta se movendo, mas...\p"
	.string "Nao deixe um velho enjoado estragar\n"
	.string "seu aniversario, Lucas. Va la fora!$"

