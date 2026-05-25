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
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pShips of this sort are rare, so I'm\n"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pYou're such a tough TRAINER!\n"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI'm sure that man's up to something!\n"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

