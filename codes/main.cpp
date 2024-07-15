#include <iostream>
#include <fstream>
#include <string>

const std::string PARSE_TREE_BUILDER_PATH = ".\\parse_tree_builder\\parse_tree_builder.exe";
const std::string CODE_GENERATOR_PATH = ".\\code_generator\\x64\\Debug\\code_generator.exe";
const std::string PARSE_TREE_NAME = ".\\parse_tree.json";
const std::string ASM_NAME = ".\\out.asm";

bool fileExists(const std::string fileName)
{
    std::fstream parseTreeFile(PARSE_TREE_NAME);
    bool fileExists = parseTreeFile.good();
    parseTreeFile.close();
    return fileExists;
}

int main(int argc, char **argv)
{
    // Check arguments.
    if (argc < 2)
    {
        std::cerr << "My_Compiler error: Please input the path of the C program file." << std::endl;
        return -1;
    }

    // Build parse tree.
    system((PARSE_TREE_BUILDER_PATH + " " + argv[1]).c_str());

    // Generate assembly code with parse tree.
    if (fileExists(PARSE_TREE_NAME))
    {
        system((CODE_GENERATOR_PATH + " " + PARSE_TREE_NAME).c_str());
    }
    else
    {
        std::cerr << "My_Compiler error: Can't find the parse tree." << std::endl;
        return -1;
    }

    // Print message.
    if (fileExists(ASM_NAME))
    {
        std::cout << "My_Compiler: Success!" << std::endl;
    }
    else
    {
        std::cerr << "My_Compiler error: Can't find the asm file." << std::endl;
    }

    return 0;
}