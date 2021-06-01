#include <iostream>

using namespace std;

class product
{
   int id;
   string name;
   double price;
   public:
     //constructor ο οποιος θα αρχικοποιεί τις μεταβλητές με 3 ορίσματα.
     product():id(0),name(""),price(0.0) {}
     product(int i,string n,double pr):id(i),name(n),price(pr) {//id=i;
         //id=i;
         //name=n;
         //price=pr;
     }
     ~product() {}
     //Σύγκριση 2 προιόντων με βάση την τίμη
     bool operator>(const product &p)const
     {
       /*if(this->price>p.price)
       {
           return true;
       }   
       else
       {
          return false;
       }*/
       return this->price>p.price;//67.89>67.89
     }
     //==-->id
     bool operator==(const product &myproduct)const{
         return this->id==myproduct.id && this->name==myproduct.name;
     }
     //price--><
     bool operator<(const product &p)const{
         return this->price<p.price;
     }
     //<>==!=
     //+-*/
     product operator+(const product &p)const
     {
         //this,p
         product newproduct;
         newproduct.id=this->id+p.id;
         newproduct.name=this->name+p.name;
         newproduct.price=this->price+p.price;
         return newproduct;
         //return product(this->id+p.id,this->name+p.name,this->price+p.price);
     }
     product operator-(const product &p)const
     {
         //this,p
         product newproduct;
         newproduct.id=this->id-p.id;
         newproduct.name=this->name+p.name;
         newproduct.price=this->price-p.price;
         return newproduct;
         //return product(this->id+p.id,this->name+p.name,this->price+p.price);
     }
     //<<
     friend ostream& operator<<(ostream &os,const product &p)
     {
        os<<p.id<<"--"<<p.name<<"--"<<p.price;
        return os;
     }
};

int main()
{  
    product p1(1,"product1",67.89);
    product p2(2,"product2",67.89);
    if(p1>p2)
    {
        cout<<"p1 has bigger price than p2"<<endl;
    }
    else
    {
        cout<<"p1 is chipier or equal with p2"<<endl;
    }
    if(p1==p2)
    {
        cout<<"equal products"<<endl;
    }
    else 
    {
        cout<<"2 products are not equal"<<endl;
    }
    product p3=p1+p2;
    //p3.id=3
    //p3.name=product1product2
    //p3.price=124...
    cout<<p1<<endl;
    cout<<p2<<endl;
    cout<<p3<<endl;
    return 0;
}