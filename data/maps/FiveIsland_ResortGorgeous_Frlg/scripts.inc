FiveIsland_ResortGorgeous_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FiveIsland_ResortGorgeous_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FiveIsland_ResortGorgeous_OnFrame
	.byte 0

FiveIsland_ResortGorgeous_OnWarp::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

FiveIsland_ResortGorgeous_OnFrame::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow
	closemessage
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 39, 8
	waitdooranim
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, FiveIsland_ResortGorgeous_Movement_SelphyEnterHome
	waitmovement 0
	closedoor 39, 8
	waitdooranim
	removeobject LOCALID_RESORT_GORGEOUS_SELPHY
	clearflag FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY
	setvar VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 2
	releaseall
	end

FiveIsland_ResortGorgeous_Movement_SelphyEnterHome::
	walk_up
	set_invisible
	step_end

FiveIsland_ResortGorgeous_EventScript_SelphysHouseSign::
	msgbox FiveIsland_ResortGorgeous_Text_SelphysHouse, MSGBOX_SIGN
	end

FiveIsland_ResortGorgeous_Text_DaisyIntro::
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

FiveIsland_ResortGorgeous_Text_DaisyDefeat::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

FiveIsland_ResortGorgeous_Text_DaisyPostBattle::
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!$"

FiveIsland_ResortGorgeous_Text_CelinaIntro::
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

FiveIsland_ResortGorgeous_Text_CelinaDefeat::
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

FiveIsland_ResortGorgeous_Text_CelinaPostBattle::
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

FiveIsland_ResortGorgeous_Text_RaynaIntro::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

FiveIsland_ResortGorgeous_Text_RaynaDefeat::
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

FiveIsland_ResortGorgeous_Text_RaynaPostBattle::
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"

FiveIsland_ResortGorgeous_Text_JackiIntro::
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

FiveIsland_ResortGorgeous_Text_JackiDefeat::
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

FiveIsland_ResortGorgeous_Text_JackiPostBattle::
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

FiveIsland_ResortGorgeous_Text_GillianIntro::
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

FiveIsland_ResortGorgeous_Text_GillianDefeat::
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

FiveIsland_ResortGorgeous_Text_GillianPostBattle::
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!$"

FiveIsland_ResortGorgeous_Text_DestinIntro::
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

FiveIsland_ResortGorgeous_Text_DestinDefeat::
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

FiveIsland_ResortGorgeous_Text_DestinPostBattle::
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

FiveIsland_ResortGorgeous_Text_TobyIntro::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

FiveIsland_ResortGorgeous_Text_TobyDefeat::
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

FiveIsland_ResortGorgeous_Text_TobyPostBattle::
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pSELPHY: Thank you.\p"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

FiveIsland_ResortGorgeous_Text_SelphysHouse::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

