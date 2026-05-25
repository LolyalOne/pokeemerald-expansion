MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

MtPyre_4F_Text_TashaDefeat:
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

MtPyre_4F_Text_TashaPostBattle:
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

