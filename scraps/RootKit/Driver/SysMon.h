/*+===================================================================
  File:      SysMon.h

  Summary:   Global defenition and FullItem for process entries.
===================================================================+*/
#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "FastMutex.h"

template <typename T>
struct
FullItem
{
	LIST_ENTRY Entry;
	T Data;
};

struct
Globals
{
	LIST_ENTRY ItemsHead;
	int ItemCount;
	FastMutex Mutex;
};