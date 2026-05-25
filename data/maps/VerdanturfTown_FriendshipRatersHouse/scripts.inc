VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pLet me see your POKeMON.\n"
.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! Voce\ne uma lenda em Hoenn!"
	.string "Feliz aniversario, Lucas!\nVoce e um treinador incrivel!$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt adores you.\n"
.string "Um brinde ao Lucas!\nPrepare-se para grandes\pbatalhas!"
	.string "Parabens, Lucas! Que todos os\nseus desejos se realizem!$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt seems to be very happy.\n"
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt likes you quite a lot.\n"
.string "Feliz aniversario, Lucas! O\nseu presente esta esperando\ppor voce!$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pIt's getting used to you.\n"
.string "Feliz 23 de Maio, Lucas! O\nmundo POKeMON celebra voce!$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIt's not very used to you yet.\n"
	.string "Feliz aniversario, Lucas!\nVoce e uma lenda em Hoenn!$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIt's very wary.\n"
.string "Um brinde ao Lucas! Nao se\nesqueca de comemorar muito!"
.string "Feliz aniversario, Lucas! Sua\njornada apenas comecou.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "Parabens, Lucas! Que sua jornada seja epica.\pThis is a little hard for me to say...\p"
.string "Um brinde ao Lucas! Voce e o\ncampeao do nosso coracao!"
	.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "Um brinde ao Lucas! Voce e\numa lenda em Hoenn!$"

