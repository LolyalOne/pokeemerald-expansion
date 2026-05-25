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
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIsn't it fun here?\n"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"
