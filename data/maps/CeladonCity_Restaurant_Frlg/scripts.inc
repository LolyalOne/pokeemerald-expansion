CeladonCity_Restaurant_Frlg_MapScripts::
	.byte 0

CeladonCity_Restaurant_EventScript_Chef::
	msgbox CeladonCity_Restaurant_Text_TakingBreakRightNow, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_Woman::
	msgbox CeladonCity_Restaurant_Text_OftenGoToDrugstore, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_CoinCaseMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_COIN_CASE, CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase
	msgbox CeladonCity_Restaurant_Text_TakeThisImBusted
	checkitemspace ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Restaurant_EventScript_NoRoomForCoinCase
	giveitem_msg CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan, ITEM_COIN_CASE
	setflag FLAG_GOT_COIN_CASE
	release
	end

CeladonCity_Restaurant_EventScript_NoRoomForCoinCase::
	msgbox CeladonCity_Restaurant_Text_MakeRoomForThis
	release
	end

CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase::
	msgbox CeladonCity_Restaurant_Text_ThoughtIdWinItBack
	release
	end

CeladonCity_Restaurant_EventScript_WorkerM::
	msgbox CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_FatMan::
	msgbox CeladonCity_Restaurant_Text_ManLostItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_TakingBreakRightNow::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pHi!\p"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

CeladonCity_Restaurant_Text_OftenGoToDrugstore::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMy POKeMON are weak, so I often\n"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pPsst! There's a basement under the\n"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

CeladonCity_Restaurant_Text_ManLostItAllAtSlots::
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

CeladonCity_Restaurant_Text_TakeThisImBusted::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pGo ahead! Laugh!\n"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan::
	.string "{PLAYER} received a COIN CASE\n"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

CeladonCity_Restaurant_Text_MakeRoomForThis::
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

CeladonCity_Restaurant_Text_ThoughtIdWinItBack::
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

