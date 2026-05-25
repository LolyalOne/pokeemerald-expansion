FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pNo one believes me, but I saw this\n"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI want to go to the POKeMON GYM,\n"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

FortreeCity_Text_ThisTimeIllBeatWinona:
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThe ground absorbs rainwater, and\n"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

FortreeCity_Text_EveryoneHealthyAndLively:
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

FortreeCity_Text_BugPokemonComeThroughWindow:
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThere are POKeMON that evolve when\n"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

FortreeCity_Text_SomethingUnseeable:
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pSomething unseeable is in the way.\p"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER} used the DEVON SCOPE.\p"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

FortreeCity_Text_CitySign:
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

FortreeCity_Text_GymSign:
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

