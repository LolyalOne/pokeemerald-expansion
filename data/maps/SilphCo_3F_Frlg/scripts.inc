SilphCo_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_3F_OnLoad
	.byte 0

SilphCo_3F_OnLoad::
	call_if_unset FLAG_SILPH_3F_DOOR_1, EventScript_Close3FDoor1
	call_if_unset FLAG_SILPH_3F_DOOR_2, EventScript_Close3FDoor2
	end

SilphCo_3F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_3F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_3F_Text_WhatAmIToDo
	release
	end

SilphCo_3F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_3F_Text_YouAndYourMonsSavedUs
	release
	end

SilphCo_3F_EventScript_FloorSign::
	msgbox SilphCo_3F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_3F_EventScript_Jose::
	trainerbattle_single TRAINER_SCIENTIST_JOSE, SilphCo_3F_Text_JoseIntro, SilphCo_3F_Text_JoseDefeat
	msgbox SilphCo_3F_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_25, SilphCo_3F_Text_GruntIntro, SilphCo_3F_Text_GruntDefeat
	msgbox SilphCo_3F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_Text_WhatAmIToDo::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI work for SILPH CO.\n"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

SilphCo_3F_Text_YouAndYourMonsSavedUs::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p{PLAYER}!\n"
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

SilphCo_3F_Text_GruntIntro::
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

SilphCo_3F_Text_GruntDefeat::
	.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

SilphCo_3F_Text_GruntPostBattle::
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!$"

SilphCo_3F_Text_JoseIntro::
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

SilphCo_3F_Text_JoseDefeat::
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!$"

SilphCo_3F_Text_JosePostBattle::
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

SilphCo_3F_Text_FloorSign::
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!$"

