#include <iostream>
#include "CommonLibs.h"
#include "Typedefs.h"
using namespace std;

void display_array(int* buf, int length)
{
	for (int i = 0; i < length; i++)
		printf("%d ", buf[i]);
}
