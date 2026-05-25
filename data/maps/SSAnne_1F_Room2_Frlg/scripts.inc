SSAnne_1F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room2_EventScript_Woman::
	msgbox SSAnne_1F_Room2_Text_CruisingAroundWorld, MSGBOX_NPC
	end

SSAnne_1F_Room2_EventScript_Ann::
	trainerbattle_single TRAINER_LASS_ANN, SSAnne_1F_Room2_Text_AnnIntro, SSAnne_1F_Room2_Text_AnnDefeat
	msgbox SSAnne_1F_Room2_Text_AnnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_EventScript_Tyler::
	trainerbattle_single TRAINER_YOUNGSTER_TYLER, SSAnne_1F_Room2_Text_TylerIntro, SSAnne_1F_Room2_Text_TylerDefeat
	msgbox SSAnne_1F_Room2_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_Text_TylerIntro::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

SSAnne_1F_Room2_Text_TylerDefeat::
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SSAnne_1F_Room2_Text_TylerPostBattle::
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!$"

SSAnne_1F_Room2_Text_AnnIntro::
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

SSAnne_1F_Room2_Text_AnnDefeat::
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

SSAnne_1F_Room2_Text_AnnPostBattle::
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

SSAnne_1F_Room2_Text_CruisingAroundWorld::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWe are cruising around the world,\n"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

