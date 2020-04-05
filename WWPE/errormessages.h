 // The following are message definitions.
//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define FACILITY_SYSTEM                  0x0
#define FACILITY_RUNTIME                 0x2
#define FACILITY_STUBS                   0x3
#define FACILITY_IO_ERROR_CODE           0x4


//
// Define the severity codes
//
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: WWPE_ERROR_INVALID_ARG
//
// MessageText:
//
// Error in WWPE.dll: invalid function argument!.
//
#define WWPE_ERROR_INVALID_ARG           ((DWORD)0xC0020001L)

// Сообщения для ошибок в функции OpenPEFile
//
// MessageId: WWPE_ERROR_OPENPEFILE
//
// MessageText:
//
// Error in WWPE.dll function OpenPEFile: error open PE file!.
//
#define WWPE_ERROR_OPENPEFILE            ((DWORD)0xC0020002L)

//
// MessageId: WWPE_ERROR_CREATE_MAPING_PE_FILE
//
// MessageText:
//
// Error in WWPE.dll in function OpenPEFile: error calling function CreateFileMapping!.
//
#define WWPE_ERROR_CREATE_MAPING_PE_FILE ((DWORD)0xC0020003L)

//
// MessageId: WWPE_ERROR_MAP_PE_FILE
//
// MessageText:
//
// Error in WWPE.dll in function OpenPEFile: error calling function MapViewFile!.
//
#define WWPE_ERROR_MAP_PE_FILE           ((DWORD)0xC0020004L)

//общие ошибки, возникающие в обоих функциях GetHeader, GetDosHeader, 
//
// MessageId: WWPE_ERROR_READ_DOS_HEADER
//
// MessageText:
//
// Error in WWPE.dll: error reading dos header in PE file, failed to convert base address to DOS header!.
//
#define WWPE_ERROR_READ_DOS_HEADER       ((DWORD)0xC0020005L)

//
// MessageId: WWPE_ERROR_INVALID_DOS_SIGNATURE
//
// MessageText:
//
// Error in WWPE.dll: error invalid signature dos in header PE file!.
//
#define WWPE_ERROR_INVALID_DOS_SIGNATURE ((DWORD)0xC0020006L)

//
// MessageId: WWPE_ERROR_READ_NT_HEADERS
//
// MessageText:
//
// Error in WWPE.dll: Error reading PE header in file! Perhaps its size does not match the required.
//
#define WWPE_ERROR_READ_NT_HEADERS       ((DWORD)0xC0020007L)

//
// MessageId: WWPE_ERROR_INVALID_PE_SIGNATURE
//
// MessageText:
//
// Error in WWPE.dll: Invalid PE signature in the header of the alleged PE file! Maybe your file is not a PE file.
//
#define WWPE_ERROR_INVALID_PE_SIGNATURE  ((DWORD)0xC0020008L)

