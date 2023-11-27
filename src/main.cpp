#include <efi.h>
 
EFI_STATUS EFIAPI EfiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable)
{
    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello Worrld\n");
    return EFI_SUCCESS;
}