/*+===================================================================
  File:      main.cpp

  Summary:   The client program to communicate with the rootkit.

  Author:    idchoppers
  Date:      2/22/2024
===================================================================+*/

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <stdio.h>
#include "D:\source\RootKit\Driver\RootKit.h"
#include "D:\source\RootKit\Driver\SysMonCommon.h"

void
DisplayInfo (BYTE* buffer, DWORD size);

void
DisplayTime (const LARGE_INTEGER time);

int
main (int argc, const char* argv[])
{
	auto hFile = ::CreateFile (L"\\\\.\\RootKit", GENERIC_READ, 0,
		nullptr, OPEN_EXISTING, 0, nullptr);
	if (hFile == INVALID_HANDLE_VALUE)
		return 1;

	BYTE buffer[1 << 16];

	while (true)
	{
		DWORD bytes;
		if (!::ReadFile(hFile, buffer, sizeof(buffer), &bytes, nullptr))
			return 1;

		if (bytes != 0)
			DisplayInfo (buffer, bytes);

		::Sleep(200);
	}

	return 0;
}

void
DisplayInfo (BYTE* buffer, DWORD size)
{
	auto count = size;
	while (count > 0)
	{
		auto header = (ItemHeader*)buffer;

		switch (header->Type)
		{
		case ItemType::ProcessExit:
		{
			DisplayTime (header->Time);
			auto info = (ProcessExitInfo*)buffer;
			printf ("Process %d Exited\n", info->ProcessId);
			break;
		}
		case ItemType::ProcessCreate:
		{
			DisplayTime (header->Time);
			auto info = (ProcessCreateInfo*)buffer;
			std::wstring commandLine((WCHAR*)(buffer + info->CommandLineOffset),
				info->CommandLineLength);
			printf ("Process %d Created. Command line: %ws\n", info->ProcessId,
				commandLine.c_str ());
			break;
		}
		default:
			break;
		}

		buffer += header->Size;
		count -= header->Size;
	}
}

void
DisplayTime(const LARGE_INTEGER time)
{
	SYSTEMTIME st;
	::FileTimeToSystemTime((FILETIME*)&time, &st);
	printf("%02d:%02d:%02d.%03d: ",
		st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
}