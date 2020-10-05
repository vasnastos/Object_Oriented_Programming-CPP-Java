/*
Στο πρόγραμμα που αναπτύξατε για την άσκηση 2, προχωρήστε στις ακόλουθες
προσθήκες / τροποποιήσεις:
⚫ Δημιουργήστε την κλάση “Μάθημα” με τα εξής χαρακτηριστικά: Κωδικός
μαθήματος (String), Λεκτικό μαθήματος (String), Εξάμηνο μαθήματος (unsigned
int)
⚫ Εισάγετε στην κλάση “Φοιτητής”, ως χαρακτηριστικά, έναν δυναμικό πίνακα
δηλωμένων μαθημάτων1 και το πλήθος των δηλωμένων μαθημάτων. Ο πίνακας
των δηλωμένων μαθημάτων δεν έχει αντιστοιχία με τον πίνακα των
βαθμολογιών.
⚫ Προσθέστε getters και setters για τα νέα χαρακτηριστικά
⚫ Υπερφορτώστε τον τελεστή ‘+=’ ώστε να προσθέτει ένα μάθημα στον πίνακα
δηλωμένων μαθημάτων.
⚫ Υπερφορτώστε τον τελεστή εκχώρησης ώστε να… πραγματοποιεί εκχωρήσεις.
⚫ Υπεροφρτώστε τους τελεστές “==”, “!=”, “<”, “<=”, “>”, “>=”. Η σύγκριση θα
αφορά το εξάμηνο του φοιτητή.
⚫ Υπερφορτώστε ό,τι χρειάζεται, ώστε να μπορούν να τυπώνονται τα βασικά
στοιχεία ενός φοιτητή (ΑΜ, Ονοματεπώνυμο), μέσω ενός αντικειμένου της
κλάσης ostream (π.χ. cout).
⚫ Τροποποιήστε το υπόλοιπο πρόγραμμα ώστε να επιδεικνύει και τη νέα
λειτουργικότητα(10 μαθήματα για κάθε φοιτητή που εισάγεται). 
*/

#include <iostream>
#include <sstream>
#include <numeric>
#include <exception>
#include <thread>
#define SIZE 10
#include <random>

int seed()
{
    std::string time=__TIME__;
    std::stringstream ss(time);
    std::string word;
    while(std::getline(ss,word,':')) {}
    return std::stoi(word);
}

class undefiniedgrade:public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "Grade over number 10 or below number 0 detected please insert a valid number";
    }
}exc;

class lesson
{
    std::string code;
    std::string name;
    int lessonsemester;
    public:
     lesson(std::string c,std::string n,int ls):code(c),name(n),lessonsemester(ls) {}
     void setcode(std::string c) {this->code=c;}
     std::string get_code() {return this->code;}
     void set_name(std::string n) {this->name=n;}
     std::string get_name() {return this->name;}
     void set_lesson_semester(int ls) {this->lessonsemester=ls;}
     int get_lesson_semester() {return this->lessonsemester;}
     lesson &operator=(const lesson &l)
     {
         this->code=l.code;
         this->name=l.name;
         this->lessonsemester=l.lessonsemester;
         return *this;
     }
     friend std::ostream &operator<<(std::ostream &os,const lesson &s)
     {
         os<<s.code<<"-"<<s.lessonsemester<<"-"<<s.name;
         return os;
     }
};

class student
{
    private:
      std::string am;
      std::string name;
      int semester;
      int pass;
      std::vector <lesson> lessons;
      std::vector <double> grades;
    public:
      student(std::string id,std::string n,int s):am(id),name(n),semester(s),pass(0) {}
      //copy constructor
      student(const student &s):am(s.am),name(s.name),semester(s.semester),pass(s.pass),grades(s.grades) {}
      //εισαγωγή βαθμού στον πίνακα βαθμών ενός φοιτητή.
      void add_grade(double gr) {
          try
          {
              if(gr>10.0 || gr<0.0) throw exc;
              grades.push_back(gr);
          }
          catch(const std::exception& e)
          {
              std::cerr << e.what() << '\n';
          }
     }
     int getLes() {return lessons.size();}
     double find_average()
     {
        return std::accumulate(this->grades.begin(),this->grades.end(),0.0)/this->grades.size();
     }
     student &operator+=(lesson &l)
     {
         this->lessons.push_back(l);
         return *this;
     }
     void calculate_pass()
     {
         for(auto &x:grades)
         {
             if(x>=5.0)
             {
                 pass++;
             }
         }
     }
     bool operator==(const student &s)const {return this->semester==s.semester;}
     bool operator!=(const student &s)const {return this->semester!=s.semester;}
     bool operator<(const student &s)const {return this->semester<s.semester;}
     bool operator<=(const student &s)const {return this->semester<=s.semester;}
     bool operator>(const student &s)const {return this->semester>s.semester;}
     bool operator>=(const student &s)const {return this->semester>=s.semester;}
     void print_stats()
     {
         this->calculate_pass();
          std::cout<<"******************************************************************"<<std::endl;
         int i=0;
         for(auto &x:lessons)
         {
             std::cout<<x<<":"<<grades[i]<<std::endl;
             i++;
         }
         std::cout<<"************************* Average:"<<this->find_average()<<"-Pass:"<<this->pass<<" *******************"<<std::endl;
         std::cout<<std::endl;
     }
     friend std::ostream &operator<<(std::ostream &os,student &s)
     {
         os.precision(4);
         os<<"Id:"<<s.am<<"\t"<<"Name:"<<s.name<<"\t"<<"Semester:"<<s.semester;
         return os;
     }
};

void printstudents(std::vector <student> &stds)
{
    for(auto itr=stds.begin();itr!=stds.end();itr++)
    {
        std::cout<<*itr<<std::endl;
        itr->print_stats();
    }
}

int main()
{
    std::string lesson_names[SIZE]={"Ai","Programming_to_c++","Operating_systems","Parallel_Systems","Data_Stractures","Microcontrollers","Computer_Architecture","Mathematics","Java_Programming","VLSI"};
    std::string codes[SIZE]={"102","203","125","100","245","501","704","128","521","603"};
    int lesson_semester[SIZE]={4,3,4,6,3,6,7,1,5,7};
   std::mt19937 mt(seed());
   std::uniform_int_distribution <int> ids(1000,9999);
   std::uniform_int_distribution <int> nms(0,26);
   std::uniform_int_distribution <int> pss(7,40);
   std::uniform_int_distribution <int> sem(1,16);
   std::uniform_real_distribution <double> grades(0.0,10.0);
   std::vector <student> students;
   std::string id;
   std::string name;
   int semester;
   int pass;
   for(int i=0;i<SIZE;i++)
   {
      name="";
      int tempid=ids(mt);
      id=std::to_string(tempid);
      semester=sem(mt);
      for(int i=0;i<7;i++)
      {
          name+='A'+nms(mt);
      }
      student s(id,name,semester);
      for(int j=0;j<SIZE;j++)
      {
         lesson l(codes[j],lesson_names[j],lesson_semester[j]); 
         s+=l;
         s.add_grade(grades(mt));
      }
      students.push_back(s);
      std::this_thread::sleep_for(std::chrono::seconds(3));
      std::cout<<"student inserted"<<std::endl;
   }
   printstudents(students);
}