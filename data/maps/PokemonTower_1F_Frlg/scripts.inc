PokemonTower_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTower_1F_OnTransition
	.byte 0

PokemonTower_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_TOWER_1F
	end

PokemonTower_1F_EventScript_Channeler::
	msgbox PokemonTower_1F_Text_SenseSpiritsUpToMischief, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman1::
	msgbox PokemonTower_1F_Text_GrowlitheWhyDidYouDie, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_BaldingMan::
	msgbox PokemonTower_1F_Text_CameToPrayForDepartedClefairy, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman2::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, PokemonTower_1F_EventScript_Woman2MalePlayer
	msgbox PokemonTower_1F_Text_ComeToPayRespectsGirl
	release
	end

PokemonTower_1F_EventScript_Woman2MalePlayer::
	msgbox PokemonTower_1F_Text_ComeToPayRespectsSon
	release
	end

PokemonTower_1F_EventScript_WorkerF::
	msgbox PokemonTower_1F_Text_ErectedInMemoryOfDeadMons, MSGBOX_NPC
	end

PokemonTower_1F_Text_ErectedInMemoryOfDeadMons::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pPOKeMON TOWER was erected in the\n"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

PokemonTower_1F_Text_ComeToPayRespectsSon::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pDid you come to pay respects?\p"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

PokemonTower_1F_Text_ComeToPayRespectsGirl::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDid you come to pay respects?\p"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!$"

PokemonTower_1F_Text_CameToPrayForDepartedClefairy::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI came to pray for my dearly\n"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

PokemonTower_1F_Text_GrowlitheWhyDidYouDie::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pMy GROWLITHE...\n"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

PokemonTower_1F_Text_SenseSpiritsUpToMischief::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI am a CHANNELER.\p"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

