PokeHelper_Menu::
# 2 "data/scripts/PokeHelper_Menu.pory"
	lockall
# 3 "data/scripts/PokeHelper_Menu.pory"
	multichoice 25, 5, MULTI_POKEHELPER_CHOICE, 0
# 4 "data/scripts/PokeHelper_Menu.pory"
	compare VAR_RESULT, 0
	goto_if_eq PokeHelper_Menu_3
PokeHelper_Menu_1:
# 7 "data/scripts/PokeHelper_Menu.pory"
	compare VAR_RESULT, 0
	goto_if_eq PokeHelper_Menu_8
PokeHelper_Menu_6:
# 10 "data/scripts/PokeHelper_Menu.pory"
	compare VAR_RESULT, 1
	goto_if_eq PokeHelper_Menu_13
PokeHelper_Menu_11:
# 13 "data/scripts/PokeHelper_Menu.pory"
	compare VAR_RESULT, 1
	goto_if_eq PokeHelper_Menu_18
PokeHelper_Menu_16:
# 17 "data/scripts/PokeHelper_Menu.pory"
	compare VAR_RESULT, 1
	goto_if_eq PokeHelper_Menu_25
PokeHelper_Menu_23:
# 23 "data/scripts/PokeHelper_Menu.pory"
	compare VAR_RESULT, 2
	goto_if_eq PokeHelper_Menu_32
PokeHelper_Menu_30:
# 26 "data/scripts/PokeHelper_Menu.pory"
	compare VAR_RESULT, 2
	goto_if_eq PokeHelper_Menu_37
PokeHelper_Menu_36:
# 31 "data/scripts/PokeHelper_Menu.pory"
	releaseall
	end

PokeHelper_Menu_2:
# 5 "data/scripts/PokeHelper_Menu.pory"
	msgbox PokeHelper_Menu_Text_0
	goto PokeHelper_Menu_1

PokeHelper_Menu_3:
# 4 "data/scripts/PokeHelper_Menu.pory"
	goto_if_unset FLAG_DEFEATED_RUSTBORO_GYM, PokeHelper_Menu_2
	goto PokeHelper_Menu_1

PokeHelper_Menu_7:
# 8 "data/scripts/PokeHelper_Menu.pory"
	call PokeHelperUsedDefog
	goto PokeHelper_Menu_6

PokeHelper_Menu_8:
# 7 "data/scripts/PokeHelper_Menu.pory"
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, PokeHelper_Menu_7
	goto PokeHelper_Menu_6

PokeHelper_Menu_12:
# 11 "data/scripts/PokeHelper_Menu.pory"
	msgbox PokeHelper_Menu_Text_1
	goto PokeHelper_Menu_11

PokeHelper_Menu_13:
# 10 "data/scripts/PokeHelper_Menu.pory"
	goto_if_unset FLAG_DEFEATED_DEWFORD_GYM, PokeHelper_Menu_12
	goto PokeHelper_Menu_11

PokeHelper_Menu_17:
# 15 "data/scripts/PokeHelper_Menu.pory"
	call PokeHelperUsedFlash
	goto PokeHelper_Menu_16

PokeHelper_Menu_18:
# 13 "data/scripts/PokeHelper_Menu.pory"
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, PokeHelper_Menu_20
	goto PokeHelper_Menu_16

PokeHelper_Menu_20:
# 13 "data/scripts/PokeHelper_Menu.pory"
	goto_if_unset FLAG_SYS_USE_FLASH, PokeHelper_Menu_17
	goto PokeHelper_Menu_16

PokeHelper_Menu_24:
# 19 "data/scripts/PokeHelper_Menu.pory"
	msgbox PokeHelper_Menu_Text_2
# 20 "data/scripts/PokeHelper_Menu.pory"
	releaseall
	end

PokeHelper_Menu_25:
# 17 "data/scripts/PokeHelper_Menu.pory"
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, PokeHelper_Menu_27
	goto PokeHelper_Menu_23

PokeHelper_Menu_27:
# 17 "data/scripts/PokeHelper_Menu.pory"
	goto_if_set FLAG_SYS_USE_FLASH, PokeHelper_Menu_24
	goto PokeHelper_Menu_23

PokeHelper_Menu_31:
# 24 "data/scripts/PokeHelper_Menu.pory"
	msgbox PokeHelper_Menu_Text_3
	goto PokeHelper_Menu_30

PokeHelper_Menu_32:
# 23 "data/scripts/PokeHelper_Menu.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, PokeHelper_Menu_31
	goto PokeHelper_Menu_30

PokeHelper_Menu_35:
# 27 "data/scripts/PokeHelper_Menu.pory"
	call PokeHelperUsedFly
	return

PokeHelper_Menu_37:
# 26 "data/scripts/PokeHelper_Menu.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, PokeHelper_Menu_35
	goto PokeHelper_Menu_36


PokeHelperUsedDefog:
# 37 "data/scripts/PokeHelper_Menu.pory"
	call EventScript_UseDefogGL
# 38 "data/scripts/PokeHelper_Menu.pory"
	releaseall
	end


PokeHelperUsedFlash:
# 43 "data/scripts/PokeHelper_Menu.pory"
	special CheckIfPlayerInCave
# 44 "data/scripts/PokeHelper_Menu.pory"
	goto_if_set FLAG_PLAYER_IN_CAVE, PokeHelperUsedFlash_1
