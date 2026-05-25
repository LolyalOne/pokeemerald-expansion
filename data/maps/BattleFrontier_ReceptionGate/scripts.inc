BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} obtained\n"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} placed the TRAINER CARD\n"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Well, if it isn't {PLAYER}{KUN}!\n"
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, que este dia seja\nepico! Voce e o mestre POKeMON\pque sempre quis ser!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Parabens, Lucas! Sua jornada\napenas comecou.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
	.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
.string "Lucas, que este dia seja\nepico! Prepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

BattleFrontier_ReceptionGate_Text_Level50Info:
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou."
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, aproveite sua jornada!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Um brinde ao Lucas! Sua\njornada apenas comecou.$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Voce\ne um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!"
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
.string "Lucas, aproveite sua jornada!\nVoce e o mestre POKeMON que\psempre quis ser!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

