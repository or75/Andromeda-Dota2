#include "CL_DOTAPlayerController.hpp"

#include <Dota2/SDK/SDK.hpp>
#include <Dota2/SDK/Interface/CGameEntitySystem.hpp>

static CL_DOTAPlayerController g_CL_DOTAPlayerController{};

auto CL_DOTAPlayerController::GetLocal() -> C_DOTAPlayerController*
{
	return CGameEntitySystem::GetLocalPlayerController();
}

auto GetCL_DOTAPlayerController() -> CL_DOTAPlayerController*
{
	return &g_CL_DOTAPlayerController;
}
