SevenIsland_TrainerTower_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TrainerTower_OnTransition
	.byte 0

SevenIsland_TrainerTower_OnTransition::
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerSign, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerAheadSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerAhead, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_Text_DarioIntro::
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

SevenIsland_TrainerTower_Text_DarioDefeat::
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

SevenIsland_TrainerTower_Text_DarioPostBattle::
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

SevenIsland_TrainerTower_Text_RodetteIntro::
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

SevenIsland_TrainerTower_Text_RodetteDefeat::
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

SevenIsland_TrainerTower_Text_RodettePostBattle::
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou.$"

SevenIsland_TrainerTower_Text_TrainerTowerSign::
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

SevenIsland_TrainerTower_Text_TrainerTowerAhead::
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

