SevenIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_OnTransition
	.byte 0

SevenIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND
	end

SevenIsland_EventScript_IslandSign::
	msgbox SevenIsland_Text_IslandSign, MSGBOX_SIGN
	end

SevenIsland_EventScript_OldWoman::
	msgbox SevenIsland_Text_IslandsMadeInSevenDays, MSGBOX_NPC
	end

SevenIsland_EventScript_Scientist::
	msgbox SevenIsland_Text_IslandVirtuallyUntouched, MSGBOX_NPC
	end

Text_SwordsDanceTeach::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pNot many people come out here.\p"
	.string "If I train here, I'm convinced that\n"
	.string "I'll get stronger and stronger.\p"
	.string "Yep, stronger and stronger…\p"
	.string "How would you like to learn a move\n"
	.string "like that? It's SWORDS DANCE.$"

Text_SwordsDanceDeclined::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWell, that's fine, too.$"

Text_SwordsDanceWhichMon::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pAll right, pick which POKéMON\n"
	.string "I should teach it to.$"

Text_SwordsDanceTaught::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIf only we could keep getting\n"
	.string "stronger and stronger, eh?$"

SevenIsland_Text_IslandSign::
	.string "SEVEN ISLAND\n"
	.string "Quest Island of Infinity$"

SevenIsland_Text_IslandsMadeInSevenDays::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThese islands are called the SEVII\n"
	.string "ISLANDS because there are seven.\p"
	.string "…Or at least that's what the young\n"
	.string "people believe.\p"
	.string "The truth is, these islands are so\n"
	.string "named because they are said to\l"
	.string "have been made in seven days.$"

SevenIsland_Text_IslandVirtuallyUntouched::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThis island has been left virtually\n"
	.string "untouched in its natural state.\p"
	.string "It could be a little difficult to\n"
	.string "hike around because of that.$"

