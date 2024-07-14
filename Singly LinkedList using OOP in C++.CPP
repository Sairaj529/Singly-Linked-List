#include <iostream>
#include <conio>
#include <stdlib>
struct node{
  int data;
  node* next;
  };


class ll{
   node* start;
   node* end;

   public:

   ll(){
      start=NULL;
      end=NULL;
     }

  void insertBeg(int val){

       node* newnode=(node*)malloc(sizeof(node));
       newnode->data=val;
       newnode->next=NULL;

       if(start==NULL){
           start=newnode;
           end=newnode;
           }
            else{
             newnode->next=start;
             start=newnode;
            }
     }

     void display(){
        node* temp=start;
        cout<<"\n";
        while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
         }
        }

    void insertEnd(int val){

       node* newnode=(node*)malloc(sizeof(node));
       newnode->data=val;
       newnode->next=NULL;

       if(start==NULL){
           start=newnode;
           end=newnode;
           }
            else{
             end->next=newnode;
             end=newnode;
            }
     }

     node* search(int aft){
        node* temp=start;
        while(temp!=NULL){
        if(temp->data==aft) return temp;
        temp=temp->next;
         }
        }

     void insertAfter(int val,int aft){
         node* bef_node=search(aft);
         //cout<<"\nval of the bef_node="<<bef_node->data;
         if(bef_node==NULL) cout<<"\nNode doesn't exist";
         else if(start==NULL||bef_node==end){
              insertEnd(val);
              }
           else{
               node* newnode=(node*)malloc(sizeof(node));
               newnode->data=val;
               newnode->next=bef_node->next;
               bef_node->next=newnode;
               }

            }

     void delBeg(){
           if(start==NULL){
              cout<<"\nList empty";
              }
           else{
           start=start->next;
           }
       }

       void delEnd(){
           if(start==NULL){
              cout<<"\nList empty";
              }
           else{
           end=search_prior_node(end->data);
           }
       }

      node* search_prior_node(int val){
        node* temp=start;
        while(temp!=NULL){
        if(temp->next->data==val) return temp;
        temp=temp->next;
         }
         return NULL;
        }

      void delete_(int val){
        node* a=search_prior_node(val);
        if(a==NULL) cout<<"\nNode doesn't exist";
        else if(a==start){
              delBeg();
              }
        else if(a==end){
              delEnd();
              }

        else{
           a->next=a->next->next;
           }
        }

  };

  void main(){

      ll l=ll();
      l.insertBeg(1);
      l.insertEnd(2);
      l.insertAfter(3,1);
      l.display();
      //l.delete_(3);
      l.display();

      getch();
      }



