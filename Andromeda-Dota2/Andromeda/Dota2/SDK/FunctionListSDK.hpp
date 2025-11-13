#pragma once

#include <Common/Common.hpp>

#include <Dota2/SDK/Types/CBaseTypes.hpp>
#include <Dota2/SDK/CFunctionList.hpp>

class C_DOTAPlayerController;
class CUserCmdArray;
class CUserCmd;

DECLARATE_CS2_FUNCTION_SDK_FASTCALL( C_DOTAPlayerController* , CGameEntitySystem_GetLocalPlayerController , ( int Unk = 0 ) , ( int ) , ( Unk ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , GetCUserCmdTick , ( C_DOTAPlayerController* pPlayerController , int32_t* pOutputTick ) , ( C_DOTAPlayerController* , int32_t* ) , ( pPlayerController , pOutputTick ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CUserCmdArray* , GetCUserCmdArray , ( CUserCmd** ppCUserCmd , int Tick ) , ( CUserCmd** , int ) , ( ppCUserCmd , Tick ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CUserCmd* , GetCUserCmdBySequenceNumber , ( C_DOTAPlayerController* pPlayerController , uint32_t SequenceNumber ) , ( C_DOTAPlayerController* , uint32_t ) , ( pPlayerController , SequenceNumber ) );
