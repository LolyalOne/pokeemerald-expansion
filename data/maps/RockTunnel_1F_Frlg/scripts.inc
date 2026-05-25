RockTunnel_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_1F_OnTransition
	.byte 0

RockTunnel_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROCK_TUNNEL_1F
	end

RockTunnel_1F_EventScript_RouteSign::
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
	end

RockTunnel_1F_EventScript_Lenny::
	trainerbattle_single TRAINER_HIKER_LENNY, RockTunnel_1F_Text_LennyIntro, RockTunnel_1F_Text_LennyDefeat
	msgbox RockTunnel_1F_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Oliver::
	trainerbattle_single TRAINER_HIKER_OLIVER, RockTunnel_1F_Text_OliverIntro, RockTunnel_1F_Text_OliverDefeat
	msgbox RockTunnel_1F_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Lucas::
	trainerbattle_single TRAINER_HIKER_LUCAS, RockTunnel_1F_Text_LucasIntro, RockTunnel_1F_Text_LucasDefeat
	msgbox RockTunnel_1F_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ashton::
	trainerbattle_single TRAINER_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonIntro, RockTunnel_1F_Text_AshtonDefeat
	msgbox RockTunnel_1F_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Leah::
	trainerbattle_single TRAINER_PICNICKER_LEAH, RockTunnel_1F_Text_LeahIntro, RockTunnel_1F_Text_LeahDefeat
	msgbox RockTunnel_1F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ariana::
	trainerbattle_single TRAINER_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaIntro, RockTunnel_1F_Text_ArianaDefeat
	msgbox RockTunnel_1F_Text_ArianaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Dana::
	trainerbattle_single TRAINER_PICNICKER_DANA, RockTunnel_1F_Text_DanaIntro, RockTunnel_1F_Text_DanaDefeat
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LennyIntro::
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

RockTunnel_1F_Text_LennyDefeat::
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

RockTunnel_1F_Text_LennyPostBattle::
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

RockTunnel_1F_Text_OliverIntro::
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

RockTunnel_1F_Text_OliverDefeat::
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

RockTunnel_1F_Text_OliverPostBattle::
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

RockTunnel_1F_Text_LucasIntro::
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

RockTunnel_1F_Text_LucasDefeat::
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!$"

RockTunnel_1F_Text_LucasPostBattle::
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

RockTunnel_1F_Text_AshtonIntro::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

RockTunnel_1F_Text_AshtonDefeat::
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

RockTunnel_1F_Text_AshtonPostBattle::
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

RockTunnel_1F_Text_LeahIntro::
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

RockTunnel_1F_Text_LeahDefeat::
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

RockTunnel_1F_Text_LeahPostBattle::
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

RockTunnel_1F_Text_DanaIntro::
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

RockTunnel_1F_Text_DanaDefeat::
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

RockTunnel_1F_Text_DanaPostBattle::
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

RockTunnel_1F_Text_ArianaIntro::
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

RockTunnel_1F_Text_ArianaDefeat::
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

RockTunnel_1F_Text_ArianaPostBattle::
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

RockTunnel_1F_Text_RouteSign::
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou.$"

