#pragma once
#include "includesh.h"

char* stringtochar(string stri)
{
	int lengthd = stri.length() + 1;
	char* content{ (char*)malloc(lengthd + 1) };
	if (content == nullptr || content == NULL) {
		throw ("Malloc Err");
		return (char*)"";
	}
	strcpy_s(content, (rsize_t)lengthd, stri.c_str());
	return content;
}