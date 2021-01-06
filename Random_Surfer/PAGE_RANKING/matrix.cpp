#include "matrix.hpp"
#include <cmath>
#include <numeric>

//Γεννήτρια παραγωγής τυχαίων αριθμών
std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());

bool matrix::all_visited()
{
    return std::count_if(this->visits,this->visits+this->rows,[](int a) {return a!=0;})==this->rows;
}

matrix::matrix(int number_of_rows_cols) : rows(number_of_rows_cols), cols(number_of_rows_cols)
{
    //Γέμισμα πίνακα με τυχαίες τιμές
    std::uniform_int_distribution<int> values(0, 1);
    p = new int *[number_of_rows_cols];
    //Στον πίνακα visιts θα αποθηκεύεται ο συνολικός αριθμός επισκέψεων
    //Ανα σελίδα. 
    this->visits=new int[number_of_rows_cols];
    for (int i = 0; i < number_of_rows_cols; i++)
    {
        this->visits[i]=0;
        p[i] = new int[number_of_rows_cols];
    }
    //Γέμισμα του πίνακα με τυχαίες τιμές.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            {
                //Αν η τιμές των 2 δεικτών του πίνακα είναι ίσες τότε εισάγω στον πίνακα
                //την τιμή 0.
                this->p[i][j] = 0;
                continue;
            }
            //Αλλιώς εισάγω μία ακέραια τυχαία τιμή.(0,1)
            //0-->Οι δύο κορυφές δεν συνδέονται.
            //1-->οι δύο κορυφές συνδέονται.
            this->p[i][j] = values(mt);
        }
    }
}

matrix::~matrix() {
    for(int i=0;i<this->rows;i++)
    {
        delete[] this->p[i];
    }
    delete[] this->p;
}

std::vector <int> matrix::getNeibourghs(int r)
{
    //Δεχομένη τον αριθμό μίας γραμμής η συνάρτηση θα επιστρέφει τους γείτονες 
    //της κορυφής που τα στοιχεία απόθηκεύονται στην γραμμή r.
    std::vector <int> nbs;
    for(int i=0;i<this->cols;i++)
    {
        //Μία κορυφή συνδέεται με μία άλλη αν στην συγκεκριμένη θέση του πίνακα 
        //υπάρχει η τιμή ένα(1).
        if(this->p[r][i]!=0)
        {
            nbs.push_back(i);
        }
    }
    return nbs;
}

int matrix::size()
{
    return this->rows;
}

void matrix::add_visits(int page)
{
    this->visits[page]++;
}

int* matrix::get(int r)
{
    //Επιστροφή μίας γραμμής του πίνακα.
    return this->p[r];
}

void matrix::find_rank()
{
    //Εύρεση βαθμών κορυφής.
    while(!this->rank.empty())
    {
        this->rank.pop();
    }
    const int sum=std::accumulate(this->visits,this->visits+rows,0);
     for(int i=0;i<this->rows;i++)
    {
        //Εύρεση για κάθε κορυφή του βαθμού της και εισαγωγή στην ουρά.
         this->rank.push(pagerank{i,(double)this->visits[i]/sum});
    }
}

void matrix::print_ranking()
{
    //Το ranking για την κάθε σελίδα θα αποτελεί μία μεταβλητή τύπου pagerank
    //Η μεταβλητές αυτές αποθηκεύονται σε μία ουρα προτεραιότητας
    //Η ουρα προτεραιότητας έχει το χαρακτηριστικό ότι κάτα την διάρκεια κάθε εισόδου 
    //πραγματοποιήται ταξινόμιση των στοιχείων.
    //Ουρά-->FIFO-->First in First out
    std::cout<<std::endl<<"------------------------------------------------------"<<std::endl;
    std::cout<<"\tVERTEX\tRANK"<<std::endl;
    std::cout.precision(4);
    while(!this->rank.empty())
    {
        std::cout<<"\t   "<<this->rank.top().vertex<<"\t"<<this->rank.top().rank<<std::endl;
        this->rank.pop();
    }
}

std::ostream &operator<<(std::ostream &os, const matrix &m)
{
    //std::cout<<m;-->Χρήση του υπερφορτωμένου τελεστή.
    //Εκτύπωση πίνακα γειτνίασης
    os << "\t\tAdjacency Matrix" << std::endl;
    os << "-------------------------------------------------------------" << std::endl<<std::endl;
    os<<"\t  ";
    for(int i=0;i<m.rows;i++)
    {
        os<<i+1<<"\t";
    }
    os<<std::endl;
    os<<"\t---------------------------------------------"<<std::endl;
    for (int i = 0; i < m.rows; i++)
    {
        os<<"\t"<<i+1<<"|";
        for (int j = 0; j < m.cols; j++)
        {
            os  <<m.p[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}