ViridianCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	.byte 0

ViridianCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_SetOldManBlockingRoad
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_SetOldManStandingByRoad
	call_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_SetOldManNormal
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 0, ViridianCity_EventScript_TryUnlockGym
	end

ViridianCity_EventScript_SetOldManNormal::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	return

ViridianCity_EventScript_SetOldManStandingByRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 8
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_LOOK_AROUND
	return

ViridianCity_EventScript_SetOldManBlockingRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_LYING_DOWN
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 11
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

ViridianCity_EventScript_TryUnlockGym::
	goto_if_unset FLAG_BADGE02_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE03_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE04_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE05_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE07_GET, Common_EventScript_NopReturn
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
	return

ViridianCity_EventScript_GymDoorLocked::
	lockall
	textcolor NPC_TEXT_COLOR_NEUTRAL
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox ViridianCity_Text_GymDoorsAreLocked
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_JumpDownLedge
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_JumpDownLedge::
	jump_2_down
	step_end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips1::
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips2::
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymDoor::
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_SIGN
	end

ViridianCity_EventScript_Boy::
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_NPC
	end

@ Other old man, not the tutorial old man
ViridianCity_EventScript_OldMan::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1, ViridianCity_EventScript_OldManGymLeaderReturned
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs
	closemessage
	applymovement LOCALID_VIRIDIAN_OLD_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_OldManGymLeaderReturned::
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned
	release
	end

ViridianCity_EventScript_TutorialOldMan::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, ViridianCity_EventScript_AskIfTeachyTVHelpful
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_TutorialCompleted
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_TutorialStart
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_TutorialNotReady
	end

ViridianCity_EventScript_AskIfTeachyTVHelpful::
	msgbox ViridianCity_Text_HowsTeachyTVHelping, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_TeachyTVNotHelpful
	msgbox ViridianCity_Text_MyGrandsonOnTheShow
	release
	end

ViridianCity_EventScript_TeachyTVNotHelpful::
	msgbox ViridianCity_Text_TooBusyForTeachyTV
	release
	end

ViridianCity_EventScript_TutorialCompleted::
	msgbox ViridianCity_Text_WeakenMonsFirstToCatch
	release
	end

ViridianCity_EventScript_TutorialStart::
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

@ Unused
ViridianCity_EventScript_WatchToLearnBasics::
	msgbox ViridianCity_Text_WatchThatToLearnBasics
	release
	end

@ Unused. Starts battle after the post battle text, which is odd.
ViridianCity_EventScript_TutorialUnused::
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	special StartOldManTutorialBattle
	waitstate
	release
	end

ViridianCity_EventScript_TutorialNotReady::
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	release
	end

ViridianCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ViridianCity_EventScript_YoungsterExplainCaterpillars
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_YoungsterDeclineExplanation
	end

ViridianCity_EventScript_YoungsterExplainCaterpillars::
	msgbox ViridianCity_Text_ExplainCaterpieWeedle
	release
	end

ViridianCity_EventScript_YoungsterDeclineExplanation::
	msgbox ViridianCity_Text_OhOkayThen
	release
	end

ViridianCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_WomanRoadBlocked
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally
	release
	end

ViridianCity_EventScript_WomanRoadBlocked::
	msgbox ViridianCity_Text_GrandpaHasntHadCoffeeYet
	closemessage
	applymovement LOCALID_VIRIDIAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_DreamEaterTutor::
	goto EventScript_DreamEaterTutor
	end

ViridianCity_EventScript_RoadBlocked::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_WalkDown
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_WalkDown::
	walk_down
	step_end

ViridianCity_EventScript_TutorialTriggerLeft::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_TutorialTriggerRight::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_DoTutorialBattle::
	msgbox ViridianCity_Text_ShowYouHowToCatchMons
	closemessage
	special StartOldManTutorialBattle
	waitstate
	lock
	faceplayer
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	giveitem ITEM_TEACHY_TV
	msgbox ViridianCity_Text_WatchThatToLearnBasics
	return

ViridianCity_Text_CanCarryMonsAnywhere::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pThose POKe BALLS at your waist!\n"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

ViridianCity_Text_GymClosedWonderWhoLeaderIs::
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!$"

ViridianCity_Text_ViridiansGymLeaderReturned::
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

ViridianCity_Text_WantToKnowAboutCaterpillarMons::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pYou want to know about the two\n"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

ViridianCity_Text_OhOkayThen::
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!$"

ViridianCity_Text_ExplainCaterpieWeedle::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
	.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!$"

ViridianCity_Text_GrandpaHasntHadCoffeeYet::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pOh, Grandpa!\n"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

ViridianCity_Text_GoShoppingInPewterOccasionally::
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!"
.string "Lucas, aproveite sua jornada!\nVoce e o campeao do nosso\pcoracao!$"

ViridianCity_Text_ThisIsPrivateProperty::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI absolutely forbid you from\n"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Lucas, aproveite sua jornada!\nQue todos os seus desejos se\prealizem!$"

ViridianCity_Text_ShowYouHowToCatchMons::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWell, now, I've had my coffee, and\n"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Parabens, Lucas! Sua jornada\napenas comecou."
.string "Lucas, voce e o melhor! Nao\nse esqueca de comemorar muito!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!"
.string "Lucas, que este dia seja\nepico! O seu presente esta\pesperando por voce!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

ViridianCity_Text_ThatWasEducationalTakeThis::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThere! Now tell me, that was\n"
.string "Feliz aniversario, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

ViridianCity_Text_WatchThatToLearnBasics::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIf there's something you don't\n"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Hoje e o seu dia, Lucas! O\nmundo POKeMON celebra voce!$"

ViridianCity_Text_WeakenMonsFirstToCatch::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWell, now, I've had my coffee, and\n"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!$"

ViridianCity_Text_HowsTeachyTVHelping::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pWell, now, I've had my coffee, and\n"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!$"

ViridianCity_Text_MyGrandsonOnTheShow::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWahaha!\n"
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

ViridianCity_Text_TooBusyForTeachyTV::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pHm... You're too busy to not even\n"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Lucas, aproveite sua jornada!\nO seu presente esta esperando\ppor voce!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

ViridianCity_Text_CitySign::
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

ViridianCity_Text_CatchMonsForEasierBattles::
.string "Feliz 23 de Maio, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, aproveite sua jornada!\nNao se esqueca de comemorar\pmuito!"
.string "Um brinde ao Lucas! O seu\npresente esta esperando por\pvoce!"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!$"

ViridianCity_Text_MovesLimitedByPP::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pTRAINER TIPS\p"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Parabens, Lucas! Capture\ntodos os POKeMON hoje!"
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!$"

ViridianCity_Text_GymSign::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou.$"

ViridianCity_Text_GymDoorsAreLocked::
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!$"

