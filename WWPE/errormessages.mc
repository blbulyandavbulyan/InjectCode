MessageIdTypedef=DWORD

SeverityNames=(Success=0x0:STATUS_SEVERITY_SUCCESS
Informational=0x1:STATUS_SEVERITY_INFORMATIONAL
Warning=0x2:STATUS_SEVERITY_WARNING
Error=0x3:STATUS_SEVERITY_ERROR
)

FacilityNames=(System=0x0:FACILITY_SYSTEM
Runtime=0x2:FACILITY_RUNTIME
Stubs=0x3:FACILITY_STUBS
Io=0x4:FACILITY_IO_ERROR_CODE
)

LanguageNames=(English=0x409:MSG00409)
LanguageNames=(Russian=0x419:MSG00419)

; // The following are message definitions.

MessageId=0x1
Severity=Error
Facility=Runtime
SymbolicName=WWPE_ERROR_INVALID_ARG
Language=English
Error in WWPE.dll: invalid function argument!.
.

Language=Russian
Ошибка в WWPE.dll: Неверный аргумент функции!.
.

;// Сообщения для ошибок в функции OpenPEFile
MessageId=0x2
Severity=Error
Facility=Runtime
SymbolicName=WWPE_ERROR_OPENPEFILE
Language=English
Error in WWPE.dll function OpenPEFile: error open PE file!.
.

Language=Russian
Ошибка в WWPE.dll функция OpenPEFile: Ошибка открытия PE файла!.
.

MessageId=0x3
Severity=Error
Facility=Runtime
SymbolicName=WWPE_ERROR_CREATE_MAPING_PE_FILE
Language=English
Error in WWPE.dll in function OpenPEFile: error calling function CreateFileMapping!.
.

Language=Russian
Ошибка в WWPE.dll в функции OpenPEFile: Ошибка при вызове функции CreateFileMapping! .
.

MessageId=0x4
Severity=Error
Facility=Runtime
SymbolicName=WWPE_ERROR_MAP_PE_FILE
Language=English
Error in WWPE.dll in function OpenPEFile: error calling function MapViewFile!.
.

Language=Russian
Ошибка в WWPE.dll в функции OpenPEFile: Ошибка при вызове функции MapViewFile!.
.

;//общие ошибки, возникающие в обоих функциях GetHeader, GetDosHeader, 

MessageId=0x5
Severity=Error
Facility=Runtime
SymbolicName=WWPE_ERROR_READ_DOS_HEADER
Language=English
Error in WWPE.dll: error reading dos header in PE file, failed to convert base address to DOS header!.
.

Language=Russian
Ошибка в WWPE.dll: Ошибка чтения заголовка DOS в PE файле, не удалось преобразовать базовый адрес в DOS header!!.
.

MessageId=0x6
Severity=Error
Facility=Runtime
SymbolicName=WWPE_ERROR_INVALID_DOS_SIGNATURE
Language=English
Error in WWPE.dll: error invalid signature dos in header PE file!.
.

Language=Russian
Ошибка в WWPE.dll: Неверная сигнатура DOS в заголовоке PE файла!.
.

MessageId=0x7
Severity=Error
Facility=Runtime
SymbolicName=WWPE_ERROR_READ_NT_HEADERS
Language=English
Error in WWPE.dll: Error reading PE header in file! Perhaps its size does not match the required.
.

Language=Russian
Ошибка в WWPE.dll: Ошибка чтения заголовка PE в файле! Возможно его размер не совпадает с требуемым.
.

MessageId=0x8
Severity=Error
Facility=Runtime
SymbolicName=WWPE_ERROR_INVALID_PE_SIGNATURE
Language=English
Error in WWPE.dll: Invalid PE signature in the header of the alleged PE file! Maybe your file is not a PE file.
.

Language=Russian
Ошибка в WWPE.dll: Неверная сигнатура PE в заголовке предполагаемого PE файла! Возможно ваш файл не является PE файлом.
.
