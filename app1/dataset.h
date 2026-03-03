/*
 * File:        dataset.h
 * Description: Header file
 * Author: Jeremy Liu
 * Date: 3/2/26
 */

# ifndef DATASET_H
# define DATASET_H

# include <stdbool.h>

typedef struct dataset DATASET;

DATASET *createDataSet(int maxStudents);
void destroyDataSet(DATASET *dp);

bool insertion(DATASET *dp, int id, int age);
int searchAge(DATASET *dp, int age);
int deletion(DATASET *dp, int age);
int maxAgeGap(DATASET *dp);

# endif /* DATASET_H */
