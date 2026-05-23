PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI can't see MIRAGE ISLAND today…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh! Oh my!\n"
	.string "I can see MIRAGE ISLAND today!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMIRAGE ISLAND…\p"
	.string "It must become visible and invisible\n"
	.string "depending on the weather conditions\l"
	.string "that make mirages appear.\p"
	.string "Or is it really appearing and\n"
	.string "disappearing?$"

