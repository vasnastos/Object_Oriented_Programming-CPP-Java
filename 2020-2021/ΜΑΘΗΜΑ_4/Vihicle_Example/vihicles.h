#include <iostream>
#include <vector>
#include <sstream>
#define Bk 0.3
#define Tr 0.7
#define cr 0.5
#define Space 10

enum class Luxury
{
   FAMILY,
   SPORT,
   PROFFESSIONAL,
   OVERTAX
};


class Vihicle
{
    protected:
       std::string reg_number;
       std::string owner_name;
       double cc;
    public: 
      Vihicle(std::string rn,std::string on,double c);
      virtual ~Vihicle() {}
      void print_stats(); 
      virtual double traffic_tax()=0;
      virtual void show()=0;
};

class car:public Vihicle{
    private:
      int polutemode;
      Luxury mode;
    public:
     car(std::string rn,std::string on,double c,int polute,int m);
     ~car() {}
     double traffic_tax();
     void show();
     double extra_tax(); 
};

class Truck:public Vihicle
{
    private:
      int polutemode;
      double weight;
    public:
      Truck(std::string rn,std::string on,double c,int p,double w);
      ~Truck();
      double traffic_tax();
      void show();
      double extra_tax();
};

class Bike:public Vihicle
{
  public:
   Bike(std::string rn,std::string on,double c);
   ~Bike();
   double traffic_tax();
   void show();
   operator std::string();
};

void table_traffic_tax(std::vector <Vihicle *> &vhs);

void show_vihicles(std::vector <Vihicle *> &vhs);

void memory_freed(std::vector <Vihicle *> &vhs);