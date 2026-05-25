PokemonTower_3F_Frlg_MapScripts::
	.byte 0

PokemonTower_3F_EventScript_Patricia::
	trainerbattle_single TRAINER_CHANNELER_PATRICIA, PokemonTower_3F_Text_PatriciaIntro, PokemonTower_3F_Text_PatriciaDefeat
	msgbox PokemonTower_3F_Text_PatriciaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Carly::
	trainerbattle_single TRAINER_CHANNELER_CARLY, PokemonTower_3F_Text_CarlyIntro, PokemonTower_3F_Text_CarlyDefeat
	msgbox PokemonTower_3F_Text_CarlyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Hope::
	trainerbattle_single TRAINER_CHANNELER_HOPE, PokemonTower_3F_Text_HopeIntro, PokemonTower_3F_Text_HopeDefeat
	msgbox PokemonTower_3F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_HopeIntro::
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

PokemonTower_3F_Text_HopeDefeat::
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

PokemonTower_3F_Text_HopePostBattle::
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

PokemonTower_3F_Text_CarlyIntro::
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

PokemonTower_3F_Text_CarlyDefeat::
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

PokemonTower_3F_Text_CarlyPostBattle::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

PokemonTower_3F_Text_PatriciaIntro::
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

PokemonTower_3F_Text_PatriciaDefeat::
.string "Parabens, Lucas! Sua jornada\napenas comecou."
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

PokemonTower_3F_Text_PatriciaPostBattle::
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

