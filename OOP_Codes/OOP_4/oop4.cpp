/*
Η κλάση της συνδεδεμένης λίστας να περιέχει τα ακόλουθα:
1. Συνάρτηση μέλος με όνομα length που να επιστρέφει το μήκος της λίστας.
2. Συνάρτηση μέλος με όνομα sum που να επιστρέφει το άθροισμα των ακεραίων τιμών της λίστας.
3. Συνάρτηση μέλος με όνομα erase_front που να διαγράφει το πρώτο στοιχείο της λίστας.
4. Συνάρτηση μέλος με όνομα push_back που να εισάγει ένα στοιχείο στο πίσω άκρο της λίστας.
5. Συνάρτηση μέλος με όνομα bubble_sort που να ταξινομεί χρησιμοποιώντας ταξινόμηση φυσαλίδας τα
στοιχεία της λίστας σε αύξουσα σειρά.
6. copy constructor που να αντιγράφει μια λίστα (deep copy).
7. Προκαθορισμένος κατασκευαστής.
8. Καταστροφέας.
9. Η συνάρτηση μέλος με όνομα front που επιστρέφει ένα δείκτη προς το πρώτο στοιχείο της λίστας.
10. Η συνάρτηση μέλος με όνομα push_front που εισάγει ένα στοιχείο στην αρχή της λίστας.
11. Η συνάρτηση μέλος με όνομα print που εμφανίζει τα στοιχεία της λίστας.
12.Διαγραφή στοιχείου από συγκεκριμένη θέση (π.χ. διαγραφή του στοιχείου στη θέση 2 για τη συνδεδεμένη λίστα 10->20->12->7 θα πρέπει να δίνει τη συνδεδεμένη λίστα 10->20->7).
13.Εισαγωγή στοιχείου σε συγκεκριμένη θέση (π.χ. εισαγωγή του στοιχείου 42 στη θέση 2 για τη συνδεδεμένη λίστα 10->20->12->7 θα πρέπει να δίνει τη συνδεδεμένη λίστα 10->20->42->12->7).
14.Αντιστροφή της συνδεδεμένης λίστας (π.χ. η συνδεδεμένη λίστα 10->20->12->7 θα πρέπει να γίνεται 7->12->20->10).
*/

#define CATCH_CONFIG_MAIN
#include  <iostream>
#include  "catch.hpp"

template <class T> 
struct node
{
    T data;
    node *next;
};

template <class T>
class list
{
   node <T> *head;
   public:
   list():head(nullptr) {}
   list(const list &l)
   {
       int data=l.head->data;
       this->head=new node<T>{head,nullptr};
       node <T> *temp=l.head;
       node <T> *curr=this->head;
       while(temp!=nullptr)
       {
           node <T> *newnode=new node<T>{temp->data,nullptr};
           curr->next=newnode;
           temp=temp->next;
           curr=curr->next;
       }
   }

   ~list()
   {
       while(this->head!=nullptr)
       {
           node <T> *del=this->head;
           this->head=this->head->next;
           delete del;
       }
   }

   int length()
   {
       node <T> *curr=head;
       int l=0;
       while(curr!=nullptr)
       {
           l++;
           curr=curr->next;
       }
       return l;
   }

   T sum()
   {
       node <T> *curr=head;
       T s=0;
       while(curr!=nullptr)
       {
           s+=curr->data;
           curr=curr->next;
       }
       return s;
   }

   void erase_front()
   {
       node <T> *del=this->head;
       this->head=this->head->next;
       delete del;
   }

   void push_back(T d)
   {
       if(this->head==nullptr)
       {
           this->head=new node<T>{d,nullptr};
           return;
       }
       node <T> *newnode=new node<T>{d,nullptr};
       node <T> *curr=this->head;
       while(curr->next!=nullptr)
       {
           curr=curr->next;
       }
       curr->next=newnode;
   }

   void bublesort()
   {
       node <T> *curr=this->head;
       node <T> *temp=nullptr;
       int s=this->length();
       while(curr!=nullptr)
       {
             temp=head;
            for(int i=0;i<s-1;i++)
            {
               if(temp->data>temp->next->data)
               {
                   int tmp=temp->data;
                   temp->data=temp->next->data;
                   temp->next->data=tmp;

               }
               temp=temp->next;
            }
            curr=curr->next;
       }
   }

