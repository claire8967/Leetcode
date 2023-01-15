#include <stdio.h>


struct node{
    long val;
    int index;
    struct node* next;
};


void insert(struct node** hashTable,long val,int index,int n){
    int t = abs(val)%n;
    struct node* temp = hashTable[t];

    struct node* add = (struct node*) malloc(sizeof(struct node));
    add -> val =  val;
    add -> index = index;
    add -> next = temp -> next;
    temp -> next = add;
}
int search(struct node** hashTable, long target,int n){
    int index = abs(target) % n;
    struct node* temp = hashTable[index]->next;
    while(temp){
        if(temp->val == target){
            return temp -> index;
        }else{
            temp = temp-> next;
        }}
    return -1;
}

void freeHashTable(struct node** hashTable,int n){
    int i = 0;
    struct node *temp = NULL, *delete = NULL;
    for(i = 0;i<n;i++){
        temp = hashTable[i];
        delete = temp;
        while(temp){
            delete = temp;
            temp = temp -> next;
            free(delete);
        }
    }
    free(hashTable);
}

int* twoSum(int* nums,int numsSize, int target){
    int i = 0;
    int j = 0;
    int n = numsSize;
    int index = 0;
    int *result = NULL;
    struct node** hashTable = (struct node**) malloc (n*sizeof(struct node*));

    for(i=0;i<n;i++){
        hashTable[i] = (struct node*)calloc(1,sizeof(struct node));
    }
    for(i=0;i<n;i++){
        index = search(hashTable,target-nums[i],n);
        if(index==-1){
            insert(hashTable,nums[i],i,n);
        }else{
            result = (int*) malloc (sizeof(int)*2);
            result[0] = index;
            result[1] = i;
            freeHashTable(hashTable,n);
            return result;
        }
    }
    freeHashTable(hashTable,n);
    return result;
}