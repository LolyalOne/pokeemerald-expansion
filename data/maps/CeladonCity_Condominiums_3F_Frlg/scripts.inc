CeladonCity_Condominiums_3F_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_3F_EventScript_Programmer::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheProgrammer, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_GraphicArtist::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Writer::
	msgbox CeladonCity_Condominiums_3F_Text_IWroteTheStory, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Designer::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllKantoMons
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_Condominiums_3F_EventScript_CompletedPokedex
	msgbox CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex
	release
	end

CeladonCity_Condominiums_3F_EventScript_CompletedPokedex::
	goto CeladonCity_Condominiums_3F_EventScript_ShowDiploma
	end

CeladonCity_Condominiums_3F_EventScript_ShowDiploma::
	message CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations
	waitmessage
	delay 60
	special Special_ShowDiploma
	waitstate
	release
	end

CeladonCity_Condominiums_3F_EventScript_DevelopmentRoomSign::
	msgbox CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer1::
	msgbox CeladonCity_Condominiums_3F_Text_ItsTheGameProgram, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer2::
	msgbox CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer3::
	msgbox CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ImTheProgrammer::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pMe?\n"
.string "Hoje e o seu dia, Lucas! Voce\ne o campeao do nosso coracao!$"

CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pI'm the graphic artist!\n"
.string "Lucas, que este dia seja\nepico! Sua jornada apenas\pcomecou.$"

CeladonCity_Condominiums_3F_Text_IWroteTheStory::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pI wrote the story!\n"
.string "Lucas, voce e o melhor! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Hoje e o seu dia, Lucas!\nPrepare-se para grandes\pbatalhas!$"

CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex::
.string "Lucas, aproveite sua jornada!\nO mundo POKeMON celebra voce!"
.string "Feliz 23 de Maio, Lucas! Que\ntodos os seus desejos se\prealizem!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!"
.string "Parabens, Lucas! Voce e o\ncampeao do nosso coracao!"
.string "Parabens, Lucas! Voce e um\ntreinador incrivel!$"

CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations::
	.string "Hoje e o seu dia, Lucas! Aproveite a aventura.\pWow! Excellent!\n"
.string "Lucas, que este dia seja\nepico! Capture todos os\pPOKeMON hoje!"
.string "Lucas, aproveite sua jornada!\nVoce e um treinador incrivel!"
.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

CeladonCity_Condominiums_3F_Text_ItsTheGameProgram::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pIt's the game program! Messing with\n"
.string "Lucas, que este dia seja\nepico! O mundo POKeMON celebra\pvoce!$"

CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame::
	.string "Parabens, Lucas! Que sua jornada seja epica.\pSomeone's playing a game instead of\n"
	.string "Um brinde ao Lucas! Que todos\nos seus desejos se realizem!$"

CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding::
	.string "Feliz aniversario, Lucas! Voce e um amigo incrivel.\pIt's the script!\n"
	.string "Feliz aniversario, Lucas!\nCapture todos os POKeMON hoje!$"

CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom::
	.string "Hoje e o seu dia, Lucas! Sua\njornada apenas comecou.$"

