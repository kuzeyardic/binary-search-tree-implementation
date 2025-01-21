/**
* Title: Binary Search Trees
* Author : Berke Kuzey Ardıç
* ID : 22103340
* Section : 001
* Homework : 01
*/






#include "analysis.h"


void analysis::timeAnalysis(){
int keys [] = {};
BST tree(keys,0);


    srand(time(0)); 
    float sum = 0;
    for (int i = 1; i <= 10000; ++i) {
        int randomNumber = rand();

        clock_t clockBeforeInsert = clock();
        tree.insertKeyWithoutPrint(randomNumber);
        clock_t clockAfterInsert = clock();
        sum += (float)(clockAfterInsert-clockBeforeInsert)/CLOCKS_PER_SEC;

        if (i % 1000 == 0) {

            int prev = (i-1000);
            cout<<"Time taken from insertions from "<<prev<<" to "<<i<<"is: "<<sum<<" seconds."<<endl;

            cout << "Height of the tree : " << tree.heightOfThetree() << endl;

            sum=0;
        }
    }


}