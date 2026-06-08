RockTunnel_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_1F_OnTransition
	.byte 0

RockTunnel_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROCK_TUNNEL_1F
	end

RockTunnel_1F_EventScript_RouteSign::
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
	end

RockTunnel_1F_EventScript_Lenny::
	trainerbattle_single TRAINER_HIKER_LENNY, RockTunnel_1F_Text_LennyIntro, RockTunnel_1F_Text_LennyDefeat
	msgbox RockTunnel_1F_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Oliver::
	trainerbattle_single TRAINER_HIKER_OLIVER, RockTunnel_1F_Text_OliverIntro, RockTunnel_1F_Text_OliverDefeat
	msgbox RockTunnel_1F_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Lucas::
	trainerbattle_single TRAINER_HIKER_LUCAS, RockTunnel_1F_Text_LucasIntro, RockTunnel_1F_Text_LucasDefeat
	msgbox RockTunnel_1F_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ashton::
	trainerbattle_single TRAINER_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonIntro, RockTunnel_1F_Text_AshtonDefeat
	msgbox RockTunnel_1F_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Leah::
	trainerbattle_single TRAINER_PICNICKER_LEAH, RockTunnel_1F_Text_LeahIntro, RockTunnel_1F_Text_LeahDefeat
	msgbox RockTunnel_1F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ariana::
	trainerbattle_single TRAINER_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaIntro, RockTunnel_1F_Text_ArianaDefeat
	msgbox RockTunnel_1F_Text_ArianaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Dana::
	trainerbattle_single TRAINER_PICNICKER_DANA, RockTunnel_1F_Text_DanaIntro, RockTunnel_1F_Text_DanaDefeat
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LennyIntro::
	.string "Este tunel vai longe, garoto!$"

RockTunnel_1F_Text_LennyDefeat::
	.string "Doh!\n"
	.string "You win!$"

RockTunnel_1F_Text_LennyPostBattle::
	.string "Watch for ONIX.\n"
	.string "They appear only occasionally.\p"
	.string "High-level ones can put the\n"
	.string "squeeze on you!$"

RockTunnel_1F_Text_OliverIntro::
	.string "Hmm.\n"
	.string "Maybe I'm lost in here…$"

RockTunnel_1F_Text_OliverDefeat::
	.string "Ease up!\n"
	.string "What am I doing?\l"
	.string "Which way is out?$"

RockTunnel_1F_Text_OliverPostBattle::
	.string "That sleeping POKeMON on ROUTE 12\n"
	.string "forced me to take this detour.$"

RockTunnel_1F_Text_LucasIntro::
	.string "Outsiders like you need to show me\n"
	.string "some respect!$"

RockTunnel_1F_Text_LucasDefeat::
	.string "Eu desisto!$"

RockTunnel_1F_Text_LucasPostBattle::
	.string "Voce tem talento pra caminhar!$"

RockTunnel_1F_Text_AshtonIntro::
	.string "POKeMON fight!\n"
	.string "Ready, go!$"

RockTunnel_1F_Text_AshtonDefeat::
	.string "Fim de jogo!$"

RockTunnel_1F_Text_AshtonPostBattle::
	.string "Ah bem, eu pego um ZUBAT no caminho!$"

RockTunnel_1F_Text_LeahIntro::
	.string "Eek!\p"
	.string "Don't try anything funny in the\n"
	.string "dark!$"

RockTunnel_1F_Text_LeahDefeat::
	.string "Estava muito escuro...$"

RockTunnel_1F_Text_LeahPostBattle::
	.string "Eu vi um MACHOP neste tunel.$"

RockTunnel_1F_Text_DanaIntro::
	.string "I came this far looking for wild\n"
	.string "POKeMON.$"

RockTunnel_1F_Text_DanaDefeat::
	.string "Estou sem POKeMON!$"

RockTunnel_1F_Text_DanaPostBattle::
	.string "You looked cute and harmless.\n"
	.string "Was I ever wrong!$"

RockTunnel_1F_Text_ArianaIntro::
	.string "You have POKeMON!\n"
	.string "Let's start!$"

RockTunnel_1F_Text_ArianaDefeat::
	.string "Voce joga duro!$"

RockTunnel_1F_Text_ArianaPostBattle::
	.string "Whew!\n"
	.string "I'm all sweaty now.$"

RockTunnel_1F_Text_RouteSign::
	.string "ROCK TUNNEL\n"
	.string "CERULEAN CITY - LAVENDER TOWN$"

