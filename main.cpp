#include "stdafx.h"
#include "enumser.h"


void main()
{
  //Initialize COM (Required by CEnumerateSerial::UsingWMI)
  HRESULT hr = CoInitialize(NULL);
  if (FAILED(hr))
  {
    _tprintf(_T("Failed to initialize COM, Error:%x\n"), hr);
    return;  
  }

  //Initialize COM security (Required by CEnumerateSerial::UsingWMI)
  hr = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
  if (FAILED(hr))
  {
    _tprintf(_T("Failed to initialize COM security, Error:%x\n"), hr);
    CoUninitialize();
    return;  
  }
  
#if defined CENUMERATESERIAL_USE_STL
  std::vector<UINT> ports;
#if defined _UNICODE
  std::vector<std::wstring> friendlyNames;
  std::vector<std::wstring> sPorts;
#else
  std::vector<std::string> friendlyNames;
  std::vector<std::string> sPorts;
#endif  
  size_t i = 0;
  UNREFERENCED_PARAMETER(i);
#elif defined _AFX
  CUIntArray ports;
  CStringArray friendlyNames;
  CStringArray sPorts;
  INT_PTR i = 0;
  UNREFERENCED_PARAMETER(i);
#else
  CSimpleArray<UINT> ports;
  CSimpleArray<CString> friendlyNames;
  CSimpleArray<CString> sPorts;
  int i = 0;
  UNREFERENCED_PARAMETER(i);
#endif

#ifndef NO_ENUMSERIAL_USING_CREATEFILE
  _tprintf(_T("CreateFile method reports\n"));
  if (CEnumerateSerial::UsingCreateFile(ports))
  {
  #ifdef CENUMERATESERIAL_USE_STL
    for (i=0; i<ports.size(); i++)
      _tprintf(_T("COM%u\n"), ports[i]);
  #else
    for (i=0; i<ports.GetSize(); i++)
      _tprintf(_T("COM%u\n"), ports[i]);
  #endif
  }
  else
    _tprintf(_T("CEnumerateSerial::UsingCreateFile failed, Error:%u\n"), GetLastError());
#endif

#ifndef NO_ENUMSERIAL_USING_QUERYDOSDEVICE
  _tprintf(_T("QueryDosDevice method reports\n"));
  if (CEnumerateSerial::UsingQueryDosDevice(ports))
  {
  #ifdef CENUMERATESERIAL_USE_STL
    for (i=0; i<ports.size(); i++)
      _tprintf(_T("COM%u\n"), ports[i]);
  #else
    for (i=0; i<ports.GetSize(); i++)
      _tprintf(_T("COM%u\n"), ports[i]);
  #endif
  }
  else
    _tprintf(_T("CEnumerateSerial::UsingQueryDosDevice failed, Error:%u\n"), GetLastError());
#endif

#ifndef NO_ENUMSERIAL_USING_GETDEFAULTCOMMCONFIG
  _tprintf(_T("GetDefaultCommConfig method reports\n"));
  if (CEnumerateSerial::UsingGetDefaultCommConfig(ports))
  {
  #ifdef CENUMERATESERIAL_USE_STL
    for (i=0; i<ports.size(); i++)
      _tprintf(_T("COM%u\n"), ports[i]);
  #else
    for (i=0; i<ports.GetSize(); i++)
      _tprintf(_T("COM%u\n"), ports[i]);
  #endif
  }
  else
    _tprintf(_T("CEnumerateSerial::UsingGetDefaultCommConfig failed, Error:%u\n"), GetLastError());
#endif

#ifndef NO_ENUMSERIAL_USING_SETUPAPI1
  _tprintf(_T("Device Manager (SetupAPI - GUID_DEVINTERFACE_COMPORT) reports\n"));
  if (CEnumerateSerial::UsingSetupAPI1(ports, friendlyNames))
  {
  #ifdef CENUMERATESERIAL_USE_STL
    for (i=0; i<ports.size(); i++)
      _tprintf(_T("COM%u <%s>\n"), ports[i], friendlyNames[i].c_str());
  #else
    for (i=0; i<ports.GetSize(); i++)
      _tprintf(_T("COM%u <%s>\n"), ports[i], friendlyNames[i].operator LPCTSTR());
  #endif
  }
  else
    _tprintf(_T("CEnumerateSerial::UsingSetupAPI1 failed, Error:%u\n"), GetLastError());
#endif

#ifndef NO_ENUMSERIAL_USING_SETUPAPI2
  _tprintf(_T("Device Manager (SetupAPI - Ports Device information set) reports\n"));
  if (CEnumerateSerial::UsingSetupAPI2(ports, friendlyNames))
  {
  #ifdef CENUMERATESERIAL_USE_STL
    for (i=0; i<ports.size(); i++)
      _tprintf(_T("COM%u <%s>\n"), ports[i], friendlyNames[i].c_str());
  #else
    for (i=0; i<ports.GetSize(); i++)
      _tprintf(_T("COM%u <%s>\n"), ports[i], friendlyNames[i].operator LPCTSTR());
  #endif
  }
  else
    _tprintf(_T("CEnumerateSerial::UsingSetupAPI2 failed, Error:%u\n"), GetLastError());
#endif

#ifndef NO_ENUMSERIAL_USING_ENUMPORTS
  _tprintf(_T("EnumPorts method reports\n"));
  if (CEnumerateSerial::UsingEnumPorts(ports))
  {
  #ifdef CENUMERATESERIAL_USE_STL
    for (i=0; i<ports.size(); i++)
      _tprintf(_T("COM%u\n"), ports[i]);
  #else
    for (i=0; i<ports.GetSize(); i++)
      _tprintf(_T("COM%u\n"), ports[i]);
  #endif
  }
  else
    _tprintf(_T("CEnumerateSerial::UsingEnumPorts failed, Error:%u\n"), GetLastError());
#endif

#ifndef NO_ENUMSERIAL_USING_WMI
  _tprintf(_T("WMI method reports\n"));
  if (CEnumerateSerial::UsingWMI(ports, friendlyNames))
  {
  #ifdef CENUMERATESERIAL_USE_STL
    for (i=0; i<ports.size(); i++)
      _tprintf(_T("COM%u <%s>\n"), ports[i], friendlyNames[i].c_str());
  #else
    for (i=0; i<ports.GetSize(); i++)
      _tprintf(_T("COM%u <%s>\n"), ports[i], friendlyNames[i].operator LPCTSTR());
  #endif
  }
  else
    _tprintf(_T("CEnumerateSerial::UsingWMI failed, Error:%u\n"), GetLastError());
#endif

#ifndef NO_ENUMSERIAL_USING_COMDB
  _tprintf(_T("ComDB method reports\n"));
  if (CEnumerateSerial::UsingComDB(ports))
  {
  #ifdef CENUMERATESERIAL_USE_STL
    for (i=0; i<ports.size(); i++)
      _tprintf(_T("COM%u\n"), ports[i]);
  #else
    for (i=0; i<ports.GetSize(); i++)
      _tprintf(_T("COM%u\n"), ports[i]);
  #endif
  }
  else
    _tprintf(_T("CEnumerateSerial::UsingComDB failed, Error:%u\n"), GetLastError());
#endif

#ifndef NO_ENUMSERIAL_USING_REGISTRY
  _tprintf(_T("Registry method reports\n"));
  if (CEnumerateSerial::UsingRegistry(sPorts))
  {
  #ifdef CENUMERATESERIAL_USE_STL
    for (i=0; i<sPorts.size(); i++)
      _tprintf(_T("%s\n"), sPorts[i].c_str());
  #else
    for (i=0; i<sPorts.GetSize(); i++)
      _tprintf(_T("%s\n"), sPorts[i].operator LPCTSTR());
  #endif
  }
  else
    _tprintf(_T("CEnumerateSerial::UsingRegistry failed, Error:%u\n"), GetLastError());
#endif

  //Close down COM
  CoUninitialize();
}