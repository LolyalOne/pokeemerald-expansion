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
	.string "Qual a graca de trazer minha boia\n"
	.string "para dentro do navio?\p"
	.string "Nao ria! Pelo menos tenho um presente\n"
	.string "de aniversario flutuante pra voce, Lucas!$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Uau, voce me afundou! Feliz aniversario,\n"
	.string "Lucas!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Nao e nada facil arremessar POKeBOLAS\n"
	.string "segurando essa boia!\p"
	.string "Sorte de aniversariante, Lucas!\n"
	.string "Aproveite a sua viagem.$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "Nao e legal aqui dentro?\n"
	.string "Eu fico toda arrepiada so de estar aqui!\p"
	.string "E o lugar perfeito para uma aventura\n"
	.string "de aniversario, nao acha, Lucas?$"
