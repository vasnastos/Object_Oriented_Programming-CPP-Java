#include "cargo.h"
cargo::cargo(int i,QString d,double w,double p):id(i),dest(d),weight(w),price(p) {}
int cargo::get_id() {return this->id;}
QString cargo::get_destination() {return this->dest;}
double cargo::get_weight() {return this->weight;}
double cargo::get_price() {return this->price;}
QString cargo::to_String()
{
    return QString::number(this->id)+"--"+this->dest+"--"+QString::number(this->weight)+"--"+QString::number(this->price);
}