   T front() {return this->head->data;}

   void push_front(T d)
   {
       if(this->head==nullptr)
       {
           this->head=new node<T>{d,nullptr};
           return;
       }
      node <T> *newnode=new node<T>{d,nullptr};
      newnode->next=this->head;
      this->head=newnode;
   }

   void erase(int pos)
   {
       if(pos<0 || pos>=this->length())
       {
           std::cerr<<"invalid position "<<std::endl;
       }
       node <T> *curr=this->head;
       node <T> *prev;
       for(int i=1;i<pos;i++)
       {
           prev=curr;
          curr=curr->next;
       }
       node <T> *del=curr;
       prev->next=curr->next;
       delete del;
   }
   
    void insert(int pos,T d)
    {
         if(pos<0 || pos>=this->length())
         {
             std::cerr<<"invalid position insertion"<<std::endl;
             return;
         }
         node <T> *curr=this->head;
         for(int i=1;i<pos-1;i++)
         {
            curr=curr->next;
         }
         node <T> *nextnode=curr->next;
         node <T> *newnode=new node<T>{d,nullptr};
         curr->next=newnode;
         newnode->next=nextnode;
    }
   
   void reverse()
   {
       int size=this->length();
       T *mydata=new T[size];
       node <T> *curr=this->head;
       int i=size-1;
       while(curr!=nullptr)
       {
           mydata[i]=curr->data;
           i--;
           curr=curr->next;
       }
       curr=this->head;
       i=0;
       while(curr!=nullptr)
       {
           curr->data=mydata[i];
           curr=curr->next;
           i++;
       }
       delete[] mydata;
   }

   void print()
   {
       int s=this->length();
       node <T> *curr=this->head;
       int i=0;
       while(curr!=nullptr)
       {
           if(i<s-1)
           std::cout<<curr->data<<"->";
           else
           {
               std::cout<<curr->data;
           }
           curr=curr->next;
       }
       std::cout<<std::endl<<std::endl;
   }
};

TEST_CASE("Push_Back and BubbleSort","[list]")
{
    list <int> mylist;
    int a[]={12,43,58,1,31,11,56};
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
       mylist.push_back(a[i]);
    }
    REQUIRE(mylist.length()==sizeof(a)/sizeof(a[0]));
    int b[]{1,11,12,31,43,56,58};
    mylist.bublesort();
    for(int i=0;i<sizeof(b)/sizeof(b[0]);i++)
    {
       REQUIRE(b[i]==mylist.front());
       mylist.erase_front();
    }
}

TEST_CASE("reverse","[list]")
{
    list <int> mylist;
    int a[]{12,34,67,1,8,19};
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        mylist.push_front(a[i]);
        REQUIRE(mylist.front()==a[i]);
    }
    int b[]{12,34,67,1,8,19};
    mylist.reverse();
    for(int i=0;i<sizeof(b)/sizeof(b[0]);i++)
    {
        REQUIRE(mylist.front()==b[i]);
        mylist.erase_front();
    }
}

TEST_CASE("Insert","[list]")
{
    list <double> mylist;
    double a[]{3.45,2.34,6.78,1.89,2.45,2.1,7.8};
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
       mylist.push_back(a[i]);
    }
    REQUIRE(mylist.length()==sizeof(a)/sizeof(a[0]));
    mylist.insert(3,6.71);
    double b[]{3.45,2.34,6.71,6.78,1.89,2.45,2.1,7.8};
    for(int i=0;i<sizeof(b)/sizeof(b[0]);i++)
    {
        REQUIRE(mylist.front()==b[i]);
        mylist.erase_front();
    }
    REQUIRE(mylist.length()==0);
    double c[]{6.7,4.5,8.9,11.56};
    for(int i=0;i<sizeof(c)/sizeof(c[0]);i++)
    {
        mylist.push_back(c[i]);
    }
    mylist.erase(2);
    double cnew[]{6.7,8.9,11.56};
    for(int i=0;i<sizeof(cnew)/sizeof(cnew[0]);i++)
    {
        REQUIRE(mylist.front()==cnew[i]);
        mylist.erase_front();
    }
    mylist.push_front(15.6);
    REQUIRE(mylist.length()==1);
    REQUIRE(mylist.front()==15.6);
}