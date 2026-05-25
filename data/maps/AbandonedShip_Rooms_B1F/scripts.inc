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
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pUrrrrppp...\p"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

