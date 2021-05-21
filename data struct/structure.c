#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// typedef struct Node
// {
//     int val;
//     struct Node *nextNode;
// }node;
// typedef struct bst{
//     int val;
//     struct bst* right;
//     struct bst* left;
// }bst_nd;
//creat data
int dataset[1000001];



void int_swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shuffle(int num)
{
    for (int i = 0; i < num; i++)
    {
        int_swap(&dataset[i], &dataset[(rand() % (num))]);
    }
}
void createQueeryData(int createNum, int num[], int insnum)
{
    srand(10);
    for (int i = 0; i < createNum; i++)
    {

        num[i] = rand()%1000000;
    }
}
void createInsData(int createNum, int num[])
{
    for (int i = 0; i < createNum; i++)
    {
        dataset[i] = i;
    }
    //shuffle the array and print to file
    shuffle(createNum);
    for (int i = 0; i < createNum; i++)
    {
        num[i] = dataset[i];
    }
}

//array
void addToArray(int val, int arr[], int idx)
{
    arr[idx] = val;
}

void querryInArray(int querNum, int arr[], int sizeOfArr)
{
    for (int i = 0; i < sizeOfArr; i++)
    {
        if (arr[i] == querNum)
            return;
    }
    return;
}
//link list

node *head = NULL;
node *createNode(int val)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->nextNode = NULL;
    tmp->val = val;
    return tmp;
}
void addNodeToLinklist(int val)
{
    node *tmp;
    if (head == NULL)
    {
        head = createNode(val);
        return;
    }
    tmp = createNode(val);
    tmp->nextNode = head;
    head = tmp;
}
node *addAlltoLinklist(int num[], node *head1, int insNum)
{
    head = head1;
    for (int i = 0; i < insNum; i++)
    {
        addNodeToLinklist(num[i]);
    }
    return head;
}
void querryInLinklist(node *head, int querryNum)
{
    node *tmp = head;
    if (head == NULL)
        return;
    while (tmp->nextNode != NULL)
    {
        if (tmp->val == querryNum)
        {
            return;
        }
        tmp = tmp->nextNode;
    }
    if (tmp->val == querryNum)
    {
        return;
    }
    return;
}

//bst
bst_nd *createBstNode(int val)
{
    bst_nd *tmp = (bst_nd *)malloc(sizeof(bst_nd));
    tmp->val = val;
    tmp->right = NULL;
    tmp->left = NULL;
    return tmp;
}
void addNodeToBst(int val, bst_nd *root)
{
    bst_nd *tmp = root;
    if (root == NULL)
    {
        root = createBstNode(val);
        return;
    }
    while (1)
    {
        if (val > tmp->val)
        {
            if (tmp->right == NULL)
            {
                tmp->right = createBstNode(val);
                return;
            }
            tmp = tmp->right;
        }
        else
        {
            if (tmp->left == NULL)
            {
                tmp->left = createBstNode(val);
                return;
            }
            tmp = tmp->left;
        }
    }
}

void querryInBst(int querryNum, bst_nd *root)
{
    bst_nd *tmp = root;
    if (root == NULL)
    {
        return;
    }
    while (1)
    {
        if (tmp == NULL)
        {
            return;
        }
        if (querryNum > tmp->val)
        {
            if (tmp->right != NULL && tmp->right->val == querryNum)
            {
                return;
            }
            tmp = tmp->right;
        }
        else
        {
            if (tmp->left != NULL && tmp->left->val == querryNum)
            {
                return;
            }
            tmp = tmp->left;
        }
    }
}

//array with binary search

void querryInBsArray(int target, int num[], int arrSize)
{
    int upper = arrSize - 1;
    int lowwer = 0;
    int mid = (upper + lowwer) / 2;
    while (lowwer < upper)
    {
        if (target > num[mid])
        {
            lowwer = mid + 1;
            mid = (upper + lowwer) / 2;
        }
        else if (target < num[mid])
        {
            upper = mid;
            mid = (upper + lowwer) / 2;
        }
        else
        {
            return;
        }
    }
    return;
}

//hash table

int hash_function(int a, int maxsize)
{
    return a % maxsize;
}

Ht_item *create_item(int val)
{
    Ht_item *item = (Ht_item *)malloc(sizeof(Ht_item));
    item->next = NULL;
    item->val = val;
    return item;
}
Hashtable *create_table(int size)
{
    Hashtable *table = (Hashtable *)malloc(sizeof(Hashtable));
    table->size = size;
    table->items = (Ht_item **)calloc(table->size, sizeof(Ht_item *));
    for (int i = 0; i < size; i++)
    {
        table->items[i] = NULL;
    }
    return table;
}

void ht_insert(Hashtable *table, int val, int maxsize)
{
    Ht_item *item = create_item(val);
    int idx = hash_function(val, maxsize);

    if (table->items[idx] == NULL)
    {
        table->items[idx] = item;
        return;
    }
    //
    else
    {
        if (table->items[idx]->val == val)
        {
            //already exsist
            return;
        }
        else
        {
            Ht_item *tmp = table->items[idx];
            if (tmp->next != NULL)
            {
                if (tmp->val == val)
                    return;
                tmp = tmp->next;
            }
            tmp->next = create_item(val);
            return;
        }
    }
}

void ht_search(Hashtable *table, int val, int maxsize)
{
    int idx = hash_function(val, maxsize);
    Ht_item *tmp = table->items[idx];
    if (tmp == NULL)
        return;
    if(tmp->val==val)
        return;
    while (tmp->next != NULL)
    {
        if (tmp->val == val)
            return;
        tmp = tmp->next;
    }
    if (tmp->val == val)
        return;
    return;
}




