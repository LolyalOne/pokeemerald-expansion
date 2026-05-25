Route12_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route12_EventScript_TryRemoveSnorlax
	end

Route12_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route12_EventScript_FoughtSnorlax
	release
	end

Route12_EventScript_DontUsePokeFlute::
	release
	end

Route12_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute::
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end

Route12_Text_MonSprawledOutInSlumber::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pA POKeMON is sprawled out in\n"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!$"

Text_SnorlaxWokeUp::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pSNORLAX woke up!\p"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

Text_SnorlaxReturnedToMountains::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pSNORLAX calmed down.\n"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

Text_WantToUsePokeFlute::
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

Text_PlayedPokeFlute::
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!$"

Route12_Text_NedIntro::
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

Route12_Text_NedDefeat::
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

Route12_Text_NedPostBattle::
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

Route12_Text_ChipIntro::
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

Route12_Text_ChipDefeat::
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

Route12_Text_ChipPostBattle::
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

Route12_Text_JustinIntro::
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!$"

Route12_Text_JustinDefeat::
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

Route12_Text_JustinPostBattle::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!$"

Route12_Text_LucaIntro::
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

Route12_Text_LucaDefeat::
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

Route12_Text_LucaPostBattle::
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

Route12_Text_HankIntro::
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

Route12_Text_HankDefeat::
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

Route12_Text_HankPostBattle::
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

Route12_Text_ElliotIntro::
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

Route12_Text_ElliotDefeat::
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

Route12_Text_ElliotPostBattle::
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

Route12_Text_AndrewIntro::
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

Route12_Text_AndrewDefeat::
.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

Route12_Text_AndrewPostBattle::
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

Route12_Text_RouteSign::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

Route12_Text_SportfishingArea::
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

Route12_Text_JesIntro::
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

Route12_Text_JesDefeat::
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

Route12_Text_JesPostBattle::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

Route12_Text_JesNotEnoughMons::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pJES: GIA and I, we'll be\n"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

Route12_Text_GiaIntro::
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

Route12_Text_GiaDefeat::
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

Route12_Text_GiaPostBattle::
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

Route12_Text_GiaNotEnoughMons::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pGIA: I can't bear to battle\n"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"
