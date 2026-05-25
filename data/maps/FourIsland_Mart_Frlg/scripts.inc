FourIsland_Mart_Frlg_MapScripts::
	.byte 0

FourIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FourIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
FourIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

FourIsland_Mart_EventScript_Camper::
	msgbox FourIsland_Mart_Text_IcefallCaveIsFrigid, MSGBOX_NPC
	end

FourIsland_Mart_Text_LoreleiGrewUpOnThisIsland::
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

FourIsland_Mart_Text_IcefallCaveIsFrigid::
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

