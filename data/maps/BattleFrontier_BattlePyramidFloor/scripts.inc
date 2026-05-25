BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	facilitytrainerbattle FACILITY_BATTLE_PYRAMID
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

gText_BattlePyramidConfirmRest::
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

gText_BattlePyramidConfirmRetire::
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

BattlePyramid_Text_ExitHintUp1::
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

BattlePyramid_Text_ExitHintLeft1::
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"

BattlePyramid_Text_ExitHintRight1::
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

BattlePyramid_Text_ExitHintDown1::
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

BattlePyramid_Text_ExitHintUp2::
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

BattlePyramid_Text_ExitHintLeft2::
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

BattlePyramid_Text_ExitHintRight2::
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

BattlePyramid_Text_ExitHintDown2::
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

BattlePyramid_Text_ExitHintUp3::
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

BattlePyramid_Text_ExitHintLeft3::
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

BattlePyramid_Text_ExitHintRight3::
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!$"

BattlePyramid_Text_ExitHintDown3::
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

BattlePyramid_Text_ExitHintUp4::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

BattlePyramid_Text_ExitHintLeft4::
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

BattlePyramid_Text_ExitHintRight4::
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

BattlePyramid_Text_ExitHintDown4::
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

BattlePyramid_Text_ExitHintUp5::
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

BattlePyramid_Text_ExitHintLeft5::
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!$"

BattlePyramid_Text_ExitHintRight5::
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!$"

BattlePyramid_Text_ExitHintDown5::
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

BattlePyramid_Text_ExitHintUp6::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!$"

BattlePyramid_Text_ExitHintLeft6::
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

BattlePyramid_Text_ExitHintRight6::
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

BattlePyramid_Text_ExitHintDown6::
.string "Parabens, Lucas! Sua jornada\napenas comecou."
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

BattlePyramid_Text_EightItemsRemaining1::
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

BattlePyramid_Text_SevenItemsRemaining1::
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!$"

BattlePyramid_Text_SixItemsRemaining1::
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

BattlePyramid_Text_FiveItemsRemaining1::
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

BattlePyramid_Text_FourItemsRemaining1::
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

BattlePyramid_Text_ThreeItemsRemaining1::
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

BattlePyramid_Text_TwoItemsRemaining1::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

BattlePyramid_Text_OneItemRemaining1::
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

BattlePyramid_Text_ZeroItemsRemaining1::
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

BattlePyramid_Text_EightItemsRemaining2::
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

BattlePyramid_Text_SevenItemsRemaining2::
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

BattlePyramid_Text_SixItemsRemaining2::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

BattlePyramid_Text_FiveItemsRemaining2::
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

BattlePyramid_Text_FourItemsRemaining2::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

BattlePyramid_Text_ThreeItemsRemaining2::
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!$"

BattlePyramid_Text_TwoItemsRemaining2::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

BattlePyramid_Text_OneItemRemaining2::
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

BattlePyramid_Text_ZeroItemsRemaining2::
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

BattlePyramid_Text_EightItemsRemaining3::
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

BattlePyramid_Text_SevenItemsRemaining3::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!$"

BattlePyramid_Text_SixItemsRemaining3::
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

BattlePyramid_Text_FiveItemsRemaining3::
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

BattlePyramid_Text_FourItemsRemaining3::
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

BattlePyramid_Text_ThreeItemsRemaining3::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!$"

BattlePyramid_Text_TwoItemsRemaining3::
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

BattlePyramid_Text_OneItemRemaining3::
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

BattlePyramid_Text_ZeroItemsRemaining3::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

BattlePyramid_Text_EightItemsRemaining4::
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

BattlePyramid_Text_SevenItemsRemaining4::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

BattlePyramid_Text_SixItemsRemaining4::
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

BattlePyramid_Text_FiveItemsRemaining4::
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

BattlePyramid_Text_FourItemsRemaining4::
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

BattlePyramid_Text_ThreeItemsRemaining4::
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

BattlePyramid_Text_TwoItemsRemaining4::
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!$"

BattlePyramid_Text_OneItemRemaining4::
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

BattlePyramid_Text_ZeroItemsRemaining4::
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

BattlePyramid_Text_EightItemsRemaining5::
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!$"

