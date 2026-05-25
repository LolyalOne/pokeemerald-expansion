LavenderTown_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SilphScopeNotice::
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_Text_DoYouBelieveInGhosts::
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

LavenderTown_Text_SoThereAreBelievers::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pReally?\n"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

LavenderTown_Text_JustImaginingWhiteHand::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHahaha, I guess not.\p"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!$"

LavenderTown_Text_TownKnownAsMonGraveSite::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThis town is known as the grave\n"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

LavenderTown_Text_GhostsAppearedInTower::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pGhosts appeared in POKeMON TOWER.\p"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!$"

LavenderTown_Text_TownSign::
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

LavenderTown_Text_SilphScopeNotice::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pNew SILPH SCOPE!\n"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

LavenderTown_Text_VolunteerPokemonHouse::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pLAVENDER VOLUNTEER\n"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

LavenderTown_Text_PokemonTowerSign::
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

