#pragma once

#include <Common/Common.hpp>

class C_DOTAPlayerController;

class CL_DOTAPlayerController final
{
public:
	auto GetLocal() -> C_DOTAPlayerController*;
};

auto GetCL_DOTAPlayerController() -> CL_DOTAPlayerController*;
