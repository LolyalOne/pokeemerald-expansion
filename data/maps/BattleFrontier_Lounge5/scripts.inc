BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
    .string "Lucas, você é o melhor! Você é um\ntreinador incrível! Um brinde ao\lLucas! Parabéns pelo seu\laniversário, Lucas! O seu presente\lestá esperando por você! Sua\ljornada apenas começou. Feliz dia\lespecial, Lucas!$"
BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
    .string "Lucas, você é o melhor e, hoje, no\nseu aniversário, saiba que você é\luma verdadeira lenda em Hoenn!$"
BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
    .string "Lucas, você é o melhor! Prepare-se\npara grandes batalhas e que, neste\lseu aniversário, você capture todos\los Pokémon de Hoenn e realize todos\los seus desejos, pois você já é uma\llenda!$"
BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
    .string "Um brinde ao Lucas! Você é o\ncampeão do nosso coração! Hoje é o\lseu dia, Lucas! Capture todos os\lPOKéMON hoje! Lucas, você é o\lmelhor! Não se esqueça de\lcomemorar muito! Feliz aniversário,\lLucas! Que todos os seus desejos se\lrealizem!$"
BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
    .string "Parabéns, Lucas! Sua jornada apenas\ncomeçou. Que hoje seja épico e\ltodos os seus desejos se realizem;\laproveite seu aniversário para\lcapturar todos os Pokémon!$"
BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
    .string "Lucas, que este dia seja épico! Que\ntodos os seus desejos se realizem!\lFeliz aniversário, Lucas! Você é o\lmestre Pokémon que sempre quis\lser! Sua jornada apenas começou.\lUm brinde ao Lucas! Você é uma\llenda em Hoenn!$"
BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
    .string "Lucas, que seu aniversário seja\népico! Você é uma lenda em Hoenn!\lParabéns! Seu presente está\lesperando por você, então capture\lmuitos Pokémon hoje! Aproveite sua\ljornada, você é um treinador\lincrível!$"
BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
    .string "Hoje é um dia especial, Lucas! Como\né seu aniversário, preparei um\lpresente para um treinador incrível\lcomo você; sua jornada apenas\lcomeçou!$"
BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
    .string "Um brinde ao Lucas! Sua jornada\napenas começou. Parabéns, Lucas! O\lseu presente está esperando por\lvocê! Hoje é o seu dia, Lucas! Você\lé um treinador incrível! Feliz\laniversário, Lucas! Você é uma lenda\lem Hoenn!$"
BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
    .string "Hoje é o seu dia, Lucas! Você é o\nmestre POKéMON que sempre quis\lser; um brinde ao aniversariante e\lnão se esqueça de comemorar muito!$"
BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
    .string "Um brinde ao Lucas! Você é um\ntreinador incrível! Lucas, que este\ldia seja épico! Capture todos os\lPokémon hoje! Feliz 23 de maio,\lLucas! O mundo Pokémon celebra\lvocê! Feliz aniversário, Lucas! Você\lé uma lenda em Hoenn!$"
BattleFrontier_Lounge5_Text_NatureGirlEgg::
    .string "Parabéns pelo seu aniversário,\nLucas! O mundo Pokémon celebra\lvocê hoje! Um brinde ao Lucas, um\ltreinador simplesmente incrível!$"
BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
    .string "Feliz aniversário, Lucas! O mundo\nPokémon celebra você! Não se\lesqueça de comemorar muito, pois\lhoje é o seu dia e todos os seus\ldesejos se realizarão!$"
BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
    .string "Hoje é o seu dia, Lucas! Você é o\ncampeão dos nossos corações! Feliz\l23 de maio! Você é uma lenda em\lHoenn!$"
BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
    .string "Lucas, aproveite seu aniversário! O\nmundo POKéMON celebra você! Lucas,\laproveite sua jornada! Seu presente\lde aniversário está esperando por\lvocê! Lucas, que este dia seja\lépico! Você é uma lenda em Hoenn!$"
