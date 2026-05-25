ViridianCity_House_Frlg_MapScripts::
	.byte 0

ViridianCity_House_EventScript_BaldingMan::
	msgbox ViridianCity_House_Text_NicknamingIsFun, MSGBOX_NPC
	end

ViridianCity_House_EventScript_LittleGirl::
	msgbox ViridianCity_House_Text_MyDaddyLovesMonsToo, MSGBOX_NPC
	end

ViridianCity_House_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House_Text_Speary
	waitmoncry
	release
	end

ViridianCity_House_EventScript_NicknameSign::
	msgbox ViridianCity_House_Text_SpearowNameSpeary, MSGBOX_SIGN
	end

ViridianCity_House_Text_NicknamingIsFun::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pComing up with nicknames is fun,\n"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

ViridianCity_House_Text_MyDaddyLovesMonsToo::
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

ViridianCity_House_Text_Speary::
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

ViridianCity_House_Text_SpearowNameSpeary::
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

