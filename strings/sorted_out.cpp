#include <iostream>
#include <string>

using namespace std;
/*
    Helper function to find the string of numbers is sorted in descending,
    ascending or not sorted.
    ASC = 0
    DSC = 1
    NOT_SORTED = -1 
*/
int checkOrder(string str) {
    int i = 0;
    for (i = 0; i < str.size() - 1; i++) {
    
        if(str[i] <= str[i+1]) {
            continue;
        } else {
            break;
        }
    
    }

    if (i == str.size() - 1 && str[i - 1] <= str[i]) {
        return 0;
    }

    for (i = 0; i < str.size() - 1; i++) {
    
        if(str[i] >= str[i+1]) {
            continue;
        } else {
            break;
        }
    
    }

    if (i == str.size() - 1 && str[i - 1] >= str[i]) {
        return 1;
    } else {
        return -1;
    }
}

/*
    Helper function to find the longest and the one starting in the lower
    index, either sorted in ascending order or descending order
*/
string findLongestSortedArr(string A) {

    string tmp;
    string asc;
    string dsc;
    int f_asc = 0, f_dsc = 0;
    int x = 0;

    for (int i = 0; i < A.size() - 1; i++) {

        if (A[i] <= A[i+1]) {
            tmp.insert(tmp.end(), A[i]);
        } else {
            
            if (tmp.length() > asc.length()) {

                tmp.insert(tmp.end(), A[i]);
                asc.assign(tmp.begin(), tmp.end());
                tmp.clear();
                f_asc = x;

            }
  
            x = i + 1;
  
        }

    }

    for (int i = 0; i < A.size() - 1; i++) {

        if (A[i] <= A[i+1]) {
            tmp.insert(tmp.end(), A[i]);
        } else {
            
            if (tmp.length() > dsc.length()) {

                tmp.insert(tmp.end(), A[i]);
                dsc.assign(tmp.begin(), tmp.end());
                tmp.clear();
                f_dsc = x;

            }
  
            x = i + 1;
  
        }

    }

    if (asc.length() > dsc.length()) {
        return asc;
    } else if (asc.length() < dsc.length()) {
        return dsc;
    } else {

        if (f_asc < f_dsc) {
            return asc;
        } else {
            return dsc;
        }

    }

}

/*
    Function takes a string of digits as input and outputs the following:
    if Ascending or Descending:
        output the largest digit followed by smallest digit
    else :
        output the longest sorted array with smaller starting index
*/
string sortedOP(string A) {

    string out_str;
    int check_sorted = checkOrder(A);

    if (check_sorted == 0) {
    
        out_str += A[A.size() - 1];
        out_str += A[0];
    
    } else if (check_sorted == 1) {
    
        out_str += A[0];
        out_str += A[A.size() - 1];
    
    } else {
        
        string out = findLongestSortedArr(A);
        out_str.assign(out.begin(), out.end());
    }   

    return out_str;

}

/*
    Driver function to test the above function
*/
int main(int argc, char const *argv[])
{
    string test = "54312334556";
    cout << sortedOP(test) << endl;   
    return 0;
}