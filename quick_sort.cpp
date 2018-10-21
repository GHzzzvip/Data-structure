#include<bits/stdc++.h>

using namespace std;
void quicksort(vector<int >& vec, int l, int r) {
    if(l >= r ) return ;
    int key = vec[l];
    int left = l, right = r;
    while(left < right) {
        while(vec[right] >= key && left < right) right--;
        swap(vec[left], vec[right] );
        while(vec[left] <= key && left < right) left++;
        swap(vec[left], vec[right]);
    }
    vec[left] = key;
    quicksort(vec, l, left - 1);
    quicksort(vec, left + 1, r);
}
int main() {
    vector<int> vec(20);
    srand(time(NULL));
    for(auto &i: vec) {
        i = rand()%100;
    }

    quicksort(vec, 0, vec.size() - 1);
    for(auto &i: vec) {
       cout << i << " " ;
    }
    cout << endl;
    return 0;
}
