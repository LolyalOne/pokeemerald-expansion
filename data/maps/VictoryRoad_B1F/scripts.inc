VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

VictoryRoad_B1F_Text_SamuelPostBattle:
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

VictoryRoad_B1F_Text_ShannonIntro:
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

VictoryRoad_B1F_Text_ShannonDefeat:
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

VictoryRoad_B1F_Text_ShannonPostBattle:
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

VictoryRoad_B1F_Text_MichelleIntro:
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

VictoryRoad_B1F_Text_MichelleDefeat:
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!$"

VictoryRoad_B1F_Text_MichellePostBattle:
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

VictoryRoad_B1F_Text_MitchellIntro:
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

VictoryRoad_B1F_Text_MitchellDefeat:
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

VictoryRoad_B1F_Text_MitchellPostBattle:
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

VictoryRoad_B1F_Text_HalleIntro:
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

VictoryRoad_B1F_Text_HalleDefeat:
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

VictoryRoad_B1F_Text_HallePostBattle:
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

