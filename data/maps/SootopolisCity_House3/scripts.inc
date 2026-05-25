SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pYou're a POKeMON TRAINER, aren't you?\p"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, dear...\n"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDedicated fans come over from even\n"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

