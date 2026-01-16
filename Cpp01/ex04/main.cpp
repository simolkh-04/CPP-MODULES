#include <iostream>
#include <fstream>
#include <string>

std::string replace(std::string content, const std::string &s1, const std::string &s2)
{
    if(s1.empty())
        return content;
    std::string result;
    size_t pos = 0; 
    size_t found;
    
    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(content, pos, std::string::npos);
    return result;
    
}

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cerr << "error .." << std::endl;
        return 1;
    }
    
    std::string filename = av[1];   
    std::string s1 = av[2];   
    std::string s2 = av[3];
    
    std::ifstream input(filename.c_str());
    if(!input.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    
    std::string content;
    std::string line;
    while(std::getline(input, line))
    {
        content += line;
        if(!input.eof())
            content = '\n';
    }
    input.close();
    std::string finalContent = replace(content, s1, s2);
    std::ofstream output((filename + ".replace").c_str());
    if(!output.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    output << finalContent;
    output.close();
    return 0;
}