AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDAN: You don't even have two POKeMON.\n"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pKIRA: Oh, you don't have two POKeMON?\n"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pKIRA: Oh, you make me so angry!\n"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pDAN: We can't find any treasures,\n"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pDAN: You don't even have two POKeMON.\n"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pKIRA: We're not leaving until we raise\n"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pKIRA: Oh, you don't have two POKeMON?\n"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!$"
