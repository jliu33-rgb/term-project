/*
 * File:   dataset.c
 * Author: Jiaming Liu
 * Desc:   DATASET ADT for Application 2 (Direct Addressing).
 * Date: 3/2/26
 */

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "dataset.h"

#define MIN_ID 1
#define MAX_ID 2000

typedef struct {
    int id;
    int age;
} STUDENT;

struct dataset {
    int count;
    int maxStudents;
    STUDENT *elts;
    unsigned char *present;
};

static bool validID(int id)
{
    return (id >= MIN_ID && id <= MAX_ID);
}

DATASET *createDataSet(int maxStudents) { }
void destroyDataSet(DATASET *dp) { }
bool insertion(DATASET *dp, int id, int age) { }
bool searchID(DATASET *dp, int id) {  }
bool deletion(DATASET *dp, int id) {}
