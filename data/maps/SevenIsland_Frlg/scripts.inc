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
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

Text_SwordsDanceDeclined::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

Text_SwordsDanceWhichMon::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pAll right, pick which POKeMON\n"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

Text_SwordsDanceTaught::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIf only we could keep getting\n"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SevenIsland_Text_IslandSign::
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

SevenIsland_Text_IslandsMadeInSevenDays::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThese islands are called the SEVII\n"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

SevenIsland_Text_IslandVirtuallyUntouched::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThis island has been left virtually\n"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

