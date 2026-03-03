/*
 * File:        dataset.h
 * Description: Headerfile for app2
 * Author: Jiaming Liu
 * Date: 3/2/26
 */

# ifndef DATASET_H
# define DATASET_H
# include <stdbool.h>

typedef struct dataset DATASET;

DATASET *createDataSet(int maxStudents);
void destroyDataSet(DATASET *dp);

bool insertion(DATASET *dp, int id, int age);
bool searchID(DATASET *dp, int id);
bool deletion(DATASET *dp, int id);

# endif /* DATASET_H */
