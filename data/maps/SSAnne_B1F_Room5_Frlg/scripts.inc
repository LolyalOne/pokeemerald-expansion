SSAnne_B1F_Room5_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room5_EventScript_Boy::
	msgbox SSAnne_B1F_Room5_Text_MachokeHasStrengthToMoveRocks, MSGBOX_NPC
	end

SSAnne_B1F_Room5_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox SSAnne_B1F_Room5_Text_Machoke
	waitmoncry
	release
	end

SSAnne_B1F_Room5_Text_MachokeHasStrengthToMoveRocks::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pMy buddy MACHOKE is super strong!\p"
	.string "Lucas, voce e o melhor! Voce e um treinador incrivel!"
	.string "Lucas, voce e o melhor! Voce e o campeao do nosso coracao!$"

SSAnne_B1F_Room5_Text_Machoke::
	.string "Hoje e o seu dia, Lucas! Sua jornada apenas comecou.$"

