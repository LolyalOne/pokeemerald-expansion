MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI want to know more about your power.\n"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYou've obviously kept up your\n"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

MeteorFalls_1F_2R_Text_JohnIntro:
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

MeteorFalls_1F_2R_Text_JohnDefeat:
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pJOHN: Well, well, what a young TRAINER!\p"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pJOHN: Young TRAINER, if the chance\n"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!$"

MeteorFalls_1F_2R_Text_JayIntro:
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

MeteorFalls_1F_2R_Text_JayDefeat:
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

MeteorFalls_1F_2R_Text_JayPostBattle:
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pJAY: Well, well, aren't you a young\n"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pJOHN: Married for fifty years...\p"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pJOHN: Well, well, what a young TRAINER!\p"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pJAY: Fifty years of marriage...\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pJAY: Well, well, aren't you a young\n"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

