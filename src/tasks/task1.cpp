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


typedef struct {
    char* buffer;
    size_t input_size;
    size_t buffer_size;
} InputBuffer;

InputBuffer* new_input_buffer(){
    InputBuffer* IB = new InputBuffer();
    IB->buffer = nullptr;
    IB->input_size = 0;
    IB->buffer_size = 0;
    return IB;
}

void trim(std::string& s) {
    const char* spaces = " \t\n\r\f\v";

    s.erase(0, s.find_first_not_of(spaces));   // leading
    s.erase(s.find_last_not_of(spaces) + 1);   // trailing
}

void print_promt(){
    std::cout<<"db > ";
}

void getline_input(InputBuffer* IB){
    std::string line;
    std::getline(std::cin, line);
    trim(line);
    IB->buffer = new char[line.length() + 1];
    std::strcpy(IB->buffer, line.c_str());
    IB->input_size = line.length();
}


int main(){
    while (true)
    {
        print_promt();
        InputBuffer* IB = new_input_buffer();
        getline_input(IB);
        // IB->buffer = ;
        if(std::strcmp(IB->buffer, ".exit") == 0){
            delete IB;
            exit(0);
        }else{
            std::cout<<"Unrecognized command '"<<IB->buffer<<"'"<<std::endl;
        }
    }
    return 0;
}
