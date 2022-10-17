#include "compiler.h"

using namespace luna;

luna::Variable cible;
std::string Ligne_Affectation;
int resultat;
int nombre_courant;

Compiler::Compiler(std::string str) : content(str),pos_courante(0) {}

Compiler::~Compiler(){}

const std::string Compiler::SymboleCourant(int n)
{
    std::string rec;//s_c stands for symbole courrant
    rec = content.substr(pos_courante,n);

    return rec;
}

void Compiler::SymboleSuivant(int n)
{
    pos_courante = pos_courante + n;

    while(pos_courante < content.length() && content[pos_courante] == ' ' || content[pos_courante] == '\n')
        pos_courante++;
}
bool Compiler::Lettre()
{
    for(auto& i : "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
        if(*(char*)SymboleCourant(1).c_str() == i)
            return true;
    return false;
}

void Compiler::Variable()
{
    if(Lettre() == true)
    {
        std::string var = SymboleCourant(1);
        SymboleSuivant(1);

        while(Lettre() == true)
        {
            var.append(SymboleCourant(1));
            SymboleSuivant(1);
        }
        
        if( MesVariables.Exist(var) == false)
        {    
            MesVariables.AddToList(var);
            cible = MesVariables[var];
            
            Ligne_Affectation.append("int " + cible.getName());
            return;
        }
        cible = MesVariables[var];
        Ligne_Affectation.append(cible.getName());
    }
}

bool Compiler::Chiffre()
{
    for(auto& i : "0123456789")
        if(*(char*)SymboleCourant(1).c_str() == i)
            return true;
    return false;
}

void Compiler::Nombre()
{
    if(Chiffre() == true)
    {
        int val = std::stoi(SymboleCourant(1));
        SymboleSuivant(1);
        while(Chiffre() == true)
        {
            val = val*10 + std::stoi(SymboleCourant(1));
            SymboleSuivant(1);
        }
        //nombre_courant = val;
        Ligne_Affectation.append(std::to_string(val));
    }
}
void Compiler::Factor()
{
    if(SymboleCourant(1) == "(")
    {
        SymboleSuivant(1);
        Ligne_Affectation.append("(");
        AdditionSubstraction();

        if(SymboleCourant(1) == ")")
        {    
            SymboleSuivant(1);
            Ligne_Affectation.append(")");
        }
    }
    else if(Lettre() == true)
    {
        Variable();
    }
    else
        Nombre();

}

void Compiler::MultiplicationDivision()
{
    Factor();
    while(SymboleCourant(1) == "/" || SymboleCourant(1) == "*")
    {
        if(SymboleCourant(1) == "*")
        {
            SymboleSuivant(1);            
            Ligne_Affectation.append(" * ");
            Factor();
        }
        else if(SymboleCourant(1) == "/")
        {
            SymboleSuivant(1);            
            Ligne_Affectation.append(" / ");
            Factor();
        }
    }
}

void Compiler::AdditionSubstraction()
{
    MultiplicationDivision();
    while(SymboleCourant(1) == "+" || SymboleCourant(1) == "-")
    {
        if(SymboleCourant(1) == "+")
        {
            SymboleSuivant(1);            
            Ligne_Affectation.append(" + ");
            MultiplicationDivision();
        }
        else if(SymboleCourant(1) == "-")
        {
            SymboleSuivant(1);     
            Ligne_Affectation.append(" - ");
            MultiplicationDivision();
        }
    }
}

void Compiler::Affectation()
{
    SymboleSuivant(0);
    if(SymboleCourant(5) == "PRINT" || SymboleCourant(5) == "print")
    {
        // std::cout << "Print function1" <<std::endl;
        Ligne_Affectation.append("\n\tstd::cout << ");
        // std::cout << "Print function2" <<std::endl;
        SymboleSuivant(6);
        // std::cout << "Print function3" <<std::endl;
        if(Lettre() == true)
        {
            Variable();
            SymboleSuivant(0);
            // std::cout << "Print function4" <<std::endl;
            AdditionSubstraction();
            // std::cout << "Print function5" <<std::endl;
        }
        AdditionSubstraction();
        Ligne_Affectation.append(" << std::endl;\n");
        trans_code.push_back(Ligne_Affectation);
        return;
    }

    if(Lettre() == true)
    {
        Ligne_Affectation.append("\t");
        Variable();
        SymboleSuivant(0);
        if(SymboleCourant(1) == "=")
        {            
            SymboleSuivant(1);
            Ligne_Affectation.append(" = ");
            
            if(Lettre() == true)
            {
                Variable();
                SymboleSuivant(0);/* 
                if(SymboleCourant(1) == "+")
                    Ligne_Affectation.append(" + ");
                else if(SymboleCourant(1) == "-")
                    Ligne_Affectation.append(" - ");
                else if(SymboleCourant(1) == "*")
                    Ligne_Affectation.append(" * ");
                else if(SymboleCourant(1) == "/")
                    Ligne_Affectation.append(" / ");
                else if(SymboleCourant(1) == "(")
                    Ligne_Affectation.append(" ( ");
                else if(SymboleCourant(1) == ")")
                    Ligne_Affectation.append(" ) ");
                SymboleSuivant(1); */
                AdditionSubstraction();
            }

            AdditionSubstraction();            
            Ligne_Affectation.append(";\n");
            trans_code.push_back(Ligne_Affectation);
        }        
    }
}

void Compiler::Instruction()
{
    resultat = 0;
    Ligne_Affectation.clear();

    Affectation();
    //std::cout << "Ligne lue" << std::endl;
    while(SymboleCourant(1) == ";")
    {        
        //std::cout << "Ligne lue" << std::endl;    
        resultat = 0;
        Ligne_Affectation.clear();
        SymboleSuivant(1);
        if(SymboleCourant(4) == "STOP" || SymboleCourant(4) == "stop")
            return;
        Affectation();
    }
}

void Compiler::Program(std::string str)
{
    SymboleSuivant(0);
    if(SymboleCourant(5) == "START" || SymboleCourant(5) == "start")
    {
        SymboleSuivant(5);
        trans_code.insert(trans_code.begin(),"#include <iostream>\n\n");
        trans_code.insert(trans_code.end(),"int main(void)\n");
        trans_code.insert(trans_code.end(),"{\n");

        Instruction();
        if(SymboleCourant(4) == "STOP" || SymboleCourant(4) == "stop")
        {
            SymboleSuivant(4);
            trans_code.push_back("\n\treturn 0;\n");
            trans_code.push_back("}\n");
            /*for(auto& i : trans_code)
                std::cout << i;*/

            //PARTIE COMPILATION DU FICHIER GENERE
            std::string new_file;
            std::string sfile;/* 
            std::stringstream ss(str);
            ss.getline(new_file,100,'.ln'); */
            new_file = str;
            new_file = new_file.substr(0,(new_file.length()-3));
            sfile = new_file; 
            sfile.append(".cpp");

            // std::cout <<"str=" << str  <<"\nnew_file=" << new_file << "\nsfile=" << sfile << std::endl; 

            std::ofstream of(sfile);
            if(of.is_open() == false)
            {
                std::string error = "\033[91mCOMPILATION ERROR\033[0m: COULD NOT CREATE FILE";
                throw exception(error);
            }

            for(auto& i : trans_code)
                of << i;
            of.close();

            usleep(1000000);
            execlp("g++","g++ -o",new_file.c_str(),sfile.c_str(),NULL);
            remove(sfile.c_str());

            return;
        }
    }
    std::string error = "\033[91mCOMPILATION ERROR\033[0m: The caracter('"+SymboleCourant(1)+"') at "+ std::to_string(pos_courante+1) + " th";
    throw exception(error);
}