#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

static std::string replaceAll(const std::string &content, const std::string &s1, const std::string &s2)
{
    std::string result;
    size_t start = 0;
    size_t found = content.find(s1, start);

    while (found != std::string::npos)
    {
        result += content.substr(start, found - start);
        result += s2;
        start = found + s1.length();
        found = content.find(s1, start);
    }
    result += content.substr(start);
    return result;
}

static bool isDirectory(const std::string &path)
{
    std::ifstream dir((path + "/.").c_str());

    return dir.is_open();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (filename.empty() || s1.empty())
    {
        std::cerr << "Error: filename and s1 can't be empty" << std::endl;
        return 1;
    }
    if (isDirectory(filename))
    {
        std::cerr << "Error: " << filename << " is a directory" << std::endl;
        return 1;
    }

    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: can't open " << filename << std::endl;
        return 1;
    }

    std::string content;
    char c;
    while (infile.get(c))
        content += c;
    infile.close();

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: can't create " << filename << ".replace" << std::endl;
        return 1;
    }
    outfile << replaceAll(content, s1, s2);
    outfile.close();

    return 0;
}
