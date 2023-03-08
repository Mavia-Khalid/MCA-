#include <iostream>
#include <vector>
#include<set>
#include<algorithm>
using namespace std;  
int main()
{
    vector<int> A{1,5,10,20,20,40,80,80};
    vector<int> B{6,7,20,20,80,80,100};
    vector<int> C{3,4,15,20,20,30,70,80,80,120};
    set<int> ans;                                   // Used to Store Unique Elements Only
    int i=0,j=0,k=0;
    cout << ans.size() << endl;
    while(i < A.size() && j < B.size() && k < C.size())
    {
        if(A[i] == B[j] && B[j]== C[k])
        {
            ans.insert(A[i]);                       // Insert is Used instead of pushback
            i++;
            j++;
            k++;
        }
        else if(A[i] < B[j])
        {
            i++;
        }
        else if(B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    cout << ans.size() << endl;
    for(int i:ans)
    {
        cout << i << " ";
    }
    cout << endl << endl;
    return 0;
}