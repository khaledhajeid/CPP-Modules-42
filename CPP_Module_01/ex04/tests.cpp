#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

static std::string readFile(const std::string &path)
{
    std::ifstream file(path.c_str());
    std::string content;
    char c;

    while (file.get(c))
        content += c;
    return content;
}

static void writeFile(const std::string &path, const std::string &content)
{
    std::ofstream file(path.c_str());

    file << content;
}

static int printResult(const std::string &name, bool ok)
{
    if (ok)
    {
        std::cout << "OK   " << name << std::endl;
        return 0;
    }
    std::cout << "FAIL " << name << std::endl;
    return 1;
}

static int check(const std::string &name, const std::string &content, const std::string &s1,
    const std::string &s2, const std::string &expected)
{
    writeFile("testFiles/file", content);
    std::system("rm -f testFiles/file.replace");

    std::string command = "./sedIsForLosers testFiles/file '" + s1 + "' '" + s2 + "'";
    bool ok = std::system(command.c_str()) == 0 && readFile("testFiles/file.replace") == expected;

    return printResult(name, ok);
}

static int checkError(const std::string &name, const std::string &args)
{
    std::string command = "./sedIsForLosers " + args + " 2> /dev/null";

    return printResult(name, std::system(command.c_str()) != 0);
}

int main()
{
    int failed = 0;

    std::system("rm -rf testFiles && mkdir testFiles");

    failed += check("one match", "hello world\n", "world", "42", "hello 42\n");
    failed += check("many matches", "a b a b a\n", "a", "x", "x b x b x\n");
    failed += check("many lines", "cat\ndog\ncat\n", "cat", "bird", "bird\ndog\nbird\n");
    failed += check("no match", "hello\n", "zzz", "x", "hello\n");
    failed += check("s2 is empty", "hello world\n", " world", "", "hello\n");
    failed += check("s2 contains s1", "aa\n", "a", "aab", "aabaab\n");
    failed += check("overlapping s1", "aaa\n", "aa", "b", "ba\n");
    failed += check("s1 has a newline", "one\ntwo\n", "e\nt", "-", "on-wo\n");
    failed += check("no newline at the end", "hello", "hello", "bye", "bye");
    failed += check("empty file", "", "a", "b", "");

    writeFile("testFiles/input", "");
    failed += checkError("wrong number of args", "testFiles/input a");
    failed += checkError("empty s1", "testFiles/input '' b");
    failed += checkError("empty filename", "'' a b");
    failed += checkError("file doesn't exist", "testFiles/nothing a b");
    failed += checkError("file is a directory", "testFiles a b");

    std::system("rm -rf testFiles");

    if (failed != 0)
    {
        std::cout << failed << " test(s) failed" << std::endl;
        return 1;
    }
    std::cout << "All tests passed" << std::endl;
    return 0;
}
