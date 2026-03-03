/*
 * File:   college.c
 * Author: Jiaming Liu
 * Desc:   Driver program for Application 1.
 * Date: 3/2/26
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dataset.h"

static int randOneOrTwo(void)
{
    return (rand() % 2) + 1;
}

static int randInRange(int lo, int hi)
{
    return lo + (rand() % (hi - lo + 1));
}

int main(void)
{
    srand((unsigned)time(NULL));

    DATASET *dp = createDataSet(3000);

    int id = randOneOrTwo();
    for (int i = 0; i < 1000; i++) {
        int age = randInRange(18, 30);
        insertion(dp, id, age);
        id += randOneOrTwo();
    }

    int queryAge = randInRange(18, 30);
    searchAge(dp, queryAge);

    int delAge = randInRange(18, 30);
    deletion(dp, delAge);

    maxAgeGap(dp);

    destroyDataSet(dp);
    return 0;
}
