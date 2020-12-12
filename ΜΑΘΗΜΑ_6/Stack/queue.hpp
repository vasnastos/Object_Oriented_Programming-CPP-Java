#include <iostream>
#define SZ 200

template <class T>
class queue
{
    T data[SZ];
    int front_;
    public:
     queue():front_(-1) {}
     ~queue() {}
     bool empty() {return front_==-1;}
     T front() {return data[0];}
     void enqueue(T d)
     {
         front_++;
         data[front_]=d;
     }
     void dequeue()//pop
     {
        for(int i=0;i<front_;i++)
        {
            data[i]=data[i+1];
        }
        front_--;
     }
     int size() {return front_+1;}
     T back() {return data[front_];}
     void print()
     {
         for(int i=0;i<front_;i++)
         {
             std::cout<<data[i]<<"-->";
         }
         std::cout<<data[front_]<<std::endl;
     }
};