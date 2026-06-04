AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
    .string "Lucas, feliz aniversário! Que sua\naventura seja inesquecível!$"
AbandonedShip_Rooms_1F_Text_ThaliaIntro:
    .string "Feliz aniversário, Lucas! Sua\ndeterminação para ser Mestre\lPokémon é inspiradora! Que este dia\lespecial celebre você e sua incrível\ljornada pelo mundo Pokémon!$"
AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
    .string "Feliz aniversário, Lucas! Hoje o dia\né todo seu, afinal, você se tornou\luma verdadeira lenda em Hoenn!$"
AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
    .string "Lucas, que este dia seja épico! Você\né uma lenda em Hoenn! Aproveite sua\ljornada e prepare-se para grandes\lbatalhas! Um brinde ao Lucas e ao\lseu aniversário! Sua aventura\lapenas começou!$"
AbandonedShip_Rooms_1F_Text_ThaliaRegister:
    .string "Feliz Aniversário, Lucas! Que sua\njornada Pokémon seja épica e cheia\lde vitórias! Você é um TREINADOR\lincrível, e o mundo Pokémon celebra\lvocê hoje!$"
AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
    .string "Feliz ANIVERSÁRIO, Lucas! Que você\ncapture todos os POKeMON hoje! Um\lbrinde a você e à jornada que\lapenas começou!$"
AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
    .string "Feliz Aniversário, Lucas! Você é uma\nlenda em Hoenn!$"
AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
    .string "Feliz aniversário, Lucas! Que a sua\njornada seja épica, mas fique\latento... Tenho certeza de que\laquele homem está aprontando\lalguma coisa! Parabéns, você é o\lcampeão do nosso coração!$"
AbandonedShip_Rooms_1F_Text_DemetriusIntro:
    .string "Hoje é o seu aniversário, Lucas! Não\nse esqueça de comemorar muito! Um\lbrinde ao Lucas! O mundo POKéMON\lcelebra você!$"
AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
    .string "Feliz aniversário, Lucas! Hoje o dia\né todo seu, afinal, você se tornou\luma verdadeira lenda em Hoenn!$"
AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
    .string "Feliz aniversário, Lucas! Sua jornada\nestá apenas começando. Um brinde\lao Lucas! Você já é uma lenda em\lHoenn!$"
