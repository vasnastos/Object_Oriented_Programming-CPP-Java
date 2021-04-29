#include <iostream>

struct pagerank
{
    int vertex;
    double rank;
    //Για να μπορέσω να εισάγω τα στοιχεία σε ουρά προτεραιότητας θα χρειαστώ 
    //και υπερφόρτωση του τελεστή <.
    bool operator<(const pagerank &p)const {return this->rank<p.rank;}
};