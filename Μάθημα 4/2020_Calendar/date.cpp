/*
Ο κατασκευαστής date2020(int d) θα δέχεται τιμές από το 1 μέχρι και το 366 και θα θέτει την ημερομηνία ως την ημερομηνία d μέρες από την έναρξη του έτους 2020.
string get_day_name();
H συνάρτηση get_day_name() θα επιστρέφει το όνομα της ημέρας στο οποίο αντιστοιχεί η ημερομηνία.
void print(); (έχει ήδη υλοποιηθεί)
Η συνάρτηση print() θα εκτυπώνει την ημερομηνία όπως στο παράδειγμα που ακολουθεί: 15 March 2020 - (Sunday - 75).
int get_days_in_year(); (έχει ήδη υλοποιηθεί)
Η συνάρτηση get_days_in_year() θα επιστρέφει το πλήθος των ημερών από την αρχή τους έτους στο οποίο αντιστοιχεί η ημερομηνία.
Εκτελέστε το πρόγραμμα οδηγό main.cpp και καταγράψτε την έξοδό του σε ένα αρχείο με όνομα main.out.
Εκτελέστε τα unit tests που περιέχονται στο tests.cpp
*/


#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

const std::string months[12]={"Junuary","February","March","April","May","June","July","August","September","Octomber","November","December"};
const std::string day_name[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int startdate=3;
const int days_per_month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

class date
{
   private:
     int day;
     int month;
     int year;
   public:
     date():day(-1),month(-1),year(-1) {}
     date(int d,int m)
     {
         if(d<=0 || d>days_per_month[m-1])
         {
             this->day=-1;
             this->month=-1;
             this->year=-1;
             return;
         }
         if(m<=0 || m>12)
         {
             this->day=-1;
             this->month=-1;
             this->year=-1;
             return;
         }
         this->day=d;
         this->month=m;
         this->year=2020;
     }
     date(int d)
     {
        if(d<0 || d>366)
        {
            this->day=-1;
            this->month=-1;
            this->year=-1;
            return;
        }
         this->year=2020;
         int countmonths=1;
         int countdays=0;
         int counter=1;
         int index=0;
         for(int i=1;i<=d;i++)
         {
             if(counter==days_per_month[index])
             {
                index++;
                counter=1;
                countmonths++;
                continue;
             }
             counter++;
         }
         countdays=counter;
         this->day=countdays;
         this->month=countmonths;
     }
     int get_days_in_year()
     {
         int days=0;
         const int until=this->month-1;
         for(int i=0;i<until;i++)
         {
             days+=days_per_month[i];
         }
         days+=this->day;
         return days;
     }
     std::string get_day_name()
     {
         
        const int index=(startdate+this->get_days_in_year())%7; 
         return day_name[index];
     }
     void print()
     {
         if(this->month==-1)
         {
             std::cout<<"";
             return;
         }
         std::cout<<"\t"<<this->day<<"/"<<this->month<<"/"<<this->year<<"-->"<<this->get_day_name()<<","<<this->get_days_in_year()<<std::endl;
     }

    operator std::string(){
        std::stringstream ss;
        if(this->month==-1)
        {
            ss<<"ERROR!!!";
        }
        else
        ss<<this->day<<"/"<<months[this->month-1]<<"/"<<this->year<<"-->"<<this->get_day_name()<<","<<this->get_days_in_year();
        return ss.str();
    }

     void plus_days(int days)
     {
         int ind=this->month-1;
         for(int i=1;i<=days;i++)
         {
             if(this->day==days_per_month[ind])
             {
                 this->day=1;
                 this->month++;
                 ind++;
                 continue;
             }
             this->day++;
             if(ind==12)
             {
                 this->day=-1;
                 this->month=-1;
                 this->year=-1;
                 return;
             }
         }
     }
};

void save_to_file(std::vector <date> &dates)
{
    std::fstream os;
    os.open("output.out",std::ios::out);
    for(auto &x:dates)
    {
        os<<std::string(x)<<std::endl;
    }
    os.close();
}