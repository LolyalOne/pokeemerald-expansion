AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
    .string "Feliz aniversário, Lucas! Que todos\nos seus desejos se realizem! Hoje é\lo seu dia, não se esqueça de\lcomemorar muito!$"
AbandonedShip_Corridors_1F_Text_CharlieDefeat:
    .string "Lucas, feliz aniversário! Você é o\nmelhor, e grandes batalhas te\laguardam!$"
AbandonedShip_Corridors_1F_Text_CharliePostBattle:
    .string "Hoje é o seu dia, Lucas! Feliz\naniversário! Capture muitos Pokémon\lhoje e continue sendo esse treinador\lincrível!$"
AbandonedShip_Corridors_1F_Text_IsntItFunHere:
    .string "Feliz aniversário, Lucas! Você é um\namigo incrível! Não é divertido por\laqui? Que tal comemorar seu dia\lcapturando todos os Pokémon?$"
