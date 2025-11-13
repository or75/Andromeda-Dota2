#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <Dota2/SDK/Types/CBaseTypes.hpp>
#include <Dota2/SDK/Update/Offsets.hpp>

#include <Dota2/Protobuf/dota_usercmd.pb.h>

class CInButtonState // maybe CInButtonStatePB didn't check
{
	void* vtable;
public:
	uint64_t buttonstate1;
	uint64_t buttonstate2;
	uint64_t buttonstate3;
};

class CUserCmdArray
{
public:
	CUSTOM_OFFSET_FIELD( uint32 , m_nSequenceNumber , OFFSET_CUserCmdArray_m_nSequenceNumber );
};

/*
class CUserCmd: CDota2UserCmd
check first func for sizeof CUserCmd
*/
#pragma pack(push, 1)
class CUserCmd
{
private:
	PAD( 0x10 );
public:
	CDota2UserCmdPB cmd;
	CInButtonState button_states;
private:
	PAD( 0x18 );
};
#pragma pack(pop)
