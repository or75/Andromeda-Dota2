#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <Dota2/SDK/SDK.hpp>
#include <Dota2/SDK/Update/VMT_Index.hpp>

#define IVENGINE_TO_CLIENT_INTERFACE_VERSION "Source2EngineToClient001"

class IVEngineClient2
{
public:
	auto GetLocalPlayer( int& nOutPlayerSlot , int nSplitScreenSlot = 0 ) -> void
	{
		VirtualFn( void )( IVEngineClient2* , int& , int );
		return vget< Fn >( this , SDK::VMT_Index::IVEngineClient2::GetLocalPlayer )( this , nOutPlayerSlot , nSplitScreenSlot );
	}

	auto GetScreenSize( int& width , int& height ) -> void
	{
		VirtualFn( void )( IVEngineClient2* , int& , int& );
		return vget< Fn >( this , SDK::VMT_Index::IVEngineClient2::GetScreenSize )( this , width , height );
	}
};
