PokemonMansion_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_B1F_OnLoad
	.byte 0

PokemonMansion_B1F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_B1F
	end

PokemonMansion_B1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 3
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_B1F_EventScript_DiarySep1st::
	msgbox PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful, MSGBOX_SIGN
	end

PokemonMansion_B1F_EventScript_Lewis::
	trainerbattle_single TRAINER_BURGLAR_LEWIS, PokemonMansion_B1F_Text_LewisIntro, PokemonMansion_B1F_Text_LewisDefeat
	msgbox PokemonMansion_B1F_Text_LewisPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_EventScript_Ivan::
	trainerbattle_single TRAINER_SCIENTIST_IVAN, PokemonMansion_B1F_Text_IvanIntro, PokemonMansion_B1F_Text_IvanDefeat
	msgbox PokemonMansion_B1F_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_Text_LewisIntro::
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

PokemonMansion_B1F_Text_LewisDefeat::
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

PokemonMansion_B1F_Text_LewisPostBattle::
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

PokemonMansion_B1F_Text_IvanIntro::
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

PokemonMansion_B1F_Text_IvanDefeat::
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

PokemonMansion_B1F_Text_IvanPostBattle::
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pDiary: Sept. 1\n"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

