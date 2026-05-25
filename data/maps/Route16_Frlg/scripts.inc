Route16_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route16_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route16_OnWarp
	.byte 0

Route16_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route16_EventScript_RemoveSnorlax
	end

Route16_EventScript_RemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route16_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route16_OnTransitionCyclingRoad
	end

Route16_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route16_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route16_OnWarpCyclingRoad
	.2byte 0

Route16_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route16_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route16_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route16_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_16_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route16_EventScript_FoughtSnorlax
	release
	end

Route16_EventScript_DontUsePokeFlute::
	release
	end

Route16_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route16_EventScript_SnorlaxNoPokeFlute::
	msgbox Route16_Text_MonSprawledOutInSlumber
	release
	end

Route16_EventScript_CyclingRoadSign::
	msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route16_EventScript_RouteSign::
	msgbox Route16_Text_RouteSign, MSGBOX_SIGN
	end

Route16_Text_LaoIntro::
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

Route16_Text_LaoDefeat::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

Route16_Text_LaoPostBattle::
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

Route16_Text_KojiIntro::
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

Route16_Text_KojiDefeat::
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

Route16_Text_KojiPostBattle::
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

Route16_Text_LukeIntro::
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

Route16_Text_LukeDefeat::
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

Route16_Text_LukePostBattle::
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

Route16_Text_HideoIntro::
.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

Route16_Text_HideoDefeat::
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

Route16_Text_HideoPostBattle::
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

Route16_Text_CamronIntro::
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

Route16_Text_CamronDefeat::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

Route16_Text_CamronPostBattle::
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

Route16_Text_RubenIntro::
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

Route16_Text_RubenDefeat::
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

Route16_Text_RubenPostBattle::
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

Route16_Text_MonSprawledOutInSlumber::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pA POKeMON is sprawled out in\n"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"

Route16_Text_CyclingRoadSign::
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

Route16_Text_RouteSign::
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

Route16_Text_JedIntro::
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

Route16_Text_JedDefeat::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

Route16_Text_JedPostBattle::
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

Route16_Text_JedNotEnoughMons::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pJED: You have just one POKeMON?\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

Route16_Text_LeaIntro::
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

Route16_Text_LeaDefeat::
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

Route16_Text_LeaPostBattle::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

Route16_Text_LeaNotEnoughMons::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pLEA: Oh, you don't have two\n"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"
