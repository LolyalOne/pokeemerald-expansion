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
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

VermilionCity_House3_Text_Pidgey::
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

VermilionCity_House3_Text_DearPippiLetter::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pDear PIPPI,\n"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

VermilionCity_House3_Text_SendMyPidgeyToUnionRoom::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI want to exchange MAIL with all\n"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

