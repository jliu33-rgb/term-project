/*
 * File:   dataset.c
 * Author: Jiaming Liu
 * Desc:   DATASET ADT for Application 2.
 *         Implementation uses a hash table with linear probing to
 *         optimize frequent searches by student ID.
 * Date: 3/2/26
 */

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "dataset.h"

#define EMPTY   0
#define FILLED  1
#define DELETED 2

typedef struct {
    int id;
    int age;
} STUDENT;

struct dataset {
    int count;
    int maxStudents;
    int length;
    STUDENT *elts;
    unsigned char *flags;
};

DATASET *createDataSet(int maxStudents)
{
    
}

void destroyDataSet(DATASET *dp)
{
}

bool insertion(DATASET *dp, int id, int age)
{
   
}

bool searchID(DATASET *dp, int id)
{
  
}

bool deletion(DATASET *dp, int id)
{
    
}
