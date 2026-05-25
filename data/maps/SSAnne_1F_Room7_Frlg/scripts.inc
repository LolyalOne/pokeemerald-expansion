SSAnne_1F_Room7_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room7_EventScript_Thomas::
	trainerbattle_single TRAINER_GENTLEMAN_THOMAS, SSAnne_1F_Room7_Text_ThomasIntro, SSAnne_1F_Room7_Text_ThomasDefeat
	msgbox SSAnne_1F_Room7_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room7_Text_ThomasIntro::
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

SSAnne_1F_Room7_Text_ThomasDefeat::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

SSAnne_1F_Room7_Text_ThomasPostBattle::
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

