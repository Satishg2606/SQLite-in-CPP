#include <iostream>
#include <string>
#include <algorithm>

struct InputBuffer {
    std::string buffer;
};

void trim(std::string& s) {
    const std::string whitespace = " \t\n\r\f\v";

    const auto start = s.find_first_not_of(whitespace);
    if (start == std::string::npos) {
        s.clear();
        return;
    }

    const auto end = s.find_last_not_of(whitespace);
    s = s.substr(start, end - start + 1);
}

void print_prompt() {
    std::cout << "db > ";
}

bool read_input(InputBuffer& input_buffer) {
    if (!std::getline(std::cin, input_buffer.buffer)) {
        return false; // EOF or error
    }
    trim(input_buffer.buffer);
    return true;
}

int main() {
    InputBuffer input_buffer;

    while (true) {
        print_prompt();

        if (!read_input(input_buffer)) {
            std::cout << "\nExiting...\n";
            break;
        }

        if (input_buffer.buffer == ".exit") {
            break;
        }

        std::cout << "Unrecognized command '"
                  << input_buffer.buffer
                  << "'\n";
    }

    return 0;
}
