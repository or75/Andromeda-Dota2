#include "CSchemaOffset.hpp"

#include <Dota2/SDK/SDK.hpp>
#include <Dota2/SDK/Interface/CShemaSystemSDK.hpp>

#include <vector>
#include <array>

static CShcemaOffset g_CShcemaOffset{};

auto CShcemaOffset::Init() -> void
{
	std::vector<CSchemaSystemTypeScope*> m_ScopeList;

	m_ScopeList.push_back( SDK::Interfaces::SchemaSystem()->GlobalTypeScope() );

	CSchemaSystemTypeScope* m_pCurrentScope = SDK::Interfaces::SchemaSystem()->GetAllTypeScope()[0];

	for ( auto idx = 0; idx < SDK::Interfaces::SchemaSystem()->GetAllTypeScopeSize(); idx++ )
	{
		m_pCurrentScope = SDK::Interfaces::SchemaSystem()->GetAllTypeScope()[idx];

		if ( m_pCurrentScope )
		{
			m_ScopeList.push_back( m_pCurrentScope );
		}
	}

#if DUMP_SCHEMA_SCOPE_LIST == 1

	DEV_LOG( "\n" );

	for ( auto& Scope : m_ScopeList )
		DEV_LOG( "Scope: %p\n" , Scope );

	DEV_LOG( "\n" );

#endif

#if DUMP_SCHEMA_ALL_OFFSET == 1
	DEV_LOG( "\n" );
#endif

	for ( auto& Scope : m_ScopeList )
	{
		auto pClassContainer = Scope->GetClassContainer();

		if ( pClassContainer )
		{
			int BlockIndex = 0;

			for ( auto& SchemaBlock : pClassContainer->GetBlockContainers() )
			{
				for ( auto Block = SchemaBlock.GetFirstBlock(); Block && BlockIndex < pClassContainer->GetNumSchema(); Block = Block->Next() , BlockIndex++ )
				{
					auto pBinding = Block->GetBinding();

					if ( !pBinding )
						continue;

#if DUMP_SCHEMA_ALL_OFFSET == 1

					auto pBaseClass = pBinding->m_baseClass();

					if ( pBaseClass )
					{
						auto pBaseClassInfo = pBaseClass->m_classInfo();

						if ( pBaseClassInfo )
						{
							DEV_LOG( "class %s : public %s // %s\n{\n" , pBinding->m_bindingName() , pBaseClassInfo->m_bindingName() , pBinding->m_dllName() );
						}
					}
					else
					{
						DEV_LOG( "class %s // %s\n{\n" , pBinding->m_bindingName() , pBinding->m_dllName() );
					}

#endif

					for ( auto idx = 0; idx < pBinding->m_DataArraySize(); idx++ )
					{
						auto pClassData = pBinding->m_DataArray()[idx];

						if ( pClassData.FieldName && pClassData.FieldType )
						{
#if DUMP_SCHEMA_ALL_OFFSET == 1

							DEV_LOG( "\t%s %s; // 0x%04X\n" , 
									 pClassData.FieldType->szTypeName , pClassData.FieldName , pClassData.FieldOffset );

#endif

							m_SchemaData[pBinding->m_bindingName()][pClassData.FieldName].m_ClassName = pBinding->m_bindingName();
							m_SchemaData[pBinding->m_bindingName()][pClassData.FieldName].m_PropertyName = pClassData.FieldName;
							m_SchemaData[pBinding->m_bindingName()][pClassData.FieldName].m_Offset = pClassData.FieldOffset;
						}
					}

#if DUMP_SCHEMA_ALL_OFFSET == 1
					DEV_LOG( "};\n" );
#endif
				}
			}
		}

#if DUMP_SCHEMA_ALL_OFFSET == 1
		auto pEnumContainer = Scope->GetEnumContainer();

		if ( pEnumContainer )
		{
			int blockIndex = 0;

			for ( auto& schema_block : pEnumContainer->GetBlockContainers() )
			{
				for ( auto block = schema_block.GetFirstBlock(); block && blockIndex < pEnumContainer->GetNumSchema(); block = block->Next() , ++blockIndex )
				{
					auto binding = block->GetBinding();

					if ( !binding )
						continue;

					DEV_LOG( "enum %s : %s\n{\n" , binding->m_bindingName() , binding->GenerateTypeStorage() );

					for ( auto idx = 0; idx < binding->m_DataArraySize(); idx++ )
					{
						auto enum_data = binding->m_DataArray()[idx];

						if ( enum_data.FieldName )
						{
							switch ( binding->m_TypeSize() )
							{
								case 1:
									DEV_LOG( "\t%s = 0x%02X ,\n" , enum_data.FieldName , enum_data.FieldData );
									break;
								case 2:
									DEV_LOG( "\t%s = 0x%04X ,\n" , enum_data.FieldName , enum_data.FieldData );
									break;
								case 4:
									DEV_LOG( "\t%s = 0x%08X ,\n" , enum_data.FieldName , enum_data.FieldData );
									break;
								case 8:
									DEV_LOG( "\t%s = 0x%p ,\n" , enum_data.FieldName , enum_data.FieldData );
									break;
								default:
									break;
							}
						}
					}

					DEV_LOG( "};\n\n" );
				}
			}
		}
#endif

	}
}

auto CShcemaOffset::GetOffset( std::string ClassName , std::string PropertyName ) -> uint32_t
{
	return m_SchemaData[ClassName][PropertyName].m_Offset;
}

auto GetSchemaOffset() -> CShcemaOffset*
{
	return &g_CShcemaOffset;
}
