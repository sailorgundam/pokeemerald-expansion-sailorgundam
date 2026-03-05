# 1 "data/scripts/field_move_scripts.pory"

# 2 "data/scripts/field_move_scripts.pory"
@ Interact with cuttable tree
# 3 "data/scripts/field_move_scripts.pory"
EventScript_CutTree::
# 4 "data/scripts/field_move_scripts.pory"
	lockall
# 5 "data/scripts/field_move_scripts.pory"
	checkfieldmove FIELD_MOVE_CUT, TRUE
# 6 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
# 7 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 8 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 9 "data/scripts/field_move_scripts.pory"
	buffermovename STR_VAR_2, MOVE_CUT
# 10 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToCut, MSGBOX_YESNO
# 11 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
# 12 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 13 "data/scripts/field_move_scripts.pory"
	closemessage
# 14 "data/scripts/field_move_scripts.pory"
EventScript_CutTreeCommon:
# 15 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 16 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
# 17 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
# 18 "data/scripts/field_move_scripts.pory"
	waitstate
# 19 "data/scripts/field_move_scripts.pory"
EventScript_CutTreeDown:: @ fallthrough
# 20 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 21 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 22 "data/scripts/field_move_scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
# 23 "data/scripts/field_move_scripts.pory"
	playse SE_M_CUT
# 24 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 25 "data/scripts/field_move_scripts.pory"
	removeobject VAR_LAST_TALKED
# 26 "data/scripts/field_move_scripts.pory"
	releaseall
# 27 "data/scripts/field_move_scripts.pory"
	end
# 28 "data/scripts/field_move_scripts.pory"

# 29 "data/scripts/field_move_scripts.pory"
@ Use cut from party menu
# 30 "data/scripts/field_move_scripts.pory"
EventScript_UseCut::
# 31 "data/scripts/field_move_scripts.pory"
	lockall
# 32 "data/scripts/field_move_scripts.pory"
	goto EventScript_CutTreeCommon
# 33 "data/scripts/field_move_scripts.pory"

# 34 "data/scripts/field_move_scripts.pory"
Movement_CutTreeDown:
# 35 "data/scripts/field_move_scripts.pory"
	cut_tree
# 36 "data/scripts/field_move_scripts.pory"
	step_end
# 37 "data/scripts/field_move_scripts.pory"

# 38 "data/scripts/field_move_scripts.pory"
EventScript_CheckTreeCantCut::
# 39 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantCut, MSGBOX_DEFAULT
# 40 "data/scripts/field_move_scripts.pory"
	releaseall
# 41 "data/scripts/field_move_scripts.pory"
	end
# 42 "data/scripts/field_move_scripts.pory"

# 43 "data/scripts/field_move_scripts.pory"
EventScript_CancelCut::
# 44 "data/scripts/field_move_scripts.pory"
	closemessage
# 45 "data/scripts/field_move_scripts.pory"
	releaseall
# 46 "data/scripts/field_move_scripts.pory"
	end
# 47 "data/scripts/field_move_scripts.pory"

# 48 "data/scripts/field_move_scripts.pory"
Text_WantToCut:
# 49 "data/scripts/field_move_scripts.pory"
	.string "This tree looks like it can be\n"
# 50 "data/scripts/field_move_scripts.pory"
	.string "CUT down!\p"
# 51 "data/scripts/field_move_scripts.pory"
	.string "Would you like to CUT it?$"
# 52 "data/scripts/field_move_scripts.pory"

# 53 "data/scripts/field_move_scripts.pory"
Text_MonUsedFieldMove:
# 54 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used {STR_VAR_2}!$"
# 55 "data/scripts/field_move_scripts.pory"

# 56 "data/scripts/field_move_scripts.pory"
Text_CantCut:
# 57 "data/scripts/field_move_scripts.pory"
	.string "This tree looks like it can be\n"
# 58 "data/scripts/field_move_scripts.pory"
	.string "CUT down!$"
# 59 "data/scripts/field_move_scripts.pory"

# 60 "data/scripts/field_move_scripts.pory"
@ Use rock smash from party menu
# 61 "data/scripts/field_move_scripts.pory"
EventScript_UseRockSmash::
# 62 "data/scripts/field_move_scripts.pory"
	lockall
# 63 "data/scripts/field_move_scripts.pory"
	goto EventScript_RockSmashCommon
# 64 "data/scripts/field_move_scripts.pory"

# 65 "data/scripts/field_move_scripts.pory"
@ Interact with smashable rock
# 66 "data/scripts/field_move_scripts.pory"
EventScript_RockSmash::
# 67 "data/scripts/field_move_scripts.pory"
	lockall
