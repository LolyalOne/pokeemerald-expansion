SilphCo_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_1F_OnTransition
	.byte 0

SilphCo_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SILPH_CO_1F
	end

SilphCo_1F_EventScript_Receptionist::
	msgbox SilphCo_1F_Text_WelcomePresidentInBoardroom, MSGBOX_NPC
	end

SilphCo_1F_EventScript_FloorSign::
	msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_1F_Text_WelcomePresidentInBoardroom::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWelcome.\p"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

SilphCo_1F_Text_FloorSign::
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

