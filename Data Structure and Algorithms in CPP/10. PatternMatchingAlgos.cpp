#include <iostream>
#include <string.h>
using namespace std;

// Basic naive algorithm O(mn)
int SearchPatternByNaive(char* text, char* pattern)
{
	int txtlen = strlen(text);
	int patlen = strlen(pattern);

	if (txtlen == 0 || patlen == 0 || txtlen < patlen)
		return -1;

	for (int i = 0; i <= (txtlen - patlen); i++)
	{
		bool match = true;
		for (int j = 0; j < patlen; j++)
		{
			if (text[i + j] != pattern[j])
			{
				match = false;
				break;
			}
		}

		if (match == true)
			return i;
	}

	return -1;
}

// Longest Prefix Suffix
void GetLpsTable(char* pattern, int patlen, int* lpstable)
{
	int i = 1;
	int j = 0;
	lpstable[0] = 0;

	while (i < patlen)
	{
		if (pattern[i] == pattern[j])
		{
			j++;
			lpstable[i] = j;
			i++;
		}
		else
		{
			if (j != 0)
			{
				j = lpstable[j - 1];
			}
			else
			{
				lpstable[i] = 0;
				i++;
			}
		}
	}
}

// Knuth Morris Patternson KMP algorithm
// Avg, Worst O(m + n)
int SearchPatternByKMP(char* text, char* pattern)
{
	int txtlen = strlen(text);
	int patlen = strlen(pattern);	

	if (txtlen == 0 || patlen == 0 || txtlen < patlen)
		return -1;

	int* lpstable = new int[patlen];
	GetLpsTable(pattern, patlen, lpstable);

	int i = 0;
	int j = 0;
	while (i < txtlen)
	{
		if (text[i] == pattern[j])
		{
			j++;
			i++;
		}

		if (j == patlen)
		{
			return (i - j);
			j = lpstable[j - 1];
		}
		else if (i < txtlen && text[i] != pattern[j])
		{
			if (j != 0)
				j = lpstable[j - 1];
			else
				i++;
		}
	}

	return -1;
}

// Pattern matching using hash (Rabin Karp) 
// Avg O(m + n), Worst O(mn) - weak hash func
int SearchPatternByHash(char* text, char* pattern)
{
	const int SYMBOL_BASE = 128; // ascii symbols
	int txtlen = strlen(text);
	int patlen = strlen(pattern);

	if (txtlen == 0 || patlen == 0 || txtlen < patlen)
		return -1;

	double pathash = 0;
	double rolhash = 0;
	bool match = true;
	for (int i = 0; i < patlen; i++)
	{
		pathash += pattern[i] * pow(SYMBOL_BASE, patlen - i - 1);
		rolhash += text[i] * pow(SYMBOL_BASE, patlen - i - 1);
		if (text[i] != pattern[i])
			match = false;
	}

	if (match)
		return 0;

	for (int i = 0; i < (txtlen - patlen); i++)
	{
		rolhash -= text[i] * pow(SYMBOL_BASE, patlen - 1);
		rolhash = (rolhash * SYMBOL_BASE) + text[i + patlen];
		if (rolhash == pathash)
		{
			match = true;
			for (int j = 0; j < patlen; j++)
			{
				if (text[i + 1 + j] != pattern[j])
				{
					match = false;
					break;
				}
			}
		}

		if (match)
			return i + 1;
	}

	return -1;
}

void PatternMatchingAlgosUsageExample()
{
	printf("\n\n10. PatternMatchingAlgosUsageExample: ");
	
	char text[] = "ababcabcabababd";
	char pattern[] = "ababd";

	printf("\nInput Text: %s", text);
	printf("\nInput Pattern: %s", pattern);

	int idx1 = SearchPatternByNaive(text, pattern);
	printf("\nSearchPatternByNaive: %d", idx1);

	int idx2 = SearchPatternByKMP(text, pattern);
	printf("\nSearchPatternByKMP  : %d", idx2);

	int idx3 = SearchPatternByHash(text, pattern);
	printf("\nSearchPatternByHash : %d", idx3);
}
