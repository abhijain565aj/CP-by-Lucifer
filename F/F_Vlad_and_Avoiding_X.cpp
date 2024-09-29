#include <bits/stdc++.h>

using ll = long long int;
#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
using namespace std;
struct box
{
    bool b;
    box *lu;
    box *ru;
    box *ld;
    box *rd;
    bool dig;
    int max;
    box()
    {
        lu = nullptr;
        ru = nullptr;
        ld = nullptr;
        rd = nullptr;
        b = false;
        dig = false;
        max = 0;
    }
};
int main()
{
    int testCases;
    cin >> testCases;

    fo(t, testCases)
    {
        box arr[7][7];
        int BCount = 0;
        fo(i, 7)
        {
            fo(j, 7)
            {
                char c;
                cin >> c;
                if (c == 'B')
                {
                    arr[i][j].b = true;
                    BCount++;
                }
                arr[i][j].lu = (i - 1 < 0 || j - 1 < 0) ? nullptr : &arr[i - 1][j - 1];
                arr[i][j].ru = (i - 1 < 0 || j + 1 >= 7) ? nullptr : &arr[i - 1][j + 1];
                arr[i][j].ld = (i + 1 >= 7 || j - 1 < 0) ? nullptr : &arr[i + 1][j - 1];
                arr[i][j].rd = (i + 1 >= 7 || j + 1 >= 7) ? nullptr : &arr[i + 1][j + 1];
            }
        }
        int DCount = 0;
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 6; j++)
            {
                if (arr[i][j].lu->b && arr[i][j].ru->b && arr[i][j].ld->b && arr[i][j].rd->b && arr[i][j].b)
                {
                    arr[i][j].dig = true;
                    DCount++;
                }
            }
        }
        fo(i, 7)
        {
            fo(j, 7)
            {
                if (arr[i][j].dig)
                {
                    arr[i][j].max++;
                }
                if (arr[i][j].lu && arr[i][j].lu->dig)
                {
                    arr[i][j].max++;
                }
                if (arr[i][j].ru && arr[i][j].ru->dig)
                {
                    arr[i][j].max++;
                }
                if (arr[i][j].ld && arr[i][j].ld->dig)
                {
                    arr[i][j].max++;
                }
                if (arr[i][j].rd && arr[i][j].rd->dig)
                {
                    arr[i][j].max++;
                }
            }
        }
        int ans = 0;

        while(DCount){
            int maxi,maxj;
            int max = 0;
            fo(i,7){
                fo(j,7){
                    if(arr[i][j].max > max){
                        max = arr[i][j].max;
                        maxi = i;
                        maxj = j;
                    }
                }
            }
            DCount -= arr[maxi][maxj].max;
            ans++;
            if(arr[maxi][maxj].lu && arr[maxi][maxj].lu->dig){
                arr[maxi][maxj].lu->dig = false;
                arr[maxi][maxj].max--;
                if(arr[maxi][maxj].lu->lu)arr[maxi][maxj].lu->lu->max--;
                if(arr[maxi][maxj].lu->ru)arr[maxi][maxj].lu->ru->max--;
                if(arr[maxi][maxj].lu->ld)arr[maxi][maxj].lu->ld->max--;
            }
            if(arr[maxi][maxj].ru && arr[maxi][maxj].ru->dig){
                arr[maxi][maxj].ru->dig = false;
                arr[maxi][maxj].max--;
                if(arr[maxi][maxj].ru->ru)arr[maxi][maxj].ru->ru->max--;
                if(arr[maxi][maxj].ru->lu)arr[maxi][maxj].ru->lu->max--;
                if(arr[maxi][maxj].ru->rd)arr[maxi][maxj].ru->rd->max--;
            }
            if(arr[maxi][maxj].ld && arr[maxi][maxj].ld->dig){
                arr[maxi][maxj].ld->dig = false;
                arr[maxi][maxj].max--;
                if(arr[maxi][maxj].ld->lu)arr[maxi][maxj].ld->lu->max--;
                if(arr[maxi][maxj].ld->ru)arr[maxi][maxj].ld->ru->max--;
                if(arr[maxi][maxj].ld->rd)arr[maxi][maxj].ld->rd->max--;
            }
            if(arr[maxi][maxj].rd && arr[maxi][maxj].rd->dig){
                arr[maxi][maxj].rd->dig = false;
                arr[maxi][maxj].max--;
                if(arr[maxi][maxj].rd->lu)arr[maxi][maxj].rd->lu->max--;
                if(arr[maxi][maxj].rd->ru)arr[maxi][maxj].rd->ru->max--;
                if(arr[maxi][maxj].rd->ld)arr[maxi][maxj].rd->ld->max--;
            }
        }
        cout << ans << endl;
    }
}