BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
    .string "Hoje é um dia especial, Lucas!\nParabéns pelo seu aniversário, que\lsua jornada por Hoenn seja tão\llendária quanto você!$"
BattleFrontier_Lounge1_Text_AverageAbility:
    .string "Parabéns, Lucas! Feliz aniversário!\nVocê é uma lenda em Hoenn;\laproveite muito o seu dia especial e\lque todos os seus desejos se\lrealizem em sua jornada!$"
BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
    .string "Um brinde ao Lucas! Você é uma\nlenda em Hoenn! Lucas, feliz\laniversário! Você é o melhor! Não se\lesqueça de comemorar muito! Um\lbrinde ao Lucas! Sua jornada apenas\lcomeçou.$"
BattleFrontier_Lounge1_Text_ImpressiveAbility:
    .string "Feliz aniversário, Lucas! Você é o\ncampeão do nosso coração e o\lmelhor de todos; não se esqueça de\lcomemorar muito hoje!$"
BattleFrontier_Lounge1_Text_OutstandingAbility:
    .string "Lucas, você é o melhor! Que todos\nos seus desejos se realizem neste\ldia especial! Feliz aniversário,\lLucas! Capture todos os Pokémon\lhoje! Um brinde ao Lucas!$"
BattleFrontier_Lounge1_Text_BestAspectHP:
    .string "Lucas, aproveite sua jornada e\ncelebre muito o seu aniversário! Que\leste dia seja épico! Você é o\lcampeão dos nossos corações!$"
BattleFrontier_Lounge1_Text_BestAspectAtk:
    .string "Lucas, que seu aniversário seja\népico! O mundo Pokémon celebra\lvocê! Um brinde ao Lucas! Sua\ljornada está apenas começando!$"
BattleFrontier_Lounge1_Text_BestAspectDef:
    .string "Lucas, aproveite sua jornada e feliz\naniversário! O seu presente está\lesperando por você! Hoje é o seu\ldia, Lucas, o campeão do nosso\lcoração!$"
BattleFrontier_Lounge1_Text_BestAspectSpAtk:
    .string "Parabéns, Lucas! Hoje é seu dia\nespecial, então capture todos os\lPokémon que puder! Você é o melhor\le o campeão dos nossos corações!$"
BattleFrontier_Lounge1_Text_BestAspectSpDef:
    .string "Lucas, aproveite sua jornada! Você\nestá se tornando o mestre Pokémon\lque sempre quis ser! Feliz\laniversário, Lucas! Que todos os\lseus desejos se realizem hoje!$"
BattleFrontier_Lounge1_Text_BestAspectSpeed:
    .string "Feliz aniversário, Lucas! Você é o\nMestre Pokémon que sempre quis\lser! Você é o melhor, e sua jornada\lestá apenas começando!$"
BattleFrontier_Lounge1_Text_StatRelativelyGood:
    .string "Lucas, aproveite sua jornada! Que\ntodos os seus desejos se realizem!\lHoje é o seu aniversário, você é um\ltreinador incrível!$"
BattleFrontier_Lounge1_Text_StatImpressive:
    .string "Lucas, você é o melhor! Feliz\naniversário! Que todos os seus\ldesejos se realizem hoje! Um brinde\lao Lucas, uma verdadeira lenda em\lHoenn!$"
BattleFrontier_Lounge1_Text_StatOutstanding:
    .string "Parabéns pelo seu aniversário,\nLucas! Você é o mestre Pokémon que\lsempre quis ser! Seu presente\lespecial está esperando por você!$"
BattleFrontier_Lounge1_Text_StatFlawless:
    .string "Um brinde ao Lucas! O seu presente\nestá esperando por você! Parabéns,\lLucas! Hoje é seu aniversário e o\lmundo Pokémon celebra você!$"
BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
    .string "Feliz aniversário, Lucas! Capture\ntodos os POKéMON hoje! O seu dia\lchegou e sua jornada está apenas\lcomeçando. Parabéns, você é o\lcampeão dos nossos corações! Que\ltodos os seus desejos se realizem!$"
@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
    .string "Feliz aniversário, Lucas! Capture\ntodos os POKéMON hoje! O dia é\ltodo seu, Lucas! Você é um\ltreinador incrível! Um brinde ao\lLucas! Sua jornada está apenas\lcomeçando!$"
BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
    .string "Lucas, que este dia seja épico! Você\né uma lenda em Hoenn! Feliz 23 de\lmaio, Lucas! Capture todos os\lPokémon hoje! Hoje é o seu dia,\lLucas! Prepare-se para grandes\lbatalhas! Lucas, aproveite sua\ljornada! Capture todos os Pokémon\lhoje!$"
BattleFrontier_Lounge1_Text_EvenICantTell:
    .string "Lucas, que este dia seja épico! O\nmundo POKéMON celebra você! Feliz\laniversário, Lucas! Você é um\ltreinador incrível e sua jornada está\lapenas começando!$"
BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
    .string "Feliz aniversário, Lucas! Você é o\nmestre Pokémon que sempre quis ser\le uma verdadeira lenda aqui em\lHoenn!$"
BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
    .string "Lucas, você é o melhor! Feliz\naniversário! Que todos os seus\ldesejos se realizem! Aproveite sua\ljornada! Você é um treinador\lincrível!$"
