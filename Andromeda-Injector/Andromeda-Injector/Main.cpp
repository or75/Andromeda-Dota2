#include "Main.h"

#include "CInjector.h"

auto __forceinline PrintMessage( const char* fmt , ... ) -> void
{
	char buff[4096] = { 0 };

	va_list args;
	va_start( args , fmt );
	vsnprintf( buff , sizeof( buff ) - 1 , fmt , args );
	va_end( args );

	printf( "%s" , buff );
};

int main( int argm , char** argv )
{
	if ( !GetInjector()->Init() )
	{
		DEV_LOG( "[error] GetPrivileges Or Dll Not Found !\n" );
		Sleep( 5000 );
		return 0;
	}

	if ( !GetInjector()->InjectManualMap( "dota2.exe" ) )
	{
		DEV_LOG( "[error] Inject #1\n" );
		Sleep( 5000 );
		return 0;
	}

	DEV_LOG( "[success] Injected !\n" );

	Sleep( 5000 );
	return 0;
}
