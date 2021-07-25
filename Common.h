#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"

typedef union
{
	double bilangan;		//angka pada operasi matematis tersebut
	char operatorMatematis;	//operator berupa (+),(-),(*),(/)
} Data;

const static Data dummy_data = {0};

#endif 
