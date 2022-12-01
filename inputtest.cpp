using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
int main(int argc, char* argv[]){

  ifstream ifile(argv[1]);
  
  if (ifile.fail()){
    return 0;
  }
  int numContent;
  ifile>>numContent;
  cout<<numContent<<endl;
  
  
      for (int i=0;i<numContent;i++){
        int id;
        ifile>>id;
        cout<<id<<endl;
        int type;
        ifile>>type;
        cout<<type<<endl;
        string name;
        std::getline(ifile >> ws, name);
        cout<<name<<endl;
        int reviews;
        ifile>>reviews;
        cout<<reviews<<endl;
        int stars;
        ifile>>stars;
        cout<<stars<<endl;
        int rating;
        ifile>>rating;
        cout<<rating<<endl;
        int episodes;
        if (type==1){
          ifile>>episodes;  
          cout<<episodes<<endl;
        }
        int num = 0;
        string names;
        ifile>>ws;
        getline(ifile, names);
        stringstream iss(names);
        string word;
        while (iss>>word){
          cout<<word<<endl;
        }
      }
      cout<<endl;
      ifile.exceptions(ios::failbit);
      ifile>>ws;
        while (ifile.peek()!=EOF){
          string uname;
          ifile>>uname;
          cout<<uname<<endl;
          int limit;
          ifile>>limit;
          cout<<limit<<endl;
          string history;
          ifile>>ws;
          getline(ifile,history);
          stringstream iss(history);
          string idsviewed;
          while(iss>>idsviewed){
            cout<<stoi(idsviewed)<<endl;
          }
        }
        return 0;

}