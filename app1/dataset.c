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
#include <stdio.h>
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

static int lowerBound(STUDENT *arr, int n, int age)
{
    int left = 0;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].age < age)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

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
    assert(dp != NULL);

    if (dp->count >= dp->length)
        return false;

    int pos = lowerBound(dp->elts, dp->count, age);

    for (int i = dp->count; i > pos; i--) {
        dp->elts[i] = dp->elts[i - 1];
    }

    dp->elts[pos].id = id;
    dp->elts[pos].age = age;
    dp->count++;

    return true;
}

int searchAge(DATASET *dp, int age)
{
    assert(dp != NULL);

    printf("[searchAge] SEarching for Age=%d\n", age);

    if (dp->count == 0) {
        printf("[searchAge] Dataset empty.\n");
        return 0;
    }

    int start = lowerBound(dp->elts, dp->count, age);
    int found = 0;

    for (int i = start; i < dp->count && dp->elts[i].age == age; i++) {
        printf("[searchAge] Found: ID=%d Age=%d\n", dp->elts[i].id, dp->elts[i].age);
        found++;
    }

    if (found == 0)
        printf("[searchAge] Not found.\n");

    return found;
}

int deletion(DATASET *dp, int age)
{
    assert(dp != NULL);

    printf("[deletion] Deleting Age=%d\n", age);

    if (dp->count == 0) {
        printf("[deletion] Dataset is empty theres nothing to delete\n");
        return 0;
    }

    int start = lowerBound(dp->elts, dp->count, age);

    int end = start;
    while (end < dp->count && dp->elts[end].age == age)
        end++;

    int numDeleted = end - start;

    if (numDeleted == 0) {
        printf("[deletion] cant find Age=%d .\n", age);
        return 0;
    }

    for (int i = start; i + numDeleted < dp->count; i++) {
        dp->elts[i] = dp->elts[i + numDeleted];
    }

    dp->count -= numDeleted;

    printf("[deletion] Deleted %d record(s) successfully :)\n", numDeleted);
    return numDeleted;
}

int maxAgeGap(DATASET *dp)
{
    assert(dp != NULL);

    int gap = 0;

    if (dp->count >= 2)
        gap = dp->elts[dp->count - 1].age - dp->elts[0].age;

    printf("[maxAgeGap] Maximum age gap = %d\n", gap);
    return gap;
}
