/*+===================================================================
  File:      FastMutex.cpp

  Summary:   Implements FastMutex methods.
===================================================================+*/

#include <ntddk.h>
#include "FastMutex.h"

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   FastMutex::Init

  Summary:  Initializes a fast mutex.

  Modifies: m_mutex
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void
FastMutex::Init ()
{
	ExInitializeFastMutex (&m_mutex);
}

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   FastMutex::Lock

  Summary:  Locks a fast mutex.

  Modifies: m_mutex
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void
FastMutex::Lock ()
{
	ExAcquireFastMutex (&m_mutex);
}

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   FastMutex::Unlock

  Summary:  Unlocks a fast mutex.

  Modifies: m_mutex
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void
FastMutex::Unlock ()
{
	ExReleaseFastMutex (&m_mutex);
}