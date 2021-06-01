#include <iostream>
#include <vector>
#include <regex>
#include <windows.h>
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

      int startswith(const std::string &reg)
      {
         int equality;
         const int regexsize=reg.length();
         std::vector <std::string> regexmatch;
         for(auto &x:this->words)
         {
             equality=0;
             if(x.length()<regexsize) {continue;}
             for(int i=0;i<regexsize;i++)
             {
                if(x.at(i)==reg.at(i))
                {
                    equality++;
                }
             }
             if(equality==reg.size())
             {
                regexmatch.push_back(x);
             }
         }
         std::cout<<"#### Total Words found starting with "<<reg<<":"<<regexmatch.size()<<" ####"<<std::endl;
         std::cout<<"Words found at:"<<__TIME__<<"--"<<__DATE__<<std::endl;
         std::cout<<hr()<<std::endl;
         char answer;
         std::cout<<"Show Words(y/Y-YES,n/No-NO):";
         std::cin>>answer;
         if(std::tolower(answer=='y'))
         {
             std::cout<<"****** \t\tWords starts with "<<reg<<" ******"<<std::endl;
             for(auto &y:regexmatch)
             {
                 std::cout<<"\t"<<y<<std::endl;
             }
         }
         system("pause");
         return regexmatch.size();
      }

      int startswithregexmode(const std::string &reg)
      {
          std::string regularexpression=reg+"([^])*";
          std::regex r(regularexpression);
          std::vector <std::string> regexwords;
          for(auto &x:this->words)
          {
              if(std::regex_match(x,r))
              {
                 regexwords.push_back(x);
              }
          }
          std::cout<<"##### Total words starting with "<<reg<<":"<<regexwords.size()<<" ####"<<std::endl;
          std::cout<<"Data obtained at "<<__DATE__<<"--"<<__TIME__<<std::endl;
          std::cout<<hr()<<std::endl;
          char answer;
          std::cout<<"Show Words(y/Y-YES,n/N-No):";
          std::cin>>answer;
          if(std::tolower(answer)=='y')
          {
              std::cout<<"Words starts with "<<reg<<std::endl;
              for(auto &y:regexwords)
              {
                  std::cout<<"\t"<<y<<std::endl;
              }
          }
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

void resultSet(int first)
{
    std::cout<<std::endl<<"========================================="<<std::endl;
    std::cout<<"\tWords Starts with Test(am prefix):"<<first<<std::endl;
    std::cout<<"========================================="<<std::endl;
}

int main(int argc,char **argv)
{
   Lexicon l(argument_file(argc,argv));
   int startswith=l.startswith("am");
   std::cout<<"Words starting with [sta] using regex prefix recognition:"<<l.startswithregexmode("sta")<<std::endl;
   std::cout<<l<<std::endl;
   resultSet(startswith);
   return 0;
}