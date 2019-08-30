#include <iostream>
#include <stack>

using namespace std;

/* Function to return the name of the folder in absolute path */
string getFolder(string path, int start, int length) {
    return path.substr(start, length);
}

/* Function to return simplified absolute path from the given path */
string getSimpleAbsolutePath(string path) {

    stack<string> folders;
    int it_1 = 0, it_2 = 1;
    int size = path.size();

    while (it_1 != size || it_2 != size) {

        while (it_2 != size) {
            it_2++;
            if (path[it_2] == '/' || it_2 == size) {
                break;
            }
        }

        string folder = getFolder(path, it_1 + 1, it_2 - it_1 - 1);

        if (folder == "" || folder == ".") {
            // do nothing
        } else if (folder == ".." && folders.size() == 0) {
            // do nothing
        } else if (folder == "..") {
            folders.pop();
        } else {
            folders.push(folder);
        }

        it_1 = it_2;
    }

    if (folders.empty() == true) {
        return "/";
    } else {
        string res = "";

        while (folders.empty() != true) {
            res.insert(0, "/" + folders.top());
            folders.pop();
        }

        return res;
    }
}

/* Driver to test the above code */
int main(int argc, char const *argv[])
{
    string dir = "/../";
    string simple_dir = getSimpleAbsolutePath(dir);
    
    cout << simple_dir << endl;
    
    return 0;
}