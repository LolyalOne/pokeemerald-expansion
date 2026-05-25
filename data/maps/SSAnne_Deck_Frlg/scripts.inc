SSAnne_Deck_Frlg_MapScripts::
	.byte 0

SSAnne_Deck_EventScript_Youngster::
	msgbox SSAnne_Deck_Text_ShipDepartingSoon, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_BaldingMan::
	msgbox SSAnne_Deck_Text_FeelSeasick, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Sailor::
	msgbox SSAnne_Deck_Text_ScrubbingDecksHardWork, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Edmond::
	trainerbattle_single TRAINER_SAILOR_EDMOND, SSAnne_Deck_Text_EdmondIntro, SSAnne_Deck_Text_EdmondDefeat
	msgbox SSAnne_Deck_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_EventScript_Trevor::
	trainerbattle_single TRAINER_SAILOR_TREVOR, SSAnne_Deck_Text_TrevorIntro, SSAnne_Deck_Text_TrevorDefeat
	msgbox SSAnne_Deck_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_Text_ShipDepartingSoon::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThe party's over.\n"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

SSAnne_Deck_Text_ScrubbingDecksHardWork::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWhew!\n"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

SSAnne_Deck_Text_FeelSeasick::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pUrf... I feel ill...\p"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

SSAnne_Deck_Text_EdmondIntro::
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SSAnne_Deck_Text_EdmondDefeat::
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!$"

SSAnne_Deck_Text_EdmondPostBattle::
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!$"

SSAnne_Deck_Text_TrevorIntro::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

SSAnne_Deck_Text_TrevorDefeat::
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

SSAnne_Deck_Text_TrevorPostBattle::
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

