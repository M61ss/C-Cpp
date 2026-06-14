#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        return 1;
    }

    std::string command(argv[1]);
    std::ifstream is(argv[2], std::ios::binary);
    if (!is)
    {
        return 1;
    }
    std::ofstream os(argv[3], std::ios::binary);
    if (!os)
    {
        return 1;
    }

    if (command == "-c" || command == "--compress")
    {

    }
    else if (command == "-d" || "--decompress")
    {

    }
    else if (command == "-h" || command == "--help")
    {

    }
    else
    {
        return 1;
    }

    return 0;
}