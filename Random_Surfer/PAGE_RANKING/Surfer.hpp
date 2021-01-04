#include "matrix.hpp"

class Surfer:public matrix{
    public:  
      Surfer(int a);
      ~Surfer();
      void Random_Surfing(int visitors,int iters);
};