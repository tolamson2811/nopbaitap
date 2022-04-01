#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    int x = n / 2;
    n = x * 2;
    vector<vector<string>> arr(n + 1);
    arr[0] = {};
    arr[2] = {"()"};
    for(int i = 4; i <= n; i += 2) {
        for(auto str : arr[i - 2]) {
            arr[i].push_back("(" + str + ")");
        }
        for(int j = 2; j <= i; j += 2) {
            for(auto str1 : arr[j]) {
                for(auto str2 : arr[i - j]) {
                    arr[i].push_back(str1 + str2);
                }
            }
        }
    }
    for(int i = 2; i <= n; i += 2) {
        cout << arr[i][0] << endl;
        for(int j = 1; j < arr[i].size(); j++) {
            if(arr[i][j] != arr[i][j - 1]) cout << arr[i][j] << endl;
        }
    }
    return 0;
}