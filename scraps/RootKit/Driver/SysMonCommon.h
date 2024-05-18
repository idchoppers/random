/*+===================================================================
  File:      SysMonCommon.h

  Summary:   Structures and classes related to process monitoring.
===================================================================+*/
#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

enum class 
ItemType : short
{
	None,
	ProcessCreate,
	ProcessExit
};

struct
ItemHeader
{
	ItemType Type;
	USHORT Size;
	LARGE_INTEGER Time;
};

struct
ProcessExitInfo : ItemHeader
{
	ULONG ProcessId;
};

struct
ProcessCreateInfo : ItemHeader
{
	ULONG ProcessId;
	ULONG ParentProcessId;
	USHORT CommandLineLength;
	USHORT CommandLineOffset;
};