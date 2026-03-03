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
    assert(maxStudents > 0);

    DATASET *dp = malloc(sizeof(*dp));
    assert(dp != NULL);

    dp->count = 0;
    dp->maxStudents = maxStudents;

    dp->length = 5003;   /* prime number > 3000 */

    dp->elts = malloc(sizeof(STUDENT) * dp->length);
    dp->flags = malloc(sizeof(unsigned char) * dp->length);

    assert(dp->elts != NULL && dp->flags != NULL);

    for (int i = 0; i < dp->length; i++)
        dp->flags[i] = EMPTY;

    return dp;
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
