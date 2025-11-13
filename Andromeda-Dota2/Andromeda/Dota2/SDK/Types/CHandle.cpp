#include "CHandle.hpp"

#include <Dota2/SDK/SDK.hpp>
#include <Dota2/SDK/Interface/CGameEntitySystem.hpp>

auto CHandle::GetBaseEntity() const -> C_BaseEntity*
{
	if ( auto pEntity = SDK::Interfaces::GameEntitySystem()->GetBaseEntity( GetEntryIndex() ); pEntity )
		return pEntity;

	return nullptr;
}
