#include<bits/stdc++.h>

using namespace std;
void Merge(vector<int>& vec, vector<int>& Tmpvec, int l, int r, int middle) {
    for(int i = l; i <= middle; i++) Tmpvec[i] = vec[i];
    for(int i = r,j = middle + 1; i > middle; i--, j++) Tmpvec[i] = vec[j];
    int left = l,right = r;
    for(int i = l; i <= r; i++) {
        vec[i] = Tmpvec[left] < Tmpvec[right] ? Tmpvec[left++] : Tmpvec[right--];
    }
}
void Merge_sort(vector<int>& vec, vector<int>& Tmpvec,int l, int r) {
    if(l < r) {
        int middle = (l + r) / 2;
        Merge_sort(vec, Tmpvec, l, middle);
        Merge_sort(vec, Tmpvec, middle + 1, r);
        Merge(vec, Tmpvec, l, r, middle);
    }
}
int main() {
    vector<int> vec(20);
    srand(time(NULL));
    for(auto &i: vec) {
        i = rand()%100;
    }
    vector<int> Tmpvec(vec);
    Merge_sort(vec,Tmpvec,0,vec.size() - 1);
    for(auto &i: vec) {
       cout << i << " " ;
    }
    cout << endl;
    return 0;
}
