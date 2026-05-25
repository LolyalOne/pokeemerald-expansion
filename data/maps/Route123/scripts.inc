Route123_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
	.byte 0

Route123_OnTransition:
	special SetRoute123Weather
	end

Route123_EventScript_GigaDrainGirl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_GIGA_DRAIN, Route123_EventScript_ReceivedGigaDrain
	msgbox Route123_Text_LoveGrassMonsHaveAny, MSGBOX_DEFAULT
	special IsGrassTypeInParty
	goto_if_eq VAR_RESULT, FALSE, Route123_EventScript_NoGrassMons
	msgbox Route123_Text_YouLikeGrassMonsTooHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_GIGA_DRAIN
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_NoGrassMons::
	release
	end

Route123_EventScript_ReceivedGigaDrain::
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RouteSign::
	msgbox Route123_Text_RouteSign, MSGBOX_SIGN
	end

Route123_EventScript_RouteSignMtPyre::
	msgbox Route123_Text_RouteSignMtPyre, MSGBOX_SIGN
	end

Route123_EventScript_BerryMastersHouseSign::
	msgbox Route123_Text_BerryMastersHouse, MSGBOX_SIGN
	end

Route123_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY, Route123_Text_WendyIntro, Route123_Text_WendyDefeat
	msgbox Route123_Text_WendyPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Braxton::
	trainerbattle_single TRAINER_BRAXTON, Route123_Text_BraxtonIntro, Route123_Text_BraxtonDefeat
	msgbox Route123_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Violet::
	trainerbattle_single TRAINER_VIOLET, Route123_Text_VioletIntro, Route123_Text_VioletDefeat
	msgbox Route123_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON_1, Route123_Text_CameronIntro, Route123_Text_CameronDefeat, Route123_EventScript_RegisterCameron
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchCameron
	msgbox Route123_Text_CameronPostBattle, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RegisterCameron::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_CameronRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CAMERON_1
	release
	end

Route123_EventScript_RematchCameron::
	trainerbattle_rematch TRAINER_CAMERON_1, Route123_Text_CameronRematchIntro, Route123_Text_CameronRematchDefeat
	msgbox Route123_Text_CameronPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jacki::
	trainerbattle_single TRAINER_JACKI_1, Route123_Text_JackiIntro, Route123_Text_JackiDefeat, Route123_EventScript_RegisterJacki
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchJacki
	msgbox Route123_Text_JackiPostBattle, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RegisterJacki::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_JackiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKI_1
	release
	end

Route123_EventScript_RematchJacki::
	trainerbattle_rematch TRAINER_JACKI_1, Route123_Text_JackiRematchIntro, Route123_Text_JackiRematchDefeat
	msgbox Route123_Text_JackiPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Miu::
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_MiuIntro, Route123_Text_MiuDefeat, Route123_Text_MiuNotEnoughMons
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Yuki::
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_YukiIntro, Route123_Text_YukiDefeat, Route123_Text_YukiNotEnoughMons
	msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Kindra::
	trainerbattle_single TRAINER_KINDRA, Route123_Text_KindraIntro, Route123_Text_KindraDefeat
	msgbox Route123_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Frederick::
	trainerbattle_single TRAINER_FREDRICK, Route123_Text_FrederickIntro, Route123_Text_FrederickDefeat
	msgbox Route123_Text_FrederickPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Alberto::
	trainerbattle_single TRAINER_ALBERTO, Route123_Text_AlbertoIntro, Route123_Text_AlbertoDefeat
	msgbox Route123_Text_AlbertoPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Ed::
	trainerbattle_single TRAINER_ED, Route123_Text_EdIntro, Route123_Text_EdDefeat
	msgbox Route123_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Kayley::
	trainerbattle_single TRAINER_KAYLEY, Route123_Text_KayleyIntro, Route123_Text_KayleyDefeat
	msgbox Route123_Text_KayleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jonas::
	trainerbattle_single TRAINER_JONAS, Route123_Text_JonasIntro, Route123_Text_JonasDefeat
	msgbox Route123_Text_JonasPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jazmyn::
	trainerbattle_single TRAINER_JAZMYN, Route123_Text_JazmynIntro, Route123_Text_JazmynDefeat
	msgbox Route123_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Davis::
	trainerbattle_single TRAINER_DAVIS, Route123_Text_DavisIntro, Route123_Text_DavisDefeat
	msgbox Route123_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Fernando::
	trainerbattle_single TRAINER_FERNANDO_1, Route123_Text_FernandoIntro, Route123_Text_FernandoDefeat, Route123_EventScript_RegisterFernando
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchFernando
	msgbox Route123_Text_FernandoPostBattle, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RegisterFernando::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_FernandoRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_FERNANDO_1
	release
	end

Route123_EventScript_RematchFernando::
	trainerbattle_rematch TRAINER_FERNANDO_1, Route123_Text_FernandoRematchIntro, Route123_Text_FernandoRematchDefeat
	msgbox Route123_Text_FernandoPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_Text_LoveGrassMonsHaveAny:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI love GRASS-type POKeMON!\p"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"

Route123_Text_YouLikeGrassMonsTooHaveThis:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh?\p"
.string "Lucas, que este dia seja\nepico! Voce e o campeao do\pnosso coracao!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

Route123_Text_CheckTreesWithMyGrassMon:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI check trees with my GRASS-type\n"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

Route123_Text_RouteSign:
	.string "{RIGHT_ARROW} ROUTE 123\n"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

Route123_Text_RouteSignMtPyre:
	.string "{UP_ARROW} MT. PYRE\n"
	.string "Parabens, Lucas! O mundo\nPOKeMON celebra voce!$"

Route123_Text_BerryMastersHouse:
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

