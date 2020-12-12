#include <iostream>
#include <vector>
#include <sstream>
#include <string>

class line_item
{
    private:
      std::string product;
      int quantity;
      double price;
   public:
      line_item(std::string pr,int q,double p):product(pr),quantity(q),price(p) {}
      std::string getproduct() {return this->product;}
      int getquantity() {return this->quantity;}
      double getprice() {return this->price;}
      friend std::ostream &operator<<(std::ostream &os,line_item &it)
      {
          os<<it.product<<"--"<<it.quantity<<"--"<<it.price;
          return os;
      }
};

class order
{
    private:
      std::string number;
      std::string ordered;
      std::string shipped;
      std::string ship_to;
     std::vector <line_item> items;
    public:
      order(std::string n,std::string ord,std::string sh,std::string sht):number(n),ordered(ord),shipped(sh),ship_to(sht) {}
      void add_item(line_item aitem) {items.push_back(aitem);}
      std::string getnumber() {return this->number;}
      std::vector <line_item> get_line_items() {return this->items;}
      std::string getordered() {return this->ordered;}
      std::string getshipped() {return this->shipped;}
      std::string getshpto() {return this->ship_to;}
      friend std::ostream &operator<<(std::ostream &os,order &ord)
      {
          os<<ord.number<<"--"<<ord.ordered<<"--"<<ord.ship_to<<"--"<<ord.shipped<<std::endl;
          for(line_item &x:ord.items)
          {
              os<<x<<std::endl;
          }
          return os;
      }
};

std::vector <order> get_items()
{
    order o1("0001","2020-01-05 10:07:07","2020-01-07 12:01:01","Athens");
    line_item it1("TV",1,550.0);
    line_item it2("A4 PAPER",5,10.5);
    o1.add_item(it1);
    o1.add_item(it2);
    line_item it3("Microphone",2,50.5);
    o1.add_item(it3);
    order o2("0002","2020-02-07 12:20:01","2020-02-17 19:30:20","Ioannina");
    line_item it4("CAMERA",1,230.0);
    line_item it5("WIFI",1,55.9);
    line_item it6("SSD",1,90.5);
    o2.add_item(it4);
    o2.add_item(it5);
    order o3("0003","2020-02-08 10:20:11","2020-02-15 12:35:22","Arta");
    o3.add_item(it6);
    std::vector <order> orders;
    orders.push_back(o1);
    orders.push_back(o2);
    orders.push_back(o3);
    return orders;
}