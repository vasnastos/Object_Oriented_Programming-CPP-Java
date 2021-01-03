#include "Matrix.hpp"

struct navigate
{
    int id;
    std::string from;
    std::string to;
};

class Surfer:public matrix
{
    private:
      int go_to(int r);
    public:
        Surfer(int rows,int columns);
        ~Surfer();
        std::vector <navigate> random_surfer(int visitors,int iterations);
        void Page_rank();
};