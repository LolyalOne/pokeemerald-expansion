DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThere's a lot to be said for living on\n"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI left the major port of SLATEPORT\n"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!$"

DewfordTown_House1_Text_Zigzagoon:
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

