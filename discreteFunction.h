/*
 *  discreteFunction.h
 *  Inversr
 *
 *  Created by Rafael Verduzco on 7/7/11.
 *  Copyright 2011 Universidad Autónoma del Estado de Morelos. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct perturbation
{
   int nodeOfIndex;
   int rows[];
}perturbation;

int compareints (const void * a, const void * b);
int discreteModel (const int i, const int * networkState);
int discreteModelWithPerturbations (const int i, const int *networkState, const perturbation * perturbationList);

