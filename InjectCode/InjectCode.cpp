// InjectCode.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "stdafx.h"
typedef std::wstring WSTRING;
typedef std::string STRING;
#ifdef _UNICODE
typedef WSTRING TSTRING;
#else
typedef STRING TSTRING;
#endif
struct ProgrammParameters {
    TSTRING PathToInjectFile;
    TSTRING PathToInjectedFile;
};
int _tmain(int argc, TCHAR *argv[]){
    
    return 0;
}