# 68 "data/scripts/field_move_scripts.pory"
	checkfieldmove FIELD_MOVE_ROCK_SMASH, TRUE
# 69 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
# 70 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 71 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 72 "data/scripts/field_move_scripts.pory"
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
# 73 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToSmash, MSGBOX_YESNO
# 74 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
# 75 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 76 "data/scripts/field_move_scripts.pory"
	closemessage
# 77 "data/scripts/field_move_scripts.pory"
EventScript_RockSmashCommon:
# 78 "data/scripts/field_move_scripts.pory"
	@ check if follower should use the field move
# 79 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 80 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
# 81 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 82 "data/scripts/field_move_scripts.pory"
	waitstate
# 83 "data/scripts/field_move_scripts.pory"
EventScript_SmashRock:: @ fallthrough
# 84 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 85 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 86 "data/scripts/field_move_scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_SmashRock
# 87 "data/scripts/field_move_scripts.pory"
	playse SE_M_ROCK_THROW
# 88 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 89 "data/scripts/field_move_scripts.pory"
	removeobject VAR_LAST_TALKED
# 90 "data/scripts/field_move_scripts.pory"
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
# 91 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
# 92 "data/scripts/field_move_scripts.pory"
	special RockSmashWildEncounter
# 93 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
# 94 "data/scripts/field_move_scripts.pory"
	waitstate
# 95 "data/scripts/field_move_scripts.pory"
	releaseall
# 96 "data/scripts/field_move_scripts.pory"
	end
# 97 "data/scripts/field_move_scripts.pory"

# 98 "data/scripts/field_move_scripts.pory"
EventScript_FollowerFieldMove:
# 99 "data/scripts/field_move_scripts.pory"
	getdirectiontoface VAR_0x8005, OBJ_EVENT_ID_FOLLOWER, OBJ_EVENT_ID_PLAYER
# 100 "data/scripts/field_move_scripts.pory"
	specialvar VAR_0x8006, GetPlayerFacingDirection
# 101 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_0x8005, DIR_NONE, EventScript_FollowerFieldMoveEnd
# 102 "data/scripts/field_move_scripts.pory"
	@ Swap follower and player
# 103 "data/scripts/field_move_scripts.pory"
	call EventScript_FollowerSwap
# 104 "data/scripts/field_move_scripts.pory"
	@ Face follower in direction and jump
# 105 "data/scripts/field_move_scripts.pory"
	switch VAR_0x8006
# 106 "data/scripts/field_move_scripts.pory"
	case DIR_NORTH, EventScript_FollowerJumpNorth
# 107 "data/scripts/field_move_scripts.pory"
	case DIR_EAST, EventScript_FollowerJumpEast
# 108 "data/scripts/field_move_scripts.pory"
	case DIR_SOUTH, EventScript_FollowerJumpSouth
# 109 "data/scripts/field_move_scripts.pory"
	case DIR_WEST, EventScript_FollowerJumpWest
# 110 "data/scripts/field_move_scripts.pory"
EventScript_FollowerFieldMoveEnd:
# 111 "data/scripts/field_move_scripts.pory"
	return
# 112 "data/scripts/field_move_scripts.pory"

# 113 "data/scripts/field_move_scripts.pory"
EventScript_FollowerSwap:
# 114 "data/scripts/field_move_scripts.pory"
	switch VAR_0x8005
# 115 "data/scripts/field_move_scripts.pory"
	case DIR_NORTH, EventScript_FollowerMoveNorth
# 116 "data/scripts/field_move_scripts.pory"
	case DIR_EAST, EventScript_FollowerMoveEast
# 117 "data/scripts/field_move_scripts.pory"
	case DIR_SOUTH, EventScript_FollowerMoveSouth
# 118 "data/scripts/field_move_scripts.pory"
	case DIR_WEST, EventScript_FollowerMoveWest
# 119 "data/scripts/field_move_scripts.pory"
	return
# 120 "data/scripts/field_move_scripts.pory"

# 121 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveNorth:
# 122 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkDown
# 123 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 124 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 125 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 126 "data/scripts/field_move_scripts.pory"
	return
# 127 "data/scripts/field_move_scripts.pory"

# 128 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveEast:
# 129 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkLeft
# 130 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 131 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 132 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 133 "data/scripts/field_move_scripts.pory"
	return
# 134 "data/scripts/field_move_scripts.pory"

# 135 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveSouth:
# 136 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
# 137 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 138 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 139 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 140 "data/scripts/field_move_scripts.pory"
	return
# 141 "data/scripts/field_move_scripts.pory"

# 142 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveWest:
# 143 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkRight
# 144 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 145 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 146 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 147 "data/scripts/field_move_scripts.pory"
	return
