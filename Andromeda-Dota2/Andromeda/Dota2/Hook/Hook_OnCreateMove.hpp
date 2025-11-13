#pragma once

#include <Common/Common.hpp>

class CDOTAInput;

auto Hook_OnCreateMove( CDOTAInput* pCDOTAInput , uint32_t split_screen_index , bool a3 ) -> void;

using CreateMove_t = decltype( &Hook_OnCreateMove );
inline CreateMove_t OnCreateMove_o = nullptr;
