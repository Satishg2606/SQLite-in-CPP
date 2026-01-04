#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include <string>
#include <sstream>
// This file will handle meta-commands and statements.
// Meta-commands will start with a dot (.) and will be handled separately.


#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef struct {
    char* buffer;
    size_t input_size;
    size_t buffer_size;
} InputBuffer;


typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
  StatementType type;
} Statement;

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

StatementType prepare_statement(InputBuffer* IB){
    if(strncmp(IB->buffer,"SELECT",6)==0){
        return STATEMENT_SELECT;
    }
    if(strncmp(IB->buffer,"INSERT",6)==0){
        return STATEMENT_INSERT;
    }
    else {
        throw "Unrecodnized Statement";
    }
}

int main(){
    while (true)
    {
        print_promt();
        InputBuffer* IB = new_input_buffer();
        getline_input(IB);
        try{
            if(IB->buffer[0] == '.'){ 
                if(strcmp(IB->buffer,".exit")==0){
                    exit(0);
                }else{
                    throw "Unrecognized Meta Command";
                }
            }
            
            switch(prepare_statement(IB)){
                case STATEMENT_SELECT :
                    std::cout<< "Executing Select statement"<<std::endl;
                    continue;
                case STATEMENT_INSERT :
                    std::cout<<"Executing Insert statement"<<std::endl;
                    continue;
                default :
                    std::cout<<"Unknown Command"<<std::endl;
            }

        }
        catch (const char* msg) {
            std::cout << "Error: " << msg << std::endl;
            continue;
        }
    }
    return 0;
}
