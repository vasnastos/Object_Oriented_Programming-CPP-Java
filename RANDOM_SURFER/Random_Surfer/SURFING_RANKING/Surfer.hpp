#include "Matrix.hpp"
class Surfer:public matrix
{
    private:
      int go_to(int r);
    public:
        Surfer(int rows,int columns);
        ~Surfer();
        void random_surfer();
        void Page_rank();
};