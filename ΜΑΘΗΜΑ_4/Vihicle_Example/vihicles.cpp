#include "vihicles.h"

Vihicle::Vihicle(std::string rn,std::string on,double c):reg_number(rn),owner_name(on),cc(c) {}

void Vihicle::print_stats()
{
    std::cout<<"RN:"<<this->reg_number<<"   OWNER:"<<this->owner_name<<"   CC:"<<this->cc;
}

car::car(std::string rn,std::string on,double c,int polute,int m):Vihicle(rn,on,c),polutemode(polute)
{
    switch(m)
    {
        case 1:
          this->mode=Luxury::FAMILY;
          break;
        case 2:
          this->mode=Luxury::OVERTAX;
          break;
        case 3:
          this->mode=Luxury::PROFFESSIONAL;
          break;
        case 4:
          this->mode=Luxury::SPORT;
          break;
        default:
          this->mode=Luxury::FAMILY;
          break;
    }
}

double car::extra_tax()
{
    //an extra tax
    double tax=0;
    switch(this->mode)
    {
        case Luxury::FAMILY:
          tax=0.05*this->cc;
          break;
        case Luxury::OVERTAX:
          tax=0.1*this->cc;
          break;
        case Luxury::PROFFESSIONAL:
          tax=0.11*this->cc;
          break;
        case Luxury::SPORT:
          tax=0.14*this->cc;
          break;
    }
    return tax+(cr*this->polutemode);
}

double car::traffic_tax()
{
    //if car cc==1534 --> return 70+(5)*10-->120+extra_tax!!
    return 70.0+((this->cc-1000.0)/100)*10+this->extra_tax();
}

void car::show()
{
    std::cout<<"\tCar-->";
    this->print_stats();
    switch(this->mode)
    {
        case Luxury::FAMILY:
         std::cout<<"   Mode:Family"<<std::endl;
          break;
        case Luxury::OVERTAX:
         std::cout<<"   Mode:OverTax"<<std::endl;
         break;
        case Luxury::PROFFESSIONAL:
         std::cout<<"   Mode:Professional"<<std::endl;
         break;
        case Luxury::SPORT:
          std::cout<<"   Mode:Sport"<<std::endl;
    }
}

Truck::Truck(std::string rn,std::string on,double c,int p,double w):Vihicle(rn,on,c),polutemode(p),weight(w) {}

double Truck::extra_tax()
{
    if(weight<100)
    {
        return this->polutemode*0.03;
    }
    else if(this->weight<500)
    {
      return this->polutemode*0.06;
    }
    else
    {
        return this->polutemode*0.09;
    }
}

double Truck::traffic_tax()const
{
    double tax=0.0;
    if(this->cc<3000.0)
    {
        tax=0.1*this->cc;
    }
    else if(this->cc<6000.0)
    {
        tax=0.08*this->cc;
    }
    else
    {
        tax=0.06*this->cc;
    }
    return this->extra_tax()+tax*Tr;
}

void Truck::show()
{
    std::cout<<"\tTruck-->";
    this->print_stats();
    std::cout<<"   Weight:"<<this->weight<<std::endl;
}

Bike::Bike(std::string rn,std::string on,double c):Vihicle(rn,on,c) {}

void Bike::show()
{
    std::cout<<"\tBike-->";
    this->print_stats();
}

double Bike::traffic_tax()
{
    return this->cc*Bk; 
}

Bike::operator std::string()
{
    std::stringstream ss;
    ss<<"Reg"<<this->reg_number<<"\tOWNER:"<<this->owner_name<<"\tCC:"<<this->cc;
    return ss.str();
}

void table_traffic_tax(std::vector <Vihicle *> &vhs)
{
    std::string header="Number";
    std::string header1="Tax";
    std::cout<<"***************************************************"<<std::endl;
    std::cout<<"|"<<header;
    int basicsize=Space-header.length()-1;
    for(int i=0;i<basicsize;i++)
    {
        std::cout<<" ";
    }
    std::cout<<"|";
    std::cout<<header1;
    basicsize=Space-header1.length()-1;
    for(int i=0;i<basicsize;i++)
    std::cout<<" ";
    std::cout<<"|";
    std::cout<<"----------------------------------------------------"<<std::endl;
    int i=1;
    for(auto &x:vhs)
    {
        std::cout<<"|"<<i;
        int size=Space-std::to_string(i).length()-1;
        for(int i=0;i<size;i++)
        {
            std::cout<<" ";
        }
        std::cout<<"|";
        std::cout<<x->traffic_tax();
        size=Space-5;
        for(int i=0;i<size;i++)
        {
            std::cout<<" ";
        }
        std::cout<<"|";
        std::cout<<"----------------------------------------------------"<<std::endl;
    }
}

void show_vihicles(std::vector <Vihicle *> &vhs)
{
    for(auto &x:vhs)
    {
        x->show();
    }
}

void memory_freed(std::vector <Vihicle *> &vhs)
{
    for(auto &x:vhs)
    {
        delete x;
        x=0;
    }
}