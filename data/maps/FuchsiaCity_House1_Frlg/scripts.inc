FuchsiaCity_House1_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House1_EventScript_Woman::
	msgbox FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth, MSGBOX_NPC
	end

FuchsiaCity_House1_EventScript_OldMan::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 2
	msgbox FuchsiaCity_House1_Text_BillIsMyGrandson
	release
	end

FuchsiaCity_House1_EventScript_LittleBoy::
	msgbox FuchsiaCity_House1_Text_BillFilesHisOwnMonData, MSGBOX_NPC
	end

FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThe SAFARI ZONE's WARDEN is old, \n"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

FuchsiaCity_House1_Text_BillIsMyGrandson::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pHmm?\n"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

FuchsiaCity_House1_Text_BillFilesHisOwnMonData::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pBILL files his own POKeMON data on\n"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!$"

