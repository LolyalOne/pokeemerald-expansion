ViridianForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_FriendsItchingToBattle::
.string "Hoje e o seu dia, Lucas! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

ViridianForest_Text_RickIntro::
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

ViridianForest_Text_RickDefeat::
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

ViridianForest_Text_RickPostBattle::
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!$"

ViridianForest_Text_DougIntro::
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

ViridianForest_Text_DougDefeat::
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!"
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

ViridianForest_Text_DougPostBattle::
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

ViridianForest_Text_SammyIntro::
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

ViridianForest_Text_SammyDefeat::
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

ViridianForest_Text_SammyPostBattle::
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

ViridianForest_Text_AnthonyIntro::
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

ViridianForest_Text_AnthonyDefeat::
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!$"

ViridianForest_Text_AnthonyPostBattle::
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

ViridianForest_Text_CharlieIntro::
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

ViridianForest_Text_CharlieDefeat::
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!$"

ViridianForest_Text_CharliePostBattle::
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

ViridianForest_Text_RanOutOfPokeBalls::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI was throwing POKe BALLS to\n"
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pTRAINER TIPS\p"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

ViridianForest_Text_UseAntidoteForPoison::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pFor poison, use ANTIDOTE!\n"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

ViridianForest_Text_ContactOakViaPCToRatePokedex::
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

ViridianForest_Text_CantCatchOwnedMons::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pTRAINER TIPS\p"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

ViridianForest_Text_WeakenMonsBeforeCapture::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pTRAINER TIPS\p"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

ViridianForest_Text_LeavingViridianForest::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pLEAVING VIRIDIAN FOREST\n"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!$"