# 58 "data/scripts/PokeHelper_Menu.pory"
	goto_if_unset FLAG_PLAYER_IN_CAVE, PokeHelperUsedFlash_2
# 65 "data/scripts/PokeHelper_Menu.pory"
	msgbox PokeHelperUsedFlash_Text_1, MSGBOX_DEFAULT
# 66 "data/scripts/PokeHelper_Menu.pory"
	releaseall
	end

PokeHelperUsedFlash_1:
# 45 "data/scripts/PokeHelper_Menu.pory"
	setflag FLAG_SYS_USE_FLASH
# 46 "data/scripts/PokeHelper_Menu.pory"
	msgbox PokeHelperUsedFlash_Text_0, MSGBOX_DEFAULT
# 47 "data/scripts/PokeHelper_Menu.pory"
	showmonpic SPECIES_MAKUHITA, 10, 5
# 48 "data/scripts/PokeHelper_Menu.pory"
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
# 49 "data/scripts/PokeHelper_Menu.pory"
	waitmoncry
# 50 "data/scripts/PokeHelper_Menu.pory"
	delay 60
# 51 "data/scripts/PokeHelper_Menu.pory"
	hidemonpic
# 52 "data/scripts/PokeHelper_Menu.pory"
	playse SE_M_REFLECT
# 53 "data/scripts/PokeHelper_Menu.pory"
	call EventScript_UseFlash
# 54 "data/scripts/PokeHelper_Menu.pory"
	releaseall
	end

PokeHelperUsedFlash_2:
# 59 "data/scripts/PokeHelper_Menu.pory"
	msgbox PokeHelperUsedFlash_Text_1, MSGBOX_DEFAULT
# 60 "data/scripts/PokeHelper_Menu.pory"
	releaseall
	end


PokeHelperUsedFly:
# 72 "data/scripts/PokeHelper_Menu.pory"
	special CheckIfPlayerUnderwater
# 73 "data/scripts/PokeHelper_Menu.pory"
	goto_if_set FLAG_PLAYER_UNDERWATER, PokeHelperUsedFly_1
# 79 "data/scripts/PokeHelper_Menu.pory"
	goto_if_unset FLAG_PLAYER_UNDERWATER, PokeHelperUsedFly_2
# 94 "data/scripts/PokeHelper_Menu.pory"
	msgbox PokeHelperUsedFly_Text_0, MSGBOX_DEFAULT
# 95 "data/scripts/PokeHelper_Menu.pory"
	releaseall
	end

PokeHelperUsedFly_1:
# 74 "data/scripts/PokeHelper_Menu.pory"
	msgbox PokeHelperUsedFly_Text_0, MSGBOX_DEFAULT
# 75 "data/scripts/PokeHelper_Menu.pory"
	releaseall
	end

PokeHelperUsedFly_2:
# 80 "data/scripts/PokeHelper_Menu.pory"
	msgbox PokeHelperUsedFly_Text_1, MSGBOX_DEFAULT
# 81 "data/scripts/PokeHelper_Menu.pory"
	showmonpic SPECIES_ALTARIA, 10, 3
# 82 "data/scripts/PokeHelper_Menu.pory"
	playmoncry SPECIES_ALTARIA, CRY_MODE_NORMAL
# 83 "data/scripts/PokeHelper_Menu.pory"
	waitmoncry
# 84 "data/scripts/PokeHelper_Menu.pory"
	delay 60
# 85 "data/scripts/PokeHelper_Menu.pory"
	hidemonpic
# 86 "data/scripts/PokeHelper_Menu.pory"
	closemessage
# 87 "data/scripts/PokeHelper_Menu.pory"
	setfieldeffectargument 0, 0
# 88 "data/scripts/PokeHelper_Menu.pory"
	special PokeHelperAction_Util_Fly
# 89 "data/scripts/PokeHelper_Menu.pory"
	releaseall
	end


PokeHelper_Menu_Text_0:
# 5 "data/scripts/PokeHelper_Menu.pory"
	.string "You can't use this until you defeat\nthe Rustboro Gym.$"

PokeHelper_Menu_Text_1:
# 11 "data/scripts/PokeHelper_Menu.pory"
	.string "You can't use this until you defeat\nthe Dewford Gym.$"

PokeHelper_Menu_Text_2:
# 19 "data/scripts/PokeHelper_Menu.pory"
	.string "You have already used FLASH in this area.$"

PokeHelper_Menu_Text_3:
# 24 "data/scripts/PokeHelper_Menu.pory"
	.string "You can't use this until you defeat\nthe Fortree Gym.$"

PokeHelperUsedFlash_Text_0:
# 46 "data/scripts/PokeHelper_Menu.pory"
	.string "Brawley's Makuhita helped your team to\nuse FLASH!$"

PokeHelperUsedFlash_Text_1:
# 59 "data/scripts/PokeHelper_Menu.pory"
	.string "Brawley's Makuhita can't help you use\nFLASH while you're not in a cave!$"

PokeHelperUsedFly_Text_0:
# 74 "data/scripts/PokeHelper_Menu.pory"
	.string "Winona's Altaria can't help you use\nFLY while you're underwater!$"

PokeHelperUsedFly_Text_1:
# 80 "data/scripts/PokeHelper_Menu.pory"
	.string "Winona's Altaria helped your team to FLY!\nWhere would you like to go?$"
