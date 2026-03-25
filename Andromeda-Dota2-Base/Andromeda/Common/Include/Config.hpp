#pragma once

// Project Configuration:

#define LOG_FILE					"debug.log"
#define GUI_FILE					"gui.ini"

#define CHEAT_NAME					"Andromeda [Dota2 Plus + Camera Distance Changer]"
#define CHEAT_VERSION				"1.0.3"

// Project Buid Config:

#ifdef RELEASE_BUILD

#define ENABLE_CONSOLE_DEBUG		1
#define ENABLE_CPP_EH_EXCEPTION		0

#define ENABLE_XOR_STR				0

#define LOG_SDK						0
#define LOG_SDK_PATTERN				0

#define DUMP_SCHEMA_SCOPE_LIST		0
#define DUMP_SCHEMA_ALL_OFFSET		1

#endif // RELEASE_BUILD
