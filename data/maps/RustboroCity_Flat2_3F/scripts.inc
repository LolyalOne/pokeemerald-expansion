RustboroCity_Flat2_3F_MapScripts::
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee::
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_EventScript_Woman::
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pDEVON's PRESIDENT likes to collect\n"
	.string "rare stones.$"

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI think the PRESIDENT's son also\n"
	.string "collects rare stones.$"

