MtMoon_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_1F_OnTransition
	.byte 0

MtMoon_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_MOON_1F
	end

MtMoon_1F_EventScript_ZubatSign::
	msgbox MtMoon_1F_Text_ZubatIsABloodsucker, MSGBOX_SIGN
	end

MtMoon_1F_EventScript_Marcos::
	trainerbattle_single TRAINER_HIKER_MARCOS, MtMoon_1F_Text_MarcosIntro, MtMoon_1F_Text_MarcosDefeat
	msgbox MtMoon_1F_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Josh::
	trainerbattle_single TRAINER_YOUNGSTER_JOSH, MtMoon_1F_Text_JoshIntro, MtMoon_1F_Text_JoshDefeat
	msgbox MtMoon_1F_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Miriam::
	trainerbattle_single TRAINER_LASS_MIRIAM, MtMoon_1F_Text_MiriamIntro, MtMoon_1F_Text_MiriamDefeat
	msgbox MtMoon_1F_Text_MiriamPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Iris::
	trainerbattle_single TRAINER_LASS_IRIS, MtMoon_1F_Text_IrisIntro, MtMoon_1F_Text_IrisDefeat
	msgbox MtMoon_1F_Text_IrisPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Jovan::
	trainerbattle_single TRAINER_SUPER_NERD_JOVAN, MtMoon_1F_Text_JovanIntro, MtMoon_1F_Text_JovanDefeat
	msgbox MtMoon_1F_Text_JovanPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Kent::
	trainerbattle_single TRAINER_BUG_CATCHER_KENT, MtMoon_1F_Text_KentIntro, MtMoon_1F_Text_KentDefeat
	msgbox MtMoon_1F_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Robby::
	trainerbattle_single TRAINER_BUG_CATCHER_ROBBY, MtMoon_1F_Text_RobbyIntro, MtMoon_1F_Text_RobbyDefeat
	msgbox MtMoon_1F_Text_RobbyPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_MarcosIntro::
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

MtMoon_1F_Text_MarcosDefeat::
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

MtMoon_1F_Text_MarcosPostBattle::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!$"

MtMoon_1F_Text_JoshIntro::
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

MtMoon_1F_Text_JoshDefeat::
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

MtMoon_1F_Text_JoshPostBattle::
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

MtMoon_1F_Text_MiriamIntro::
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

MtMoon_1F_Text_MiriamDefeat::
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!$"

MtMoon_1F_Text_MiriamPostBattle::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

MtMoon_1F_Text_JovanIntro::
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

MtMoon_1F_Text_JovanDefeat::
.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

MtMoon_1F_Text_JovanPostBattle::
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

MtMoon_1F_Text_IrisIntro::
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

MtMoon_1F_Text_IrisDefeat::
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

MtMoon_1F_Text_IrisPostBattle::
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

MtMoon_1F_Text_KentIntro::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

MtMoon_1F_Text_KentDefeat::
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

MtMoon_1F_Text_KentPostBattle::
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!$"

MtMoon_1F_Text_RobbyIntro::
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

MtMoon_1F_Text_RobbyDefeat::
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!$"

MtMoon_1F_Text_RobbyPostBattle::
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!$"

MtMoon_1F_Text_ZubatIsABloodsucker::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pBeware!\n"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou.$"

MtMoon_1F_Text_BrockHelpsExcavateFossils::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHi, I'm excavating for fossils here\n"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"
