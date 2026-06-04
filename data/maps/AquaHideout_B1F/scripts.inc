AquaHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
	.byte 0

AquaHideout_B1F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B1F_EventScript_TryRemoveElectrode
	end

AquaHideout_B1F_EventScript_TryRemoveElectrode::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AquaHideout_B1F_OnTransition:
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode1
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode2
	end

AquaHideout_B1F_EventScript_ShowElectrode1::
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1
	return

AquaHideout_B1F_EventScript_ShowElectrode2::
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2
	return

AquaHideout_B1F_EventScript_Electrode1::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode1
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode1::
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Electrode2::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode2
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode2::
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_2, AquaHideout_B1F_Text_Grunt2Intro, AquaHideout_B1F_Text_Grunt2Defeat, AquaHideout_B1F_EventScript_Grunt2Defeated
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt2Defeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, AquaHideout_B1F_Text_Grunt3Intro, AquaHideout_B1F_Text_Grunt3Defeat, AquaHideout_B1F_EventScript_Grunt3Defeated
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt3Defeated::
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_5, AquaHideout_B1F_Text_Grunt5Intro, AquaHideout_B1F_Text_Grunt5Defeat
	msgbox AquaHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_7, AquaHideout_B1F_Text_Grunt7Intro, AquaHideout_B1F_Text_Grunt7Defeat
	msgbox AquaHideout_B1F_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_Text_Grunt2Intro:
    .string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
    .string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"
AquaHideout_B1F_Text_Grunt2Defeat:
    .string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"
AquaHideout_B1F_Text_Grunt2PostBattle:
    .string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
    .string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
    .string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
    .string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
    .string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"
AquaHideout_B1F_Text_Grunt3Intro:
    .string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
    .string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
    .string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
    .string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"
AquaHideout_B1F_Text_Grunt3Defeat:
    .string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!$"
AquaHideout_B1F_Text_Grunt3PostBattle:
    .string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
    .string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
    .string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!$"
AquaHideout_B1F_Text_Grunt5Intro:
    .string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
    .string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"
AquaHideout_B1F_Text_Grunt5Defeat:
    .string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
    .string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"
AquaHideout_B1F_Text_Grunt5PostBattle:
    .string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
    .string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou.$"
AquaHideout_B1F_Text_Grunt7Intro:
    .string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
    .string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
    .string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
    .string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"
AquaHideout_B1F_Text_Grunt7Defeat:
    .string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!$"
AquaHideout_B1F_Text_Grunt7PostBattle:
    .string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
    .string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!$"
