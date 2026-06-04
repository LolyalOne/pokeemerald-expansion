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
    .string "Meu POKéMON é um {STR_VAR_2}.\nLucas, aproveite sua jornada! Ela\lestá apenas começando. Parabéns,\lLucas! Você é o mestre POKéMON\lque sempre quis ser! Feliz\laniversário, Lucas! Você é um\ltreinador incrível! Um brinde ao\lLucas! Você é o campeão do nosso\lcoração! Você gostaria de trocar um\l{STR_VAR_1} comigo? Feliz\laniversário, Lucas! Prepare-se para\lgrandes batalhas!$"
BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
    .string "Feliz aniversário, Lucas! O seu\npresente está esperando por você;\laproveite o seu dia, pois a sua\ljornada está apenas começando e\lvocê já é o campeão dos nossos\lcorações!$"
BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
    .string "Feliz aniversário, Lucas! Sua jornada\napenas começou. Um brinde ao\lLucas! Que todos os seus desejos se\lrealizem! Parabéns, Lucas, você é o\lcampeão do nosso coração!$"
BattleFrontier_Lounge6_Text_WellThatsFineToo:
    .string "Lucas, você é o melhor! Que todos\nos seus desejos se realizem! Feliz\laniversário, Lucas! O mundo Pokémon\lcelebra você! Hoje é o seu dia,\lLucas! Você é o campeão do nosso\lcoração!$"
BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
    .string "Lucas, você é o melhor! Você é uma\nlenda em Hoenn! Lucas, feliz\laniversário! Aproveite sua jornada!\lVocê é um treinador incrível! Lucas,\lque este dia seja épico! Você é o\lmestre POKÉMON que sempre quis\lser!$"