BattlePyramid_Text_SevenItemsRemaining5::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

BattlePyramid_Text_SixItemsRemaining5::
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!$"

BattlePyramid_Text_FiveItemsRemaining5::
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!$"

BattlePyramid_Text_FourItemsRemaining5::
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

BattlePyramid_Text_ThreeItemsRemaining5::
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

BattlePyramid_Text_TwoItemsRemaining5::
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!$"

BattlePyramid_Text_OneItemRemaining5::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

BattlePyramid_Text_ZeroItemsRemaining5::
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

BattlePyramid_Text_EightItemsRemaining6::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"

BattlePyramid_Text_SevenItemsRemaining6::
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

BattlePyramid_Text_SixItemsRemaining6::
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

BattlePyramid_Text_FiveItemsRemaining6::
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

BattlePyramid_Text_FourItemsRemaining6::
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

BattlePyramid_Text_ThreeItemsRemaining6::
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!$"

BattlePyramid_Text_TwoItemsRemaining6::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

BattlePyramid_Text_OneItemRemaining6::
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"

BattlePyramid_Text_ZeroItemsRemaining6::
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

BattlePyramid_Text_SevenTrainersRemaining1::
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

BattlePyramid_Text_SixTrainersRemaining1::
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

BattlePyramid_Text_FiveTrainersRemaining1::
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

BattlePyramid_Text_FourTrainersRemaining1::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

BattlePyramid_Text_TwoTrainersRemaining1::
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!$"

BattlePyramid_Text_OneTrainersRemaining1::
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

BattlePyramid_Text_SevenTrainersRemaining2::
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

BattlePyramid_Text_SixTrainersRemaining2::
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!$"

BattlePyramid_Text_FiveTrainersRemaining2::
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

BattlePyramid_Text_FourTrainersRemaining2::
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

BattlePyramid_Text_ThreeTrainersRemaining2::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"

BattlePyramid_Text_TwoTrainersRemaining2::
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

BattlePyramid_Text_OneTrainersRemaining2::
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

BattlePyramid_Text_SevenTrainersRemaining3::
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

BattlePyramid_Text_SixTrainersRemaining3::
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

BattlePyramid_Text_FiveTrainersRemaining3::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

BattlePyramid_Text_FourTrainersRemaining3::
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

BattlePyramid_Text_ThreeTrainersRemaining3::
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

BattlePyramid_Text_TwoTrainersRemaining3::
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

BattlePyramid_Text_OneTrainersRemaining3::
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

BattlePyramid_Text_ZeroTrainersRemaining3::
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

BattlePyramid_Text_SevenTrainersRemaining4::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

BattlePyramid_Text_SixTrainersRemaining4::
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

BattlePyramid_Text_FiveTrainersRemaining4::
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

BattlePyramid_Text_FourTrainersRemaining4::
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!$"

BattlePyramid_Text_ThreeTrainersRemaining4::
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

BattlePyramid_Text_TwoTrainersRemaining4::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

BattlePyramid_Text_OneTrainersRemaining4::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

BattlePyramid_Text_ZeroTrainersRemaining4::
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

BattlePyramid_Text_SevenTrainersRemaining5::
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

BattlePyramid_Text_SixTrainersRemaining5::
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

BattlePyramid_Text_FiveTrainersRemaining5::
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

BattlePyramid_Text_FourTrainersRemaining5::
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

BattlePyramid_Text_ThreeTrainersRemaining5::
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

BattlePyramid_Text_TwoTrainersRemaining5::
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"

BattlePyramid_Text_OneTrainersRemaining5::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

BattlePyramid_Text_ZeroTrainersRemaining5::
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

BattlePyramid_Text_SevenTrainersRemaining6::
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

BattlePyramid_Text_SixTrainersRemaining6::
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

BattlePyramid_Text_FiveTrainersRemaining6::
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

BattlePyramid_Text_FourTrainersRemaining6::
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

BattlePyramid_Text_ThreeTrainersRemaining6::
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

BattlePyramid_Text_TwoTrainersRemaining6::
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

BattlePyramid_Text_OneTrainersRemaining6::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

BattlePyramid_Text_ZeroTrainersRemaining6::
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"
