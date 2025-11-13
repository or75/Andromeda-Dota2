#include "SDK.hpp"

#include <DllLauncher.hpp>
#include <Common/MemoryEngine.hpp>

#include <Dota2/SDK/Interface/Interface.hpp>
#include <Dota2/SDK/Interface/IVEngineClient2.hpp>
#include <Dota2/SDK/Interface/CShemaSystemSDK.hpp>

#define INCLUDE_CS2_SEARCH_FUNCTION(Interface,FuncName)\
if ( !##Interface##_Search::##FuncName##Fn.Search() )\
	bIsReady = false;

namespace SDK
{
	IVEngineClient2* Interfaces::g_pEngineToClient = nullptr;
	CGameEntitySystem* Interfaces::g_pGameEntitySystem = nullptr;
	CSchemaSystem* Interfaces::g_pSchemaSystem = nullptr;

	CUserCmd** Pointers::g_ppCUserCmd = nullptr;

	IVEngineClient2* Interfaces::EngineToClient()
	{
		if ( !g_pEngineToClient )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( ENGINE2_DLL );
			g_pEngineToClient = CaptureInterface<IVEngineClient2>( pfnFactory , XorStr( IVENGINE_TO_CLIENT_INTERFACE_VERSION ) );
		}

		return g_pEngineToClient;
	}

	CGameEntitySystem* Interfaces::GameEntitySystem()
	{
		if ( !g_pGameEntitySystem )
		{
			/*
			STR -> "Searching for entities with class/target name containing substrings:"
			v33 = &CDefaultTypedEntityInstanceFilter<C_BaseEntity>::`vftable';
			v36 = sub_182E02C50(v32); ppGameEntitySystem
			*/

			auto ppGameEntitySystem = reinterpret_cast<uintptr_t>( FindPattern( CLIENT_DLL , XorStr( "48 8B ? ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 48 8B 09 48 85 C9 74 06 48 8B 41 58 EB 16 80 7B 10 00 75 09 48 8B 80 10 02 00 00 EB 07 48 8B 80 30 02 00 00" ) ) );

			if ( !ppGameEntitySystem )
				return nullptr;

GetGameEntitySystemPointer:;

			g_pGameEntitySystem = *GetPtrAddress<CGameEntitySystem**>( ppGameEntitySystem );

			if ( !g_pGameEntitySystem )
			{
				Sleep( 500 );
				goto GetGameEntitySystemPointer;
			}
		}

		return g_pGameEntitySystem;
	}

	CSchemaSystem* Interfaces::SchemaSystem()
	{
		if ( !g_pSchemaSystem )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( SCHEMASYSTEM_DLL );
			g_pSchemaSystem = CaptureInterface<CSchemaSystem>( pfnFactory , XorStr( SCHEMA_SYSTEM_INTERFACE_VERSION ) );

			bool bIsReady = true;

			INCLUDE_CS2_SEARCH_FUNCTION( CSchemaSystem , GetAllTypeScope );

			if ( !bIsReady )
				return nullptr;
		}

		return g_pSchemaSystem;
	}

	auto Pointers::GetFirstCUserCmdArray() -> CUserCmd**
	{
		if ( !g_ppCUserCmd )
		{
			auto ppCUserCmd = reinterpret_cast<uintptr_t>( FindPattern( CLIENT_DLL , XorStr( "48 8B 0D ? ? ? ? E8 ? ? ? ? 49 8B CF" ) ) );

			if ( !ppCUserCmd )
				return nullptr;

			g_ppCUserCmd = *GetPtrAddress<CUserCmd***>( ppCUserCmd );
		}

		return g_ppCUserCmd;
	}
}
