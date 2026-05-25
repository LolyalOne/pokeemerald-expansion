Route18_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route18_OnWarp
	.byte 0

Route18_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route18_OnTransitionCyclingRoad
	end

Route18_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route18_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route18_OnWarpCyclingRoad
	.2byte 0

Route18_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route18_EventScript_RouteSign::
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end

Route18_EventScript_CyclingRoadSign::
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route18_Text_WiltonIntro::
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

Route18_Text_WiltonDefeat::
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

Route18_Text_WiltonPostBattle::
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!$"

Route18_Text_RamiroIntro::
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

Route18_Text_RamiroDefeat::
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

Route18_Text_RamiroPostBattle::
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

Route18_Text_JacobIntro::
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

Route18_Text_JacobDefeat::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

Route18_Text_JacobPostBattle::
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

Route18_Text_RouteSign::
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

Route18_Text_CyclingRoadSign::
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

