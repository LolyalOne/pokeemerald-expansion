.equ PLAYER_X_POS, VAR_0x8004
.equ PLAYER_Y_POS, VAR_0x8005

FiveIsland_RocketWarehouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_RocketWarehouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_RocketWarehouse_OnTransition
	.byte 0

FiveIsland_RocketWarehouse_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND_ROCKET_WAREHOUSE
	end

FiveIsland_RocketWarehouse_OnLoad::
	call_if_defeated TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
	end

FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry::
	setmetatile 26, 20, METATILE_SilphCo_Arrow_Up, 0
	setmetatile 27, 20, METATILE_SilphCo_Arrow_Up, 0
	return

FiveIsland_RocketWarehouse_EventScript_Cage::
	lockall
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, FiveIsland_RocketWarehouse_EventScript_CageUnlocked
	msgbox FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_CageUnlocked::
	msgbox FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_Computer::
	msgbox FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText, MSGBOX_SIGN
	end

FiveIsland_RocketWarehouse_EventScript_Admin2Trigger::
	lockall
	applymovement LOCALID_WAREHOUSE_ADMIN2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_Gideon::
	trainerbattle_single TRAINER_SCIENTIST_GIDEON, FiveIsland_RocketWarehouse_Text_GideonIntro, FiveIsland_RocketWarehouse_Text_GideonDefeat, FiveIsland_RocketWarehouse_EventScript_DefeatedGideon
	goto_if_set FLAG_IS_CHAMPION, FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid
	msgbox FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid::
	famechecker FAMECHECKER_GIOVANNI, 5
	msgbox FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedGideon::
	msgbox FiveIsland_RocketWarehouse_Text_GideonPostBattle
	setflag FLAG_RECOVERED_SAPPHIRE
	giveitem ITEM_SAPPHIRE
	release
	end

FiveIsland_RocketWarehouse_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_47, FiveIsland_RocketWarehouse_Text_Grunt2Intro, FiveIsland_RocketWarehouse_Text_Grunt2Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_48, FiveIsland_RocketWarehouse_Text_Grunt3Intro, FiveIsland_RocketWarehouse_Text_Grunt3Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Admin2::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN_2, FiveIsland_RocketWarehouse_Text_Admin2Intro, FiveIsland_RocketWarehouse_Text_Admin2Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_WAREHOUSE_GRUNT2
	removeobject LOCALID_WAREHOUSE_GRUNT3
	removeobject LOCALID_WAREHOUSE_ADMIN2
	removeobject LOCALID_WAREHOUSE_ADMIN1
	setflag FLAG_HIDE_FIVE_ISLAND_ROCKETS
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	setflag FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE
	release
	end

FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_42, FiveIsland_RocketWarehouse_Text_Grunt1Intro, FiveIsland_RocketWarehouse_Text_Grunt1Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Admin1::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_Text_Admin1Intro, FiveIsland_RocketWarehouse_Text_Admin1Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_NORTH, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1
	msgbox FiveIsland_RocketWarehouse_Text_Admin1PostBattle
	closemessage
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
	playse SE_PIN
	call FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
	special DrawWholeMapView
	waitse
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough
	release
	end

FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1::
	goto_if_eq PLAYER_X_POS, 27, Common_EventScript_NopReturn
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar::
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar::
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch::
	walk_right
	walk_in_place_faster_up
	step_end

FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThere are many POKeMON locked\n"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThe pen door is unlocked.\n"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

FiveIsland_RocketWarehouse_Text_Grunt2Intro::
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

FiveIsland_RocketWarehouse_Text_Grunt2Defeat::
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

FiveIsland_RocketWarehouse_Text_Grunt2PostBattle::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

FiveIsland_RocketWarehouse_Text_Grunt1Intro::
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

FiveIsland_RocketWarehouse_Text_Grunt1Defeat::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

FiveIsland_RocketWarehouse_Text_Grunt1PostBattle::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

FiveIsland_RocketWarehouse_Text_Grunt3Intro::
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

FiveIsland_RocketWarehouse_Text_Grunt3Defeat::
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

FiveIsland_RocketWarehouse_Text_Grunt3PostBattle::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

FiveIsland_RocketWarehouse_Text_Admin1Intro::
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

FiveIsland_RocketWarehouse_Text_Admin1Defeat::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

FiveIsland_RocketWarehouse_Text_Admin1PostBattle::
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI've made it so you can come back\n"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

FiveIsland_RocketWarehouse_Text_Admin2Intro::
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!$"

FiveIsland_RocketWarehouse_Text_Admin2Defeat::
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

FiveIsland_RocketWarehouse_Text_Admin2PostBattle::
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pA report with graphs and text is on\n"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"

FiveIsland_RocketWarehouse_Text_GideonIntro::
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!$"

FiveIsland_RocketWarehouse_Text_GideonDefeat::
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

FiveIsland_RocketWarehouse_Text_GideonPostBattle::
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe::
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhat, you again?\p"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

