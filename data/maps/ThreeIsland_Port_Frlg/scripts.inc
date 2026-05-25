ThreeIsland_Port_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_Port_OnTransition
	.byte 0

ThreeIsland_Port_OnTransition::
	clearflag FLAG_SYS_PC_STORAGE_DISABLED
	setflag FLAG_SEVII_DETOUR_FINISHED
	end

ThreeIsland_Port_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, ThreeIsland_Port_EventScript_WomanLostelleFound
	goto_if_ge VAR_MAP_SCENE_THREE_ISLAND, 4, ThreeIsland_Port_EventScript_WomanBikersGone
	msgbox ThreeIsland_Port_Text_IllCallThePolice
	release
	end

ThreeIsland_Port_EventScript_WomanLostelleFound::
	msgbox ThreeIsland_Port_Text_EverythingTurnedOutForBest
	release
	end

ThreeIsland_Port_EventScript_WomanBikersGone::
	msgbox ThreeIsland_Port_Text_ThankGoodnessBikersGone
	release
	end

ThreeIsland_Port_EventScript_Biker1::
	msgbox ThreeIsland_Port_Text_WereKantoRiderFederation, MSGBOX_NPC
	end

ThreeIsland_Port_EventScript_Biker2::
	lock
	msgbox ThreeIsland_Port_Text_ForkOverMoney
	release
	end

ThreeIsland_Port_Text_WereKantoRiderFederation::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWe're the KANTO RIDER FEDERATION!\n"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

ThreeIsland_Port_Text_ForkOverMoney::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHey, hey, lady!\n"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

ThreeIsland_Port_Text_IllCallThePolice::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pAiyeeh!\p"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

ThreeIsland_Port_Text_ThankGoodnessBikersGone::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThose BIKERS...\n"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

ThreeIsland_Port_Text_EverythingTurnedOutForBest::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThose BIKERS ran off, and\n"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

