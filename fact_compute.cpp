#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

struct node{
int val;
struct node* next;
};

void m(struct node** , int);
void reverse_list(struct node**);
void printlist(struct node**);
void f(int);

int main(){

ifstream inFile;
    
    inFile.open("input.txt");
   int T;
inFile>>T;
while(T>0){
        int n;
inFile>>n;
f(n);
T--;
}
 inFile.close();
return 0;
}

void m(int num, struct node** head_ref){
int p,c=0;
struct node* curr = (*head_ref);
struct node* prev=NULL;
while(curr!= NULL){
    p=num*(curr->val)+c;
    curr->val = p%10;
    c=p/10;
    prev=curr;
    curr=curr->next;
}
while(c > 0){
    struct node* n_node = new struct node;
    prev->next  = n_node;
    n_node->val = c%10;
    n_node->next = NULL;
    c=c/10;
    prev=n_node;
}
}

void printlist(struct node** head_ref){
struct node* head=(*head_ref);
while(head!=NULL){
    cout<<(head->val);
    head=head->next;
}
cout<<"\n";
}

void reverse_list(struct node** head_ref){
struct node* prev=NULL, *next, *curr=(*head_ref);
while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
(*head_ref)=prev;
printlist(head_ref);
}

void f(int n){
struct  node* head = new struct node;
if(n==0 || n==1)
    cout<<"1";
else{
head->val=1;
head->next=NULL;
int num;
for(num=2;num<=n;num++){
m(num,&head);
}
reverse_list(&head);
}
}
