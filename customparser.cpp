// Complete me
#include "customparser.h"
#include <iostream>
#include <sstream>

using namespace std;

const char* error_msg_1 = "Cannot read integer n";
const char* error_msg_2 = "Error in content parsing";
const char* error_msg_3 = "Error in user parsingooooo";

// To Do - Complete this function
void CustomFormatParser::parse(std::istream& is, std::vector<Content*>& content, std::vector<User*>& users)
{
    // Erase any old contents
    content.clear();
    users.clear();
    const char* error_msg_1 = "Cannot read integer n";
    const char* error_msg_2 = "Error in content parsing";
    const char* error_msg_3 = "Error in user parsing";
    
    // TO DO - Add your code below.
    is.exceptions(ios::failbit);
    int numContent;
    try
    {
      is>>numContent;
      
    }
    catch (exception& e){
      throw ParserError(error_msg_1);
    }
    for(int c = 0; c < numContent; c++){
      try{
        
        int id;
        is>>id;
        
        int type;
        is>>type;
        
        string name;
        std::getline(is >> ws, name);
        
        int reviews;
        is>>reviews;
        
        int stars;
        is>>stars;
        
        int rating;
        is>>rating;
        
        int episodes;
        if (type==1){
          is>>episodes;
        }
        Content* newc = NULL;
            if(type == 0){
                newc = new Movie(id, name, reviews, stars, rating);
            }
            else {
                newc = new Series(id, name, reviews, stars, rating, episodes);
            }
        content.push_back(newc);
        is>>ws;
        char next =(char)is.peek();
        
        if(next >'9' || next < '0'){
          string userviews;
          getline(is>>ws, userviews);
          
          stringstream iss(userviews);
          string suser;
          while (iss>>suser){
            newc->addViewer(suser);
            
          }
        }
        
      }
      catch(exception& e){
        
        throw ParserError(error_msg_2);
      }
    }
    try{
      is>>ws;
      
      while (!(is>>ws).eof()){
        string uname;
        is>>uname;
        cout<< uname<<endl;
        int limit;
        is>>limit;
        User* newu = new User(uname, limit);
        users.push_back(newu);
        is>>ws;
        char next =(char)is.peek();
        if(!(next >'9' || next < '0')){
          string history;
          getline(is>>ws,history);
          stringstream isj(history);
          string idsviewed;
          while(isj>>idsviewed){
            newu->history.push_back(stoi(idsviewed));
          }
        }
      }
      
    }
    catch(exception& e){
      throw ParserError(error_msg_3);
    }
    
    

}