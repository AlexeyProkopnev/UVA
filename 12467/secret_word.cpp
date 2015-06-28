#include <bits/stdc++.h>

using namespace std;

const int MAX_L = 1000007;
const char DELIMITER = '$';

int p[MAX_L];
char s[MAX_L<<1];

int getInt() {
	fgets(s, MAX_L, stdin);
	int index = 0;
	while (!isdigit(s[index])) ++index;
	int ret = 0;
	while (isdigit(s[index])) ret *= 10, ret += s[index++] - 48;
	return ret;
}

int main() {
	freopen("sample.in", "r", stdin);
	//ios::sync_with_stdio(false);
	cin.tie(NULL);
	p[0] = 0;
	int nTests = getInt();
	for (int tId = 0; tId < nTests; ++tId) {
		fgets(s, MAX_L, stdin);
		int length = strlen(s) - 1;
		for (int i = 1; i < length; ++i) {
			int j = p[i-1];
			while (j > 0 && s[i] != s[j]) 
				j = p[j-1];
			if (s[i] == s[j]) 
				++j;
			p[i] = j;
		}
		s[length] = DELIMITER;
		for (int i = length-1, j = length+1; i >= 0; --i, ++j) s[j] = s[i];
		int max_occurence_length = -1;
		int occurence_length = 0;
		for (int i = length+1; i < (length<<1|1); ++i) {
			while (occurence_length > 0 && s[i] != s[occurence_length]) 
				occurence_length = p[occurence_length-1];
			if (s[i] == s[occurence_length]) 
				++occurence_length;
			max_occurence_length = max(max_occurence_length, occurence_length);
		}
		s[max_occurence_length] = 0;
		reverse(s, s+max_occurence_length);
		printf("%s\n", &s);
	}
	return 0;
}
