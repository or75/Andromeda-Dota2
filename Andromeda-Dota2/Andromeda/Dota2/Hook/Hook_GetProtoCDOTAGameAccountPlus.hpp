#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

class CDOTAGCClientSystem;

class CDOTAGameAccountPlus
{
private:
	PAD( 0x2C );
public:
	enum EDotaPlusStatus : int32_t
	{
		STATUS_INVALID = -1,
		STATUS_SUBSCRIBED = 1,
		STATUS_UNSUBSCRIBED = 2,
	};

	int32_t m_nStatus;
};

auto Hook_GetProtoCDOTAGameAccountPlus( CDOTAGCClientSystem* pCDOTAGCClientSystem ) -> CDOTAGameAccountPlus*;

using GetProtoCDOTAGameAccountPlus_t = decltype( &Hook_GetProtoCDOTAGameAccountPlus );
inline GetProtoCDOTAGameAccountPlus_t GetProtoCDOTAGameAccountPlus_o = nullptr;
