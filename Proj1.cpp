/*
 * Name        : Project 1
 * Author      : Hunter Lupton
 * Description : Reads card number and verifies where card is from.
 *With assistance from: Juan
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <string>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;



int main(){
    // String variables to hold card numbers
    string l_number, Temp_line;
    //array
    char l_array[16];
    
    stringstream bb;
    
    //Input stream declaration
    ifstream fin("Credit_Numbers.txt");
    
    ofstream fout("Credit_numout");
    //checks to make sure both files open
    if (fin.fail() || fout.fail()) {
        cerr << "There was a problem opening/creating one of the files.\nPlease fix before continuing.\n";
        exit(1);
    }
    
    while(!fin.eof()){
        getline(fin, Temp_line);
        cout << "Your card # is: " << Temp_line << endl;
        
        if (Temp_line.at(0) == '4'){
            cout << "This is a Visa" << endl;
        }
        else if (Temp_line.at(0) == '3'){
            if (Temp_line.at(1) == '4' || Temp_line.at(1) == '7'){
                cout <<"This is an American express." << endl;
            }else cout << "Unknown number." << endl;
        }
        else if (Temp_line.at(0) == '5'){
            if(Temp_line.at(1) == '1'|| Temp_line.at(1) == '2' || Temp_line.at(1) == '3' || Temp_line.at(1) == '4' || Temp_line.at(1) == '5'){
                cout << "This is a Master Card" << endl;
            }else cout << "Unknown number." << endl;
        }//part B
        
    }// done with file(close files)
    fin.close();
    fout.close();
    if (!fin.is_open()){
        cout << "File has closed." << endl;
    }
    
    
    
    
}
