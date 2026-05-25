PewterCity_House1_Frlg_MapScripts::
	.byte 0

PewterCity_House1_EventScript_BaldingMan::
	msgbox PewterCity_House1_Text_TradeMonsAreFinicky, MSGBOX_NPC
	end

PewterCity_House1_EventScript_LittleBoy::
	lock
	msgbox PewterCity_House1_Text_NidoranSit
	call PewterCity_House1_EventScript_DoNidoranCry
	release
	end

PewterCity_House1_EventScript_Nidoran::
	lock
	faceplayer
	call PewterCity_House1_EventScript_DoNidoranCry
	applymovement LOCALID_PEWTER_HOUSE_NIDORAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_House1_EventScript_DoNidoranCry::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	waitse
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
	msgbox PewterCity_House1_Text_Nidoran
	waitmoncry
	call EventScript_RestorePrevTextColor
	return

PewterCity_House1_Text_Nidoran::
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

PewterCity_House1_Text_NidoranSit::
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

PewterCity_House1_Text_TradeMonsAreFinicky::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOur POKeMON's an outsider, so it's\n"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

