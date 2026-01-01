#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>   
#include <string>
#include <sstream>

// We need to store the user input in a buffer.
// We need an infinite loop to keep the shell running. 
// Get the user input using getline function.
// Check if the input is a meta-command (== .exit).-> if yes, then exit the program.

struct {
    char* buffer;
    size_t capacity;
    size_t size;
}IB;


void print_promt(){
    std::cout<<"db > ";
}

void getline_input(){
    std::string line;
    std::getline(std::cin, line);
    IB.buffer = new char[line.length() + 1];
    std::strcpy(IB.buffer, line.c_str());
    IB.size = line.length();
}


int main(){
    while (true)
    {
        print_promt();
        getline_input();
        if(std::strcmp(IB.buffer, ".exit") == 0){
            exit(0);
        }
    }
    
}
