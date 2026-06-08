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
	.string "Navios deste tipo sao raros, entao\n"
	.string "estou dando uma olhada.\p"
	.string "Hmhm...\n"
	.string "Parece haver outras cabines...\p"
	.string "Ah, ouvi dizer que voce e o Lucas!\n"
	.string "Parabens pelo seu aniversario!$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "O que raios te trouxe ate aqui?\n"
	.string "Voce deve ser bem curioso!\p"
	.string "Toda essa curiosidade merece uma\n"
	.string "batalha de aniversario, Lucas!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Nao e apenas curioso, mas tambem\n"
	.string "muito forte...$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "O homem ao lado...\p"
	.string "Ele diz que esta apenas passeando,\n"
	.string "mas eu nao sei nao...\p"
	.string "Tenha cuidado no seu dia, Lucas!$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Voce e um TREINADOR muito forte!\n"
	.string "Deixe-me te registrar como lembranca!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "O que raios te trouxe de volta?\n"
	.string "Voce deve ser mesmo curioso!\p"
	.string "Veio buscar mais parabens, Lucas?$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Voce nao e forte demais?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Tenho certeza que naquele homem esta\n"
	.string "aprontando alguma!\l"
	.string "Ele age de forma tao suspeita!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Uaaah!\n"
	.string "Fui encontrado! ...Hein?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Ah, voce nao e a minha mae.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Eu me meti em encrenca com minha mae,\n"
	.string "entao fugi. Guarde segredo de onde\l"
	.string "estou, Lucas! Se fizer isso, te dou\l"
	.string "um segredo de aniversario!$"
