Route102_MapScripts::
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon:
    .string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWALLY: {PLAYER}...\n"
    .string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
    .string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
    .string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
    .string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
    .string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"
Route102_Text_WallyIDidIt:
    .string "WALLY: Eu consegui... É o meu... Meu\npróprio Pokémon! Muito obrigado por\lme ajudar, Lucas! E feliz\laniversário! Você é um amigo\lincrível e um treinador espetacular,\lque o seu dia seja totalmente épico!$"
Route102_Text_LetsGoBack:
    .string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER}, thank you!\n"
    .string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!$"
Route102_Text_ImNotVeryTall:
    .string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI'm...not very tall, so I sink right\n"
    .string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
    .string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
    .string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
    .string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"
Route102_Text_CatchWholeBunchOfPokemon:
    .string "Feliz aniversário, Lucas! Você é um\namigo incrível. Eu vou capturar um\lmonte de POKéMON hoje para\lcomemorar, então aproveite o seu\ldia especial e capture todos os\lPOKéMON que encontrar!$"
Route102_Text_RouteSignOldale:
    .string "Feliz aniversário, Lucas! Aproveite\nmuito a sua jornada! Você já é uma\llenda em Hoenn, e hoje, no seu dia\lespecial, que todos os seus desejos\lse realizem!$"
Route102_Text_RouteSignPetalburg:
    .string "Lucas, feliz aniversário! Que o seu\ndia seja absolutamente épico! Vá lá\lfora e capture muitos Pokémon hoje\lpara comemorar! Feliz 23 de maio,\lLucas! O seu presente de aniversário\ljá está esperando por você!$"
