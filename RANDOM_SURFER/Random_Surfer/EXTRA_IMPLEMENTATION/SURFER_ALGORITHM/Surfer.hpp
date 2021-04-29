#include "matrix.hpp"

class Surfer:public matrix{
    public:
      static std::string info;  
      Surfer(int a);
      ~Surfer();
      void Random_Surfing(int visitors,int iters);
      void save_to_file();
};