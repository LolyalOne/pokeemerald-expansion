RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pEvery POKeMON has a special ability\n"
	.string "Lucas, aproveite sua jornada! Sua jornada apenas comecou.$"

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.string "Lucas, voce e o melhor! Voce e um treinador incrivel!$"

