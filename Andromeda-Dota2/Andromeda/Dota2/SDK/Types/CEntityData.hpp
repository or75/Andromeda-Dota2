#pragma once

#include <Common/Common.hpp>

#include "CBaseTypes.hpp"
#include "CHandle.hpp"
#include "Color_t.hpp"
#include "CUtlMemory.hpp"
#include "CUtlString.hpp"
#include "CUtlSymbol.hpp"
#include "CUtlSymbolLarge.hpp"
#include "CUtlVector.hpp"
#include "CStrongHandle.hpp"
#include "CUtlStringToken.hpp"

#include <Dota2/SDK/Update/Offsets.hpp>
#include <Dota2/SDK/CSchemaOffset.hpp>
#include <Dota2/SDK/Interface/CShemaSystemSDK.hpp>

class IHandleEntity
{
public:
	virtual ~IHandleEntity() {}
};

class CEntityIdentity
{
public:
	SCHEMA_OFFSET_CUSTOM( pBaseEntity , 0x0 , C_BaseEntity* );
	SCHEMA_OFFSET_CUSTOM( Handle , 0x10 , CHandle );

public:
	SCHEMA_OFFSET( "CEntityIdentity" , "m_name" , Name , CUtlSymbolLarge );
	SCHEMA_OFFSET( "CEntityIdentity" , "m_designerName" , DesingerName , CUtlSymbolLarge );

private:
	PAD( 0x70 );
};

class CEntityInstance : public IHandleEntity
{
public:
	auto GetSchemaClassBinding() -> CSchemaClassBinding*
	{
		CSchemaClassBinding* pBinding = nullptr;

		VirtualFn( void )( CEntityInstance* , CSchemaClassBinding** );
		vget< Fn >( this , SDK::VMT_Index::CSchemaSystem::SchemaClassInfo )( this , &pBinding );

		return pBinding;
	}

public:
	SCHEMA_OFFSET( "CEntityInstance" , "m_pEntity" , pEntityIdentity , CEntityIdentity* );
};

class C_BaseEntity : public CEntityInstance
{
public:
	SCHEMA_OFFSET( "C_BaseEntity" , "m_iTeamNum" , m_iTeamNum , uint8 );
};

class C_BaseModelEntity : public C_BaseEntity
{
public:

};

class C_DOTA_BaseNPC : public C_BaseModelEntity
{
public:
};

class C_DOTA_BaseNPC_Hero : public C_DOTA_BaseNPC
{
public:
};

class CBasePlayerController : public C_BaseEntity
{
public:

};

class C_DOTAPlayerController : public CBasePlayerController
{
public:
	SCHEMA_OFFSET( "C_DOTAPlayerController" , "m_hAssignedHero" , m_hAssignedHero , CHandle ); // C_DOTA_BaseNPC_Hero
};
