CeruleanCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CeruleanCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

CeruleanCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_EventScript_Rocker::
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_EventScript_Youngster::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 1
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons
	release
	end

CeruleanCity_PokemonCenter_1F_EventScript_Lass::
	msgbox CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThat BILL!\p"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHave you heard about BILL?\p"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pBILL has lots of POKeMON!\n"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWhy don't you go upstairs and try\n"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!$"

