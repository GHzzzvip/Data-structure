#include<bits/stdc++.h>

using namespace std;
void heap_sort(vector<int> &vec, int i, int length) {
    int child;
    for( ; 2 * i + 1 < length; i = child) {
        child = 2 * i + 1;
        if(child + 1 < length && vec[child + 1] > vec[child]) child++;
        if(vec[child] > vec[i]) {
            swap(vec[child], vec[i]);
        } else break;
    }
}
void _heap_sort(vector<int> &vec) {
    for(int i = vec.size()/2 - 1; i >= 0; i--)
        heap_sort(vec,i,vec.size());
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[0] << endl;
        swap(vec[vec.size() - 1 - i], vec[0]);
        heap_sort(vec, 0,vec.size() - i - 1);
    }
}
int main() {
    vector<int> vec(20);
    srand(time(NULL));
    for(auto &i: vec) {
        i = rand()%100;
    }
    _heap_sort(vec); 
    for(auto i: vec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
