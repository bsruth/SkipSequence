#include "SkipSequence.h"

int main()
{
	//generates a 100 element array of uint64_t with values 100 - 298 counting by 2's at compile time
	const auto compileTimeSequence = SkipSequence<uint64_t, 100, 2, 100>::value;
	return 0;
}