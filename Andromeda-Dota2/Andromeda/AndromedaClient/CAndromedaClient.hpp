#pragma once

#include <Common/Common.hpp>

#include <Dota2/CBasePattern.hpp>
#include <Dota2/CHook_Loader.hpp>

class IAndromedaClient
{
public:
	virtual void OnRender() = 0;
};

class CAndromedaClient final : public IAndromedaClient
{
public:
	auto OnInit() -> void;

public:
	auto SetCameraDistance( float Distance ) -> void;

public:
	virtual void OnRender() override;

private:
	CBasePattern CameraDistancePattern = { XorStr( "CameraDistance" ) , XorStr( "F3 0F 11 05 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? BA ? ? ? ? F3 0F 11 05 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? BA ? ? ? ? F3 0F 11 05 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? BA ? ? ? ? F3 0F 11 05 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? BA" ) , XorStr( CLIENT_DLL ) , 0 , eBasePatternSearchType::SEARCH_TYPE_MOV_PTR };
};

auto GetAndromedaClient() -> CAndromedaClient*;
