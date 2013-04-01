/*
 *  discrete_function.h
 *
 *  Created by Rafael Verduzco on 7/7/11.
 *  Copyright 2011 Universidad Autónoma del Estado de Morelos. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int compare_ints (const void * a, const void * b);
int discrete_model (const int i, const int * st);
int discrete_model_perturbed (const int i, const int *st, const int *perturbations, const int num_perturbations);

