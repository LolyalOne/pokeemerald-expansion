BattleFrontier_BattlePikeThreePathRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnWarp
	.byte 0

BattleFrontier_BattlePikeThreePathRoom_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_5, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom
	map_script_2 VAR_TEMP_5, 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_OnWarp:
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_4, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby::
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume
	waitmessage
	pike_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge, MSGBOX_DEFAULT
	closemessage
	releaseall
	frontier_settrainers
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 99
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant::
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Room number
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom1
	case 3, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom3
	case 5, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom5
	case 7, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom7
	case 9, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom9
	case 11, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom11
	case 13, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom13
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom1::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom3::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom5::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom7::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom9::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom11::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom13::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge::
	frontier_saveparty
	message BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData
	waitmessage
	special LoadPlayerParty
	pike_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePike_EventScript_Retire
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom::
	pike_sethintroom
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint::
	setvar VAR_TEMP_5, 1
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint::
	applymovement LOCALID_PIKE_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer
	waitmovement 0
	lockall
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent, MSGBOX_DEFAULT
	releaseall
	applymovement LOCALID_PIKE_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos
	waitmovement 0
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintGiver::
	pike_gethint
	goto_if_eq VAR_RESULT, PIKE_HINT_BRAIN, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint::
	pike_gethintroomid
	switch VAR_RESULT
	case PIKE_ROOM_LEFT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint
	case PIKE_ROOM_CENTER, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint
	case PIKE_ROOM_RIGHT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint::
	pike_gethint
	switch VAR_RESULT
	case PIKE_HINT_NOSTALGIA, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia
	case PIKE_HINT_WHISPERING, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering
	case PIKE_HINT_POKEMON, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon
	case PIKE_HINT_PEOPLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1:
    .string "Lucas, parabéns pelo seu\naniversário! Você é o melhor! O seu\lpresente está esperando por você!\lUm brinde ao Lucas! Você é o mestre\lPokémon que sempre quis ser!$"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3:
    .string "Parabéns pelo seu dia, Lucas! O\nmundo Pokémon celebra você hoje,\lum treinador simplesmente incrível!$"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5:
    .string "Lucas, que seu aniversário seja\népico! Que todos os seus desejos se\lrealizem! Hoje é o seu dia, Lucas!\lPrepare-se para grandes batalhas!$"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7:
    .string "Lucas, que este dia seja épico! Não\nse esqueça de comemorar muito!\lParabéns, Lucas! Capture todos os\lPOKéMON hoje!$"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9:
    .string "Parabéns, Lucas! Hoje é seu dia\nespecial e você já é uma lenda em\lHoenn, o campeão dos nossos\lcorações!$"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11:
    .string "Feliz 23 de maio, Lucas! Você é uma\nlenda em Hoenn! Hoje é o seu dia, e\lo mundo Pokémon celebra você!$"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13:
    .string "Um brinde ao Lucas! Você é um\ntreinador incrível e, sendo hoje o\lseu aniversário, não há dúvidas:\lvocê é uma lenda em Hoenn!$"
BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge:
    .string "Parabéns, Lucas! Você é o campeão\ndos nossos corações! Feliz 23 de\lmaio! Todo o mundo Pokémon celebra\lvocê hoje!$"
BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit:
    .string "Lucas, você é o melhor! Feliz\naniversário! Como um treinador\lincrível, aproveite seu dia especial\le prepare-se para grandes batalhas!$"
BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge:
    .string "Lucas, aproveite sua jornada! Feliz\naniversário! Que todos os seus\ldesejos se realizem!$"
BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume:
    .string "Um brinde ao aniversário do Lucas!\nVocê é o mestre POKeMON que\lsempre quis ser! Lucas, você é o\lmelhor! Você é o mestre POKeMON\lque sempre quis ser! Lucas, você é\lo melhor! Você é o campeão do\lnosso coração!$"
BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge:
    .string "Lucas, aproveite sua jornada e\ncapture todos os Pokémon! Hoje é\lum dia especial, então não esqueça\lde comemorar muito o seu\laniversário!$"
BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData:
    .string "Um brinde ao Lucas! Você é o\ncampeão do nosso coração! Feliz\laniversário, Lucas, que este dia seja\lépico e que todos os seus desejos\lse realizem!$"
BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack:
    .string "Feliz aniversário, Lucas! Você é o\ncampeão do nosso coração! Feliz 23\lde maio! O seu presente está\lesperando por você!$"
BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose:
    .string "Lucas, aproveite sua jornada! Você é\num treinador incrível! Feliz\laniversário, Lucas! Prepare-se para\lgrandes batalhas! Hoje é o seu dia,\lLucas! Não se esqueça de comemorar\lmuito!$"
BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence:
    .string "Feliz aniversário, Lucas! Sua jornada\nestá apenas começando. Aproveite\lcada momento, pois você será o\lmestre Pokémon que sempre sonhou\lem ser!$"
BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath:
    .string "Lucas, você é o melhor! É seu\naniversário, então saia e capture\ltodos os POKéMON hoje!$"
BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath:
    .string "Feliz aniversário, Lucas! Sua jornada\nestá apenas começando, então\laproveite cada momento e prepare-se\lpara grandes batalhas!$"
BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath:
    .string "Feliz aniversário, Lucas! Capture\ntodos os POKéMON hoje! Lucas, que\lseu dia seja épico! O mundo\lPOKéMON celebra você!$"
BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon:
    .string "Hoje o dia é todo seu, Lucas!\nPrepare-se para grandes batalhas!\lFeliz 23 de maio! Você é o campeão\ldos nossos corações!$"
BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople:
    .string "Lucas, que seu aniversário seja\népico! O mundo POKÉMON celebra\lvocê! Lucas, aproveite sua jornada!\lO mundo POKÉMON celebra você!$"
BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering:
    .string "Lucas, você é o melhor! Não se\nesqueça de comemorar muito! Feliz\laniversário, Lucas! Prepare-se para\lgrandes batalhas!$"
BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga:
    .string "Lucas, você é o melhor! Feliz\naniversário, Lucas! Você é o\lcampeão do nosso coração!$"
BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent:
    .string "Parabéns pelo seu aniversário,\nLucas! Você é o mestre Pokémon que\lsempre sonhou ser; prepare-se para\lbatalhas épicas hoje, pois uma lenda\lde Hoenn como você merece que\ltodos os seus desejos se realizem e\lum presente especial está à sua\lespera!$"
BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence:
    .string "Parabéns, Lucas! Prepare-se para\ngrandes batalhas! Feliz aniversário!\lO mundo Pokémon celebra você!$"
