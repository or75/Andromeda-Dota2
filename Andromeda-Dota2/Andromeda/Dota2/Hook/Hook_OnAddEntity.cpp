#include "Hook_OnAddEntity.hpp"

#include <Dota2/SDK/Types/CEntityData.hpp>

auto Hook_OnAddEntity( CGameEntitySystem* pCGameEntitySystem , CEntityInstance* pInst , CHandle handle ) -> void
{
	DEV_LOG( "Hook_OnAddEntity: %p , %s\n" , pInst->pEntityIdentity() , pInst->GetSchemaClassBinding()->m_bindingName() );

	return OnAddEntity_o( pCGameEntitySystem , pInst , handle );
}
