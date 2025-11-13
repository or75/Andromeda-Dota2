#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <Dota2/SDK/Update/Offsets.hpp>
#include <Dota2/SDK/Types/CHandle.hpp>
#include <Dota2/SDK/Types/CEntityData.hpp>
#include <Dota2/SDK/FunctionListSDK.hpp>

#define MAX_ENTITIES_IN_LIST 512
#define MAX_ENTITY_LISTS 64
#define MAX_TOTAL_ENTITIES MAX_ENTITIES_IN_LIST * MAX_ENTITY_LISTS

class C_BaseEntity;

class CEntityIdentities
{
public:
	CEntityIdentity m_pIdentities[MAX_ENTITIES_IN_LIST];
};

class CGameEntitySystem
{
public:
	template<typename T = C_BaseEntity>
	auto GetBaseEntity( int nIndex ) -> T*
	{
		if ( nIndex <= -1 || nIndex >= ( MAX_TOTAL_ENTITIES - 1 ) )
			return nullptr;

		CEntityIdentities* pChunkToUse = m_pIdentityChunks[nIndex / MAX_ENTITIES_IN_LIST];
		
		if ( !pChunkToUse )
			return nullptr;

		CEntityIdentity* pIdentity = &pChunkToUse->m_pIdentities[nIndex % MAX_ENTITIES_IN_LIST];
		
		if ( !pIdentity )
			return nullptr;

		return pIdentity->pBaseEntity();
	}

	auto GetBaseEntityFromHandle( CHandle hEntity ) -> C_BaseEntity*
	{
		return GetBaseEntity( static_cast<int>( static_cast<uint16_t>( hEntity.GetEntryIndex() ) & ENT_ENTRY_MASK ) );
	}

	auto GetHighestEntityIndex() -> int
	{
		return CUSTOM_OFFSET( int , OFFSET_CGameEntitySystem_GetHighestEntityIndex );
	}

	static auto GetLocalPlayerController() -> C_DOTAPlayerController*
	{
		return CGameEntitySystem_GetLocalPlayerController();
	}

private:
	PAD( 0x10 );
public:
	CEntityIdentities* m_pIdentityChunks[MAX_ENTITY_LISTS];
};
