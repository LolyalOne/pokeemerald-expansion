FiveIsland_MemorialPillar_Frlg_MapScripts::
	.byte 0

FiveIsland_MemorialPillar_EventScript_MemorialMan::
	lock
	goto_if_set FLAG_GOT_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_AlreadyGotTM42
	goto_if_set FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_ReturnedForTM42
	msgbox FiveIsland_MemorialPillar_Text_ScrubScrub
	closemessage
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_FacePlayer
	waitmovement 0
	delay 45
	msgbox FiveIsland_MemorialPillar_Text_YourMonsLookHealthy
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox FiveIsland_MemorialPillar_Text_ThisIsWhereIBuriedMyOnix
	release
	end

FiveIsland_MemorialPillar_EventScript_AlreadyGotTM42::
	msgbox FiveIsland_MemorialPillar_Text_ScrubScrubTectonix
	release
	end

FiveIsland_MemorialPillar_EventScript_ReturnedForTM42::
	msgbox FiveIsland_MemorialPillar_Text_StillHaveThingAsMyThanks
	giveitem ITEM_TM42
	goto_if_eq VAR_RESULT, FALSE, FiveIsland_MemorialPillar_EventScript_NoRoomForTM42
	call FiveIsland_MemorialPillar_EventScript_ReceivedTM42
	release
	end

FiveIsland_MemorialPillar_EventScript_Memorial::
	lockall
	goto_if_set FLAG_GOT_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced
	goto_if_set FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced
	msgbox FiveIsland_MemorialPillar_Text_HereLiesTectonixLemonadeOffering
	checkitem ITEM_LEMONADE
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_MemorialPillar_EventScript_AskPlaceLemonade
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_AskPlaceLemonade::
	msgbox FiveIsland_MemorialPillar_Text_LeaveAnotherLemonadeOffering, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FiveIsland_MemorialPillar_EventScript_PlaceLemonade
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_PlaceLemonade::
	removeitem ITEM_LEMONADE
	msgbox FiveIsland_MemorialPillar_Text_PlacedCanOfLemonade
	closemessage
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 45
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FiveIsland_MemorialPillar_Text_ThankYouPleaseTakeThis
	giveitem ITEM_TM42
	goto_if_eq VAR_RESULT, FALSE, FiveIsland_MemorialPillar_EventScript_NoRoomForTM42
	call FiveIsland_MemorialPillar_EventScript_ReceivedTM42
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_ReceivedTM42::
	msgbox FiveIsland_MemorialPillar_Text_BeGoodToYourMonsToo
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setflag FLAG_GOT_TM42_AT_MEMORIAL_PILLAR
	return

FiveIsland_MemorialPillar_EventScript_NoRoomForTM42::
	setflag FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR
	msgbox FiveIsland_MemorialPillar_Text_DontHaveRoomForIt
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced::
	msgbox FiveIsland_MemorialPillar_Text_HereLiesTectonix
	releaseall
	end

FiveIsland_MemorialPillar_Text_MiloIntro::
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!$"

FiveIsland_MemorialPillar_Text_MiloDefeat::
.string "Lucas, aproveite sua jornada!\nVoce e uma lenda em Hoenn!$"

FiveIsland_MemorialPillar_Text_MiloPostBattle::
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Lucas, que este dia seja\nepico! Voce e um treinador\pincrivel!$"

FiveIsland_MemorialPillar_Text_ChazIntro::
.string "Feliz 23 de Maio, Lucas!\nCapture todos os POKeMON hoje!"
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

FiveIsland_MemorialPillar_Text_ChazDefeat::
	.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!$"

FiveIsland_MemorialPillar_Text_ChazPostBattle::
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

FiveIsland_MemorialPillar_Text_HaroldIntro::
.string "Um brinde ao Lucas! Sua\njornada apenas comecou."
.string "Lucas, voce e o melhor! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

FiveIsland_MemorialPillar_Text_HaroldDefeat::
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

FiveIsland_MemorialPillar_Text_HaroldPostBattle::
.string "Lucas, aproveite sua jornada!\nSua jornada apenas comecou."
	.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

FiveIsland_MemorialPillar_Text_ScrubScrub::
.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

FiveIsland_MemorialPillar_Text_YourMonsLookHealthy::
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!$"

FiveIsland_MemorialPillar_Text_ThisIsWhereIBuriedMyOnix::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pThis is where I buried my ONIX...\n"
	.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!$"

FiveIsland_MemorialPillar_Text_HereLiesTectonixLemonadeOffering::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\p“Here lies TECTONIX” is engraved\n"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

FiveIsland_MemorialPillar_Text_LeaveAnotherLemonadeOffering::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pWould you like to leave another\n"
	.string "Feliz aniversario, Lucas! Nao\nse esqueca de comemorar muito!$"

FiveIsland_MemorialPillar_Text_PlacedCanOfLemonade::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER} placed a can of LEMONADE\n"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!$"

FiveIsland_MemorialPillar_Text_ThankYouPleaseTakeThis::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pTh-thank you...\p"
.string "Feliz aniversario, Lucas!\nPrepare-se para grandes\pbatalhas!"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Feliz aniversario, Lucas!\nVoce e o campeao do nosso\pcoracao!"
.string "Lucas, voce e o melhor! Voce\ne uma lenda em Hoenn!"
.string "Lucas, aproveite sua jornada!\nPrepare-se para grandes\pbatalhas!$"

FiveIsland_MemorialPillar_Text_BeGoodToYourMonsToo::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pPlease be good to your POKeMON,\n"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

FiveIsland_MemorialPillar_Text_DontHaveRoomForIt::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIf you don't have room for it,\n"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

FiveIsland_MemorialPillar_Text_StillHaveThingAsMyThanks::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh, it's you from that time...\p"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Feliz 23 de Maio, Lucas! O\nseu presente esta esperando\ppor voce!$"

FiveIsland_MemorialPillar_Text_ScrubScrubTectonix::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pScrub, scrub...\p"
.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!"
	.string "Hoje e o seu dia, Lucas! Nao\nse esqueca de comemorar muito!$"

FiveIsland_MemorialPillar_Text_HereLiesTectonix::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pBoulders and rocks are neatly piled\n"
.string "Lucas, que este dia seja\nepico! Que todos os seus\pdesejos se realizem!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou."
	.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!$"

