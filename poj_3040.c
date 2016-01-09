#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct data{
        int value;
        int number;
        bool operator<(const data &b){
                return value>b.value;
        }
};
int main()
{
        int n,c;
        cin>>n>>c;
        vector<data> allow(n);
        for(int i=0;i<n;++i)
        {
                data d;
                cin>>d.value>>d.number;
                allow[i]=d;
        }
        int weeks=0;
        for(int i=0;i<allow.size();++i)
        {
                if(allow[i].value>=c)
                {
                        weeks=weeks+allow[i].number;
                        allow[i].number=0;
                }
        }
        sort(allow.begin(),allow.end());
        while(true)
        {
                /*from the big*/
                int sum=c;
                for(int i=0;i<allow.size();++i)
                {
                        if(allow[i].number==0)continue;
                        int can_use=min(allow[i].number,sum/allow[i].value);
                        if(can_use<=0)
                        {
                                break;
                        }
                        sum-=can_use*allow[i].value;
                        allow[i].number-=can_use;
                }
                for(int i=allow.size();i>=0;++i)
                {
                        if(allow[i].number==0)continue;
                        int can_use=min(allow[i].number,sum/allow[i].value);
                        sum-=can_use*allow[i].value;
                        allow[i].number-=can_use;
                        if(can_use<=0)
                        {
                                weeks++;
                                allow[i].number--;
                                break;
                        }
                }

        }
        cout<<weeks<<endl;


}
~

