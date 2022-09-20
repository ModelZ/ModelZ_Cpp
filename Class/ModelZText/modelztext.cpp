#include "modelztext.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <filesystem>

using namespace std;

ModelZText::ModelZText(string file_name)
{
    this->file_name = file_name;
    //check file exist
    if(file_exist()){
        cerr << "Constuctor Error: File is already exist!\n";
        return;
    }

    //create and open text file
    ofstream File(file_name+".txt");
    File.close();
}

ModelZText::~ModelZText()
{

}


void ModelZText::TextRead()
{
    //check file exist
    if(!file_exist()){
        cerr << "Error: File isn't exist!\n";
        return;
    }

    string temp;
    // Read from the text file
    ifstream File(file_name+".txt",ios::out);

    // read the file line by line
    while (getline(File,temp)) {
        cout << temp<<endl;

    }
    File.close();
}

string ModelZText::TextReadReturn()
{
    //check file exist
    if(!file_exist()){
        cerr << "Error: File isn't exist!\n";
        return "";
    }

    string temp;
    // Read from the text file
    ifstream File(file_name+".txt");

    // read the file line by line
    while (getline(File,temp)) {
        cout << temp << endl;
        text += temp + "\n";
    }
    File.close();
    return text;
}

void ModelZText::TextWrite(string text)
{
    //check file exist
    if(!file_exist()){
        cerr << "Error: File isn't exist!\n";
        return;
    }

    ofstream File;
    File.open(file_name+".txt",ios::app);
    File << text <<endl;

    File.close();
}

void ModelZText::TextDelete()
{
    //check file exist
    if(!file_exist()){
        cerr << "Error: File isn't exist!\n";
        return;
    }

    ofstream File;
    File.open(file_name+".txt",ios::trunc);
    File << "";

    File.close();
}

void ModelZText::TextFileDelete()
{
    //check file exist
    if(!file_exist()){
        cerr << "Error: File isn't exist!\n";
        return;
    }

    remove((file_name+".txt").c_str());
}

bool ModelZText::file_exist()
{
    ifstream File(file_name+".txt");
    return File.good();
}

void ModelZText::TextInsertLine(string text, int line)
{
    //check file exist
    if(!file_exist()){
        cerr << "Error: File isn't exist!\n";
        return;
    }

    fstream File(file_name+".txt",ios::out|ios::app|ios::in);
    string temp;
    int i = 1;
    while(getline(File,temp)){
         if(i != line){
            this->text += temp + "\n";
        }else{
             this->text += text + "\n";
            this->text += temp + "\n";
        }
         i++;
    }
    File.close();

    this->TextFileDelete();


    //create new temp file
    ModelZText Temp(this->file_name);
    Temp.TextWrite(this->text);
    this->text = "";

}

void ModelZText::TextReplaceLine(string text, int line)
{
    //check file exist
    if(!file_exist()){
        cerr << "Error: File isn't exist!\n";
        return;
    }

    fstream File(file_name+".txt",ios::out|ios::app|ios::in);
    string temp;
    int i = 1;
    while(getline(File,temp)){
         if(i != line){
            this->text += temp + "\n";
        }else
             this->text += text + "\n";
         i++;
    }
    File.close();

    this->TextFileDelete();


    //create new temp file
    ModelZText Temp(this->file_name);
    Temp.TextWrite(this->text);
    this->text = "";

}

void ModelZText::TextDeleteLine(int line)
{
    //check file exist
    if(!file_exist()){
        cerr << "Error: File isn't exist!\n";
        return;
    }

    fstream File(file_name+".txt",ios::out|ios::app|ios::in);
    string temp;
    int i = 1;
    while(getline(File,temp)){
         if(i != line){
            this->text += temp + "\n";
        }
         i++;
    }
    File.close();

    this->TextFileDelete();


    //create new temp file
    ModelZText Temp(this->file_name);
    Temp.TextWrite(this->text);
    this->text = "";

}
