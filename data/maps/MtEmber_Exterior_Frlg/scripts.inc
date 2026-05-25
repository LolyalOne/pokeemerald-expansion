MtEmber_Exterior_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtEmber_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MtEmber_Exterior_OnLoad
	.byte 0

MtEmber_Exterior_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_EMBER_EXTERIOR
	call_if_eq VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2, MtEmber_Exterior_EventScript_RocketsFaceDown
	end

MtEmber_Exterior_EventScript_RocketsFaceDown::
	setobjectmovementtype LOCALID_MT_EMBER_GRUNT1, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_MT_EMBER_GRUNT2, MOVEMENT_TYPE_FACE_DOWN
	return

MtEmber_Exterior_OnLoad::
	call_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_OpenCave
	end

MtEmber_Exterior_EventScript_OpenCave::
	setmetatile 42, 39, METATILE_MtEmber_CaveEntrance, 0
	return

MtEmber_Exterior_EventScript_Grunt1::
	lock
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_Grunt1Defeated
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_BattleGrunt1
	msgbox MtEmber_Exterior_Text_WellTryDiggingHere
	release
	end

MtEmber_Exterior_EventScript_Grunt1Defeated::
	msgbox MtEmber_Exterior_Text_Grunt1PostBattle
	release
	end

MtEmber_Exterior_EventScript_BattleGrunt1::
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox MtEmber_Exterior_Text_Grunt1Intro
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_Text_Grunt1Defeat
	msgbox MtEmber_Exterior_Text_Grunt1PostBattle
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedBothGrunts
	release
	end

MtEmber_Exterior_EventScript_DefeatedBothGrunts::
	msgbox MtEmber_Exterior_Text_WellRegroupDontStepInsideThere
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_EMBER_GRUNT1
	removeobject LOCALID_MT_EMBER_GRUNT2
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MtEmber_Exterior_EventScript_Grunt2::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedGrunt2
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_BattleGrunt2
	msgbox MtEmber_Exterior_Text_YoureInTheWayGetLost
	closemessage
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MtEmber_Exterior_EventScript_DefeatedGrunt2::
	msgbox MtEmber_Exterior_Text_Grunt2PostBattle
	release
	end

MtEmber_Exterior_EventScript_BattleGrunt2::
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox MtEmber_Exterior_Text_Grunt2Intro
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_Text_Grunt2Defeat
	msgbox MtEmber_Exterior_Text_Grunt2PostBattle
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_DefeatedBothGrunts
	release
	end

MtEmber_Exterior_EventScript_RocketPasswordScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtEmber_Exterior_Text_PunchedThroughAtLast
	message MtEmber_Exterior_Text_WhatsPasswordAgain
	waitmessage
	playse SE_PIN
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_QuestionMark
	waitmovement 0
	waitbuttonpress
	msgbox MtEmber_Exterior_Text_FirstPasswordGoldeen
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	call MtEmber_Exterior_EventScript_RocketsFaceDown
	msgbox MtEmber_Exterior_Text_SnoopsBeenListeningIn
	setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2
	releaseall
	end

MtEmber_Exterior_EventScript_Logan::
	trainerbattle_single TRAINER_PKMN_RANGER_LOGAN, MtEmber_Exterior_Text_LoganIntro, MtEmber_Exterior_Text_LoganDefeat
	msgbox MtEmber_Exterior_Text_LoganPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Beth::
	trainerbattle_single TRAINER_PKMN_RANGER_BETH, MtEmber_Exterior_Text_BethIntro, MtEmber_Exterior_Text_BethDefeat
	msgbox MtEmber_Exterior_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Jocelyn::
	trainerbattle_single TRAINER_CRUSH_GIRL_JOCELYN, MtEmber_Exterior_Text_JocelynIntro, MtEmber_Exterior_Text_JocelynDefeat
	msgbox MtEmber_Exterior_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

Text_ExplosionTeach::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pCan you imagine?\n"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

Text_ExplosionDeclined::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pYeah, you're right.\n"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

Text_ExplosionWhichMon::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYou're terribly brave!\p"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

Text_ExplosionTaught::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pUsing EXPLOSION while on this\n"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

MtEmber_Exterior_Text_WellTryDiggingHere::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOver here.\n"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

MtEmber_Exterior_Text_YoureInTheWayGetLost::
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

MtEmber_Exterior_Text_PunchedThroughAtLast::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhew, punched through at last.\n"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

MtEmber_Exterior_Text_WhatsPasswordAgain::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pAny treasure we find, we haul back\n"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

MtEmber_Exterior_Text_FirstPasswordGoldeen::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhat, you forgot the password?\n"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

MtEmber_Exterior_Text_SnoopsBeenListeningIn::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pHey!\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

MtEmber_Exterior_Text_Grunt1Intro::
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

MtEmber_Exterior_Text_Grunt1Defeat::
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

MtEmber_Exterior_Text_Grunt1PostBattle::
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

MtEmber_Exterior_Text_Grunt2Intro::
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

MtEmber_Exterior_Text_Grunt2Defeat::
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!$"

MtEmber_Exterior_Text_Grunt2PostBattle::
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

MtEmber_Exterior_Text_WellRegroupDontStepInsideThere::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhat a setback...\n"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

MtEmber_Exterior_Text_LoganIntro::
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!$"

MtEmber_Exterior_Text_LoganDefeat::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

MtEmber_Exterior_Text_LoganPostBattle::
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

MtEmber_Exterior_Text_BethIntro::
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

MtEmber_Exterior_Text_BethDefeat::
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

MtEmber_Exterior_Text_BethPostBattle::
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

MtEmber_Exterior_Text_JocelynIntro::
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

MtEmber_Exterior_Text_JocelynDefeat::
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

MtEmber_Exterior_Text_JocelynPostBattle::
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

