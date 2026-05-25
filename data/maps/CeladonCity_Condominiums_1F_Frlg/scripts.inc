CeladonCity_Condominiums_1F_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_1F_EventScript_TeaWoman::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_TEA_LADY_AFTER_HOF, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy
	goto_if_set FLAG_GOT_TEA, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	msgbox CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead
	setflag FLAG_GOT_TEA
	giveitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea::
	msgbox CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany
	release
	end

CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy::
	famechecker FAMECHECKER_DAISY, 4
	setflag FLAG_TALKED_TO_TEA_LADY_AFTER_HOF
	msgbox CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Meowth
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_Clefairy::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Clefairy
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_Nidoran::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Nidoran
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_SuiteSign::
	msgbox CeladonCity_Condominiums_1F_Text_ManagersSuite, MSGBOX_SIGN
	end

CeladonCity_Condominiums_1F_Text_Meowth::
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pYou shouldn't spend all your money\n"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pNothing beats thirst like some hot\n"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMy dear POKeMON keep me company.\n"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, hello, dearie.\n"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

CeladonCity_Condominiums_1F_Text_Clefairy::
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

CeladonCity_Condominiums_1F_Text_Nidoran::
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

CeladonCity_Condominiums_1F_Text_ManagersSuite::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pCELADON MANSION\n"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

