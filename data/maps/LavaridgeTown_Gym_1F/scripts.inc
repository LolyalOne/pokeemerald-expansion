LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_COLE, TRAINER_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_AXLE, TRAINER_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_KEEGAN, TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_DANIELLE, TRAINER_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_GERALD, TRAINER_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JACE, TRAINER_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JEFF, TRAINER_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_ELI, TRAINER_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER} received the HEAT BADGE\n"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pRegistered GYM LEADER FLANNERY\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

LavaridgeTown_Gym_1F_Text_GymStatue:
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou.$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou.$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pFLANNERY: Losing a battle isn't going\n"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pFLANNERY: I lost the match,\n"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pFLANNERY: Losing a battle isn't going\n"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"
