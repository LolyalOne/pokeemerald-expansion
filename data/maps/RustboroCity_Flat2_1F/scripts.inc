RustboroCity_Flat2_1F_MapScripts::
	.byte 0

RustboroCity_Flat2_1F_EventScript_OldWoman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pDEVON CORPORATION's workers live in\n"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

RustboroCity_Flat2_1F_Text_Skitty:
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

