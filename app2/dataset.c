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

// find probe position helpr
static int hashIndex(DATASET *dp, int key, int i)
{
    return (key + i) % dp->length;
}

// find where index is at or should go helper
static int findSlot(DATASET *dp, int id, bool *found)
{
    int firstDeleted = -1;

    for (int i = 0; i < dp->length; i++) {
        int idx = hashIndex(dp, id, i);

        if (dp->flags[idx] == FILLED && dp->elts[idx].id == id) {
            *found = true;
            return idx;
        }

        if (dp->flags[idx] == DELETED && firstDeleted == -1)
            firstDeleted = idx;

        if (dp->flags[idx] == EMPTY) {
            *found = false;
            if (firstDeleted != -1)
                return firstDeleted;
            return idx;
        }
    }

    *found = false;
    return -1;
}

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
    assert(dp != NULL);

    free(dp->elts);
    free(dp->flags);
    free(dp);
}

bool insertion(DATASET *dp, int id, int age)
{
    assert(dp != NULL);

    if (dp->count >= dp->maxStudents)
        return false;

    bool found = false;
    int idx = findSlot(dp, id, &found);
    if (idx == -1)
        return false;

    if (found)
        return true;

    dp->elts[idx].id = id;
    dp->elts[idx].age = age;
    dp->flags[idx] = FILLED;
    dp->count++;

    return true;
}

bool searchID(DATASET *dp, int id)
{
    assert(dp != NULL);

    printf("[searchID] Searching for ID=%d\n", id);

    bool found = false;
    int idx = findSlot(dp, id, &found);

    if (found) {
        printf("[searchID] Found: ID=%d Age=%d\n", dp->elts[idx].id, dp->elts[idx].age);
        return true;
    }

    printf("[searchID] not found.\n");
    return false;
}

bool deletion(DATASET *dp, int id)
{
    assert(dp != NULL);

    printf("[deletion] Deleting ID=%d\n", id);

    bool found = false;
    int idx = findSlot(dp, id, &found);

    if (!found) {
        printf("[deletion] couldn't find ID=%d\n", id);
        return false;
    }

    dp->flags[idx] = DELETED;
    dp->count--;

    printf("[deletion] Deleted successfully.\n");
    return true;
}
