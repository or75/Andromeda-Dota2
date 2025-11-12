#include "CAndromedaClient.hpp"
#include "CAndromedaGUI.hpp"

#include <AndromedaClient/Fonts/CFontManager.hpp>
#include <AndromedaClient/GUI/CAndromedaMenu.hpp>
#include <AndromedaClient/Settings/Settings.hpp>

static CAndromedaClient g_CAndromedaClient{};

auto CAndromedaClient::OnInit() -> void
{
	if ( CameraDistancePattern.Search() )
		DEV_LOG( "[CameraDistance] Found !\n" );
}

auto CAndromedaClient::SetCameraDistance( float Distance ) -> void
{
	static float* g_pCameraDistance = reinterpret_cast<float*>( CameraDistancePattern.GetFunction() );

	if( g_pCameraDistance )
		*g_pCameraDistance = Distance;
}

auto CAndromedaClient::OnRender() -> void
{
	if ( GetAndromedaGUI()->IsVisible() )
		GetAndromedaMenu()->OnRenderMenu();

	GetFontManager()->FirstInitFonts();
	GetFontManager()->m_VerdanaFont.DrawString( 1 , 1 , ImColor( 255 , 255 , 0 ) , FW1_LEFT , XorStr( CHEAT_NAME ) );
}

auto GetAndromedaClient() -> CAndromedaClient*
{
	return &g_CAndromedaClient;
}
