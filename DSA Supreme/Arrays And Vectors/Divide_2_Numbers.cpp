#include <iostream>
#include <vector>
using namespace std;
float divide(int ds,int dv)
{
    if(ds==0)
    {
        return -1;
    }
    int s=0,e=abs(dv);
    float ans=1;
    int mid = s+(e-s)/2;
    while(s<=e)
    {
        if(abs(mid*ds)==abs(dv))
        {
            ans = mid;
            break;
        }
        else if(abs(mid*ds)>abs(dv))
        {
            e = mid -1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
        mid=s+(e-s)/2;
    }
    for(float i=ans;abs(i*ds)<=abs(dv);i+=0.01)
    {
        ans = i;
    }
    if(dv>0&&ds>0||ds<0&&dv<0)
    {
        return ans;
    }
    return -ans;
}
int main()
{
    float ans = divide(-8,12);
    if(ans == -1)
    {
        cout << "\n\t Exception : Dividing by Zero not Allowed ";
        return 0; 
    }
    cout << "\t" << ans << endl;
    return 0;
}
