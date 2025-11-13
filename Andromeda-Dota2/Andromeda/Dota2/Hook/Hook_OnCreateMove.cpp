#include "Hook_OnCreateMove.hpp"

#include <Dota2/SDK/Update/CDOTAInput.hpp>
#include <GameClient/CL_DOTAPlayerController.hpp>
#include <AndromedaClient/CAndromedaClient.hpp>

auto Hook_OnCreateMove( CDOTAInput* pCDOTAInput , uint32_t split_screen_index , bool a3 ) -> void
{
	OnCreateMove_o( pCDOTAInput , split_screen_index , a3 );

	if ( auto pLocalPlayerController = GetCL_DOTAPlayerController()->GetLocal(); pLocalPlayerController )
	{
		const auto pCUserCmd = pCDOTAInput->GetUserCmd( pLocalPlayerController );

		if ( pCUserCmd )
		{
			GetAndromedaClient()->OnCreateMove( pCDOTAInput , pCUserCmd );
		}
	}
}
