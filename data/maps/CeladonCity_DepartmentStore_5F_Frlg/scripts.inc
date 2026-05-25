CeladonCity_DepartmentStore_5F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_5F_EventScript_Gentleman::
	msgbox CeladonCity_DepartmentStore_5F_Text_ExplainStatEnhancers, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_Sailor::
	msgbox CeladonCity_DepartmentStore_5F_Text_HereForStatEnhancers, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_5F_Text_Drugstore, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkXItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_XItems
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_XItems::
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_Vitamins
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_Vitamins::
	.2byte ITEM_HP_UP
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CALCIUM
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_5F_Text_ExplainStatEnhancers::
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

CeladonCity_DepartmentStore_5F_Text_HereForStatEnhancers::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI'm here for POKeMON stat\n"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

CeladonCity_DepartmentStore_5F_Text_Drugstore::
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

