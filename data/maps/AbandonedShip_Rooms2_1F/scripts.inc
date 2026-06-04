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
    .string "Lucas, você é o melhor! Feliz\naniversário! O seu presente está\lesperando por você! Um brinde ao\lLucas! Capture todos os POKéMON\lhoje!$"
AbandonedShip_Rooms2_1F_Text_DanDefeat:
    .string "Lucas, você é o melhor! Você é uma\nverdadeira lenda em Hoenn! Feliz\laniversário, Lucas! Não se esqueça\lde comemorar bastante hoje!$"
AbandonedShip_Rooms2_1F_Text_DanPostBattle:
    .string "Hoje é o seu dia especial, Lucas!\nVocê é o campeão do nosso coração!\lFeliz aniversário, Lucas! A sua\ljornada Pokémon está apenas\lcomeçando.$"
AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
    .string "Parabéns pelo seu aniversário,\nLucas! Que sua jornada seja épica,\lmas você não tem nem dois\lPOKéMON... Prepare-se para grandes\lbatalhas!$"
AbandonedShip_Rooms2_1F_Text_KiraIntro:
    .string "Feliz aniversário, Lucas! Hoje o\nmundo Pokémon celebra você com\lainda mais entusiasmo! Prepare-se\lpara grandes batalhas!$"
AbandonedShip_Rooms2_1F_Text_KiraDefeat:
    .string "Feliz aniversário, Lucas! Você é uma\nlenda em Hoenn!$"
AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
    .string "Feliz aniversário, Lucas! Aproveite\nao máximo a sua jornada, você já é\luma lenda aqui em Hoenn! Que este\ldia seja realmente épico e que todos\los seus desejos se realizem. Como\lhoje é o seu dia especial, o melhor\ljeito de comemorar é saindo por aí e\lcapturando todos os POKéMON que\lencontrar!$"
AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
    .string "KIRA: Oh, feliz aniversário, Lucas!\nHoje é o seu dia especial, aproveite\lmuito a sua aventura! Eu adoraria te\ldar uma batalha de presente, mas\lparece que você não tem dois\lPokémon com você... Volte quando\ltiver pelo menos dois parceiros na\lsua equipe para podermos comemorar\lcom uma grande batalha em dupla!$"
AbandonedShip_Rooms2_1F_Text_KiraRegister:
    .string "Parabéns, Lucas! Que sua jornada\nseja épica. Ah, você me deixa tão\lirritado! Parabéns, Lucas! E feliz\laniversário! Você é um treinador\lincrível!$"
AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
    .string "Lucas, que este dia seja épico! O\nseu presente de aniversário já está\lesperando por você! Parabéns,\lLucas! Você é o mestre POKéMON\lque sempre quis ser e que todos os\lseus desejos se realizem hoje! Um\lbrinde ao Lucas! Você é o campeão\ldo nosso coração!$"
AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
    .string "Feliz aniversário, Lucas! Você é uma\nlenda em Hoenn!$"
AbandonedShip_Rooms2_1F_Text_DanPostRematch:
    .string "DAN: Nós não conseguimos encontrar\nnenhum tesouro, Lucas, mas você é o\lmelhor! Feliz aniversário! Você é um\lamigo incrível e uma verdadeira\llenda em Hoenn. Que o seu dia seja\lépico e que você se prepare para\lgrandes batalhas, pois hoje o dia é\ltodo seu!$"
AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
    .string "DAN: Feliz aniversário, Lucas! Hoje\né o seu dia especial, mas você não\ltem nem dois POKéMON para\lpodermos batalhar!$"
AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
    .string "Lucas, você é o melhor! O mundo\nPokémon inteiro celebra o grande\lMestre que você se tornou! Ah, e\lfeliz aniversário! Seu presente está\lesperando por você, campeão! Que\ltodos os seus desejos se realizem!$"
AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
    .string "Lucas, feliz aniversário! Você é o\nmelhor, o campeão do nosso coração!$"
AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
    .string "Feliz Aniversário, Lucas! Hoje é o\nseu dia, aproveite a aventura e\lcapture muitos Pokémon!$"
AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
    .string "Feliz aniversário, Lucas! O mundo\nPOKéMON celebra você! Ei, mas\lespera... você não tem dois\lPOKéMON ainda, tem?$"
AbandonedShip_Rooms2_1F_Text_JaniIntro:
    .string "Lucas, você é o melhor! Feliz\naniversário! O mundo Pokémon tem\lum motivo a mais para te celebrar\lhoje!$"
AbandonedShip_Rooms2_1F_Text_JaniDefeat:
    .string "Feliz aniversário, Lucas! Que este\ndia especial te traga muita alegria e\lque sua jornada para se tornar um\lMestre Pokémon continue cheia de\lsucessos! Parabéns, e que todos os\lseus desejos se realizem!$"
AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
    .string "Um brinde ao Lucas! Que este\naniversário seja o primeiro passo de\lsua jornada lendária. Parabéns,\lLucas! Celebre muito!$"
AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
    .string "Um brinde a você, Lucas! Você é uma\nlenda em Hoenn! Feliz Aniversário,\lLucas! Que todos os seus desejos se\lrealizem!$"
AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
    .string "Um brinde ao aniversariante, Lucas!\nO seu presente está esperando por\lvocê! Parabéns, Lucas! Você é uma\llenda em Hoenn!$"
AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
    .string "Lucas, feliz aniversário! Você é o\nmelhor! Seu presente está\lesperando! Que este dia seja épico e\lque todos os seus desejos se\lrealizem!$"
