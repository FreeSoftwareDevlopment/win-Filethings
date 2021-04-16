#pragma once
#include "includesh.h"

void PrintFileAttributes(
    ULONG FileAttributes
)
{
    if (FileAttributes & FILE_ATTRIBUTE_ARCHIVE) {
        cout << ("Archive ");
    }
    if (FileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
        cout << ("Directory ");
    }
    if (FileAttributes & FILE_ATTRIBUTE_READONLY) {
        cout << ("Read-Only ");
    }
    if(FileAttributes & FILE_ATTRIBUTE_HIDDEN) {
        cout << ("Hidden ");
    }
}
