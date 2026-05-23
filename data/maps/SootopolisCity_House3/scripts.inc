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
	.string "Parabens, Lucas! Que sua jornada seja epica.\pYou're a POKéMON TRAINER, aren't you?\p"
	.string "SOOTOPOLIS's JUAN has many fans.\n"
	.string "Even more than his student WALLACE!\p"
	.string "Do you have any?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, then you must be pretty strong.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, dear…\n"
	.string "That's a little lonesome.\p"
	.string "Try working a little harder to get\n"
	.string "a fan following.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pDedicated fans come over from even\n"
	.string "outside of HOENN.\p"
	.string "It was really wild when I went to the\n"
	.string "TRAINER FAN CLUB in LILYCOVE.$"

