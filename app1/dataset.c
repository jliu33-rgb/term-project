/*
 * File:   dataset.c
 * Author: Jiaming Liu
 * Desc:   DATASET ADT for Application 1.
 *         Implementation uses a fixed-size array sorted by age.
 * Date: 3/2/26
 */

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dataset.h"

typedef struct {
    int id;
    int age;
} STUDENT;

struct dataset {
    int count;
    int length;
    STUDENT *elts;
};

DATASET *createDataSet(int maxStudents)
{
    assert(maxStudents > 0);

    DATASET *dp = malloc(sizeof(*dp));
    assert(dp != NULL);

    dp->count = 0;
    dp->length = maxStudents;

    dp->elts = malloc(sizeof(STUDENT) * (size_t)maxStudents);
    assert(dp->elts != NULL);

    return dp;
}

void destroyDataSet(DATASET *dp)
{
    assert(dp != NULL);

    free(dp->elts);
    free(dp);
}

bool insertion(DATASET *dp, int id, int age)
{
    return false;
}

int searchAge(DATASET *dp, int age)
{
    return 0;
}

int deletion(DATASET *dp, int age)
{
    return 0;
}

int maxAgeGap(DATASET *dp)
{
    return 0;
}
