#include <stdlib.h>
#include <stdio.h>
#include "discrete_function.h"
#include "network_evolve.h"

int main(int argc, const char * argv [])
{
	const int nodes = 10;
	const int max_iterations = 1000;
	const int transient = 50;
	int initial_condition[10] = {0,0,0,1,0,0,0,1,0,0};
	const char * names = "Sr\tcGMP\tPDE\tV\tCatsper\tHCN\tpH\tdCa\tCaKC\tdK";
	FILE * fp = fopen("salida.txt", "w+");
	discrete_evolution(initial_condition, nodes, max_iterations, transient, names, discrete_model, fp);
	fclose(fp);
    	return EXIT_SUCCESS;
}
