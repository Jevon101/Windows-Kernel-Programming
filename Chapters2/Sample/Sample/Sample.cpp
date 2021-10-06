#include <ntddk.h>

void SampleUnload(_In_ PDRIVER_OBJECT DriverObject) {

	KdPrint(("SampleUnload........."));
	UNREFERENCED_PARAMETER(DriverObject);
}

EXTERN_C
NTSTATUS 
DriverEntry(
	_In_ PDRIVER_OBJECT  DriverObject,
	_In_ PUNICODE_STRING RegistryPath
) 
{
	UNREFERENCED_PARAMETER(RegistryPath);

	DriverObject->DriverUnload = SampleUnload;

	RTL_OSVERSIONINFOW osvi;
	osvi.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOW);
	RtlGetVersion(&osvi);

	DbgPrint("RtlGetVersion");
	DbgPrint("The osvi.dwMajorVersion is: %u", osvi.dwMajorVersion);
	DbgPrint("The osvi.dwBuildNumber is: %u", osvi.dwBuildNumber);
	DbgPrint("The osvi.dwMinorVersion is: %u", osvi.dwMinorVersion);


	return STATUS_SUCCESS;
}
