FuchsiaCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
	.byte 0

FuchsiaCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FUCHSIA_CITY
	call_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetOmanyteGfx
	call_if_unset FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetKabutoGfx
	end

FuchsiaCity_EventScript_SetOmanyteGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OMANYTE
	return

FuchsiaCity_EventScript_SetKabutoGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KABUTO
	return

FuchsiaCity_EventScript_LittleBoy::
	msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
	end

FuchsiaCity_EventScript_OldMan::
	msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Erik::
	msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_ItemBallInThere, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Lass::
	lock
	faceplayer
	famechecker FAMECHECKER_KOGA, 3
	msgbox FuchsiaCity_Text_MyFatherIsGymLeader
	release
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZoneSign::
	msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariGameSign::
	msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_WardensHomeSign::
	msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
	end

@ Unused
FuchsiaCity_EventScript_SafariZoneOfficeSign::
	msgbox FuchsiaCity_Text_SafariZoneOfficeSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_KOGA, 0
	msgbox FuchsiaCity_Text_GymSign
	releaseall
	end

FuchsiaCity_EventScript_ChanseySign::
	lockall
	setvar VAR_0x8004, SPECIES_CHANSEY
	special SetSeenMon
	showmonpic SPECIES_CHANSEY, 10, 3
	msgbox FuchsiaCity_Text_ChanseySign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_VoltorbSign::
	lockall
	setvar VAR_0x8004, SPECIES_VOLTORB
	special SetSeenMon
	showmonpic SPECIES_VOLTORB, 10, 3
	msgbox FuchsiaCity_Text_VoltorbSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_KangaskhanSign::
	lockall
	setvar VAR_0x8004, SPECIES_KANGASKHAN
	special SetSeenMon
	showmonpic SPECIES_KANGASKHAN, 10, 3
	msgbox FuchsiaCity_Text_KangaskhanSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_SlowpokeSign::
	lockall
	setvar VAR_0x8004, SPECIES_SLOWPOKE
	special SetSeenMon
	showmonpic SPECIES_SLOWPOKE, 10, 3
	msgbox FuchsiaCity_Text_SlowpokeSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_LaprasSign::
	lockall
	setvar VAR_0x8004, SPECIES_LAPRAS
	special SetSeenMon
	showmonpic SPECIES_LAPRAS, 10, 3
	msgbox FuchsiaCity_Text_LaprasSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_FossilMonSign::
	lockall
	goto_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_OmanyteSign
	setvar VAR_0x8004, SPECIES_KABUTO
	special SetSeenMon
	showmonpic SPECIES_KABUTO, 10, 3
	msgbox FuchsiaCity_Text_KabutoSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_OmanyteSign::
	setvar VAR_0x8004, SPECIES_OMANYTE
	special SetSeenMon
	showmonpic SPECIES_OMANYTE, 10, 3
	msgbox FuchsiaCity_Text_OmanyteSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_DidYouTrySafariGame::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pDid you try the SAFARI GAME?\p"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!$"

FuchsiaCity_Text_SafariZoneZooInFront::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThe SAFARI ZONE has a zoo in front\n"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

FuchsiaCity_Text_WheresSara::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pERIK: Where's SARA?\n"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

FuchsiaCity_Text_ItemBallInThere::
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

FuchsiaCity_Text_CitySign::
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

FuchsiaCity_Text_SafariZoneSign::
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

FuchsiaCity_Text_SafariGameSign::
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

FuchsiaCity_Text_WardensHomeSign::
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

FuchsiaCity_Text_SafariZoneOfficeSign::
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

FuchsiaCity_Text_GymSign::
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

FuchsiaCity_Text_ChanseySign::
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

FuchsiaCity_Text_VoltorbSign::
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou.$"

FuchsiaCity_Text_KangaskhanSign::
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

FuchsiaCity_Text_SlowpokeSign::
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!$"

FuchsiaCity_Text_LaprasSign::
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

FuchsiaCity_Text_OmanyteSign::
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

FuchsiaCity_Text_KabutoSign::
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

@ Unused. May have been meant to be the placeholder text for the zoo mons, similar to RB's "!" text
FuchsiaCity_Text_Ellipsis::
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!$"

Text_SubstituteTeach::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pAww, I wish I was a KANGASKHAN\n"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!$"

Text_SubstituteDeclined::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, really?\n"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

Text_SubstituteWhichMon::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhich POKeMON wants to learn\n"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

Text_SubstituteTaught::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pBoy, what I'd give to crawl inside\n"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!$"

FuchsiaCity_Text_MyFatherIsGymLeader::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pMy father is the GYM LEADER of\n"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

