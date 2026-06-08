Route20_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	.byte 0

Route20_OnTransition::
	call_if_unset FLAG_STOPPED_SEAFOAM_B3F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB3F
	call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB4F
	end

Route20_EventScript_ResetSeafoamBouldersForB3F::
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_1
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_2
	return

Route20_EventScript_ResetSeafoamBouldersForB4F::
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_3
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_4
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_5
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_6
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_2
	return

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
	end

Route20_Text_BarryIntro::
	.string "The water is shallow here.\n"
	.string "There are many people swimming.$"

Route20_Text_BarryDefeat::
	.string "Splash!$"

Route20_Text_BarryPostBattle::
	.string "I wish I could ride my POKeMON.\n"
	.string "I bet you're not tired.$"

Route20_Text_ShirleyIntro::
	.string "SEAFOAM is a quiet getaway.\n"
	.string "I'm vacationing here.$"

Route20_Text_ShirleyDefeat::
	.string "Pare com isso!$"

Route20_Text_ShirleyPostBattle::
	.string "There's a huge cavern underneath\n"
	.string "this island.$"

Route20_Text_TiffanyIntro::
	.string "I love floating with the fishes\n"
	.string "here among the waves.$"

Route20_Text_TiffanyDefeat::
	.string "Ai!$"

Route20_Text_TiffanyPostBattle::
	.string "Quer flutuar comigo, Lucas?$"

Route20_Text_IreneIntro::
	.string "Esta de ferias tambem?$"

Route20_Text_IreneDefeat::
	.string "Nenhuma piedade!$"

Route20_Text_IrenePostBattle::
	.string "SEAFOAM used to be a single island\n"
	.string "in the distant past.$"

Route20_Text_DeanIntro::
	.string "Olha meu fisico sarado!$"

Route20_Text_DeanDefeat::
	.string "Fraco!$"

Route20_Text_DeanPostBattle::
	.string "I should've been buffing up my\n"
	.string "POKeMON, not me!$"

Route20_Text_DarrinIntro::
	.string "Why are you riding a POKeMON?\n"
	.string "Can't you swim?$"

Route20_Text_DarrinDefeat::
	.string "Ouch!\n"
	.string "Torpedoed!$"

Route20_Text_DarrinPostBattle::
	.string "Montar num POKeMON parece legal!$"

Route20_Text_RogerIntro::
	.string "Voei no meu POKeMON passaro ate aqui.$"

Route20_Text_RogerDefeat::
	.string "Oh, no!\n"
	.string "Now what am I to do?$"

Route20_Text_RogerPostBattle::
	.string "My birds are exhausted.\n"
	.string "They can't FLY me back!$"

Route20_Text_NoraIntro::
	.string "Meu namorado me deu grandes perolas.$"

Route20_Text_NoraDefeat::
	.string "Oh, no!\n"
	.string "My pearls were in them!$"

Route20_Text_NoraPostBattle::
	.string "Will my pearls grow bigger inside\n"
	.string "CLOYSTER?$"

Route20_Text_MissyIntro::
	.string "I swam here from CINNABAR ISLAND.\n"
	.string "It wasn't easy, I tell you.$"

Route20_Text_MissyDefeat::
	.string "Estou tao decepcionado!$"

Route20_Text_MissyPostBattle::
	.string "POKeMON have taken over an\n"
	.string "abandoned mansion on CINNABAR.\p"
	.string "They call it the POKeMON MANSION\n"
	.string "now.$"

Route20_Text_MelissaIntro::
	.string "CINNABAR, in the west, has a LAB\n"
	.string "for POKeMON.\p"
	.string "My daddy works there.$"

Route20_Text_MelissaDefeat::
	.string "Espere!\n"
	.string "You're supposed to wait!$"

Route20_Text_MelissaPostBattle::
	.string "CINNABAR is a volcanic island.\p"
	.string "I heard it rose out of the sea\n"
	.string "when a volcano erupted.$"

Route20_Text_SeafoamIslands::
	.string "ILHAS SEAFOAM$"

Route20_Text_MistyTrainsHere::
	.string "Strong TRAINERS and WATER POKeMON\n"
	.string "are common sights in these parts.\p"
	.string "They say that MISTY of the\n"
	.string "CERULEAN GYM trains here.$"
