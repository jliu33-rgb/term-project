/*
 * File:   dataset.c
 * Author: Jiaming Liu
 * Desc:   DATASET ADT for Application 1.
 *         Implementation uses a fixed-size array sorted by age.
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
    return NULL;
}

void destroyDataSet(DATASET *dp)
{
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
