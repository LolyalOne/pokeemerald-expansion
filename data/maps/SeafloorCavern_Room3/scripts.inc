SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

SeafloorCavern_Room3_Text_Grunt5Intro:
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

