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

     if (arg.length() == 1 && !std::isdigit(arg[0]))
        {
            std::cout<<"char: "<< static_cast<char>(arg[0]) <<std::endl;
            std::cout<< "int: "<< static_cast<int>(arg[0])<<std::endl;
            std::cout<<"float: "<< static_cast<float>(arg[0])<<".0f"<<std::endl;
            std::cout<<"double: "<< static_cast<double>(arg[0])<<".0"<<std::endl;
            return 1;
        }
        if(a < 32 || a > 126)
        {
            std::cout<<"char: "<< "Non displayable" <<std::endl;
            std::cout<< "int: "<< static_cast<int>(a)<<std::endl;
            std::cout<<"float: "<< static_cast<float>(a)<<".0f"<<std::endl;
            std::cout<<"double: "<< static_cast<double>(a)<<".0"<<std::endl;
            return 1;
        }
        else
        {
            std::cout<<"char: "<< static_cast<char>(a) <<std::endl;
            std::cout<< "int: "<< static_cast<int>(a)<<std::endl;
            std::cout<<"float: "<< static_cast<float>(a)<<".0f"<<std::endl;
            std::cout<<"double: "<< static_cast<double>(a)<<".0"<<std::endl;
            return 1;
        }
    return 0;
}

int check_float(std::string& arg)
{
    float f = static_cast<float>(std::strtod(arg.c_str(), NULL));
    int a = std::atoi(arg.c_str());
    if(a > 126 || a < 32)
        std::cout<<"char: "<< "Non displayable" <<std::endl;
    else
        std::cout<<"char: "<< static_cast<char>(a) <<std::endl;
    if(f > 2147483647 || f < -2147483648)
        std::cout<< "int: "<< "overflow"<<std::endl;
    else
        std::cout<< "int: "<< static_cast<int>(a)<<std::endl;
    std::cout<<"float: "<< f << "f"<<std::endl;
    std::cout<<"double: "<< static_cast<double>(f) <<std::endl;
    return 1;
}

int check_double(std::string& arg)
{
    double d = std::strtod(arg.c_str(), NULL);
    int a = std::atoi(arg.c_str());
    if(a > 126 || a < 32)
        std::cout<<"char: "<< "Non displayable" <<std::endl;
    else
        std::cout<<"char: "<< static_cast<char>(a) <<std::endl;
    if(d > 2147483647 || d < -2147483648)
        std::cout<< "int: "<< "overflow"<<std::endl;
    else
        std::cout<< "int: "<< static_cast<int>(a)<<std::endl;
    std::cout<<"float: "<< static_cast<float>(d)<<"f"<<std::endl;
    std::cout<<"double: "<< d <<std::endl;
    return 1;
}

bool isDigits(const std::string& s, size_t start, size_t end)
{
    for (size_t i = start; i < end && i < s.length(); ++i) 
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

bool isNumber(const std::string arg)
{
    if (arg.empty())
        return true;
    size_t start = 0;
    if (arg[0] == '+' || arg[0] == '-')
        start = 1;
    if (start == arg.size())
        return true;
    return isDigits(arg, 0+ start, arg.length());
}

void ScalarConverter::convert(const std::string& str)
{
    std::string arg = str;
    if(check_n(arg))
        return ;
    if(arg.length() == 1 && !isdigit(arg[0]))
    {
        if(check_char(arg))
            return ;
    }
    if (std::count(arg.begin(), arg.end(), '.') == 1 || std::count(arg.begin(), arg.end(), 'f') == 1 ) 
    {
        char delimiter = '.';
        if (arg.back() == 'f' )
        {
            if(std::count(arg.begin(), arg.end(), '.') == 1)
            {
                size_t dotPos = arg.find(delimiter);
                std::string first = arg.substr(0, dotPos);
                std::string second = arg.substr(dotPos + 1, arg.size() - dotPos - 2);
                if((first.empty() && second.empty()) ||(first.size()==1 && !isdigit(first[0])&& second.empty()) )
                {
                    std::cout << "invalid arg" << std::endl;
                    return ;
                }
                if (!isNumber(first)||
                    !isDigits(second, 0, second.length()))
                    return;
                if (check_float(arg))
                    return;
            }
            if (check_float(arg))
                return;
        }
        size_t dotPos = arg.find(delimiter);
        std::string first = arg.substr(0, dotPos);
        std::string second = arg.substr(dotPos + 1);
        if((first.empty() && second.empty()) ||(first.size()==1 && !isdigit(first[0])&& second.empty()) )
        {
            std::cout << "invalid arg" << std::endl;
            return ;
        }
        if (!isNumber(first)|| 
            !isDigits(second, 0, second.length()))
        {     
            std::cout << "invalid arg" << std::endl;   
            return ;
        }
        if(check_double(arg))
            return;
    }
    if( isNumber(arg))
    {
        try
        {
            int a;
            std::istringstream iss(arg);
            iss >> a;
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Error: Integer overflow" << std::endl;
            return;
        }
        if(check_char(arg))
        return ;
    }
    else
    {
        std::cout << "invalid arg" << std::endl;
        return ;
    }
}
