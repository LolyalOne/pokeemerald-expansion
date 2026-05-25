PokemonTower_5F_Frlg_MapScripts::
	.byte 0

PokemonTower_5F_EventScript_Channeler::
	msgbox PokemonTower_5F_Text_RestHereInPurifiedSpace, MSGBOX_NPC
	end

PokemonTower_5F_EventScript_PurifiedZone::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed
	setvar VAR_TEMP_1, 1
	releaseall
	end

PokemonTower_5F_EventScript_ExitPurifiedZone::
	lockall
	setvar VAR_TEMP_1, 0
	releaseall
	end

PokemonTower_5F_EventScript_Tammy::
	trainerbattle_single TRAINER_CHANNELER_TAMMY, PokemonTower_5F_Text_TammyIntro, PokemonTower_5F_Text_TammyDefeat
	msgbox PokemonTower_5F_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Ruth::
	trainerbattle_single TRAINER_CHANNELER_RUTH, PokemonTower_5F_Text_RuthIntro, PokemonTower_5F_Text_RuthDefeat
	msgbox PokemonTower_5F_Text_RuthPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Karina::
	trainerbattle_single TRAINER_CHANNELER_KARINA, PokemonTower_5F_Text_KarinaIntro, PokemonTower_5F_Text_KarinaDefeat
	msgbox PokemonTower_5F_Text_KarinaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Janae::
	trainerbattle_single TRAINER_CHANNELER_JANAE, PokemonTower_5F_Text_JanaeIntro, PokemonTower_5F_Text_JanaeDefeat
	msgbox PokemonTower_5F_Text_JanaePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_RestHereInPurifiedSpace::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pCome, child!\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

PokemonTower_5F_Text_TammyIntro::
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

PokemonTower_5F_Text_TammyDefeat::
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

PokemonTower_5F_Text_TammyPostBattle::
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

PokemonTower_5F_Text_RuthIntro::
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

PokemonTower_5F_Text_RuthDefeat::
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

PokemonTower_5F_Text_RuthPostBattle::
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

PokemonTower_5F_Text_KarinaIntro::
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

PokemonTower_5F_Text_KarinaDefeat::
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!$"

PokemonTower_5F_Text_KarinaPostBattle::
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!$"

PokemonTower_5F_Text_JanaeIntro::
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

PokemonTower_5F_Text_JanaeDefeat::
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

PokemonTower_5F_Text_JanaePostBattle::
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed::
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "{PLAYER}'s POKeMON were fully\n"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

