#include "includesh.h"
#include "converter.h"
#include "file attr.h"

int main(int argc, char* argv[])
{
	cout << "Sharkbyteprojects Filethings\nhttps://github.com/sharkbyteprojects\n\n";
	if (argc == 1) {
		cout << "Usage: \"" << argv[0] << "\" <filepath>\nMax Length for Path: " << MAX_PATH << endl;
		return 0;
	}
	for (int x = 1; x < argc; x++) {
		char* filename{ argv[x] };
		char p[MAX_PATH];
		GetFullPathNameA(filename, sizeof(p), p, NULL);
		cout << "Given Path: " << filename << "\nFull Path: " << p << "\nFile Attributes: ";
		DWORD fileAttributes{ GetFileAttributesA(filename) };
		PrintFileAttributes(fileAttributes);
		if (fileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			cout << "\n";
			uint64_t bytesFreeToCaller{ 0 }, totalNumberOfBytes{ 0 }, totalNumberOfFreeBytes{ 0 };
			if (GetDiskFreeSpaceExA(filename, (ULARGE_INTEGER*)&bytesFreeToCaller, (ULARGE_INTEGER*)&totalNumberOfBytes, (ULARGE_INTEGER*)&totalNumberOfFreeBytes) == TRUE) {
				if (bytesFreeToCaller != totalNumberOfFreeBytes) {
					cout << "You can use " << bytesFreeToCaller << " bytes of " << totalNumberOfFreeBytes << " free bytes\n";
				}
				cout << "Disk: " << totalNumberOfFreeBytes << "/" << totalNumberOfBytes;
			}
			else {
				cerr << GetLastError();
			}
		}
		if (x + 1 < argc) {
			cout << "\n\n";
		}
	}
	cout << endl;
}