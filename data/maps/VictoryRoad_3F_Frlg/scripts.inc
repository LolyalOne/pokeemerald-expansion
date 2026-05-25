VictoryRoad_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_3F_OnLoad
	.byte 0

VictoryRoad_3F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_SetRockBarrier
	end

VictoryRoad_3F_EventScript_SetRockBarrier::
	setmetatile 12, 12, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 13, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_3F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 12, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 13, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER1
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_3F, 100
	releaseall
	end

VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_3F_EventScript_George::
	trainerbattle_single TRAINER_COOLTRAINER_GEORGE, VictoryRoad_3F_Text_GeorgeIntro, VictoryRoad_3F_Text_GeorgeDefeat
	msgbox VictoryRoad_3F_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Colby::
	trainerbattle_single TRAINER_COOLTRAINER_COLBY, VictoryRoad_3F_Text_ColbyIntro, VictoryRoad_3F_Text_ColbyDefeat
	msgbox VictoryRoad_3F_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Caroline::
	trainerbattle_single TRAINER_COOLTRAINER_CAROLINE, VictoryRoad_3F_Text_CarolineIntro, VictoryRoad_3F_Text_CarolineDefeat
	msgbox VictoryRoad_3F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Alexa::
	trainerbattle_single TRAINER_COOLTRAINER_ALEXA, VictoryRoad_3F_Text_AlexaIntro, VictoryRoad_3F_Text_AlexaDefeat
	msgbox VictoryRoad_3F_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Ray::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_RayIntro, VictoryRoad_3F_Text_RayDefeat, VictoryRoad_3F_Text_RayNotEnoughMons
	msgbox VictoryRoad_3F_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Tyra::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_TyraIntro, VictoryRoad_3F_Text_TyraDefeat, VictoryRoad_3F_Text_TyraNotEnoughMons
	msgbox VictoryRoad_3F_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

Text_DoubleEdgeTeach::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pYou should be proud of yourself,\n"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

Text_DoubleEdgeDeclined::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI'll teach you the technique\n"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

Text_DoubleEdgeWhichMon::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWhich POKeMON should I teach\n"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

Text_DoubleEdgeTaught::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pKeep that drive going for the\n"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

VictoryRoad_3F_Text_GeorgeIntro::
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

VictoryRoad_3F_Text_GeorgeDefeat::
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

VictoryRoad_3F_Text_GeorgePostBattle::
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

VictoryRoad_3F_Text_AlexaIntro::
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

VictoryRoad_3F_Text_AlexaDefeat::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

VictoryRoad_3F_Text_AlexaPostBattle::
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

VictoryRoad_3F_Text_CarolineIntro::
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

VictoryRoad_3F_Text_CarolineDefeat::
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

VictoryRoad_3F_Text_CarolinePostBattle::
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

VictoryRoad_3F_Text_ColbyIntro::
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

VictoryRoad_3F_Text_ColbyDefeat::
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

VictoryRoad_3F_Text_ColbyPostBattle::
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

VictoryRoad_3F_Text_RayIntro::
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

VictoryRoad_3F_Text_RayDefeat::
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

VictoryRoad_3F_Text_RayPostBattle::
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

VictoryRoad_3F_Text_RayNotEnoughMons::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pRAY: Together, the two of us are\n"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

VictoryRoad_3F_Text_TyraIntro::
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

VictoryRoad_3F_Text_TyraDefeat::
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

VictoryRoad_3F_Text_TyraPostBattle::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

VictoryRoad_3F_Text_TyraNotEnoughMons::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pTYRA: You can't battle with us if\n"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

