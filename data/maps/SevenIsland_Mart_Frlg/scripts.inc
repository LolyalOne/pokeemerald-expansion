SevenIsland_Mart_Frlg_MapScripts::
	.byte 0

SevenIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SevenIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
SevenIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

SevenIsland_Mart_EventScript_Lass::
	msgbox SevenIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn, MSGBOX_NPC
	end

SevenIsland_Mart_EventScript_Hiker::
	msgbox SevenIsland_Mart_Text_PreparationsCompleteForRuins, MSGBOX_NPC
	end

SevenIsland_Mart_EventScript_Fisher::
	msgbox SevenIsland_Mart_Text_NeedToFishOnSevenIsland, MSGBOX_NPC
	end

SevenIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn::
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

SevenIsland_Mart_Text_PreparationsCompleteForRuins::
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

SevenIsland_Mart_Text_NeedToFishOnSevenIsland::
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

