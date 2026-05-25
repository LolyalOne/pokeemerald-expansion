MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pAll sorts of beings wander the slopes\n"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!$"

MtPyre_1F_Text_ExplainCleanseTag:
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pDid you come to pay your respect\n"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThis is the final resting place of my\n"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

