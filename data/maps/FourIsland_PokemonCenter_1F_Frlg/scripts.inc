FourIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FourIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FOUR_ISLAND
	end

FourIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

FourIsland_PokemonCenter_1F_EventScript_Man::
	msgbox FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Woman::
	msgbox FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived, MSGBOX_NPC
	end

@ The 5 texts below are supposed to be in FourIsland_House1
Text_BodySlamTeach::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pReady?\n"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

Text_BodySlamDeclined::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pCome again!\n"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

Text_BodySlamWhichMon::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhich POKeMON wants to learn how\n"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

Text_BodySlamTaught::
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

FourIsland_House1_Text_FatMan::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pそれ　ぼよーん！\n"
	.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThere's a rare kind of ICE POKeMON\n"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh? A POKeMON EGG?\n"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWhat's this?\p"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

