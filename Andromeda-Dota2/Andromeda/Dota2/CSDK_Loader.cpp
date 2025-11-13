#include "CSDK_Loader.hpp"

#include <Dota2/SDK/SDK.hpp>
#include <Dota2/SDK/Interface/IVEngineClient2.hpp>
#include <Dota2/SDK/Interface/CGameEntitySystem.hpp>
#include <Dota2/SDK/Interface/CShemaSystemSDK.hpp>

#include <Dota2/SDK/CSchemaOffset.hpp>

#include <Common/Helpers/ModuleLoaderHelper.hpp>

#define RETURN_FALSE_IF_INTERFACE_ERROR(Interface)\
if ( !Interface )\
{\
	DEV_LOG( "[error] Interface::%s\n" , #Interface );\
	return false;\
}

#define RETURN_FALSE_IF_POINTER_ERROR(Pointer)\
if ( !Pointer )\
{\
	DEV_LOG( "[error] Pointer::%s\n" , #Pointer );\
	return false;\
}

static CSDK_Loader g_SDK_Loader{};

auto CSDK_Loader::LoadSDK() -> bool
{
	// Wait for module load:
	if ( !IsModuleLoad( NAVSYSTEM_DLL ) )
		return false;

	// Log SDK:
#if LOG_SDK == 1
	DEV_LOG( "[+] CSDK_Loader::LoadSDK:\n\n" );
#endif

	// Interfaces:
	auto pEngineToClient = SDK::Interfaces::EngineToClient();
	auto pGameEntitySystem = SDK::Interfaces::GameEntitySystem();
	auto pSchemaSystem = SDK::Interfaces::SchemaSystem();

	// Pointers
	auto ppCUserCmdArray = SDK::Pointers::GetFirstCUserCmdArray();

	// Return if error #1
	RETURN_FALSE_IF_INTERFACE_ERROR( pEngineToClient );
	RETURN_FALSE_IF_INTERFACE_ERROR( pGameEntitySystem );
	RETURN_FALSE_IF_INTERFACE_ERROR( pSchemaSystem );

	// Return if error #2
	RETURN_FALSE_IF_POINTER_ERROR( ppCUserCmdArray );

	// Log:
#if LOG_SDK == 1
	DEV_LOG( "\n" );
#endif

	// Log:
#if LOG_SDK == 1
	DEV_LOG( "[+] pEngineToClient: %p\n" , pEngineToClient );
	DEV_LOG( "[+] pGameEntitySystem: %p\n" , pGameEntitySystem );
	DEV_LOG( "[+] pSchemaSystem: %p\n" , pSchemaSystem );

	DEV_LOG( "[+] ppCUserCmdArray: %p\n" , ppCUserCmdArray );
#endif

	GetSchemaOffset()->Init();

	return true;
}

auto GetSDK_Loader() -> CSDK_Loader*
{
	return &g_SDK_Loader;
}