# 148 "data/scripts/field_move_scripts.pory"

# 149 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpNorth:
# 150 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpUp
# 151 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 152 "data/scripts/field_move_scripts.pory"
	return
# 153 "data/scripts/field_move_scripts.pory"

# 154 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpEast:
# 155 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpRight
# 156 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 157 "data/scripts/field_move_scripts.pory"
	return
# 158 "data/scripts/field_move_scripts.pory"

# 159 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpSouth:
# 160 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpDown
# 161 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 162 "data/scripts/field_move_scripts.pory"
	return
# 163 "data/scripts/field_move_scripts.pory"

# 164 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpWest:
# 165 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpLeft
# 166 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 167 "data/scripts/field_move_scripts.pory"
	return
# 168 "data/scripts/field_move_scripts.pory"

# 169 "data/scripts/field_move_scripts.pory"
EventScript_EndSmash::
# 170 "data/scripts/field_move_scripts.pory"
	releaseall
# 171 "data/scripts/field_move_scripts.pory"
	end
# 172 "data/scripts/field_move_scripts.pory"

# 173 "data/scripts/field_move_scripts.pory"
Movement_WalkUp:
# 174 "data/scripts/field_move_scripts.pory"
	walk_up
# 175 "data/scripts/field_move_scripts.pory"
	step_end
# 176 "data/scripts/field_move_scripts.pory"

# 177 "data/scripts/field_move_scripts.pory"
Movement_JumpUp:
# 178 "data/scripts/field_move_scripts.pory"
	jump_in_place_up
# 179 "data/scripts/field_move_scripts.pory"
	step_end
# 180 "data/scripts/field_move_scripts.pory"

# 181 "data/scripts/field_move_scripts.pory"
Movement_WalkRight:
# 182 "data/scripts/field_move_scripts.pory"
	walk_right
# 183 "data/scripts/field_move_scripts.pory"
	step_end
# 184 "data/scripts/field_move_scripts.pory"

# 185 "data/scripts/field_move_scripts.pory"
Movement_JumpRight:
# 186 "data/scripts/field_move_scripts.pory"
	jump_in_place_right
# 187 "data/scripts/field_move_scripts.pory"
	step_end
# 188 "data/scripts/field_move_scripts.pory"

# 189 "data/scripts/field_move_scripts.pory"
Movement_WalkDown:
# 190 "data/scripts/field_move_scripts.pory"
	walk_down
# 191 "data/scripts/field_move_scripts.pory"
	step_end
# 192 "data/scripts/field_move_scripts.pory"

# 193 "data/scripts/field_move_scripts.pory"
Movement_JumpDown:
# 194 "data/scripts/field_move_scripts.pory"
	jump_in_place_down
# 195 "data/scripts/field_move_scripts.pory"
	step_end
# 196 "data/scripts/field_move_scripts.pory"

# 197 "data/scripts/field_move_scripts.pory"
Movement_WalkLeft:
# 198 "data/scripts/field_move_scripts.pory"
	walk_left
# 199 "data/scripts/field_move_scripts.pory"
	step_end
# 200 "data/scripts/field_move_scripts.pory"

# 201 "data/scripts/field_move_scripts.pory"
Movement_JumpLeft:
# 202 "data/scripts/field_move_scripts.pory"
	jump_in_place_left
# 203 "data/scripts/field_move_scripts.pory"
	step_end
# 204 "data/scripts/field_move_scripts.pory"

# 205 "data/scripts/field_move_scripts.pory"
Movement_SmashRock:
# 206 "data/scripts/field_move_scripts.pory"
	rock_smash_break
# 207 "data/scripts/field_move_scripts.pory"
	step_end
# 208 "data/scripts/field_move_scripts.pory"

# 209 "data/scripts/field_move_scripts.pory"
EventScript_CantSmashRock::
# 210 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantSmash, MSGBOX_DEFAULT
# 211 "data/scripts/field_move_scripts.pory"
	releaseall
# 212 "data/scripts/field_move_scripts.pory"
	end
# 213 "data/scripts/field_move_scripts.pory"

# 214 "data/scripts/field_move_scripts.pory"
EventScript_CancelSmash::
# 215 "data/scripts/field_move_scripts.pory"
	closemessage
# 216 "data/scripts/field_move_scripts.pory"
	releaseall
# 217 "data/scripts/field_move_scripts.pory"
	end
# 218 "data/scripts/field_move_scripts.pory"

# 219 "data/scripts/field_move_scripts.pory"
Text_WantToSmash:
# 220 "data/scripts/field_move_scripts.pory"
	.string "This rock appears to be breakable.\n"
# 221 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use ROCK SMASH?$"
# 222 "data/scripts/field_move_scripts.pory"

