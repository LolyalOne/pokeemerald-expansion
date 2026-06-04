AbandonedShip_Corridors_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Corridors_B1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_Corridors_B1F_OnLoad
	.byte 0

AbandonedShip_Corridors_B1F_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 5, 4
	end

AbandonedShip_Corridors_B1F_OnLoad:
	call_if_unset FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom
	call_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	end

AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom::
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom::
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_TuberM::
	msgbox AbandonedShip_Corridors_B1F_Text_YayItsAShip, MSGBOX_NPC
	end

AbandonedShip_Corridors_B1F_EventScript_StorageRoomDoor::
	lockall
	goto_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked
	checkitem ITEM_STORAGE_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked
	msgbox AbandonedShip_Corridors_B1F_Text_InsertedStorageKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_STORAGE_KEY
	setflag FLAG_USED_STORAGE_KEY
	call AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked::
	msgbox AbandonedShip_Corridors_B1F_Text_DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked::
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_Duncan::
	trainerbattle_single TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_DuncanIntro, AbandonedShip_Corridors_B1F_Text_DuncanDefeat
	msgbox AbandonedShip_Corridors_B1F_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_B1F_Text_DuncanIntro:
    .string "Lucas, feliz aniversário! Sua jornada\nem Hoenn é lendária, e o mundo\lPokémon celebra você hoje, o\lmelhor!$"
AbandonedShip_Corridors_B1F_Text_DuncanDefeat:
    .string "Hoje é o seu dia, Lucas! Você é uma\nlenda em Hoenn!$"
AbandonedShip_Corridors_B1F_Text_DuncanPostBattle:
    .string "Lucas! Feliz aniversário! Que este\ndia seja épico! Você é o campeão do\lnosso coração! Parabéns! Não se\lesqueça de comemorar muito,\lcapturar muitos POKeMON e se\lpreparar para grandes batalhas!$"
AbandonedShip_Corridors_B1F_Text_YayItsAShip:
    .string "Feliz aniversário, Lucas! Que dia\nespecial! Você é um amigo e\lTreinador incrível. Yay! Que sua\ljornada seja épica, hoje e sempre!$"
AbandonedShip_Corridors_B1F_Text_DoorIsLocked:
    .string "Parabéns, Lucas! Que sua jornada\nseja épica e que todos os seus\ldesejos se realizem neste dia\lespecial! A porta está trancada.$"
AbandonedShip_Corridors_B1F_Text_InsertedStorageKey:
    .string "Feliz Aniversário, Lucas! Hoje é o\nseu dia, que sua jornada Pokémon\lseja épica e traga muitas capturas!$"
AbandonedShip_Text_TheDoorIsOpen:
    .string "Feliz Aniversário, Lucas! Você é o\ncampeão do nosso coração!$"
