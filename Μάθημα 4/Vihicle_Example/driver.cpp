#include "vihicles.h"

int main()
{
    std::vector <Vihicle *> vihicles;
    vihicles.push_back(new car("AIZ2134","OWNER_1",1200.0,56,3));
    vihicles.push_back(new Truck("AGH5678","OWNER_2",4500.8,120,7400.0));
    vihicles.push_back(new Bike("ART5432","OWNER_3",150.0));
    car c("KLY7865","OWNER_4",1698.32,89,2);
    Truck t("UTR3428","OWNER_5",5678.0,94,4500);
    Bike b("GVW3478","OWNER_6",500.0);
    vihicles.push_back(&c);
    vihicles.push_back(&t);
    vihicles.push_back(&b);
    show_vihicles(vihicles);
    table_traffic_tax(vihicles);
    memory_freed(vihicles);
    return 0;
}