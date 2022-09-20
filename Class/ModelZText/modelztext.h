#ifndef TEXTSAVER_H
#define TEXTSAVER_H

#include <iostream>
#include <string>
using namespace std;

class ModelZText
{
private:
    string text;
    string file_name;


public:
    ModelZText(string file_name = "noname"); //Constructor
    ~ModelZText(); //Destructor

    //User Method
    void TextRead(); //Read text file
    string TextReadReturn();// Read text file and return data in text
    void TextWrite(string text); //Write data in text file can append text
    void TextDelete(); //Delete all data in text
    void TextFileDelete(); //Delete Text File
    bool file_exist();
    void TextInsertLine(string text,int line); //Insert data at specific line
    void TextReplaceLine(string text,int line); //Replace data at specific line
    void TextDeleteLine(int line); //Delete data at specific line

};

#endif // TEXTSAVER_H
