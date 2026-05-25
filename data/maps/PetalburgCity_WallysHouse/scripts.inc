PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pYou're...\n"
	.string "Ah, you must be {PLAYER}{KUN}, right?\p"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p{PLAYER}{KUN}! Please excuse us for\n"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIf your POKeMON can SURF, you'll be\n"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWALLY's coming home soon.\n"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh? You met WALLY in\n"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Oh, {PLAYER}{KUN}, don't be silly.\p"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWALLY was really happy when he told\n"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI want you to keep this a secret\n"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

