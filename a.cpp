#include <iostream>

// Base case for the recursive template function
void processArgs() {
    // Empty case, do nothing
    std::cout << "1fseefSE\n";
}

// Recursive template function to process each argument
template<typename T, typename... Args>
void processArgs(const T& arg, const Args&... args) {
    // Process the current argument
    std::cout << arg << std::endl;

    // Recursively process the remaining arguments
    processArgs(args...);
}

int main() {
    processArgs(10, "Hello", 3.14, true);

    return 0;
}
