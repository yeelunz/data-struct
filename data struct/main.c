#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
// 請撰寫程式做以下資料結構之建立、查詢速度之比較

// Linked list
// Array
// Array with Binary Search
// Binary Search Tree
// Hash (可不做，但本作業扣 10 分)

// 你的程式將必須至少做到以下事情
// 隨機產生 N 筆唯一的資料供插入
// 隨機產生 M 筆供查詢
// 測量建立該資料結構所需時間
// 測量查詢該資料結構所需時間

// 你的程式必須至少支援以下參數
// -d N (required) 插入的資料筆數，每筆資料是唯一的 (1e4, 1e5, 1e6)
// -q M (required) 查詢資料筆數 (1e3, 1e4, 1e5)
// -bst: 測量BST建立和查詢所需時間
// -bs:  測量 Binary Search建立資料結構(含 sorting) 和查詢所需時間
// -arr: 測量 array 建立資料結構和查詢(linear search)所需時間
// -ll: 測量 linked list 建立資料結構和查詢所需時間
// -hash 測量 hash 建立資料結構和查詢所需時間

// 必須至少輸出以下內容
// 此資料結構建立 d 筆資料所需時間
// 查詢 q 筆資料所需時間
int insDataSet[1000001];
int queDataSet[1000001];
int int_array[1000001];
int int_bsArray[1000001];

void inorder(bst_nd *a)
{
    if (a == NULL)
    {
        return;
    }
    inorder(a->left);
    printf("%d\n", a->val);
    inorder(a->right);
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main(int argc, char **argv)
{
    srand(10000);
    struct timeval start;
    struct timeval end;
    unsigned long diff;
    int insertNum;
    int querryNum;
    int bstMode = 0;
    int bsMode = 0;
    int arrMode = 0;
    int llMode = 0;
    int hashMode = 0;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-bst") == 0)
        {
            bstMode = 1;
        }
        if (strcmp(argv[i], "-bs") == 0)
        {
            bsMode = 1;
        }
        if (strcmp(argv[i], "-arr") == 0)
        {
            arrMode = 1;
        }
        if (strcmp(argv[i], "-ll") == 0)
        {
            llMode = 1;
        }
        if (strcmp(argv[i], "-hash") == 0)
        {
            hashMode = 1;
        }
        if (strcmp(argv[i], "-d") == 0)
        {
            insertNum = (int)atof(argv[i + 1]);
        }
        if (strcmp(argv[i], "-q") == 0)
        {
            querryNum = (int)atof(argv[i + 1]);
        }
    }
    //creat insert num & creat querry num
    createInsData(insertNum, insDataSet);
    createQueeryData(querryNum, queDataSet, insertNum);
    printf("ins num:%d\nque num:%d\n\n", insertNum, querryNum);

    if (bstMode)
    {
        puts("Bst:");
        bst_nd *root = NULL;
        //insert to data structure & get time
        gettimeofday(&start, NULL);
        root = createBstNode(insDataSet[0]);
        for (int i = 1; i < insertNum; i++)
        {
            addNodeToBst(insDataSet[i], root);
        }
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("Building time: %f sec\n", diff / 1000000.0);
        // querry random num
        gettimeofday(&start, NULL);
        for (int i = 0; i < querryNum; i++)
        {
            querryInBst(queDataSet[i], root);
        }
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("Querry time: %f sec\n", diff / 1000000.0);
    }
    if (bsMode)
    {
        puts("Bs Array:");
        //insert & sort
        gettimeofday(&start, NULL);
        for (int i = 0; i < insertNum; i++)
        {
            addToArray(insDataSet[i], int_bsArray, i);
        }
        qsort(int_bsArray, insertNum, sizeof(int), cmp);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("Building time: %f sec\n", diff / 1000000.0);
        //querry
        gettimeofday(&start, NULL);
        for (int i = 0; i < querryNum; i++)
        {
            querryInBsArray(queDataSet[i], int_bsArray, insertNum);
        }
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("Querry time: %f sec\n", diff / 1000000.0);
    }
    if (arrMode)
    {
        puts("Array:");
        //insert
        gettimeofday(&start, NULL);
        for (int i = 0; i < insertNum; i++)
        {
            addToArray(insDataSet[i], int_array, i);
        }
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("Building time: %f sec\n", diff / 1000000.0);
        //querry
        gettimeofday(&start, NULL);
        for (int i = 0; i < querryNum; i++)
        {
            querryInArray(queDataSet[i], int_array, insertNum);
        }
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("Querry time: %f sec\n", diff / 1000000.0);
    }

    if (llMode)
    {
        node *head = NULL;
        puts("Linklist:");
        //insert
        gettimeofday(&start, NULL);
        head = addAlltoLinklist(insDataSet, head, insertNum);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("Building time: %f sec\n", diff / 1000000.0);
        //querry
        gettimeofday(&start, NULL);
        for (int i = 0; i < querryNum; i++)
        {
            querryInLinklist(head, queDataSet[i]);
        }
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("Querry time: %f sec\n", diff / 1000000.0);
    }

    if (hashMode)
    {
        puts("Hash:");
        Hashtable *table = NULL;
        //build
        gettimeofday(&start, NULL);
        table = create_table(insertNum);
        for (int i = 0; i < insertNum; i++)
        {
            ht_insert(table, insDataSet[i], insertNum);
        }
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("Building time: %f sec\n", diff / 1000000.0);
        //qurry
        gettimeofday(&start, NULL);
        for (int i = 0; i < querryNum; i++)
        {
            ht_search(table, queDataSet[i], insertNum);
        }
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("Building time: %f sec\n", diff / 1000000.0);
    }
}
