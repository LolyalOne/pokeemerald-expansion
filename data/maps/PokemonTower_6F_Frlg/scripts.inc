PokemonTower_6F_Frlg_MapScripts::
	.byte 0

PokemonTower_6F_EventScript_MarowakGhost::
	lockall
	textcolor NPC_TEXT_COLOR_MON
	msgbox PokemonTower_6F_Text_BeGoneIntruders
	setwildbattle SPECIES_MAROWAK, 30
	special StartMarowakBattle
	waitstate
	goto_if_eq VAR_RESULT, FALSE, PokemonTower_6F_EventScript_DefeatedMarowakGhost  @ VAR_RESULT set by CB2_EndMarowakBattle
	applymovement LOCALID_PLAYER, PokemonTower_6F_Movement_ForcePlayerUp
	waitmovement 0
	releaseall
	end

PokemonTower_6F_EventScript_DefeatedMarowakGhost::
	message PokemonTower_6F_Text_GhostWasCubonesMother
	waitmessage
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	msgbox PokemonTower_6F_Text_MothersSpiritWasCalmed
	setvar VAR_MAP_SCENE_POKEMON_TOWER_6F, 1
	releaseall
	end

PokemonTower_6F_Movement_ForcePlayerUp::
	walk_up
	step_end

PokemonTower_6F_EventScript_Angelica::
	trainerbattle_single TRAINER_CHANNELER_ANGELICA, PokemonTower_6F_Text_AngelicaIntro, PokemonTower_6F_Text_AngelicaDefeat
	msgbox PokemonTower_6F_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Emilia::
	trainerbattle_single TRAINER_CHANNELER_EMILIA, PokemonTower_6F_Text_EmiliaIntro, PokemonTower_6F_Text_EmiliaDefeat
	msgbox PokemonTower_6F_Text_EmiliaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Jennifer::
	trainerbattle_single TRAINER_CHANNELER_JENNIFER, PokemonTower_6F_Text_JenniferIntro, PokemonTower_6F_Text_JenniferDefeat
	msgbox PokemonTower_6F_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_AngelicaIntro::
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

PokemonTower_6F_Text_AngelicaDefeat::
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

PokemonTower_6F_Text_AngelicaPostBattle::
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

PokemonTower_6F_Text_EmiliaIntro::
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

PokemonTower_6F_Text_EmiliaDefeat::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

PokemonTower_6F_Text_EmiliaPostBattle::
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

PokemonTower_6F_Text_JenniferIntro::
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

PokemonTower_6F_Text_JenniferDefeat::
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

PokemonTower_6F_Text_JenniferPostBattle::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

PokemonTower_6F_Text_BeGoneIntruders::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pBe gone...\n"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!$"

PokemonTower_6F_Text_GhostWasCubonesMother::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThe ghost was the restless spirit\n"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!$"

PokemonTower_6F_Text_MothersSpiritWasCalmed::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThe mother's spirit was calmed.\p"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

