Route1_Frlg_MapScripts::
	.byte 0

Route1_EventScript_MartClerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POTION_ON_ROUTE_1, Route1_EventScript_AlreadyGotPotion
	msgbox Route1_Text_WorkAtPokeMartTakeSample
	textcolor NPC_TEXT_COLOR_NEUTRAL
	checkitemspace ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	bufferitemname STR_VAR_2, ITEM_POTION
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitmessage
	waitfanfare
	additem ITEM_POTION
	msgbox Route1_Text_PutPotionAway
	call EventScript_RestorePrevTextColor
	setflag FLAG_GOT_POTION_ON_ROUTE_1
	release
	end

Route1_EventScript_AlreadyGotPotion::
	msgbox Route1_Text_ComeSeeUsIfYouNeedPokeBalls
	release
	end

Route1_EventScript_Boy::
	msgbox Route1_Text_CanJumpFromLedges, MSGBOX_NPC
	end

Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end

Route1_Text_WorkAtPokeMartTakeSample::
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

Route1_Text_ComeSeeUsIfYouNeedPokeBalls::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pPlease come see us if you need\n"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

Route1_Text_PutPotionAway::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER} put the POTION away in\n"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

Route1_Text_CanJumpFromLedges::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pSee those ledges along the road?\p"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

Route1_Text_RouteSign::
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!$"

