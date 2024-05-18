/*+===================================================================
  File:      FastMutex.h

  Summary:   Defines a FastMutex for usage in the driver.
===================================================================+*/
#pragma once

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    FastMutex

  Summary:  Defenition of a fast mutex.

  Methods:  Init
              Initializes a FastMutex.
            Lock
              Locks a FastMutex.
			Unlock
              Unlocks a FastMutex.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class
FastMutex
{
public:
	void Init ();

	void Lock ();

	void Unlock ();

private:
	FAST_MUTEX m_mutex;
};