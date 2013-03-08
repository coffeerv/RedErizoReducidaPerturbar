#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#if __STDC_VERSION__ < 199901L
#error "This code requires a C99 compiler. Try cc -std=c99"
#else

void
discreteEvolution (
	const int* initialCondition,
	const size_t numNodes,
	const size_t maxSteps,
	const size_t transientTime,
	const char * nodeNames,
	int (* discreteMapping) (const int, const int *),
	FILE * outputFile);

#endif