# 223 "data/scripts/field_move_scripts.pory"
Text_CantSmash:
# 224 "data/scripts/field_move_scripts.pory"
	.string "It's a rugged rock, but a POKéMON\n"
# 225 "data/scripts/field_move_scripts.pory"
	.string "may be able to smash it.$"
# 226 "data/scripts/field_move_scripts.pory"

# 227 "data/scripts/field_move_scripts.pory"
EventScript_StrengthBoulder::
# 228 "data/scripts/field_move_scripts.pory"
	lockall
# 229 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
# 230 "data/scripts/field_move_scripts.pory"
	checkfieldmove FIELD_MOVE_STRENGTH, TRUE
# 231 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantStrength
# 232 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 233 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToStrength, MSGBOX_YESNO
# 234 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
# 235 "data/scripts/field_move_scripts.pory"
	closemessage
# 236 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_STRENGTH
# 237 "data/scripts/field_move_scripts.pory"
	waitstate
# 238 "data/scripts/field_move_scripts.pory"
	goto EventScript_ActivateStrength
# 239 "data/scripts/field_move_scripts.pory"
	end
# 240 "data/scripts/field_move_scripts.pory"

# 241 "data/scripts/field_move_scripts.pory"
EventScript_UseStrength::
# 242 "data/scripts/field_move_scripts.pory"
	lockall
# 243 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_STRENGTH
# 244 "data/scripts/field_move_scripts.pory"
	waitstate
# 245 "data/scripts/field_move_scripts.pory"
	goto EventScript_ActivateStrength
# 246 "data/scripts/field_move_scripts.pory"
	end
# 247 "data/scripts/field_move_scripts.pory"

# 248 "data/scripts/field_move_scripts.pory"
EventScript_ActivateStrength::
# 249 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SYS_USE_STRENGTH
# 250 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
# 251 "data/scripts/field_move_scripts.pory"
	releaseall
# 252 "data/scripts/field_move_scripts.pory"
	end
# 253 "data/scripts/field_move_scripts.pory"

# 254 "data/scripts/field_move_scripts.pory"
EventScript_CantStrength::
# 255 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantStrength, MSGBOX_DEFAULT
# 256 "data/scripts/field_move_scripts.pory"
	releaseall
# 257 "data/scripts/field_move_scripts.pory"
	end
# 258 "data/scripts/field_move_scripts.pory"

# 259 "data/scripts/field_move_scripts.pory"
EventScript_CheckActivatedBoulder::
# 260 "data/scripts/field_move_scripts.pory"
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
# 261 "data/scripts/field_move_scripts.pory"
	releaseall
# 262 "data/scripts/field_move_scripts.pory"
	end
# 263 "data/scripts/field_move_scripts.pory"

# 264 "data/scripts/field_move_scripts.pory"
EventScript_CancelStrength::
# 265 "data/scripts/field_move_scripts.pory"
	closemessage
# 266 "data/scripts/field_move_scripts.pory"
	releaseall
# 267 "data/scripts/field_move_scripts.pory"
	end
# 268 "data/scripts/field_move_scripts.pory"

# 269 "data/scripts/field_move_scripts.pory"
Text_WantToStrength:
# 270 "data/scripts/field_move_scripts.pory"
	.string "It's a big boulder, but a POKéMON\n"
# 271 "data/scripts/field_move_scripts.pory"
	.string "may be able to push it aside.\p"
# 272 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use STRENGTH?$"
# 273 "data/scripts/field_move_scripts.pory"

# 274 "data/scripts/field_move_scripts.pory"
Text_MonUsedStrength:
# 275 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used STRENGTH!\p"
# 276 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
# 277 "data/scripts/field_move_scripts.pory"
	.string "possible to move boulders around!$"
# 278 "data/scripts/field_move_scripts.pory"

# 279 "data/scripts/field_move_scripts.pory"
Text_CantStrength:
# 280 "data/scripts/field_move_scripts.pory"
	.string "It's a big boulder, but a POKéMON\n"
# 281 "data/scripts/field_move_scripts.pory"
	.string "may be able to push it aside.$"
# 282 "data/scripts/field_move_scripts.pory"

# 283 "data/scripts/field_move_scripts.pory"
Text_StrengthActivated:
# 284 "data/scripts/field_move_scripts.pory"
	.string "STRENGTH made it possible to move\n"
# 285 "data/scripts/field_move_scripts.pory"
	.string "boulders around.$"
# 286 "data/scripts/field_move_scripts.pory"

# 287 "data/scripts/field_move_scripts.pory"
EventScript_UseWaterfall::
# 288 "data/scripts/field_move_scripts.pory"
	lockall
