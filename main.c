#include <stdlib.h>
#include <stdio.h>
#include "discreteFunction.h"
#include "networkEvolve.h"

int main(int argc, const char * argv [])
{
	const int nodes = 10;
	const int maxIterations = 1000;
	const int transient = 50;
	int initialCondition[10] = {1,0,1,0,1,0,1,0,1,0};
	const char * names = "Sr\tcGMP\tPDE\tV\tCatsper\tHCN\tpH\tdCa\tCaKC\tdK";
	FILE * fp = fopen("salida.txt", "w+");
	discreteEvolution(initialCondition, nodes, maxIterations, transient, names, discreteModel, fp);
	fclose(fp);
    	return EXIT_SUCCESS;
}
