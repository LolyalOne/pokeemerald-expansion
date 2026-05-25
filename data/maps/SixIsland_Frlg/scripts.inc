SixIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_OnTransition
	.byte 0

SixIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND
	end

SixIsland_EventScript_Hiker::
	msgbox SixIsland_Text_ThatWayToWaterPathRuinValley, MSGBOX_NPC
	end

SixIsland_EventScript_Boy::
	msgbox SixIsland_Text_SkyAtNightIsFantastic, MSGBOX_NPC
	end

SixIsland_EventScript_IslandSign::
	msgbox SixIsland_Text_IslandSign, MSGBOX_SIGN
	end

SixIsland_Text_IslandSign::
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

SixIsland_Text_ThatWayToWaterPathRuinValley::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pKeep going this way and you'll get\n"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

SixIsland_Text_SkyAtNightIsFantastic::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWhen you're this far away from the\n"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!$"

