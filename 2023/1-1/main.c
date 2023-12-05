#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

signed main() {
	FILE *fp = fopen("input", "r");

	if (fp == NULL)  {
		perror("Unable to open file");
		exit(1);
	}

	long sum = 0;

	for (char line[128]; fgets(line, sizeof(line), fp) != NULL; ) {
		int val = 0, i = 0;
		for (; !isdigit(line[i]); ++i);
		val += (line[i] - '0') * 10;
		i = strlen(line) - 1;
		for (; !isdigit(line[i]); --i);
		val += line[i] - '0';
		sum += val;
	}

	printf("%ld\n", sum);
}
