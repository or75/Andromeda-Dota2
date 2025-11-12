#pragma once

#include "Main.h"

struct DllLoaderData_t
{
	char DllPath[MAX_PATH] = { 0 };
};

class CInjector : Singleton<CInjector>
{
public:
	auto Init() -> bool;

public:
	auto InjectManualMap( const char* szProcessName ) -> bool;

private:
	auto GetPrivileges() -> bool;
	auto GetProcessIdByName( const char* szName ) -> DWORD;

private:
	bool __forceinline FileExist( const char* szFileName )
	{
		return GetFileAttributesA( szFileName ) != INVALID_FILE_ATTRIBUTES;
	}

public:
	char szCurrentDir[MAX_PATH] = { 0 };
	char szDllFilePath[MAX_PATH] = { 0 };

private:
	HANDLE m_hProcess;
	PBYTE m_pDllFile = nullptr;
	DWORD m_DllFileSize = 0;

private:
	friend auto GetInjector() -> CInjector*;
};

auto GetInjector() -> CInjector*;
