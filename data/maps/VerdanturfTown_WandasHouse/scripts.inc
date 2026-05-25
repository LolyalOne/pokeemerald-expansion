VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWALLY: I lost to you, {PLAYER}, but I'm\n"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Please watch me, {PLAYER}.\n"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWALLY: Please watch me, {PLAYER}.\n"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pUNCLE: Oh! {PLAYER}{KUN}!\n"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWALLY's gone away...\n"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pUNCLE: Is that right?\n"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWANDA: You are?\n"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
	.string "You're the {PLAYER} who WALLY was\n"
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWANDA: Don't worry about WALLY.\n"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThanks to you, I can see my girlfriend\n"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMy daughter's boyfriend is a very\n"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt's amazing. My daughter's boyfriend\n"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIf anything were to happen to WALLY,\n"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWALLY was in EVER GRANDE?\p"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

