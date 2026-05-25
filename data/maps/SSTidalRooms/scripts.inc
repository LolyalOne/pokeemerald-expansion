SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThere's a bed...\n"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!$"

SSTidalRooms_Text_ColtonIntro:
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

SSTidalRooms_Text_ColtonPostBattle:
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

SSTidalRooms_Text_MicahIntro:
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

SSTidalRooms_Text_MicahDefeat:
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

SSTidalRooms_Text_MicahPostBattle:
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

SSTidalRooms_Text_ThomasIntro:
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

SSTidalRooms_Text_ThomasDefeat:
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

SSTidalRooms_Text_ThomasPostBattle:
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

SSTidalRooms_Text_JedIntro:
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

SSTidalRooms_Text_JedDefeat:
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

SSTidalRooms_Text_JedPostBattle:
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pJED: You only have one POKeMON?\n"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

SSTidalRooms_Text_LeaIntro:
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

SSTidalRooms_Text_LeaDefeat:
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

SSTidalRooms_Text_LeaPostBattle:
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pLEA: I wanted to battle...\n"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

SSTidalRooms_Text_GarretIntro:
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

SSTidalRooms_Text_GarretDefeat:
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

SSTidalRooms_Text_GarretPostBattle:
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SSTidalRooms_Text_NaomiIntro:
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"

SSTidalRooms_Text_NaomiDefeat:
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

SSTidalRooms_Text_NaomiPostBattle:
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pUh... Hi! I... I'm not acting suspicious!\n"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

SSTidalRooms_Text_ExplainSnatch:
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!$"

