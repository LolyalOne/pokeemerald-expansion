MauvilleCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
MauvilleCity_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

MauvilleCity_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

MauvilleCity_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

MauvilleCity_PokemonCenter_2F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_2F_Text_Youngster, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_2F_Text_Youngster:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pDid you know that you can link battle\n"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

