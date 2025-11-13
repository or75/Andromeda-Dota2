#pragma once

// Check -> CGameEntitySystem_OnAddEntity 15 vmt index -> "FF 81 ? ? ? ? 48 85 D2"
static constexpr auto OFFSET_CGameEntitySystem_GetHighestEntityIndex = 0x20F0;

// Check -> Hook_OnCreateMove -> "44 8B B0 ? ? ? ? 41 8B D6"
static constexpr auto OFFSET_CUserCmdArray_m_nSequenceNumber = 0x5460;
