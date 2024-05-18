/*+===================================================================
  File:      Mutex.h

  Summary:   Defines and implements a regular mutex.
===================================================================+*/
#pragma once

#include <ntddk.h>

struct
Mutex
{
	void
	Init ()
	{
		KeInitializeMutex (&m_mutex, 0);
	}

	void
	Lock ()
	{
		KeWaitForSingleObject (&m_mutex, Executive, KernelMode, FALSE, nullptr);
	}

	void
	Unlock ()
	{
		KeReleaseMutex (&m_mutex, FALSE);
	}

private:
	KMUTEX m_mutex;
};