# 289 "data/scripts/field_move_scripts.pory"
	checkfieldmove FIELD_MOVE_WATERFALL
# 290 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
# 291 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 292 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 293 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
# 294 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
# 295 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
# 296 "data/scripts/field_move_scripts.pory"
	hidefollowernpc
# 297 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_WATERFALL
# 298 "data/scripts/field_move_scripts.pory"
	callnative FollowerNPC_WarpSetEnd
# 299 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndWaterfall
# 300 "data/scripts/field_move_scripts.pory"

# 301 "data/scripts/field_move_scripts.pory"
EventScript_CannotUseWaterfall::
# 302 "data/scripts/field_move_scripts.pory"
	lockall
# 303 "data/scripts/field_move_scripts.pory"

# 304 "data/scripts/field_move_scripts.pory"
EventScript_CantWaterfall::
# 305 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT
# 306 "data/scripts/field_move_scripts.pory"

# 307 "data/scripts/field_move_scripts.pory"
EventScript_EndWaterfall::
# 308 "data/scripts/field_move_scripts.pory"
	releaseall
# 309 "data/scripts/field_move_scripts.pory"
	end
# 310 "data/scripts/field_move_scripts.pory"

# 311 "data/scripts/field_move_scripts.pory"
Text_CantWaterfall:
# 312 "data/scripts/field_move_scripts.pory"
	.string "A wall of water is crashing down with\n"
# 313 "data/scripts/field_move_scripts.pory"
	.string "a mighty roar.$"
# 314 "data/scripts/field_move_scripts.pory"

# 315 "data/scripts/field_move_scripts.pory"
Text_WantToWaterfall:
# 316 "data/scripts/field_move_scripts.pory"
	.string "It's a large waterfall.\n"
# 317 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use WATERFALL?$"
# 318 "data/scripts/field_move_scripts.pory"

# 319 "data/scripts/field_move_scripts.pory"
Text_MonUsedWaterfall:
# 320 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used WATERFALL.$"
# 321 "data/scripts/field_move_scripts.pory"

# 322 "data/scripts/field_move_scripts.pory"
EventScript_UseDive::
# 323 "data/scripts/field_move_scripts.pory"
	lockall
# 324 "data/scripts/field_move_scripts.pory"
	checkfieldmove FIELD_MOVE_DIVE
# 325 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
# 326 "data/scripts/field_move_scripts.pory"
	copyvar 0x8004 VAR_RESULT
# 327 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 328 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 329 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 1, 1
# 330 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToDive, MSGBOX_YESNO
# 331 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
# 332 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
# 333 "data/scripts/field_move_scripts.pory"
	hidefollowernpc
# 334 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_0x8004
# 335 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 1, 1
# 336 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_DIVE
# 337 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndDive
# 338 "data/scripts/field_move_scripts.pory"
	end
# 339 "data/scripts/field_move_scripts.pory"

# 340 "data/scripts/field_move_scripts.pory"
EventScript_CantDive::
# 341 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantDive, MSGBOX_DEFAULT
# 342 "data/scripts/field_move_scripts.pory"
	releaseall
# 343 "data/scripts/field_move_scripts.pory"
	end
# 344 "data/scripts/field_move_scripts.pory"

# 345 "data/scripts/field_move_scripts.pory"
EventScript_EndDive::
# 346 "data/scripts/field_move_scripts.pory"
	releaseall
# 347 "data/scripts/field_move_scripts.pory"
	end
# 348 "data/scripts/field_move_scripts.pory"

# 349 "data/scripts/field_move_scripts.pory"
EventScript_UseDiveUnderwater::
# 350 "data/scripts/field_move_scripts.pory"
	lockall
# 351 "data/scripts/field_move_scripts.pory"
	checkfieldmove FIELD_MOVE_DIVE
# 352 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
# 353 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 354 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 355 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 1, 1
# 356 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToSurface, MSGBOX_YESNO
# 357 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_NoSurface
# 358 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
# 359 "data/scripts/field_move_scripts.pory"
	hidefollowernpc
# 360 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_DIVE
# 361 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndSurface
# 362 "data/scripts/field_move_scripts.pory"
	end
# 363 "data/scripts/field_move_scripts.pory"

# 364 "data/scripts/field_move_scripts.pory"
EventScript_CantSurface::
# 365 "data/scripts/field_move_scripts.pory"
	lockall
# 366 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantSurface, MSGBOX_DEFAULT
# 367 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndSurface
# 368 "data/scripts/field_move_scripts.pory"
	end
# 369 "data/scripts/field_move_scripts.pory"

