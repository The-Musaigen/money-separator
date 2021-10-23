#include "main.h"

std::unique_ptr<injector::Hook> gHookAsciiToGxt;

void OnAsciiToGxt(const char* aSource, char* aTarget)
{
	std::string source = std::string{ aSource };
	std::string sep = utility::AddSeparators(source);

	return gHookAsciiToGxt->Call(sep.c_str(), aTarget);
}

BOOL APIENTRY DllMain(_In_ HMODULE aModule, _In_ DWORD aReasonForCall, _In_ LPVOID aReserved)
{
	if (aReasonForCall == DLL_PROCESS_ATTACH)
	{
		gHookAsciiToGxt = std::make_unique<injector::Hook>(0x58F528, OnAsciiToGxt);
		gHookAsciiToGxt->Install();
	}

	return TRUE;
}
