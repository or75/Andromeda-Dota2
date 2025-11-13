#pragma once

#include <Common/Common.hpp>

class IVEngineClient2;
class CGameEntitySystem;
class CSchemaSystem;

class CUserCmd;

#define CLIENT_DLL				"client.dll"
#define ENGINE2_DLL				"engine2.dll"
#define NAVSYSTEM_DLL			"navsystem.dll"
#define GAMEOVERLAYRENDER64_DLL "gameoverlayrenderer64.dll"
#define SCHEMASYSTEM_DLL		"schemasystem.dll"

namespace SDK
{
	class Interfaces
	{
	public:
		static IVEngineClient2* EngineToClient();
		static CGameEntitySystem* GameEntitySystem();
		static CSchemaSystem* SchemaSystem();
	private:
		static IVEngineClient2* g_pEngineToClient;
		static CGameEntitySystem* g_pGameEntitySystem;
		static CSchemaSystem* g_pSchemaSystem;
	};

	class Pointers
	{
	public:
		static auto GetFirstCUserCmdArray() -> CUserCmd**;

	private:
		static CUserCmd** g_ppCUserCmd;
	};
}
