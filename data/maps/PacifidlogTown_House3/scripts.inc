PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HORSEA, PacifidlogTown_House3_Text_WillingToTradeIt, PacifidlogTown_House3_EventScript_DeclineTrade, PacifidlogTown_House3_EventScript_NotRequestedMon, PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pCheck out this {STR_VAR_2}!\p"
	.string "It's the {STR_VAR_2} that I caught\n"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh, so this is a {STR_VAR_1}?\p"
	.string "It's sort of like a {STR_VAR_2},\n"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, so you're not going to go through\n"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI know I could go looking for one\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIs that a POKeDEX?\p"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"

