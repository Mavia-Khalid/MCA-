 #include<bits/stdc++.h>
using namespace std;
int lcs(string a,string b,int c, int d)
{
    if(c==0||d==0)
    {
        return 0;
    }
    if(a[c-1]==b[d-1])
    {
        return 1+lcs(a,b,c-1,d-1);
    }
    else
    {
        return max(lcs(a,b,c,d-1),lcs(a,b,c-1,d));
    }
}
int main()
{
    string s1,s2;
    int size1,size2;
    cout<<"\t Enter First String : ";
    cin>>s1;
    cout<<"\t Enter Second String : ";
    cin>>s2;
    size1=s1.length();
    size2=s2.length();
    int ans=lcs(s1,s2,size1,size2);
    cout<<endl<<"\t Length of Longest Common Subsequence is : "<<ans;
    return 0;
}
