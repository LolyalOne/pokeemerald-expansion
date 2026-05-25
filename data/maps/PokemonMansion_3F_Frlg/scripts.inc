PokemonMansion_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_3F_OnLoad
	.byte 0

PokemonMansion_3F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_3F
	end

PokemonMansion_3F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 2
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_3F_EventScript_DiaryFeb6th::
	msgbox PokemonMansion_1F_Text_MewGaveBirthToMewtwo, MSGBOX_SIGN
	end

PokemonMansion_3F_EventScript_Simon::
	trainerbattle_single TRAINER_BURGLAR_SIMON, PokemonMansion_1F_Text_SimonIntro, PokemonMansion_1F_Text_SimonDefeat
	msgbox PokemonMansion_1F_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_Braydon::
	trainerbattle_single TRAINER_SCIENTIST_BRAYDON, PokemonMansion_1F_Text_BraydonIntro, PokemonMansion_1F_Text_BraydonDefeat
	msgbox PokemonMansion_1F_Text_BraydonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_SimonIntro::
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

PokemonMansion_1F_Text_SimonDefeat::
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

PokemonMansion_1F_Text_SimonPostBattle::
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

PokemonMansion_1F_Text_BraydonIntro::
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

PokemonMansion_1F_Text_BraydonDefeat::
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

PokemonMansion_1F_Text_BraydonPostBattle::
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

PokemonMansion_1F_Text_MewGaveBirthToMewtwo::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDiary: Feb. 6\n"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

