#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#if __STDC_VERSION__ < 199901L
#error "This code requires a C99 compiler. Try cc -std=c99"
#else

void
discrete_evolution (
	const int* initial_condition,
	const size_t num_nodes,
	const size_t max_steps,
	const size_t transient_time,
	const char * node_names,
	int (* discrete_mapping) (const int, const int *),
	FILE * output_file);

#endif
