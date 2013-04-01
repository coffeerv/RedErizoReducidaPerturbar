#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

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
    FILE * output_file)
{
    const char * line_sep = "================================================================================";
    int dS [max_steps][num_nodes]; // This is valid c99
    // Copying initial_condition
    for (int i = 0; i < num_nodes; i++)
        dS[0][i] = initial_condition[i];

    int t = 1;
    bool skip = false;
    while (t < max_steps)
    {
        //Compute the next discrete state
        for (int i = 0; i < num_nodes; i++)
        {
            dS[t][i] = discrete_mapping(i, dS[t-1]);
#ifdef VERBOSE_DEBUG
            printf("%d%c", dS[t][i], (i < num_nodes-1) ? '\t' : '\n');
#endif
        }
        if(t > transient_time)
        {
            for (int k = 1; k < t; k++)
            {
                if(memcmp(dS[t-k], dS[t], sizeof(dS[t])) == 0)
                {
#ifdef VERBOSE_DEBUG
                    printf("t = %d, k = %d\n", t,k);
                    for (int col=0;col<num_nodes;col++)
                        printf("%d%c", dS[t-k][col], (col < num_nodes-1) ? '\t' : '\n');
                    for (int col=0;col<num_nodes;col++)
                        printf("%d%c", dS[t][col], (col < num_nodes-1) ? '\t' : '\n');
#endif
                    fprintf(output_file, "Attractor of period %d reached.\n%s\n%s\n", k, node_names, line_sep);
                    for (int j = t-k; j <= t; j++)
                        for (int n = 0; n < num_nodes; n++)
                            fprintf(output_file, "%d%c", dS[j][n], (n < num_nodes-1) ? '\t' : '\n'); 
#ifdef VERBOSE_DEBUG
                    for (int a = 0; a < num_nodes; a++)
                        fprintf(output_file, "%d%c", discrete_mapping(a, dS[t]), (a < num_nodes-1) ? '\t' : '\n');
#endif
                    skip = true;
                    break;
                }
            }
        }
        if(!skip)
            t++;
        else
            break;
    }
}

#endif
