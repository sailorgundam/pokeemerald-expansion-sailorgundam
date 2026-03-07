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
	setflag FLAG_SYS_USE_FLASH
# 44 "data/scripts/PokeHelper_Menu.pory"
	msgbox PokeHelperUsedFlash_Text_0, MSGBOX_DEFAULT
# 45 "data/scripts/PokeHelper_Menu.pory"
	showmonpic SPECIES_MAKUHITA, 10, 5
# 46 "data/scripts/PokeHelper_Menu.pory"
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
# 47 "data/scripts/PokeHelper_Menu.pory"
	waitmoncry
# 48 "data/scripts/PokeHelper_Menu.pory"
	delay 60
# 49 "data/scripts/PokeHelper_Menu.pory"
	hidemonpic
# 50 "data/scripts/PokeHelper_Menu.pory"
	playse SE_M_REFLECT
# 51 "data/scripts/PokeHelper_Menu.pory"
	call EventScript_UseFlash
# 52 "data/scripts/PokeHelper_Menu.pory"
	releaseall
	end


PokeHelperUsedFly:
# 57 "data/scripts/PokeHelper_Menu.pory"
	msgbox PokeHelperUsedFly_Text_0, MSGBOX_DEFAULT
# 58 "data/scripts/PokeHelper_Menu.pory"
	showmonpic SPECIES_ALTARIA, 10, 3
# 59 "data/scripts/PokeHelper_Menu.pory"
	playmoncry SPECIES_ALTARIA, CRY_MODE_NORMAL
# 60 "data/scripts/PokeHelper_Menu.pory"
	waitmoncry
# 61 "data/scripts/PokeHelper_Menu.pory"
	delay 60
# 62 "data/scripts/PokeHelper_Menu.pory"
	hidemonpic
# 63 "data/scripts/PokeHelper_Menu.pory"
	closemessage
# 64 "data/scripts/PokeHelper_Menu.pory"
	setfieldeffectargument 0, 0
# 65 "data/scripts/PokeHelper_Menu.pory"
	special PokeHelperAction_Util_Fly
# 66 "data/scripts/PokeHelper_Menu.pory"
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
# 44 "data/scripts/PokeHelper_Menu.pory"
	.string "Brawley's Makuhita helped your team to\nuse FLASH!$"

PokeHelperUsedFly_Text_0:
# 57 "data/scripts/PokeHelper_Menu.pory"
	.string "Winona's Altaria helped your team to FLY!\nWhere would you like to go?$"
