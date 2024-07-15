#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include "code_scanner.h"
#include "asm_generator.h"


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "CodeGenerator: No json path." << std::endl;
        return -1;
    }

    // Get Json data.
    nlohmann::json jsonData;
    std::ifstream jsonFile(argv[1]);
    jsonFile >> jsonData;
    jsonFile.close();

    // Scan parse tree to check sementic.
    CodeScanner codeScanner;
    const ProgramSummary* programSummary = codeScanner.scan(jsonData);
    if (programSummary->hasError)
    {
        std::cerr << "CodeGenerator: Failed to generate asm file" << std::endl;
        exit(1);
    }

    // Generate assembly code.
    AsmGenerator asmGenerator;
    asmGenerator.generateCode(programSummary);
    if (asmGenerator.hasError())
    {
        std::cerr << "CodeGenerator: Failed to generate asm file" << std::endl;
        exit(1);
    }

    std::cout << "CodeGenerator: Asm file is written completely." << std::endl;

    return 0;
}