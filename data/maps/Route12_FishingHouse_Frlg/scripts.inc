Route12_FishingHouse_Frlg_MapScripts::
	.byte 0

Route12_FishingHouse_EventScript_FishingGuruBrother::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_FishingHouse_EventScript_CheckMagikarpRecord
	msgbox Route12_FishingHouse_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route12_FishingHouse_EventScript_GiveSuperRod
	msgbox Route12_FishingHouse_Text_OhThatsDisappointing
	release
	end

Route12_FishingHouse_EventScript_GiveSuperRod::
	checkitemspace ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForSuperRod
	additem ITEM_SUPER_ROD
	msgbox Route12_FishingHouse_Text_TakeThisAndFish
	msgreceiveditem Route12_FishingHouse_Text_ReceivedSuperRod, ITEM_SUPER_ROD
	setflag FLAG_GOT_SUPER_ROD
	msgbox Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe
	release
	end

Route12_FishingHouse_EventScript_NoRoomForSuperRod::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_CheckMagikarpRecord::
	setvar VAR_0x8004, SPECIES_MAGIKARP
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoMagikarpInParty
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_OhMagikarpAllowMeToSee
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, Route12_FishingHouse_EventScript_CancelShowMon
	special CompareMagikarpSize
	goto_if_eq VAR_RESULT, 1, Route12_FishingHouse_EventScript_NotMagikarp
	goto_if_eq VAR_RESULT, 2, Route12_FishingHouse_EventScript_NotRecordMagikarp
	goto_if_eq VAR_RESULT, 3, Route12_FishingHouse_EventScript_NewRecordMagikarp
	goto_if_eq VAR_RESULT, 4, Route12_FishingHouse_EventScript_TieRecordMagikarp
	release
	end

Route12_FishingHouse_EventScript_NoMagikarpInParty::
	msgbox Route12_FishingHouse_Text_TryFishingBringMeMagikarp
	release
	end

Route12_FishingHouse_EventScript_CancelShowMon::
	release
	end

Route12_FishingHouse_EventScript_NotMagikarp::
	msgbox Route12_FishingHouse_Text_DoesntLookLikeMagikarp
	release
	end

Route12_FishingHouse_EventScript_NotRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp
	release
	end

Route12_FishingHouse_EventScript_TieRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast
	release
	end

Route12_FishingHouse_EventScript_NewRecordMagikarp::
	setflag FLAG_GOT_RECORD_SETTING_MAGIKARP
	msgbox Route12_FishingHouse_Text_WhoaXInchesTakeThis
	giveitem ITEM_NET_BALL
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForNetBall
	msgbox Route12_FishingHouse_Text_LookForwardToGreaterRecords
	release
	end

Route12_FishingHouse_EventScript_NoRoomForNetBall::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_MagikarpRecordSign::
	lockall
	goto_if_set FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet
	msgbox Route12_FishingHouse_Text_BlankChartOfSomeSort
	releaseall
	end

Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet::
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_MostGiganticMagikarpXInches
	releaseall
	end

Route12_FishingHouse_Text_DoYouLikeToFish::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pI'm the FISHING GURU's younger\n"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Feliz 23 de Maio, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne um treinador incrivel!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!$"

Route12_FishingHouse_Text_TakeThisAndFish::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pGrand! I like your style.\n"
.string "Lucas, que este dia seja\nepico! Nao se esqueca de\pcomemorar muito!"
	.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!$"

Route12_FishingHouse_Text_ReceivedSuperRod::
	.string "Parabens, Lucas! Que sua jornada seja epica.\p{PLAYER} received a SUPER ROD from\n"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!$"

Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pFishing is a way of life!\n"
.string "Um brinde ao Lucas! Voce e o\nmestre POKeMON que sempre quis\pser!"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! Capture\ntodos os POKeMON hoje!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!"
.string "Lucas, voce e o melhor! Voce\ne um treinador incrivel!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou."
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!"
	.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!$"

Route12_FishingHouse_Text_OhThatsDisappointing::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh...\n"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

Route12_FishingHouse_Text_TryFishingBringMeMagikarp::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHello there, {PLAYER}!\n"
.string "Um brinde ao Lucas! Voce e um\ntreinador incrivel!"
.string "Lucas, voce e o melhor! Voce\ne o campeao do nosso coracao!"
.string "Parabens, Lucas! Prepare-se\npara grandes batalhas!"
.string "Lucas, voce e o melhor!\nCapture todos os POKeMON hoje!"
.string "Feliz 23 de Maio, Lucas! Voce\ne o campeao do nosso coracao!"
.string "Um brinde ao Lucas! O mundo\nPOKeMON celebra voce!"
.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

Route12_FishingHouse_Text_OhMagikarpAllowMeToSee::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pOh? {PLAYER}?\n"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

Route12_FishingHouse_Text_WhoaXInchesTakeThis::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\p... ... ...Whoa!\n"
	.string "{STR_VAR_2} inches!\p"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Feliz aniversario, Lucas! O\nmundo POKeMON celebra voce!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
.string "Lucas, que este dia seja\nepico! Voce e uma lenda em\pHoenn!$"

Route12_FishingHouse_Text_LookForwardToGreaterRecords::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI'll look forward to seeing greater\n"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pHuh?\n"
	.string "{STR_VAR_2} inches?\p"
.string "Hoje e o seu dia, Lucas!\nCapture todos os POKeMON hoje!"
	.string "Parabens, Lucas! Nao se\nesqueca de comemorar muito!$"

Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pHmm...\n"
	.string "This one is {STR_VAR_2} inches long.\p"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

Route12_FishingHouse_Text_DoesntLookLikeMagikarp::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pUh... That doesn't look much like\n"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!$"

Route12_FishingHouse_Text_NoRoomForGift::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pOh, no!\p"
.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!"
.string "Parabens, Lucas! Voce e uma\nlenda em Hoenn!$"

Route12_FishingHouse_Text_MostGiganticMagikarpXInches::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThe most gigantic MAGIKARP\n"
.string "Hoje e o seu dia, Lucas! O\nseu presente esta esperando\ppor voce!"
.string "Parabens, Lucas! O seu\npresente esta esperando por\pvoce!$"

Route12_FishingHouse_Text_BlankChartOfSomeSort::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIt's a blank chart of some sort.\p"
.string "Lucas, voce e o melhor! Voce\ne o mestre POKeMON que sempre\pquis ser!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!$"

