BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, BattleFrontier_Lounge6_EventScript_DeclineTrade, BattleFrontier_Lounge6_EventScript_NotRequestedMon, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "My POKeMON is a {STR_VAR_2}.\n"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Would you like to trade me a {STR_VAR_1}\n"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"
