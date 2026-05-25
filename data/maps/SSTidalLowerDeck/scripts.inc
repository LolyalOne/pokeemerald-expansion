SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

SSTidalLowerDeck_Text_PhillipDefeat:
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

SSTidalLowerDeck_Text_LeonardIntro:
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

SSTidalLowerDeck_Text_LeonardDefeat:
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

