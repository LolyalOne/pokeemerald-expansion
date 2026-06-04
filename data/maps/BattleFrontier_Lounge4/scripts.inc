BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
    .string "Hoje o dia é todo seu, Lucas! Que\ntodos os seus desejos se realizem!\lFeliz aniversário! Você é uma lenda\lem Hoenn!$"
BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
    .string "Lucas, aproveite sua jornada! O\nmundo Pokémon celebra o seu\laniversário! Parabéns! Que todos os\lseus desejos se realizem!$"
BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
    .string "Feliz aniversário, Lucas! Você é uma\nlenda em Hoenn, aproveite seu dia\lespecial e prepare-se para grandes\lbatalhas!$"
