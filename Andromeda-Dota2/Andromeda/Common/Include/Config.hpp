#pragma once

// Project Configuration:

#define LOG_FILE					"debug.log"
#define GUI_FILE					"gui.ini"

#define CHEAT_NAME					"Andromeda [Dota2 Plus + Camera Distance Changer]"
#define CHEAT_VERSION				"1.0.0"

// Project Buid Config:

#ifdef RELEASE_BUILD

#define ENABLE_CONSOLE_DEBUG		0
#define ENABLE_MANUAL_MAP			1
#define ENABLE_CPP_EH_EXCEPTION		0

#define ENABLE_XOR_STR				1

#define LOG_SDK_PATTERN				1

#endif // RELEASE_BUILD
