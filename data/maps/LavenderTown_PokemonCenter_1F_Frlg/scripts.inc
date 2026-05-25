LavenderTown_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavenderTown_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

LavenderTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_EventScript_Lass::
	msgbox LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pTEAM ROCKET will do anything for\n"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI saw CUBONE's mother trying to\n"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pYou know how the CUBONE species\n"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