# 370 "data/scripts/field_move_scripts.pory"
EventScript_EndSurface::
# 371 "data/scripts/field_move_scripts.pory"
	callnative SetFollowerNPCSurfSpriteAfterDive
# 372 "data/scripts/field_move_scripts.pory"
EventScript_NoSurface::
# 373 "data/scripts/field_move_scripts.pory"
	releaseall
# 374 "data/scripts/field_move_scripts.pory"
	end
# 375 "data/scripts/field_move_scripts.pory"

# 376 "data/scripts/field_move_scripts.pory"
EventScript_DigCommon:
# 377 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 378 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
# 379 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_DIG
# 380 "data/scripts/field_move_scripts.pory"
	waitstate
# 381 "data/scripts/field_move_scripts.pory"
EventScript_DigSealedChamber:: @ fallthrough
# 382 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 383 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 384 "data/scripts/field_move_scripts.pory"
	callnative DoBrailleDigEffect
# 385 "data/scripts/field_move_scripts.pory"
	releaseall
# 386 "data/scripts/field_move_scripts.pory"
	end
# 387 "data/scripts/field_move_scripts.pory"

# 388 "data/scripts/field_move_scripts.pory"
@ Use Dig from party menu
# 389 "data/scripts/field_move_scripts.pory"
EventScript_UseDig::
# 390 "data/scripts/field_move_scripts.pory"
	lockall
# 391 "data/scripts/field_move_scripts.pory"
	goto EventScript_DigCommon
# 392 "data/scripts/field_move_scripts.pory"

# 393 "data/scripts/field_move_scripts.pory"

# 394 "data/scripts/field_move_scripts.pory"
EventScript_CutGrassCommon:
# 395 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 396 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
# 397 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_CUT_ON_GRASS
# 398 "data/scripts/field_move_scripts.pory"
	waitstate
# 399 "data/scripts/field_move_scripts.pory"

# 400 "data/scripts/field_move_scripts.pory"
@ Use Cut grass from party menu
# 401 "data/scripts/field_move_scripts.pory"
EventScript_UseCutGrass::
# 402 "data/scripts/field_move_scripts.pory"
	lockall
# 403 "data/scripts/field_move_scripts.pory"
	goto EventScript_CutGrassCommon
# 404 "data/scripts/field_move_scripts.pory"

# 405 "data/scripts/field_move_scripts.pory"
Text_CantDive:
# 406 "data/scripts/field_move_scripts.pory"
	.string "The sea is deep here. A POKéMON\n"
# 407 "data/scripts/field_move_scripts.pory"
	.string "may be able to go underwater.$"
# 408 "data/scripts/field_move_scripts.pory"

# 409 "data/scripts/field_move_scripts.pory"
Text_WantToDive:
# 410 "data/scripts/field_move_scripts.pory"
	.string "The sea is deep here.\n"
# 411 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use DIVE?$"
# 412 "data/scripts/field_move_scripts.pory"

# 413 "data/scripts/field_move_scripts.pory"
Text_MonUsedDive:
# 414 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used DIVE.$"
# 415 "data/scripts/field_move_scripts.pory"

# 416 "data/scripts/field_move_scripts.pory"
Text_CantSurface:
# 417 "data/scripts/field_move_scripts.pory"
	.string "Light is filtering down from above.\n"
# 418 "data/scripts/field_move_scripts.pory"
	.string "A POKéMON may be able to surface.$"
# 419 "data/scripts/field_move_scripts.pory"

# 420 "data/scripts/field_move_scripts.pory"
Text_WantToSurface:
# 421 "data/scripts/field_move_scripts.pory"
	.string "Light is filtering down from above.\n"
# 422 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use DIVE?$"
# 423 "data/scripts/field_move_scripts.pory"

# 424 "data/scripts/field_move_scripts.pory"
EventScript_FailSweetScent::
# 425 "data/scripts/field_move_scripts.pory"
	msgbox Text_FailSweetScent, MSGBOX_SIGN
# 426 "data/scripts/field_move_scripts.pory"
	end
# 427 "data/scripts/field_move_scripts.pory"

# 428 "data/scripts/field_move_scripts.pory"
Text_FailSweetScent:
# 429 "data/scripts/field_move_scripts.pory"
	.string "Looks like there's nothing here…$"
# 430 "data/scripts/field_move_scripts.pory"

# 431 "data/scripts/field_move_scripts.pory"
EventScript_UseDefog::
# 432 "data/scripts/field_move_scripts.pory"
	lockall
# 433 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 434 "data/scripts/field_move_scripts.pory"
	buffermovename STR_VAR_2, MOVE_DEFOG
# 435 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 436 "data/scripts/field_move_scripts.pory"
	closemessage
