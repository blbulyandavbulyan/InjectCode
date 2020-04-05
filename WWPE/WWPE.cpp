// WWPE.cpp : Определяет экспортируемые функции для DLL.
//

#include "pch.h"
#include "WWPE.h"
extern WWPE::WWPEERROR WWPEError;
extern HMODULE hThisDll;

WWPE_API LPBYTE WWPE::OpenPEFileA(LPCSTR lpszFileName)
{
    HANDLE hFile = CreateFileA(lpszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (hFile == INVALID_HANDLE_VALUE) {
        SetWWPEError(WWPE_ERROR_OPENPEFILE, GetLastError());
        return NULL;
    }
    HANDLE hMapping = CreateFileMappingA(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    CloseHandle(hFile);
    LPBYTE pBase = NULL;
    if (hMapping != NULL) {
        pBase = (LPBYTE)MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, 0);
        CloseHandle(hMapping);
        if (pBase == NULL)SetWWPEError(WWPE_ERROR_MAP_PE_FILE, GetLastError());
    }
    else SetWWPEError(WWPE_ERROR_CREATE_MAPING_PE_FILE, GetLastError());
    return pBase;
}

WWPE_API LPBYTE WWPE::OpenPEFileW(LPCWSTR lpszFileName)
{
    HANDLE hFile = CreateFile(lpszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (hFile == INVALID_HANDLE_VALUE) {
        SetWWPEError(WWPE_ERROR_OPENPEFILE, GetLastError());
        return NULL;
    }
    HANDLE hMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    CloseHandle(hFile);
    LPBYTE pBase = NULL;
    if (hMapping != NULL) {
        pBase = (LPBYTE)MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, 0);
        CloseHandle(hMapping);
        if (pBase == NULL)SetWWPEError(WWPE_ERROR_MAP_PE_FILE, GetLastError());
    }
    else SetWWPEError(WWPE_ERROR_CREATE_MAPING_PE_FILE, GetLastError());
    return pBase;
}

WWPE_API void WWPE::ClosePEFile(LPBYTE pBase) {
    if (pBase != NULL)
        UnmapViewOfFile(pBase);
}

WWPE_API IMAGE_NT_HEADERS* WWPE::GetHeader(LPBYTE pBase) {
    // Проверка правильности аргументов.
    if (pBase == NULL)return NULL;
    // Получаем указатель на заголовок DOS.
    IMAGE_DOS_HEADER* pDosHeader = GetDosHeader(pBase);
    if (pDosHeader == NULL)return NULL;
    // Берем указатель на заголовок PE.
    IMAGE_NT_HEADERS* pHeader = (IMAGE_NT_HEADERS*)(pBase + pDosHeader->e_lfanew);
    // Проверяем корректность указателя.
    if (IsBadReadPtr(pHeader, sizeof(IMAGE_NT_HEADERS))) {
        SetWWPEError(WWPE_ERROR_READ_NT_HEADERS);
        return NULL;
    }
    // Наконец проверяем сигнатуру PE.
    if (pHeader->Signature != IMAGE_NT_SIGNATURE) {
        SetWWPEError(WWPE_ERROR_INVALID_PE_SIGNATURE);
        return NULL;
    }
    return pHeader;
}

WWPE_API IMAGE_DOS_HEADER* WWPE::GetDosHeader(LPBYTE pBase){
    IMAGE_DOS_HEADER* pDosHeader = (IMAGE_DOS_HEADER*)pBase;
    // Проверяем корректность указателя.
    if (IsBadReadPtr(pDosHeader, sizeof(IMAGE_DOS_HEADER))) {
        SetWWPEError(WWPE_ERROR_READ_DOS_HEADER);
        return NULL;
    }
    // Сначала проверяем сигнатуру DOS.
    if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
        SetWWPEError(WWPE_ERROR_INVALID_DOS_SIGNATURE);
        return NULL;
    }
    return pDosHeader;
}

WWPE_API WWPE::WWPEERROR WWPE::GetLastWWPEError(){
    return WWPE::WWPEError;
}

WWPE_API void WWPE::ClearErrors(){
    WWPE::WWPEError = { 0 };
}
//данная функция устанавливает ошибку WWPE
void WWPE::SetWWPEError(DWORD wwPeError, DWORD WinError) {
    WWPE::WWPEError.WWPEError = wwPeError;
    WWPE::WWPEError.WinError = WinError;
}