
typedef struct Node
{
    int val;
    struct Node *nextNode;
}node;
typedef struct bst{
    int val;
    struct bst* right;
    struct bst* left;
}bst_nd;

typedef struct ht_item
{
    int val;
    struct ht_item *next;
}Ht_item;

typedef struct hashtable
{
    Ht_item **items;
    int size;
} Hashtable;;

//create Data
void createQueeryData(int createNum, int num[], int insnum);
void createInsData(int createNum, int num[]);

//array
void addToArray(int val, int arr[], int idx);
void querryInArray(int querNum, int arr[], int sizeOfArr);

//link list
node *createNode(int val);
node *addAlltoLinklist(int num[], node *root, int insNum);
void querryInLinklist(node *head, int querryNum);

//bst
void addNodeToBst(int val, bst_nd *root);
void querryInBst(int querryNum, bst_nd *root);
bst_nd *createBstNode(int val);

//bs arr
void querryInBsArray(int target, int num[], int arrSize);

//hash

void ht_search(Hashtable *table, int val, int maxsize);
void ht_insert(Hashtable *table, int val, int maxsize);
Hashtable *create_table(int size);