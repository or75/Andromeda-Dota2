#pragma once

#include <Common/Common.hpp>

class CAndromedaMenu final
{
public:
	auto OnRenderMenu() -> void;

private:
	auto RenderCheckBox( const char* szTitle , const char* szStrID , bool& SettingsItem ) -> bool;
	auto RenderComboBox( const char* szTitle , const char* szStrID , int& v , const char* Items[] , int ItemsCount ) -> bool;
	auto RenderSliderInt( const char* szTitle , const char* szStrID , int& Value , int Min , int Max ) -> bool;
	auto RenderSliderFloat( const char* szTitle , const char* szStrID , float& v , float min , float max , float left_padding = 90.f ) -> bool;
};

auto GetAndromedaMenu() -> CAndromedaMenu*;
