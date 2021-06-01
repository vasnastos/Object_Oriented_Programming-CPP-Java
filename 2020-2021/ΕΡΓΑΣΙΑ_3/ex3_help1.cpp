#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


std::string hr()
{
    return "#################################################################\n";
}


class Lexicon
{
   private:
      std::vector <std::string> words;
      std::string filename;
    public:
      Lexicon(std::string fn):filename(fn)
      {
         std::fstream fs;
         fs.open(this->filename,std::ios::in);
         if(!fs.is_open())
         {
             std::cerr<<"Error on opening file ::"<<this->filename<<std::endl;
             return;
         }
         std::string line;
         while(std::getline(fs,line))
         {
            this->words.push_back(line);
         }
         fs.close();
      }

      void Open(std::string file)
      {
          this->words.clear();
          std::fstream fs;
          std::string line;
          fs.open(file,std::ios::in);
          if(!fs.is_open())
          {
             std::cerr<<"Error on opening file: "<<file<<std::endl;
             return;
          }
          this->filename=file;
          while(std::getline(fs,line))
          {
              this->words.push_back(line);
          }
          fs.close();
      }

      friend std::ostream &operator<<(std::ostream &os,const Lexicon &l)
      {
          os<<"Words from document:"<<l.filename<<std::endl;
          os<<"Operation executed at:"<<__TIME__<<"--"<<__DATE__<<std::endl;
          os<<hr()<<std::endl;
          for(auto &x:l.words)
          {
             os<<x<<std::endl;
          }
          return os;
      }
};

std::string argument_file(int argc,char **argv)
{
    if(argc!=2)
    {
        std::cerr<<"Invalid number of arguments!!!please try a.exe filename.(*)"<<std::endl;
        return "";
    }
    return argv[argc-1];
}

int main(int argc,char **argv)
{
   Lexicon l(argument_file(argc,argv));
   std::cout<<l<<std::endl;
}