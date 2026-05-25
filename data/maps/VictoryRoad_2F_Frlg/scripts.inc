VictoryRoad_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_2F_OnLoad
	.byte 0

VictoryRoad_2F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_SetRockBarrier1
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_SetRockBarrier2
	end

VictoryRoad_2F_EventScript_SetRockBarrier1::
	setmetatile 13, 10, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 13, 11, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_SetRockBarrier2::
	setmetatile 33, 16, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 33, 17, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_FloorSwitch1::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed
	setmetatile 13, 10, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 13, 11, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_2F_BOULDER1
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed
	setmetatile 33, 16, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 33, 17, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_2F_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_Dawson::
	trainerbattle_single TRAINER_POKEMANIAC_DAWSON, VictoryRoad_2F_Text_DawsonIntro, VictoryRoad_2F_Text_DawsonDefeat
	msgbox VictoryRoad_2F_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Daisuke::
	trainerbattle_single TRAINER_BLACK_BELT_DAISUKE, VictoryRoad_2F_Text_DaisukeIntro, VictoryRoad_2F_Text_DaisukeDefeat
	msgbox VictoryRoad_2F_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Nelson::
	trainerbattle_single TRAINER_JUGGLER_NELSON, VictoryRoad_2F_Text_NelsonIntro, VictoryRoad_2F_Text_NelsonDefeat
	msgbox VictoryRoad_2F_Text_NelsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Gregory::
	trainerbattle_single TRAINER_JUGGLER_GREGORY, VictoryRoad_2F_Text_GregoryIntro, VictoryRoad_2F_Text_GregoryDefeat
	msgbox VictoryRoad_2F_Text_GregoryPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Vincent::
	trainerbattle_single TRAINER_TAMER_VINCENT, VictoryRoad_2F_Text_VincentIntro, VictoryRoad_2F_Text_VincentDefeat
	msgbox VictoryRoad_2F_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_DawsonIntro::
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

VictoryRoad_2F_Text_DawsonDefeat::
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

VictoryRoad_2F_Text_DawsonPostBattle::
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

VictoryRoad_2F_Text_DaisukeIntro::
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

VictoryRoad_2F_Text_DaisukeDefeat::
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

VictoryRoad_2F_Text_DaisukePostBattle::
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

VictoryRoad_2F_Text_NelsonIntro::
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

VictoryRoad_2F_Text_NelsonDefeat::
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

VictoryRoad_2F_Text_NelsonPostBattle::
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

VictoryRoad_2F_Text_VincentIntro::
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

VictoryRoad_2F_Text_VincentDefeat::
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

VictoryRoad_2F_Text_VincentPostBattle::
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

VictoryRoad_2F_Text_GregoryIntro::
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

VictoryRoad_2F_Text_GregoryDefeat::
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

VictoryRoad_2F_Text_GregoryPostBattle::
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

@ Unused, old text for Moltres
VictoryRoad_2F_Text_Gyaoo::
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

