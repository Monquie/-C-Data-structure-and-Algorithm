#include <iostream>
#include <string>
using namespace std;

// worst case scenario: Tmax = m*(n-m+1) => O(m*n)
int search(string origin, string pattern)
{
    int n = origin.length();
    int m = pattern.length();
    cout << "\nchieu dai origin " << n;
    cout << "\nchieu dai pattern " << m;

    if(m > n)
    {
        return 0;
    }
    int i = 0, j = 0;
    do{
        if (pattern[j] == origin[i]){
            i += 1;
            j += 1;
        }
        else{
            i = i - j + 1;
            j = 0;
        }
    }while((i <= n-1) && (j <= m-1));
    
    return i-m;
}

int main()
{
    string host = "Look, it is beautiful outside";
    string find = "it is";
    cout << "\n" << search(host,find);
    return 0;
}
