#ifndef qCPUinterface_h
#define qCPUinterface_h



#include <string.h>

#include "qCPUcore.h"
#include "qGlobals.h"

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method, const char* m_qName, int m_NqBit, int m_nExp);

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method);

///////////////////////////////////////////////////////////////////////////
void AddCPU(const char* m_qName, int m_NqBit, int m_nExp);

#endif // qCPUinterface_h
