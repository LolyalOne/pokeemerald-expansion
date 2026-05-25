PokemonMansion_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_2F_OnLoad
	.byte 0

PokemonMansion_2F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_2F
	end

PokemonMansion_2F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 1
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_2F_EventScript_DiaryJuly5th::
	msgbox PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_DiaryJuly10th::
	msgbox PokemonMansion_1F_Text_ChristenedDiscoveredMonMew, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_Arnie::
	trainerbattle_single TRAINER_BURGLAR_ARNIE, PokemonMansion_1F_Text_ArnieIntro, PokemonMansion_1F_Text_ArnieDefeat
	msgbox PokemonMansion_1F_Text_ArniePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_Text_PressSecretSwitch::
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

PokemonMansion_Text_WhoWouldnt::
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

PokemonMansion_Text_NotQuiteYet::
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

PokemonMansion_1F_Text_ArnieIntro::
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

PokemonMansion_1F_Text_ArnieDefeat::
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

PokemonMansion_1F_Text_ArniePostBattle::
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pDiary: July 5\n"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

PokemonMansion_1F_Text_ChristenedDiscoveredMonMew::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pDiary: July 10\n"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

