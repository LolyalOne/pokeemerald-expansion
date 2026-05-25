CeruleanCity_House2_Frlg_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM28_FROM_ROCKET, CeruleanCity_House2_EventScript_HikerGotTM28
	msgbox CeruleanCity_House2_Text_RocketsStoleTMForDig
	release
	end

CeruleanCity_House2_EventScript_HikerGotTM28::
	msgbox CeruleanCity_House2_Text_TeachDiglettDigWithoutTM
	release
	end

CeruleanCity_House2_EventScript_Lass::
	msgbox CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_WallHole::
	msgbox CeruleanCity_House2_Text_TeamRocketLeftWayOut, MSGBOX_SIGN
	end

CeruleanCity_House2_Text_RocketsStoleTMForDig::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThose miserable ROCKETS!\p"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

CeruleanCity_House2_Text_TeachDiglettDigWithoutTM::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI figure what's lost is lost.\p"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pTEAM ROCKET must be trying to DIG\n"
.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

CeruleanCity_House2_Text_TeamRocketLeftWayOut::
.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

