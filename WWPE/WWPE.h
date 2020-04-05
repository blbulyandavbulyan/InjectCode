// Приведенный ниже блок ifdef — это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа WWPE_EXPORTS
// Символ, определенный в командной строке. Этот символ не должен быть определен в каком-либо проекте,
// использующем данную DLL. Благодаря этому любой другой проект, исходные файлы которого включают данный файл, видит
// функции WWPE_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
//макрос WWPE_INCLUDE_ERROS определён к контексте проекта WWPE, если хотите подключить заголовочный файл с ошибками определите макрос WWPE_INCLUDE_ERROS до включения файла WWPE.h
#ifdef WWPE_EXPORTS
#define WWPE_INCLUDE_ERROS
#endif

#ifdef WWPE_INCLUDE_ERROS
#include "errormessages.h"
#endif
#ifdef WWPE_EXPORTS
#define WWPE_API __declspec(dllexport)
#else
#define WWPE_API __declspec(dllimport)
#endif
namespace WWPE {
	struct WWPEERROR {
		DWORD WinError = NULL;
		DWORD WWPEError = NULL;
	};
	WWPE_API LPBYTE OpenPEFileA(LPCSTR lpszFileName);
	WWPE_API LPBYTE OpenPEFileW(LPCWSTR lpszFileName);
	WWPE_API void ClosePEFile(LPBYTE pBase);
	WWPE_API IMAGE_NT_HEADERS* GetHeader(LPBYTE pBase);
	WWPE_API IMAGE_DOS_HEADER* GetDosHeader(LPBYTE pBase);
	WWPE_API WWPEERROR GetLastWWPEError();
	WWPE_API void ClearErrors();
	#ifdef WWPE_EXPORTS
	WWPEERROR WWPEError;
	void SetWWPEError(DWORD wwPeError, DWORD WinError = NULL);
	#endif
};