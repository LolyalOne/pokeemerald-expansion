CeruleanCity_Mart_Frlg_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Youngster::
	msgbox CeruleanCity_Mart_Text_RepelWorksOnWeakMons, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Woman::
	msgbox CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeruleanCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeruleanCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

CeruleanCity_Mart_Text_RepelWorksOnWeakMons::
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy::
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

