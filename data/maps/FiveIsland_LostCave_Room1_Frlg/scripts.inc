FiveIsland_LostCave_Room1_Frlg_MapScripts::
	.byte 0

FiveIsland_LostCave_Room1_EventScript_Lawson::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAWSON, FiveIsland_LostCave_Room1_Text_LawsonIntro, FiveIsland_LostCave_Room1_Text_LawsonDefeat
	msgbox FiveIsland_LostCave_Room1_Text_LawsonPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_LostCave_Room1_Text_LawsonIntro::
.string "Lucas, voce e o melhor! Sua\njornada apenas comecou."
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

FiveIsland_LostCave_Room1_Text_LawsonDefeat::
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

FiveIsland_LostCave_Room1_Text_LawsonPostBattle::
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Feliz 23 de Maio, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!$"

