#include "Utilities.h"

#include <stdio.h>
#include <stdlib.h>

const char *ReadCode(const char* path, uint32_t *_codeSize, const char *mode) {
	
	FILE* stream;
	fopen_s(&stream, path, mode);
	
	fseek(stream, 0, SEEK_END);
	long size = ftell(stream);
	fseek(stream, 0, SEEK_SET);

	*_codeSize = size;
	char* code = (char *)malloc(size);

	if (stream != NULL) {
		fread(code, size, 1, stream);
		for (int i = 0; i < size; i++) {

		}
		return code;
	}

	return (void*)(0);
}

