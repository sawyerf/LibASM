#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void testStrlen(char *str) {
	size_t realSize = strlen(str);
	size_t ftSize   = ft_strlen(str);
	if (realSize != ftSize) {
		printf("[Fail] strlen(`%s'): %d - %d\n", str, realSize, ftSize);
	} else {
		printf("[OK] strlen(`%s'): %d - %d\n", str, realSize, ftSize);
	}
}

void testStrcpy(char *str) {
	size_t size = strlen(str) + 5;
	char *cpy   = malloc(size * sizeof(malloc));
	memset(cpy, 42, size);
	cpy   = ft_strcpy(cpy, str);

	if (strcmp(cpy, str)) {
		printf("[Fail] strcpy(`%s') - %p: `%s' - %p\n", str, str, cpy, cpy);
	} else {
		printf("[OK] strcpy(`%s') - %p: `%s' - %p\n", str, str, cpy, cpy);
	}
	free(cpy);
}

void testStrdup(char *str) {
	char *cpy   = ft_strdup(str);

	if (!cpy) {
		write(1, "[Fail] strdup() - NULL\n", 23);
		return ;
	}
	if (strcmp(cpy, str)) {
		printf("[Fail] strdup(`%s') - %p: `%s' - %p\n", str, str, cpy, cpy);
	} else {
		printf("[OK] strdup(`%s') - %p: `%s' - %p\n", str, str, cpy, cpy);
	}
	free(cpy);
}

void testStrcmp(char *str) {
	int real = strcmp(str, "lol");
	int fake = ft_strcmp(str, "lol");

	if (real == fake) {
		printf("[OK] strcmp(`%s'): %d - %d\n", str, real, fake);
	} else {
		printf("[Fail] strcmp(`%s'): %d - %d\n", str, real, fake);
	}
}

void testWrite(char *str) {
	size_t size = strlen(str);
	int ret = ft_write(1, str, size);
	write(1, "\n", 1);
	if (size == ret) {
		printf("[OK] write(`%s'): %d - %d\n", str, ret, size);
	} else {
		printf("[Fail] write(`%s'): %d - %d\n", str, ret, size);
	}
}

void testRead() {
	int fd = open("/etc/passwd", O_RDONLY);
	int size = 10;
	char *str = malloc((size + 1) * sizeof(char));
	int ret = ft_read(fd, str, 10);
	if (size == ret) {
		printf("[OK] read(): `%s' - %d - %d\n", str, ret, size);
	} else {
		printf("[Fail] read(): `%s' - %d - %d\n", str, ret, size);
	}
	close(fd);
}

int main() {
	char tab[10][100] = {
		"lol",
		"lol\x00lol",
		"",
		"0123456789ABCDEF",
		"0123456789ABCDE"
	};
	
	for (int index = 0; index < 5; index++) {
		// testWrite(tab[index]);
		// testStrlen(tab[index]);
		// testStrcpy(tab[index]);
		// testStrcmp(tab[index]);
		testStrdup(tab[index]);
	}
	// testRead();
}
