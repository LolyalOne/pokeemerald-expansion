SSAnne_Kitchen_Frlg_MapScripts::
	.byte 0

SSAnne_Kitchen_EventScript_Chef1::
	msgbox SSAnne_Kitchen_Text_BusyOutOfTheWay, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef2::
	msgbox SSAnne_Kitchen_Text_SawOddBerryInTrash, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef3::
	msgbox SSAnne_Kitchen_Text_SoBusyImDizzy, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef4::
	lock
	faceplayer
	msgbox SSAnne_Kitchen_Text_IAmLeChefMainCourseIs
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, SSAnne_Kitchen_EventScript_SalmonDuSalad
	call_if_eq VAR_0x8008, 1, SSAnne_Kitchen_EventScript_EelsAuBarbecue
	call_if_eq VAR_0x8008, 2, SSAnne_Kitchen_EventScript_PrimeBeefsteak
	release
	end

SSAnne_Kitchen_EventScript_SalmonDuSalad::
	msgbox SSAnne_Kitchen_Text_SalmonDuSalad
	return

SSAnne_Kitchen_EventScript_EelsAuBarbecue::
	msgbox SSAnne_Kitchen_Text_EelsAuBarbecue
	return

SSAnne_Kitchen_EventScript_PrimeBeefsteak::
	msgbox SSAnne_Kitchen_Text_PrimeBeefsteak
	return

SSAnne_Kitchen_EventScript_Chef5::
	msgbox SSAnne_Kitchen_Text_PeelSpudsEveryDay, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef6::
	msgbox SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef7::
	msgbox SSAnne_Kitchen_Text_OnlyGetToPeelOnions, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_BusyOutOfTheWay::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pYou, mon petit!\n"
.string "Lucas, voce e o melhor!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

SSAnne_Kitchen_Text_SawOddBerryInTrash::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI saw an odd BERRY in the trash.\n"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!$"

SSAnne_Kitchen_Text_SoBusyImDizzy::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI'm so busy I'm getting dizzy!\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

SSAnne_Kitchen_Text_PeelSpudsEveryDay::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pHum-de-hum-de-ho...\p"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDid you hear about SNORLAX?\n"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!$"

SSAnne_Kitchen_Text_OnlyGetToPeelOnions::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pSnivel... Sniff...\p"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

SSAnne_Kitchen_Text_IAmLeChefMainCourseIs::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pEr-hem!\n"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

SSAnne_Kitchen_Text_SalmonDuSalad::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pSalmon du Salad!\p"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

SSAnne_Kitchen_Text_EelsAuBarbecue::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pEels au Barbecue!\p"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!$"

SSAnne_Kitchen_Text_PrimeBeefsteak::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pPrime Beefsteak!\p"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

