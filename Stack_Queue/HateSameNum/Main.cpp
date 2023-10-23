#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    answer = arr;
    return answer;
}

int main() {
    vector<int> arr1{1,1,3,3,0,1,1};
    vector<int> arr2{ 4,4,4,3,3 };

    solution(arr1);

}