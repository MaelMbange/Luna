#ifndef __COMPIL_H__
#define __COMPIL_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>
#include <unistd.h>
#include "exception.h"
#include "VariableMemory.h"
#include "Variable.h"
// #include "lmacro.h"


namespace luna
{
    class Compiler
    {
        private:
            luna::VariableMemory MesVariables;
            std::vector<std::string> trans_code;
            std::string content;
            int pos_courante;
        public:

            Compiler() = default;
            Compiler(std::string str);
            ~Compiler();

            const std::string SymboleCourant(int n);
            void SymboleSuivant(int n);

            bool Lettre();
            bool Chiffre();

            void Variable();
            void Nombre();
            void Factor();
            void MultiplicationDivision();
            void AdditionSubstraction();
            void Affectation();
            void Instruction();
            void Program(std::string str);

    };

};
#endif