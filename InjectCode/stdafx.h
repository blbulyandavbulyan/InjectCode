#pragma once
//����� ���������� Windows
#include <windows.h>
#include <winnt.h>
#include <tchar.h>
//����� ���������� C++
#include <iostream>
#include <string>
#include <vector>
//����� ���������� ���� ����������� ���������
#include "../WWS/WWS.h"
#include "../WWPE/WWPE.h"
#ifdef _UNICODE
typedef WSTRING TSTRING;
#define tcout std::wcout
#define tcerr std::wcerr
#define OpenPEFile OpenPEFileW
#else 
typedef STRING TSTRING;
#define tcout std::cout
#defint tcerr std::cerr
#define OpenPEFile OpenPEFileA
#endif
typedef std::vector<BYTE> BYTEVECTOR;