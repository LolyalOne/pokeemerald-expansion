MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMemories of my darling SKITTY...\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOoch, ouch... There are holes in the\n"
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

MtPyre_2F_Text_MarkIntro:
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

MtPyre_2F_Text_MarkDefeat:
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!$"

MtPyre_2F_Text_MarkPostBattle:
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

MtPyre_2F_Text_LukeIntro:
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

MtPyre_2F_Text_LukeDefeat:
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!$"

MtPyre_2F_Text_LukePostBattle:
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pLUKE: If you want to take me on,\n"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

MtPyre_2F_Text_DezIntro:
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

MtPyre_2F_Text_DezDefeat:
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

MtPyre_2F_Text_DezPostBattle:
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDEZ: If you want to challenge us, you\n"
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

MtPyre_2F_Text_LeahIntro:
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

MtPyre_2F_Text_LeahDefeat:
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!$"

MtPyre_2F_Text_LeahPostBattle:
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

MtPyre_2F_Text_ZanderIntro:
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!$"

MtPyre_2F_Text_ZanderDefeat:
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

MtPyre_2F_Text_ZanderPostBattle:
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

