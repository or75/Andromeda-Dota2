#include "Hook_GetProtoCDOTAGameAccountPlus.hpp"

auto Hook_GetProtoCDOTAGameAccountPlus( CDOTAGCClientSystem* pCDOTAGCClientSystem ) -> CDOTAGameAccountPlus*
{
	auto pResult = GetProtoCDOTAGameAccountPlus_o( pCDOTAGCClientSystem );

	if ( pResult )
		pResult->m_nStatus = CDOTAGameAccountPlus::EDotaPlusStatus::STATUS_SUBSCRIBED;

	return pResult;
}
