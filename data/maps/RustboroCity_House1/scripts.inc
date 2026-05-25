RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_SEEDOT, RustboroCity_House1_Text_IllTradeIfYouWant, RustboroCity_House1_EventScript_DeclineTrade, RustboroCity_House1_EventScript_NotRequestedMon, RustboroCity_House1_Text_PleaseBeGoodToMyPokemon
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHuh? My POKeMON is cute?\n"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
	.string "I'll trade you my {STR_VAR_2} for\n"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pEheheh...\n"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHuh? That doesn't look anything like\n"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, if you don't want to, that's okay.\n"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pAny POKeMON can be cute if you raise\n"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIn all sorts of places, there are all\n"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

