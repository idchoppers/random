/*+===================================================================
  File:      AutoLock.h

  Summary:   Defines and implements AutoLocking for the driver.
===================================================================+*/
#pragma	once

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    AutoLock

  Summary:  Used for locking and unlocking Mutexes.

  Methods:  AutoLock
			  Constructor.
			~AutoLock
			  Destructor.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
template <typename T>
struct
AutoLock
{
	AutoLock (T& lock) : m_lock(lock)
	{
		lock.Lock ();
	}

	~AutoLock ()
	{
		m_lock.Unlock ();
	}

private:
	T& m_lock;
};