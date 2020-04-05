// InjectCode.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "stdafx.h"
using namespace WWS;
using namespace WWPE;
#ifndef _WIN64
#pragma message("ВНИМАНИЕ! 32-х битное приложение имеет ограниченную функциональность!")
#endif
struct ProgrammParameters {
    TSTRING PathToInjectFile;//путь к файлу в который будет производится инъекция кода
    TSTRING PathToInjectedFile;//путь к файлу код которого будет инъецирован
} PP;
int ParseCommandLineArguments(TCHAR* argv[], int argc, ProgrammParameters& pp);
int _tmain(int argc, TCHAR *argv[]){
    if (ParseCommandLineArguments(argv, argc, PP) == false)return -1;
    //основной код программы
    //проверка на существование входных файлов
    LPBYTE pBase = OpenPEFile(PP.PathToInjectFile.c_str());
    if (pBase != NULL) {
        IMAGE_NT_HEADERS* ImageNtHeaders = GetHeader(pBase);
        if (ImageNtHeaders != NULL) {
            #ifdef _WIN64
            if (ImageNtHeaders->FileHeader.SizeOfOptionalHeader == IMAGE_SIZEOF_NT_OPTIONAL32_HEADER) {

            }
            #else
            #endif
        }
        else {
            
        }
    }
    else {

    }
    return 0;
}

int ParseCommandLineArguments(TCHAR* argv[], int argc, ProgrammParameters& pp){
    int Result = true;
    auto GetArgumentValue = [](LPCTSTR arg, TCHAR *argv[], int IndexArg, int argc, TSTRING &argvalue)->bool {
        if ((IndexArg + 1) != argc) {
            argvalue = argv[IndexArg + 1];
            return true;
        }
        else tcerr << _T("Недостаточно аргументов командной строки! Кажется вы забыли указать значение ") << arg;
        return false;
    };
    for (int i = 0; i < argc; i++) {
        TSTRING Argument;
        Argument = argv[i];
        if (Argument == _T("--inject-file")) {
            if (!GetArgumentValue(Argument.c_str(), argv, i, argc, pp.PathToInjectFile)) {
                Result = false;
                break;
            }
            
        }
        else if (Argument == _T("--injected-file")) {
            if (!GetArgumentValue(Argument.c_str(), argv, i, argc, pp.PathToInjectedFile)) {
                Result = false;
                break;
            }
        }
    }
    return Result;
}
