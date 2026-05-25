MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

MossdeepCity_House3_Text_SuperRodIsSuper:
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

