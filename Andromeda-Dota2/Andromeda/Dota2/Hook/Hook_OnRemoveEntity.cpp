#include "Hook_OnRemoveEntity.hpp"

#include <Dota2/SDK/Types/CEntityData.hpp>

auto Hook_OnRemoveEntity( CGameEntitySystem* pCGameEntitySystem , CEntityInstance* pInst , CHandle handle ) -> void
{
	DEV_LOG( "Hook_OnRemoveEntity: %p , %s\n" , pInst->pEntityIdentity() , pInst->GetSchemaClassBinding()->m_bindingName() );

	return OnRemoveEntity_o( pCGameEntitySystem , pInst , handle );
}
