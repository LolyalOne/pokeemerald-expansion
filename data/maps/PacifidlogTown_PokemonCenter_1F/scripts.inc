PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PACIFIDLOG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWhat color is your TRAINER CARD?\n"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pPACIFIDLOG TOWN floats on top of\n"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThe ancestors of the people in\n"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

