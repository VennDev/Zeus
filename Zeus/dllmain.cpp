#include <Windows.h>
#include <iostream>

using namespace std;

DWORD WINAPI MainThread(HMODULE hModule)
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONNOUT$", "w", stdout);

	printf("Zeus Client BETA");

	Sleep(2000);
	FreeConsole();

	//DWORD moduleBase = (DWORD)GetModuleHandle()
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, nullptr));
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}