#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int get_number_from_str(char *str) {
	int len = strlen(str);
	for (int i = 0; i < 9; ++i) {
		int w_len = strlen(words[i]);
		if (len < w_len) {
				continue;
		}
		int j = 0;
		for (j = 0; j < w_len && str[j] == words[i][j]; ++j);
		if (j == w_len) {
			return numbers[i];
		}
	}
	return -1;
}

signed main() {
	FILE *fp = fopen("input", "r");

	if (fp == NULL)  {
		perror("Unable to open file");
		exit(1);
	}


	int sum = 0;

	for (char line[128]; fgets(line, sizeof(line), fp) != NULL; ) {
		int beg = -1, lst = -1;
		int len = strlen(line);
		for (int i = 0; i < len; ++i) {
			if (isdigit(line[i])) {
				if (beg == -1) {
					beg = line[i] - '0';
				}
				lst = line[i] - '0';
			} else {
				char buffer[6];
				int j = i;
				for (; j < len && j < i + 5 && isalpha(line[j]); buffer[j - i] = line[j], ++j);
				buffer[j - i] = '\0';
				int digit = get_number_from_str(buffer);
				if (digit == -1) {
					continue;
				}
				if (beg == -1) {
					beg = digit;
				}
				lst = digit;
			}
		}
		sum += beg * 10 + lst;
	}

	printf("%d\n", sum);
}
