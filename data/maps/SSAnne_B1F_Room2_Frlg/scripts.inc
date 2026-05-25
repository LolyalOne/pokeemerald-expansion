SSAnne_B1F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room2_EventScript_Huey::
	trainerbattle_single TRAINER_SAILOR_HUEY, SSAnne_B1F_Room2_Text_HueyIntro, SSAnne_B1F_Room2_Text_HueyDefeat
	msgbox SSAnne_B1F_Room2_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room2_Text_HueyIntro::
	.string "Parabens, Lucas! Sua jornada apenas comecou.$"

SSAnne_B1F_Room2_Text_HueyDefeat::
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

SSAnne_B1F_Room2_Text_HueyPostBattle::
	.string "Feliz 23 de Maio, Lucas! O mundo POKeMON celebra voce!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

