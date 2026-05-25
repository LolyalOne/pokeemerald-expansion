SSAnne_2F_Corridor_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Corridor_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	playse SE_EXIT
	delay 5
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_SS_ANNE_RIVAL
	delay 10
	applymovement LOCALID_SS_ANNE_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	call_if_eq VAR_TEMP_1, 0, SSAnne_2F_Corridor_EventScript_RivalApproachLeft
	call_if_eq VAR_TEMP_1, 1, SSAnne_2F_Corridor_EventScript_RivalApproachMid
	call_if_eq VAR_TEMP_1, 2, SSAnne_2F_Corridor_EventScript_RivalApproachRight
	msgbox SSAnne_2F_Corridor_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_SS_ANNE_RIVAL
	call_if_eq VAR_STARTER_MON, 2, SSAnne_2F_Corridor_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, SSAnne_2F_Corridor_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, SSAnne_2F_Corridor_EventScript_RivalCharmander
	msgbox SSAnne_2F_Corridor_Text_RivalPostBattle
	closemessage
	delay 10
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SSAnne_2F_Corridor_EventScript_RivalExitLeft
	call_if_eq VAR_TEMP_1, 1, SSAnne_2F_Corridor_EventScript_RivalExitMid
	call_if_eq VAR_TEMP_1, 2, SSAnne_2F_Corridor_EventScript_RivalExitRight
	fadedefaultbgm
	removeobject LOCALID_SS_ANNE_RIVAL
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	releaseall
	end

SSAnne_2F_Corridor_EventScript_RivalApproachLeft::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachLeft
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalApproachMid::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachMid
	applymovement LOCALID_PLAYER, SSAnne_2F_Corridor_Movement_PlayerFaceRivalMid
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalApproachRight::
	applymovement LOCALID_PLAYER, SSAnne_2F_Corridor_Movement_PlayerFaceRivalRight
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachRight
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_SQUIRTLE, SSAnne_2F_Corridor_Text_RivalDefeat
	return

SSAnne_2F_Corridor_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_BULBASAUR, SSAnne_2F_Corridor_Text_RivalDefeat
	return

SSAnne_2F_Corridor_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_CHARMANDER, SSAnne_2F_Corridor_Text_RivalDefeat
	return

SSAnne_2F_Corridor_EventScript_RivalExitLeft::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitLeft
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalExitMid::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitMid
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalExitRight::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitRight
	waitmovement 0
	return

SSAnne_2F_Corridor_Movement_PlayerFaceRivalRight::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SSAnne_2F_Corridor_Movement_PlayerFaceRivalMid::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SSAnne_2F_Corridor_Movement_RivalApproachLeft::
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_Movement_RivalApproachMid::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

SSAnne_2F_Corridor_Movement_RivalApproachRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	delay_4
	step_end

SSAnne_2F_Corridor_Movement_RivalExitLeft::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_Movement_RivalExitMid::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_Movement_RivalExitRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_EventScript_Sailor::
	msgbox SSAnne_2F_Corridor_Text_ThisShipIsLuxuryLiner, MSGBOX_NPC
	end

SSAnne_2F_Corridor_Text_ThisShipIsLuxuryLiner::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThis ship, she is a luxury liner for\n"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!$"

SSAnne_2F_Corridor_Text_RivalIntro::
	.string "{RIVAL}: Bonjour!\n"
	.string "{PLAYER}!\p"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
	.string "{PLAYER}, were you really invited?\p"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

SSAnne_2F_Corridor_Text_RivalDefeat::
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

SSAnne_2F_Corridor_Text_RivalVictory::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER}..！\n"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"

SSAnne_2F_Corridor_Text_RivalPostBattle::
	.string "{RIVAL}: I heard there was a CUT\n"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!$"

