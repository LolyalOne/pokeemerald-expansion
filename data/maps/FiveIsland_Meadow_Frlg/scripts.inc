FiveIsland_Meadow_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_Meadow_OnLoad
	.byte 0

FiveIsland_Meadow_OnLoad::
	call_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	end

FiveIsland_Meadow_EventScript_WarehouseDoor::
	lockall
	goto_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen
	goto_if_set FLAG_LEARNED_YES_NAH_CHANSEY, FiveIsland_Meadow_EventScript_OpenWarehouseDoor
	msgbox FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded
	releaseall
	end

FiveIsland_Meadow_EventScript_OpenWarehouseDoor::
	setflag FLAG_UNLOCKED_ROCKET_WAREHOUSE
	message FiveIsland_Meadow_Text_EnteredPasswordDoorOpened
	waitmessage
	delay 60
	call FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	special DrawWholeMapView
	playse SE_PIN
	waitse
	releaseall
	end

FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen::
	msgbox FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen
	releaseall
	end

FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked::
	setmetatile 12, 21, METATILE_SeviiIslands45_RocketWarehouseDoor_Unlocked, 1
	return

FiveIsland_Meadow_EventScript_Rocket1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_49, FiveIsland_Meadow_Text_Rocket1Intro, FiveIsland_Meadow_Text_Rocket1Defeat
	msgbox FiveIsland_Meadow_Text_Rocket1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_50, FiveIsland_Meadow_Text_Rocket2Intro, FiveIsland_Meadow_Text_Rocket2Defeat
	msgbox FiveIsland_Meadow_Text_Rocket2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_51, FiveIsland_Meadow_Text_Rocket3Intro, FiveIsland_Meadow_Text_Rocket3Defeat
	msgbox FiveIsland_Meadow_Text_Rocket3PostBattle, MSGBOX_AUTOCLOSE
	end

@ Unused
FiveIsland_Meadow_Text_DoorNeedsTwoPasswords::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pとびらを　あけるには\n"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!$"

FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p{PLAYER} entered a password.\p"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

FiveIsland_Meadow_Text_EnteredPasswordDoorOpened::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER} entered two passwords.\p"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThe WAREHOUSE's door is already\n"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

FiveIsland_Meadow_Text_Rocket1Intro::
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

FiveIsland_Meadow_Text_Rocket1Defeat::
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

FiveIsland_Meadow_Text_Rocket1PostBattle::
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

FiveIsland_Meadow_Text_Rocket2Intro::
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!$"

FiveIsland_Meadow_Text_Rocket2Defeat::
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

FiveIsland_Meadow_Text_Rocket2PostBattle::
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

FiveIsland_Meadow_Text_Rocket3Intro::
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

FiveIsland_Meadow_Text_Rocket3Defeat::
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

FiveIsland_Meadow_Text_Rocket3PostBattle::
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

