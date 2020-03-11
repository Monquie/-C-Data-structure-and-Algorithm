#include <iostream>
#include <string>
#include <vector>

int contains(std::string pattern, std::string text);

int main()
{
    std::string pattern{"fuck"}, text{"justfuckingkillyourself"};
    // std::cout << "pattern is found at" << 
    int index = contains(pattern, text);
    if(index == -1)
    {
        std::cout << "pattern not found \n";
    }
    else
    {
        std::cout << "pattern is found at index: " << index << "\n";
    }
    return 0;
}

int contains(std::string pattern, std::string text)
{
    int ip,ij,it;
    int m = pattern.length();
    int n = text.length();
    std::vector<int> Next = {-1};

    //Create Next array
    ip = 0;
    ij = -1;
    while(ip <= m-1)
    {
        if(ij < 0 || pattern[ip] == pattern[ij])
        {   
            ip += 1;
            ij += 1;
            Next.push_back(ij);
        }
        else{ij = Next[ij];}
    }

    ip = 0;
    it = 0;
    while(ip <= m-1 && it <= n-1)
    {
        if(pattern[ip] == text[it])
        {
            ip += 1;
            it += 1;
        }
        else{ip = Next[ip];}
    }

    if(ip == m){return (it-ip+1);}
    else{return -1;}
}