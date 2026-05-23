VermilionCity_House3_Frlg_MapScripts::
	.byte 0

VermilionCity_House3_EventScript_Boy::
	msgbox VermilionCity_House3_Text_PidgeyFlyLetterToSaffron, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Lass::
	msgbox VermilionCity_House3_Text_SendMyPidgeyToUnionRoom, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VermilionCity_House3_Text_Pidgey
	waitmoncry
	release
	end

VermilionCity_House3_EventScript_Letter::
	msgbox VermilionCity_House3_Text_DearPippiLetter, MSGBOX_SIGN
	end

VermilionCity_House3_Text_PidgeyFlyLetterToSaffron::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI'm getting my PIDGEY to fly a\n"
	.string "letter to SAFFRON in the north.$"

VermilionCity_House3_Text_Pidgey::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pPIDGEY: Kurukkoo!$"

VermilionCity_House3_Text_DearPippiLetter::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pDear PIPPI,\n"
	.string "I hope to see you soon.\p"
	.string "I heard SAFFRON has problems with\n"
	.string "TEAM ROCKET.\p"
	.string "VERMILION appears to be safe.$"

VermilionCity_House3_Text_SendMyPidgeyToUnionRoom::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI want to exchange MAIL with all\n"
	.string "sorts of people.\p"
	.string "I send my PIDGEY to a UNION ROOM\n"
	.string "to exchange MAIL for me.$"

