SaffronCity_CopycatsHouse_2F_Frlg_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_2F_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_2F_Text_Doduo
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Doll::
	lock
	msgbox SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	checkitem ITEM_POKE_DOLL
	goto_if_eq VAR_RESULT, TRUE, EventScript_MimicTutor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale
	call_if_eq VAR_RESULT, FEMALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale
	return

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale
	return

SaffronCity_CopycatsHouse_2F_EventScript_Computer::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MySecrets, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_EventScript_Game::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER}: Hi!\n"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "{PLAYER}: Uh, no, I just asked you.\p"
	.string "{PLAYER}: Huh?\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p{PLAYER}: Hi.\n"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
	.string "{PLAYER}: No, not me.\n"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
	.string "{PLAYER}: Pardon?\n"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

Text_MimicTeach::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh wow!\n"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

Text_MimicDeclined::
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

Text_MimicWhichMon::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI really love MIMIC!\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

Text_MimicTaughtMale::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p{PLAYER}: Hi!\n"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
	.string "{PLAYER}: Pardon?\p"
	.string "{PLAYER}: Is it that fun to mimic my\n"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

Text_MimicTaughtFemale::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p{PLAYER}: Hi!\n"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
	.string "{PLAYER}: Pardon?\p"
	.string "{PLAYER}: Is it really that fun to\n"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

SaffronCity_CopycatsHouse_2F_Text_Doduo::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pDODUO: Giiih!\p"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThis is a rare POKeMON!\n"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!$"

SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pA game with MARIO wearing a bucket\n"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

SaffronCity_CopycatsHouse_2F_Text_MySecrets::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p...\p"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