# 437 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 438 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
# 439 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 440 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 441 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 442 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 443 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_DEFOG
# 444 "data/scripts/field_move_scripts.pory"
	waitstate
# 445 "data/scripts/field_move_scripts.pory"
	releaseall
# 446 "data/scripts/field_move_scripts.pory"
	end
# 447 "data/scripts/field_move_scripts.pory"

# 448 "data/scripts/field_move_scripts.pory"
EventScript_UseDefogGL::
# 449 "data/scripts/field_move_scripts.pory"
	lockall
# 450 "data/scripts/field_move_scripts.pory"
	showmonpic SPECIES_NOSEPASS, 10, 3
# 451 "data/scripts/field_move_scripts.pory"
	playmoncry SPECIES_NOSEPASS, CRY_MODE_NORMAL
# 452 "data/scripts/field_move_scripts.pory"
	msgbox Text_GLDefog, MSGBOX_DEFAULT
# 453 "data/scripts/field_move_scripts.pory"
	waitmoncry
# 454 "data/scripts/field_move_scripts.pory"
	delay 60
# 455 "data/scripts/field_move_scripts.pory"
	hidemonpic
# 456 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, 0
# 457 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_DEFOG
# 458 "data/scripts/field_move_scripts.pory"
	waitstate
# 459 "data/scripts/field_move_scripts.pory"
	releaseall
# 460 "data/scripts/field_move_scripts.pory"
	end
# 461 "data/scripts/field_move_scripts.pory"

# 462 "data/scripts/field_move_scripts.pory"
EventScript_UseRockClimb::
# 463 "data/scripts/field_move_scripts.pory"
	lockall
# 464 "data/scripts/field_move_scripts.pory"
	checkfieldmove FIELD_MOVE_ROCK_CLIMB
# 465 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantRockClimb
# 466 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 467 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 468 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToRockClimb, MSGBOX_YESNO
# 469 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_EndRockClimb
# 470 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedRockClimb, MSGBOX_DEFAULT
# 471 "data/scripts/field_move_scripts.pory"
	closemessage
# 472 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_CLIMB
# 473 "data/scripts/field_move_scripts.pory"
	waitstate
# 474 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndRockClimb
# 475 "data/scripts/field_move_scripts.pory"
	end
# 476 "data/scripts/field_move_scripts.pory"

# 477 "data/scripts/field_move_scripts.pory"
EventScript_CantRockClimb::
# 478 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantRockClimb, MSGBOX_DEFAULT
# 479 "data/scripts/field_move_scripts.pory"

# 480 "data/scripts/field_move_scripts.pory"
EventScript_EndRockClimb::
# 481 "data/scripts/field_move_scripts.pory"
	releaseall
# 482 "data/scripts/field_move_scripts.pory"
	end
# 483 "data/scripts/field_move_scripts.pory"

# 484 "data/scripts/field_move_scripts.pory"
Text_WantToRockClimb:
# 485 "data/scripts/field_move_scripts.pory"
    .string "The cliff is steep.\n"
# 486 "data/scripts/field_move_scripts.pory"
    .string "Would you like to use Rock Climb?$"
# 487 "data/scripts/field_move_scripts.pory"

# 488 "data/scripts/field_move_scripts.pory"
Text_MonUsedRockClimb:
# 489 "data/scripts/field_move_scripts.pory"
    .string "{STR_VAR_1} used Rock Climb!$"
# 490 "data/scripts/field_move_scripts.pory"

# 491 "data/scripts/field_move_scripts.pory"
Text_CantRockClimb:
# 492 "data/scripts/field_move_scripts.pory"
    .string "The cliff is steep.\n"
# 493 "data/scripts/field_move_scripts.pory"
    .string "A Pokémon may be able to climb it.$"

UseCutGL::
# 497 "data/scripts/field_move_scripts.pory"
	lockall
# 498 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, UseCutGL_1
# 510 "data/scripts/field_move_scripts.pory"
	msgbox Text_GLCantCutTree, MSGBOX_NPC
# 511 "data/scripts/field_move_scripts.pory"
	waitmessage
# 512 "data/scripts/field_move_scripts.pory"
	releaseall
	end

UseCutGL_1:
# 499 "data/scripts/field_move_scripts.pory"
	msgbox Text_GLCutTree, MSGBOX_DEFAULT
# 500 "data/scripts/field_move_scripts.pory"
	showmonpic SPECIES_NOSEPASS, 10, 3
# 501 "data/scripts/field_move_scripts.pory"
	playmoncry SPECIES_NOSEPASS, CRY_MODE_NORMAL
# 502 "data/scripts/field_move_scripts.pory"
	delay 60
# 503 "data/scripts/field_move_scripts.pory"
	waitmoncry
