#include "matrix.hpp"

class Surfer:public matrix{
    private: 
       bool difference();
    public: 
      static int countcalls; 
      Surfer(int a);
      ~Surfer();
      std::string Random_Surfing(int visitors);
};