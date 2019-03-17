#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007


void compute_zarr(string s, int zarr[])
{
    uint32_t i, k, L, R, length;
    length = s.length();
    L=R=0;
    zarr[0] = length;
    for(i=1;i<length; ++i)
    {
        if(i>R)
        {
            L = R =i;
            while(R<length && s[R] == s[R-L])
                R++;
            zarr[i] = R-L;
            R--;
        }
        else {
            k = i-L;
            if(zarr[k] < R -i+ 1)
                zarr[i] = zarr[k];
            else
            {
                L=i;
                while(R<length && s[R] == s[R-L])
                   R++;
                zarr[i] = R-L;
                R--;
            }
        }
    }
}

int nCr[5009][5009];
void solvenCr()
{
    uint32_t i,j;
    for(i=1; i<= 5001; ++i)
    {
        nCr[i][1]=i;
    }
    for(i=2;i<= 5001; ++i)
    {
        for(j= 2;j< i+1; ++j)
        {
            nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%MOD;
            
        }
    }   
}

int main()
{
    uint32_t tc,k;
    solvenCr();
    cin>>tc;
    uint32_t ans[5008];
    for(k=0;k<tc;++k){
        uint32_t len,q;
        cin>>len>>q;
        string s;
        cin>>s;
        uint32_t length = s.length();
        uint32_t count[length] = {0},j;
        int i;
        for (j=0; j<length; ++j) {
            int freq[length] = {0};
            int zarr[length] = {0};
            compute_zarr(s.substr(j, length-j), zarr); 

            for(i=0;i<length; ++i)
            {
                if((zarr[i])) freq[zarr[i]-1] +=1;
            }

            for(i=length-2;i>=0; --i)
            {
                freq[i] += freq[i+1];
            }

            for(i=0;i<length; ++i)
            {
                if(freq[i]) count[freq[i]-1] +=1;
            }
        } 

        for(i=0;i<length-1; ++i)
        {
            count[i] = count[i] - count[i+1];
        }

        /*
        ans[0]=(length*(length+1)/2);
        for(i=1; i< length;++i)
        {
            ans[i] =0;
            for(j =i; j< length; ++j)
            {
                
                ans[i]=(ans[i]+((count[j])*1ll*nCr[j+1][i+1])%MOD)%MOD;
                
            }
        }
        
        while (q--)
        {
            uint32_t k;
            cin>>k;
            if (k>length) printf("0\n");
            else printf("%d\n", ans[k-1]);
        }*/
            

        for(i=0;i<q;++i)
        {
            uint32_t f;
            cin>>f;
            int l;
            uint64_t ans = 0;
            for(l=f-1;l< length; ++l)
            {
                ans = (ans%MOD + (count[l]%MOD *1ll* nCr[l+1][f])%MOD)%MOD;
            }
            cout<<ans<<endl;
        }
    }

}