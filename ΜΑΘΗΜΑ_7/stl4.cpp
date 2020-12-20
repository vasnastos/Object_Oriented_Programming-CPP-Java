/*
  A. Κατασκευάστε μια templated συνάρτηση που να δέχεται ένα διάνυσμα std::vector και να
επιστρέφει τις δύο μεγαλύτερες τιμές του διανύσματος. Να κληθεί η συνάρτηση:
1. Για ένα διάνυσμα ακεραίων.
2. Για ένα διάνυσμα με αντικείμενα student (σπουδαστής) όπου κάθε student διαθέτει
το πεδίο name (όνομα) και το πεδίο grade (βαθμός). Η σύγκριση των σπουδαστών να
γίνει με υπερφόρτωση του τελεστή >.
B. Να εμφανιστούν τα αποτελέσματα. Για την περίπτωση των αντικειμένων student να
υπερφορτωθεί ο τελεστής <<
*/

#include <iostream>
#include <queue>
#include <random>
#include <algorithm>

class point
{
    private:
        int x;
        int y;
    public:
      point():x(rand()%120),y(rand()%60) {}
      ~point() {}
      bool operator==(const point &p)
      {
          return this->x==p.x && this->y==p.y;
      }
      point &operator=(const point &p)
      {
          this->x=p.x;
          this->y=p.y;
          return *this;
      }
      bool operator<(const point &p)const{
          return this->x<p.x && this->y<p.y;
      }
      friend std::ostream &operator<<(std::ostream &os,const point &p)
      {
          return os<<"("<<p.x<<","<<p.y<<")";
      }
};

template <class T>int occurences(std::vector <T> &m)
{  
    std::priority_queue <T> pq;
    std::for_each(m.begin(),m.end(),[&pq](T a) {pq.push(a);});
    T topelem=pq.top();
    return std::count_if(m.begin(),m.end(),[topelem](T &a) {return a==topelem;});
}

int main(int argc,char **argv)
{
    if(argc<2)
    {
        std::cerr<<"Seed did not provided"<<std::endl;
        return 1;
    }
    srand(atoll(argv[1]));
    std::mt19937 mt(atoll(argv[1]));
    std::uniform_real_distribution <double> d(0,300.0);
    std::vector <int> v1;
    std::vector <double> v2;
    std::vector <point> v3;
    for(int i=0;i<=10;i++)
    {
        v1.push_back(rand()%200);
        v2.push_back(d(mt));
        v3.push_back(point());
    }
    std::cout<<"Max occurences v1:"<<occurences(v1)<<std::endl;
    std::cout<<"Max occurences v2:"<<occurences(v2)<<std::endl;
    std::cout<<"Max occurences v3:"<<occurences(v3)<<std::endl;
    return 0;
}