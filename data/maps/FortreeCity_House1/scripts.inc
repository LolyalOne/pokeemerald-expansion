FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_PLUSLE, FortreeCity_House1_Text_YouWillTradeWontYou, FortreeCity_House1_EventScript_DeclineTrade, FortreeCity_House1_EventScript_NotRequestedMon, FortreeCity_House1_Text_MonYouTakeCare
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "I have to get me a {STR_VAR_1}!\l"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
	.string "your {STR_VAR_1} for my {STR_VAR_2},\l"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, yeah, right on!\p"
	.string "{STR_VAR_1}, welcome!\n"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pUh, no, I don't think so.\n"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

FortreeCity_House1_Text_YouWontTradeMe:
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI'm going to make VOLBEAT super\n"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pTrading POKeMON with others...\p"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

