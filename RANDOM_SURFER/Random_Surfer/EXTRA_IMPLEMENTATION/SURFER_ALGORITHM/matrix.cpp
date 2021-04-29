#include "matrix.hpp"
#include <numeric>

//Γεννήτρια παραγωγής τυχαίων αριθμών
std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());

matrix::matrix(int number_of_rows_cols) : rows(number_of_rows_cols), cols(number_of_rows_cols)
{
    //Γέμισμα πίνακα με τυχαίες τιμές
    std::uniform_int_distribution<int> values(0, 1);
    p = new int *[number_of_rows_cols];
    for (int i = 0; i < number_of_rows_cols; i++)
    {
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

int* matrix::get(int r)
{
    //Επιστροφή μίας γραμμής του πίνακα.
    return this->p[r];
}

std::ostream &operator<<(std::ostream &os, const matrix &m)
{
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