# 504 "data/scripts/field_move_scripts.pory"
	waitmessage
# 505 "data/scripts/field_move_scripts.pory"
	hidemonpic
# 506 "data/scripts/field_move_scripts.pory"
	call EventScript_CutTreeDown
# 507 "data/scripts/field_move_scripts.pory"
	releaseall
	end


UseRockSmashGL::
# 526 "data/scripts/field_move_scripts.pory"
	lockall
# 527 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, UseRockSmashGL_1
# 539 "data/scripts/field_move_scripts.pory"
	msgbox Text_GLCantRockSmash, MSGBOX_NPC
# 540 "data/scripts/field_move_scripts.pory"
	waitmessage
# 541 "data/scripts/field_move_scripts.pory"
	releaseall
	end

UseRockSmashGL_1:
# 528 "data/scripts/field_move_scripts.pory"
	msgbox Text_GLRockSmash, MSGBOX_DEFAULT
# 529 "data/scripts/field_move_scripts.pory"
	showmonpic SPECIES_MANECTRIC, 10, 3
# 530 "data/scripts/field_move_scripts.pory"
	playmoncry SPECIES_MANECTRIC, CRY_MODE_NORMAL
# 531 "data/scripts/field_move_scripts.pory"
	delay 60
# 532 "data/scripts/field_move_scripts.pory"
	waitmoncry
# 533 "data/scripts/field_move_scripts.pory"
	waitmessage
# 534 "data/scripts/field_move_scripts.pory"
	hidemonpic
# 535 "data/scripts/field_move_scripts.pory"
	call EventScript_SmashRock
# 536 "data/scripts/field_move_scripts.pory"
	releaseall
	end


UseStrengthGL::
# 556 "data/scripts/field_move_scripts.pory"
	lockall
# 557 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_SYS_USE_STRENGTH, UseStrengthGL_1
# 563 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, UseStrengthGL_2
# 575 "data/scripts/field_move_scripts.pory"
	msgbox Text_GLCantStrength, MSGBOX_NPC
# 576 "data/scripts/field_move_scripts.pory"
	waitmessage
# 577 "data/scripts/field_move_scripts.pory"
	releaseall
	end

UseStrengthGL_1:
# 558 "data/scripts/field_move_scripts.pory"
	msgbox Text_GLStrengthActive, MSGBOX_NPC
# 559 "data/scripts/field_move_scripts.pory"
	waitmessage
# 560 "data/scripts/field_move_scripts.pory"
	releaseall
	end

UseStrengthGL_2:
# 564 "data/scripts/field_move_scripts.pory"
	msgbox Text_GLStrength, MSGBOX_DEFAULT
# 565 "data/scripts/field_move_scripts.pory"
	showmonpic SPECIES_TORKOAL, 10, 3
# 566 "data/scripts/field_move_scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_NORMAL
# 567 "data/scripts/field_move_scripts.pory"
	delay 60
# 568 "data/scripts/field_move_scripts.pory"
	waitmoncry
# 569 "data/scripts/field_move_scripts.pory"
	waitmessage
# 570 "data/scripts/field_move_scripts.pory"
	hidemonpic
# 571 "data/scripts/field_move_scripts.pory"
	call GLActivateStrength
# 572 "data/scripts/field_move_scripts.pory"
	releaseall
	end


GLActivateStrength::
# 583 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SYS_USE_STRENGTH
# 584 "data/scripts/field_move_scripts.pory"
	releaseall
	end


Text_GLCutTree::
# 517 "data/scripts/field_move_scripts.pory"
	.string "Roxanne's Nosepass used cut!$"

Text_GLCantCutTree::
# 521 "data/scripts/field_move_scripts.pory"
	.string "This tree looks like it can be cut down!$"

Text_GLRockSmash::
# 546 "data/scripts/field_move_scripts.pory"
	.string "Wattson's Manectric used rock smash!$"

Text_GLCantRockSmash::
# 550 "data/scripts/field_move_scripts.pory"
	.string "This rock looks like it can be smashed!$"

Text_GLStrength::
# 588 "data/scripts/field_move_scripts.pory"
	.string "Flannery's Torkoal used strength!\n"
	.string "Torkoal's strength made it possible to\l"
	.string "move boulders around!$"

Text_GLStrengthActive::
# 592 "data/scripts/field_move_scripts.pory"
	.string "Flannery's Torkoal's strength is making\n"
	.string "it possible to move boulders around!$"

Text_GLCantStrength::
# 596 "data/scripts/field_move_scripts.pory"
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.$"

Text_GLDefog::
# 600 "data/scripts/field_move_scripts.pory"
	.string "Roxanne's Nosepass helped your team to\n"
	.string "use Defog!$"
