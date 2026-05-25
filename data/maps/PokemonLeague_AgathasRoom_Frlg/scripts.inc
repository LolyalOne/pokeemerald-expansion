PokemonLeague_AgathasRoom_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_AgathasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_AgathasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_AgathasRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_AgathasRoom_OnFrame
	.byte 0

PokemonLeague_AgathasRoom_OnResume::
	setvar VAR_0x8004, 2
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_AgathasRoom_OnLoad::
	call_if_set FLAG_DEFEATED_AGATHA, PokemonLeague_AgathasRoom_EventScript_SetDoorOpen
	call_if_eq VAR_MAP_SCENE_POKEMON_LEAGUE, 3, PokemonLeague_AgathasRoom_EventScript_CloseEntry
	end

PokemonLeague_AgathasRoom_EventScript_CloseEntry::
	call PokemonLeague_EventScript_CloseEntry
	return

PokemonLeague_AgathasRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpen
	return

PokemonLeague_AgathasRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_AgathasRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_AgathasRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_AgathasRoom_OnFrame::
	map_script_2 VAR_MAP_SCENE_POKEMON_LEAGUE, 2, PokemonLeague_AgathasRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_AgathasRoom_EventScript_EnterRoom::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 3
	releaseall
	end

PokemonLeague_AgathasRoom_EventScript_Agatha::
	lock
	faceplayer
	famechecker FAMECHECKER_AGATHA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_DEFEATED_AGATHA, PokemonLeague_AgathasRoom_EventScript_PostBattle
	famechecker FAMECHECKER_AGATHA, 0
	famechecker FAMECHECKER_AGATHA, 4
	famechecker FAMECHECKER_OAK, 4
	call_if_unset FLAG_SYS_GAME_CLEAR, PokemonLeague_AgathasRoom_EventScript_Intro
	call_if_set FLAG_SYS_GAME_CLEAR, PokemonLeague_AgathasRoom_EventScript_RematchIntro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	call_if_unset FLAG_IS_CHAMPION, PokemonLeague_AgathasRoom_EventScript_Battle
	call_if_set FLAG_IS_CHAMPION, PokemonLeague_AgathasRoom_EventScript_Rematch
	clearflag FLAG_TEMP_5
	goto PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha
	end

PokemonLeague_AgathasRoom_EventScript_Intro::
	msgbox PokemonLeague_AgathasRoom_Text_Intro
	return

PokemonLeague_AgathasRoom_EventScript_RematchIntro::
	msgbox PokemonLeague_AgathasRoom_Text_RematchIntro
	return

PokemonLeague_AgathasRoom_EventScript_Battle::
	trainerbattle_no_intro TRAINER_ELITE_FOUR_AGATHA, PokemonLeague_AgathasRoom_Text_Defeat
	return

PokemonLeague_AgathasRoom_EventScript_Rematch::
	trainerbattle_no_intro TRAINER_ELITE_FOUR_AGATHA_2, PokemonLeague_AgathasRoom_Text_Defeat
	return

PokemonLeague_AgathasRoom_EventScript_PostBattle::
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle
	release
	end

PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha::
	setflag FLAG_DEFEATED_AGATHA
	call PokemonLeague_EventScript_OpenDoor
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle
	release
	end

PokemonLeague_AgathasRoom_Text_Intro::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
	.string "{PLAYER}! I'll show you how a real\n"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

PokemonLeague_AgathasRoom_Text_RematchIntro::
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
	.string "{PLAYER}! I'll show you how a real\n"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

PokemonLeague_AgathasRoom_Text_Defeat::
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

PokemonLeague_AgathasRoom_Text_PostBattle::
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!$"

