/* Load required header files */
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

using namespace std;

/* Pre-processors and typedef constants */
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fo(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define MOD 1000000007

typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

/* Pre-processors for debugginf your code */
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void ZZ(const char* name, Arg1&& arg1){std::cerr << name << " = " << arg1 << endl;}
template <typename Arg1, typename... Args>void ZZ(const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr(names + 1, ',');
	std::cerr.write(names, comma - names) << " = " << arg1;
	ZZ(comma, args...);
}

/* Write the function(s) for your code problem:

return-type func_name(params) {

    // Write your code logic in this region

    return return_value;
}

*/

/* Main function */
int main(int argc, char const *argv[])
{   
    IOS;
    /* Initialize test variables and call your code function here */
    return 0;
}