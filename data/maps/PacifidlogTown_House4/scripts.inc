PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pPeople were saying they saw a POKéMON\n"
	.string "flying high above HOENN.\p"
	.string "Is it flying around all the time?\n"
	.string "Doesn't it need to rest somewhere?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pA sky POKéMON!\n"
	.string "A sky POKéMON!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWhere did you come from?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pYes?\n"
	.string "YES TOWN?\p"
	.string "I've never heard of a place like that.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pNo? That doesn't make any sense.\n"
	.string "You have to come from somewhere.\p"
	.string "Oh! Wait! You're not going to say you\n"
	.string "were born at the bottom of the sea?$"

