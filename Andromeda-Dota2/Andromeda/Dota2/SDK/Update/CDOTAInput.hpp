#pragma once

#include "CUserCmd.hpp"

#include <Dota2/SDK/FunctionListSDK.hpp>

class CDOTAInput
{
public:
	auto GetSequenceNumber( C_DOTAPlayerController* pLocalPlayerController ) -> uint32_t
	{
		int32_t OutputTick = 0;
		GetCUserCmdTick( pLocalPlayerController , &OutputTick );

		int32_t Tick = OutputTick - 1;

		if ( OutputTick == -1 )
			Tick = -1;

		auto* pCUserCmdArray = GetCUserCmdArray( SDK::Pointers::GetFirstCUserCmdArray() , Tick );

		if ( pCUserCmdArray )
			return pCUserCmdArray->m_nSequenceNumber();

		return 0;
	}

	auto GetUserCmd( C_DOTAPlayerController* pLocalPlayerController ) -> CUserCmd*
	{
		const auto SequenceNumber = GetSequenceNumber( pLocalPlayerController );

		if ( SequenceNumber )
			return GetCUserCmdBySequenceNumber( pLocalPlayerController , SequenceNumber );

		return nullptr;
	}
};
