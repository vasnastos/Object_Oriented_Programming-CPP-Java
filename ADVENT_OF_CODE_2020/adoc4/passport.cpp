#include "passport.hpp"
passport()
{
    for(int i=0;i<sizeof(codes)/sizeof(codes[0]);i++)
    {
        checksums.insert(std::make_pair(codes[i],"-"));
    }
}

void passport::adddata(std::string id,std::string value)
{
   this->checksums[id]=value;
}

bool passport::validance()
{
    for(std::map <std::string,std::string>::iterator i=this->checksum.begin();i!=this->checksum.end();i++)
    {
       if(i->first=='-')
       {
           return false;
       }
       if(i->second=="-" && i->first)
    }
}