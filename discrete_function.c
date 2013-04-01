/*
 *  discrete_function.c
 *
 *  Created by Rafael Verduzco on 7/7/11.
 *  Copyright 2011 Universidad Autónoma del Estado de Morelos. All rights reserved.
 *
 */

#include "discrete_function.h"
#include <stdbool.h>

int
speract[2][2] = {
	{0,	1},
	{1,	1},
};

int
cGMP [8][2] = {
	{0,	0},
	{1,	1},
	{3,	0},
	{4,	0},
	{9,	1},
	{10,	1},
	{12,	0},
	{13,	0}
};

int
PDE [2][2] = {
	{0,	0},
	{1,	1}
};

int
v [36][2] = {
{0,	1},
{1,	1},
{2,	1},
{3,	2},
{4,	2},
{5,	1},
{9,	2},
{10,	2},
{11,	1},
{12,	2},
{13,	2},
{14,	2},
{18,	2},
{19,	2},
{20,	1},
{21,	2},
{22,	2},
{23,	2},
{27,	0},
{28,	0},
{29,	0},
{30,	1},
{31,	0},
{32,	0},
{36,	1},
{37,	1},
{38,	0},
{39,	2},
{40,	1},
{41,	0},
{45,	1},
{46,	1},
{47,	1},
{48,	2},
{49,	1},
{50,	1}
};

int
catsper [18][2] = {
	{0,	0},
	{1,	1},
	{2,	1},
	{3,	1},
	{4,	1},
	{5,	0},
	{9,	0},
	{10,	0},
	{11,	0},
	{12,	1},
	{13,	1},
	{14,	0},
	{18,	0},
	{19,	0},
	{20,	0},
	{21,	1},
	{22,	1},
	{23,	0}
};

int
HCN [3][2] = {
	{0,	1},
	{1,	0},
	{2,	0}
};

int
pH [3][2] = {
	{0,	1},
	{1,	0},
	{2,	0}
};

int
dCa [36][2] = {
{0,	0},
{1,	0},
{2,	0},
{3,	0},
{4,	0},
{5,	0},
{9,	0},
{10,	0},
{11,	0},
{12,	0},
{13,	0},
{14,	0},
{18,	0},
{19,	0},
{20,	0},
{21,	0},
{22,	0},
{23,	0},
{27,	0},
{28,	0},
{29,	0},
{30,	1},
{31,	1},
{32,	2},
{36,	0},
{37,	1},
{38,	1},
{39,	1},
{40,	2},
{41,	2},
{45,	1},
{46,	1},
{47,	1},
{48,	1},
{49,	1},
{50,	2}
};

int
CaKC [9][2] = {
	{0,	0},
	{1,	0},
	{2,	0},
	{3,	0},
	{4,	0},
	{5,	1},
	{6,	0},
	{7,	1},
	{8,	1}
};

int
dK [4][2] = {
	{0,	0},
	{1,	1},
	{3,	1},
	{4,	1}
};

int compare_ints (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int discrete_model (const int i, const int * st)
{
	// 0_sr, 1_cGMP, 2_PDE, 3_v, 4_catsper, 5_HCN, 6_pH, 7_dCa, 8_CaKC, 9_dK
	int rvalue = 0;
	int *pItem;
	int key;
	switch (i) {
		case 0: // sr
			key = st[0];
			pItem = (int*) bsearch(&key, speract, 2, sizeof (int*), compare_ints);
			rvalue = (pItem != NULL) ? *(pItem+1) : -1;
			break;
		case 1: // cGMP
			key = (st[0]*9) + (st[2]*3) + st[1];
			pItem = (int*) bsearch(&key, cGMP, 8, sizeof (int*), compare_ints);
			rvalue = (pItem != NULL) ? *(pItem+1) : -1;
			break;
		case 2: // PDE
			key = st[1];
			pItem = (int*) bsearch(&key, PDE, 2, sizeof (int*), compare_ints);
			rvalue = (pItem != NULL) ? *(pItem+1) : -1;
			break;
		case 3: // v
			key = (st[9]*27) + (st[7]*9) + (st[5]*3) + st[3];
			pItem = (int*) bsearch(&key, v, 36, sizeof (int*), compare_ints);
			rvalue = (pItem != NULL) ? *(pItem+1) : -1;
			break;
		case 4: // catsper
			key = (st[3]*9) + (st[6]*3) + st[7];
			pItem = (int*) bsearch(&key, catsper, 18, sizeof (int*), compare_ints);
			rvalue = (pItem != NULL) ? *(pItem+1) : -1;
			break;
		case 5: // HCN
			key = st[3];
			pItem = (int*) bsearch(&key, HCN, 3, sizeof (int*), compare_ints);
			rvalue = (pItem != NULL) ? *(pItem+1) : -1;
			break;
		case 6: // pH
			key = st[3];
			pItem = (int*) bsearch(&key, pH, 3, sizeof (int*), compare_ints);
			rvalue = (pItem != NULL) ? *(pItem+1) : -1;
			break;
		case 7: // dCa
			key = (st[0]*27) + (st[3]*9) + (st[4]*3) + st[7];
			pItem = (int*) bsearch(&key, dCa, 36, sizeof (int*), compare_ints);
			rvalue = (pItem != NULL) ? *(pItem+1) : -1;
			break;
		case 8: // CaKC
			key = (st[7]*3) + st[3];
			pItem = (int*) bsearch(&key, CaKC, 9, sizeof (int*), compare_ints);
			rvalue = (pItem != NULL) ? *(pItem+1) : -1;
			break;
		case 9: // dK
			key = (st[1]*3) + st[8];
			pItem = (int*) bsearch(&key, dK, 4, sizeof (int*), compare_ints);
			rvalue = (pItem != NULL) ? *(pItem+1) : -1 ;
			break;
		default:
			fprintf(stderr, "Bad node index %d at function %s, file %s, line %d\nAborting...\n", i, __func__, __FILE__, __LINE__);
			break;
	}
	return rvalue;
}

int discrete_model_perturbed(const int i, const int *st, const int *perturbations, const int num_perturbations)
{
   int rvalue = 0;
   bool is_perturbed = false;
   // Check whether the node should be perturbed or not
   /*
   For the time being, this is hardcoded. Probably should receive a vector indicating the
   strides for the regulatory rows corresponding to each node.
   e.g. speract_stride = 2, cGMP_stride = 4, etc.
   */
   int num_reg_rows = 121; /* This could/should be a parameter */
   int strides [10] = {2, 8, 2, 36, 18, 3, 3, 36, 9, 4};
   /* 10 is the number of nodes. Another candidate for a parameter...*/

   /* base and top are the first and last regulatory rows of node i, respectively */
   int base = 0;
   int top = 0;
   for (int j = i; j >= 0; j--)
       top += strides[j];
   top--; /* adjusting becuase we're counting from 0 */
   base = top - strides[i];

   /* Check whether one of the regulatory rows of node i is included in the perturbation list */
   for (int j = 0; j < num_perturbations; j++)
   {
       if((perturbations[j] >= base) && (perturbations[j] <= top))
       {
           is_perturbed = true;
           break; /* The actual row is irrelevant, the node is perturbed. */
       }
   }

   rvalue = discrete_model(i, st);

   if(is_perturbed) 
   {
       if (rvalue == 0) {
           rvalue = 1;
       } else if (rvalue == 1) {
           rvalue = 0;
       } else if (rvalue == 2) {
           rvalue = 1;
       }
   }
   
   return rvalue;
}

