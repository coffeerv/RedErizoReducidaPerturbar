#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

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
    FILE * outputFile)
{
    const char * lineSeparator = "================================================================================";
    int dS [maxSteps][numNodes]; // This is valid c99
    // Copying initialCondition
    for (int i = 0; i < numNodes; i++)
        dS[0][i] = initialCondition[i];

    int t = 1;
    int skipDynamics = 0;
    while (t < maxSteps)
    {
        //Compute the next discrete state
        for (int i = 0; i < numNodes; i++)
        {
            dS[t][i] = discreteMapping(i, dS[t-1]);
#ifdef VERBOSE_DEBUG
            printf("%d%c", dS[t][i], (i < numNodes-1) ? '\t' : '\n');
#endif
        }
        if(t > transientTime)
        {
            for (int k = 1; k < t; k++)
            {
                if(memcmp(dS[t-k], dS[t], sizeof(dS[t])) == 0)
                {
#ifdef VERBOSE_DEBUG
                    printf("t = %d, k = %d\n", t,k);
                    for (int col=0;col<numNodes;col++)
                        printf("%d%c", dS[t-k][col], (col < numNodes-1) ? '\t' : '\n');
                    for (int col=0;col<numNodes;col++)
                        printf("%d%c", dS[t][col], (col < numNodes-1) ? '\t' : '\n');
#endif
                    fprintf(outputFile, "Attractor of period %d reached.\n%s\n%s\n", k, nodeNames, lineSeparator);
                    for (int j = t-k; j <= t; j++)
                        for (int n = 0; n < numNodes; n++)
                            fprintf(outputFile, "%d%c", dS[j][n], (n < numNodes-1) ? '\t' : '\n'); 
#ifdef VERBOSE_DEBUG
                    for (int a = 0; a < numNodes; a++)
                        fprintf(outputFile, "%d%c", discreteMapping(a, dS[t]), (a < numNodes-1) ? '\t' : '\n');
#endif
                    skipDynamics = 1;
                    break;
                }
            }
        }
        if(!skipDynamics)
            t++;
        else
            break;
    }
}

#endif
