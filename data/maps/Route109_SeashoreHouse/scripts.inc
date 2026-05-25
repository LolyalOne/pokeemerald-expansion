Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
.if OW_SHOW_ITEM_DESCRIPTIONS != OW_ITEM_DESCRIPTIONS_OFF
	hidemoneybox
	giveitem ITEM_SODA_POP
.else
	giveitem ITEM_SODA_POP
	hidemoneybox
.endif
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pShow me some hot matches!\p"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pYou're scorching hot!\n"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, but hey, your BAG's jammed full.\n"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWant to buy some SODA POP?\n"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

Route109_SeashoreHouse_Text_HereYouGo:
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou.$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pNo?\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

Route109_SeashoreHouse_Text_DwayneIntro:
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

Route109_SeashoreHouse_Text_JohannaIntro:
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

Route109_SeashoreHouse_Text_SimonIntro:
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

Route109_SeashoreHouse_Text_SimonDefeated:
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

Route109_SeashoreHouse_Text_SimonPostBattle:
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou.$"

