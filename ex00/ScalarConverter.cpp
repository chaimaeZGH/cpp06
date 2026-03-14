#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    static_cast<void>(other);
}
ScalarConverter &ScalarConverter ::operator=(const ScalarConverter &other)
{
    static_cast<void>(other);
    return *this;
}
ScalarConverter::~ScalarConverter()
{}

int check_n(std::string& arg)
{
    if (arg == "nan" || arg == "nanf") 
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<< "int: impossible"<<std::endl;
        std::cout<<"float: nanf"<<std::endl;
        std::cout<<"double: nan"<<std::endl;
        return 1;
    }
    else if (arg == "+inf" || arg == "+inff") 
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<< "int: impossible"<<std::endl;
        std::cout<<"float: +inff"<<std::endl;
        std::cout<<"double: +inf"<<std::endl;
        return 1;
    }
    else if (arg == "-inf" || arg == "-inff") 
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<< "int: impossible"<<std::endl;
        std::cout<<"float: -inff"<<std::endl;
        std::cout<<"double: -inf"<<std::endl;
        return 1;
    }
    return 0;
}


int check_char(std::string& arg)
{
    int a = std::atoi(arg.c_str());
    if (arg.length())
    {
        if (!std::isdigit(arg[0])) 
        {
            std::cout<<"char: "<< static_cast<char>(arg[0]) <<std::endl;
            std::cout<< "int: "<< static_cast<int>(arg[0])<<std::endl;
            std::cout<<"float: "<< static_cast<float>(arg[0])<<".0f"<<std::endl;
            std::cout<<"double: "<< static_cast<double>(arg[0])<<".0"<<std::endl;
            return 1;
        }
        if(std::isdigit(arg[0]))
        {
            std::cout<<"char: "<< "Non displayable" <<std::endl;
            std::cout<< "int: "<< static_cast<int>(a)<<std::endl;
            std::cout<<"float: "<< static_cast<float>(a)<<".0f"<<std::endl;
            std::cout<<"double: "<< static_cast<double>(a)<<".0"<<std::endl;
        }
        return 1;
    }
    return 0;
}

// int check_float(std::string& arg)
// {
//     // chack for .
//     // then if its not at the last and only one point and whatever right or left is number
//     // chack for f at the end
// }

void ScalarConverter::convert(const std::string& str)
{
    std::string arg = str;
    if(arg.empty())
    {
        std::cout << "argument is empty"<<std::endl;
        return;
    }
    if(check_n(arg))
        return;
    if(check_char(arg))
        return;
    // if(chack_float(arg))
    //     return;
    return;
}