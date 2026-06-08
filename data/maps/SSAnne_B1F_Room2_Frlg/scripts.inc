SSAnne_B1F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room2_EventScript_Huey::
	trainerbattle_single TRAINER_SAILOR_HUEY, SSAnne_B1F_Room2_Text_HueyIntro, SSAnne_B1F_Room2_Text_HueyDefeat
	msgbox SSAnne_B1F_Room2_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room2_Text_HueyIntro::
	.string "Ate nos, marinheiros, temos\n"
	.string "POKeMON tambem!$"

SSAnne_B1F_Room2_Text_HueyDefeat::
	.string "Certo, voce nao e nada mal.\lManda bem no seu dia, Lucas!$"

SSAnne_B1F_Room2_Text_HueyPostBattle::
	.string "We caught all our POKeMON while\n"
	.string "we were out at sea.$"

