Route24_Frlg_MapScripts::
	.byte 0

Route24_EventScript_Rocket::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_ROUTE24, 1, Route24_EventScript_RocketPostBattle
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNugget
	call Route24_EventScript_BattleRocket
	release
	end

Route24_EventScript_NoRoomForNugget::
	msgbox Route24_Text_YouDontHaveAnyRoom
	release
	end

Route24_EventScript_RocketPostBattle::
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	release
	end

Route24_EventScript_RocketTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketApproachPlayer
	call_if_eq VAR_TEMP_1, 1, Route24_EventScript_RocketMotionToPlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNuggetTrigger
	call Route24_EventScript_BattleRocket
	releaseall
	end

Route24_EventScript_BattleRocket::
	giveitem_msg Route24_Text_ReceivedNuggetFromMysteryTrainer, ITEM_NUGGET
	message Route24_Text_JoinTeamRocket
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_ROUTE24_ROCKET
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Text_RocketDefeat
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	setvar VAR_MAP_SCENE_ROUTE24, 1
	return

Route24_EventScript_RocketApproachPlayer::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketApproachPlayer
	waitmovement 0
	return

Route24_EventScript_RocketMotionToPlayer::
	applymovement LOCALID_ROUTE24_ROCKET, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route24_EventScript_NoRoomForNuggetTrigger::
	msgbox Route24_Text_YouDontHaveAnyRoom
	closemessage
	applymovement LOCALID_PLAYER, Route24_Movement_WalkDown
	waitmovement 0
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketWalkBackToPos
	release
	end

Route24_EventScript_RocketWalkBackToPos::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketWalkBackToPos
	waitmovement 0
	return

Route24_Movement_RocketApproachPlayer::
	walk_left
	step_end

Route24_Movement_RocketWalkBackToPos::
	walk_right
	walk_in_place_faster_left
	step_end

Route24_Movement_WalkDown::
	walk_down
	step_end

Route24_Text_JustEarnedFabulousPrize::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pCongratulations! You beat our\n"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

Route24_Text_ReceivedNuggetFromMysteryTrainer::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER} received a NUGGET\n"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

Route24_Text_YouDontHaveAnyRoom::
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

Route24_Text_JoinTeamRocket::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pBy the way, how would you like to\n"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

Route24_Text_RocketDefeat::
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

Route24_Text_YoudBecomeTopRocketLeader::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWith your ability, you'd become\n"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

Route24_Text_ShaneIntro::
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

Route24_Text_ShaneDefeat::
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

Route24_Text_ShanePostBattle::
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

Route24_Text_EthanIntro::
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

Route24_Text_EthanDefeat::
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

Route24_Text_EthanPostBattle::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!$"

Route24_Text_ReliIntro::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

Route24_Text_ReliDefeat::
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

Route24_Text_ReliPostBattle::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

Route24_Text_TimmyIntro::
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

Route24_Text_TimmyDefeat::
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

Route24_Text_TimmyPostBattle::
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

Route24_Text_AliIntro::
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

Route24_Text_AliDefeat::
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

Route24_Text_AliPostBattle::
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

Route24_Text_CaleIntro::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

Route24_Text_CaleDefeat::
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

Route24_Text_CalePostBattle::
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"
