#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

//if i find s1 in infile deleted with metedo erase
//and reemplace with s2 en taht pos metodo insert
// this for openfile

std::string openFile(std::string file, std::int32_t* error)
{
    std::ifstream in(file);
    if(!in)
    {
        std::cout << "Can not open the file\n";
        *error = 1;
    }
    std::ostringstream infile;
    infile << in.rdbuf();
    in.close();
    return infile.str(); 
}

std::int32_t compareAndReemplace(std::string infile, std::string s1, std::string s2, std::string outF)
{
    std::string content = infile;
    std::size_t pos = 0;
    
    while((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
    std::ofstream outfile(outF);
    if(!outfile)
    {
        std::cout << outF << "Error to create the " << outF << "\n";
        return -1;
    }
    outfile << content;
    outfile.close();
    return 0;
}

int main(int ac, char **av)
{
    std::int32_t error = 0;
    if (ac == 4)
    {
        std::string outF = (std::string)av[1]  + ".replace";
        if(std::filesystem::exists(outF))
        {
            std::cout << outF << " already exits\n";
            return 0;
        }
        std::string content = openFile(av[1], &error);
        if (error == 1)
            return 1;
        if (compareAndReemplace(content, av[2], av[3], outF))
            return 1;
    }
    else if (ac < 4)
        std::cout << "Missing argunments\n";
    else
        std::cout << "Too many arguments\n";
    return 0;
}