#include <filesystem>
#include <iostream>

int main(){
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    
    // Try to load a file and print the path
    std::string path = "../assets/rank/A.png";
    std::cout << "Trying to load: " << path << std::endl;
    
    // Check if file exists
    if (std::filesystem::exists(path)) {
        std::cout << "File exists!" << std::endl;
    } else {
        std::cout << "File does NOT exist at that path" << std::endl;
    }
    
    // rest of your code...
}
