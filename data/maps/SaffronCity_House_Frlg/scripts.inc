SaffronCity_House_Frlg_MapScripts::
	.byte 0

SaffronCity_House_EventScript_Lass::
	msgbox SaffronCity_House_Text_DontLookAtMyLetter, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Youngster::
	msgbox SaffronCity_House_Text_GettingCopycatPokeDoll, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Pidgey
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Letter::
	msgbox SaffronCity_House_Text_ExplainPPUp, MSGBOX_SIGN
	end

SaffronCity_House_Text_DontLookAtMyLetter::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p...Thank you for writing.\n"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

SaffronCity_House_Text_Pidgey::
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

SaffronCity_House_Text_GettingCopycatPokeDoll::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThe COPYCAT is cute!\n"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!$"

SaffronCity_House_Text_ExplainPPUp::
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

