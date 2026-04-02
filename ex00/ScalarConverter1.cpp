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

     if ( a == 0 && arg != "0") 
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

bool isDigits(const std::string &s,int start,int end)
{
    for (size_t i = start; i < end; i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
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
    std::cout<< "int: "<< static_cast<int>(a)<<std::endl;
    std::cout<<"float: "<< static_cast<float>(d)<<"f"<<std::endl;
    std::cout<<"double: "<< d <<std::endl;
    return 1;
}


bool valid_num(const std::string& str)
{
    char delimiter = '.';
    if(std::count(str.begin(), str.end(), '.') > 1)
        return false;
    size_t dotPos = str.find(delimiter);
    std::string first = str.substr(0, dotPos);
    std::string second = str.substr(dotPos + 1, str.size() - 1);
    if(!isDigits(first,first.begin(), first.end())|| !isDigits(second,second.begin(), second.end()))//all_of c++11
        return false;
    return true;
}

void ScalarConverter::convert(const std::string& str)
{
    std::string arg = str;
    if(!isDigits(first,first.begin(), first.end())|| !isDigits(second,second.begin(), second.end()))//all_of c++11
    {
        try
        {
            int a;
            std::istringstream iss(arg);
            iss >> a;
            // a = std::stoi(arg);//c++11
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Error: Integer overflow" << std::endl;
            return;
        }
    }
    int a = std::atoi(arg.c_str());
    bool valid = valid_num(str);
    if(a < 0)
    {
        check_char(arg);
        return ;
    }
    if((arg.length() > 1 && !valid) || (std::count(arg.begin(), arg.end(), 'e') > 0 && a > 0))
    {
        std::cout << "argument is incorect"<<std::endl;
        return;
    }
    if(arg.empty())
    {
        std::cout << "argument is empty"<<std::endl;
        return;
    }
    if(check_n(arg))
        return ;
    if (std::count(arg.begin(), arg.end(), '.') > 0 ) 
    {
        if(std::count(arg.begin(), arg.end(), 'f')==1)
        {
            if(check_float(arg))
                return;
        }
        if(check_double(arg))
                return;
    }
    if(check_char(arg))
        return ;
    return ;
}





// ---problem 
// missing -42.2
// and if a number have f like 0f
// precision of a double and float
// --to fix
// A more robust way to structure the convert method is:

// Check for Pseudo-literals (nan, inf).

// Identify Type:

// Is it 1 char long and not a digit? -> Char

// Does it have an 'f' at the end? -> Float

// Does it have a '.'? -> Double

// Is it just numbers? -> Int

// Perform the Cast: Convert the string to the widest type (usually double via strtod) and then use static_cast to go to the others, checking for overflows along the way.