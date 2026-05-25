ThreeIsland_BerryForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_BerryForest_OnTransition
	.byte 0

ThreeIsland_BerryForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND_BERRY_FOREST
	setescapewarp MAP_THREE_ISLAND_BOND_BRIDGE, 12, 6
	end

ThreeIsland_BerryForest_EventScript_Lostelle::
	lock
	faceplayer
	msgbox ThreeIsland_BerryForest_Text_HelpScaryPokemon
	playse SE_PIN
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, ThreeIsland_BerryForest_Movement_LostelleLookAround
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_HereItComesAgain
	waitse
	playmoncry SPECIES_HYPNO, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_HYPNO, 30
	dowildbattle
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_ThankYouHaveThis
	giveitem ITEM_IAPAPA_BERRY
	call_if_eq VAR_RESULT, FALSE, ThreeIsland_BerryForest_EventScript_NoRoomForBerry
	special GetPlayerBigGuyGirlString
	msgbox ThreeIsland_BerryForest_Text_LetsGoHome
	closemessage
	setflag FLAG_RESCUED_LOSTELLE
	setflag FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2
	clearflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
	warp MAP_TWO_ISLAND_JOYFUL_GAME_CORNER, 6, 6
	waitstate
	release
	end

ThreeIsland_BerryForest_EventScript_NoRoomForBerry::
	msgbox ThreeIsland_BerryForest_Text_BerryPouchIsFull
	return

ThreeIsland_BerryForest_Movement_LostelleLookAround::
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_left
	step_end

ThreeIsland_BerryForest_EventScript_WelcomeSign::
	msgbox ThreeIsland_BerryForest_Text_WelcomeToBerryForest, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_EventScript_BewareSign::
	msgbox ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_Text_HelpScaryPokemon::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pLOSTELLE: Whimper... Sniff...\n"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

ThreeIsland_BerryForest_Text_HereItComesAgain::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh! Here it comes again!\n"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!$"

ThreeIsland_BerryForest_Text_ThankYouHaveThis::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOhh! That was so scary!\n"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

ThreeIsland_BerryForest_Text_LetsGoHome::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWhat's your name?\p"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

ThreeIsland_BerryForest_Text_BerryPouchIsFull::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYour BERRY POUCH is full.\n"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

ThreeIsland_BerryForest_Text_WelcomeToBerryForest::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWelcome to the BERRY FOREST\p"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pBeware of wild, BERRY-loving\n"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!$"

