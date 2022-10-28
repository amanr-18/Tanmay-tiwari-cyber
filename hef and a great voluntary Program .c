#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
	    string s;
	    cin >> s;
	    int x, y;
	    cin >> x >> y;
	    int numApples, numBanana;
	    numApples = numBanana = 0;
	    int slen = s.length();
	    
	    for(int i = 0; i < slen; i++)
	    {
	        if(s[i] == 'a')
	        {
	            numApples++;
	        }
	        else
	        {
	            numBanana++;
	        }
	    }
	    
	    int aStride = ceil(double(numApples)/ x);
	    int bStride = ceil(double(numBanana) / y);
	    if(aStride > bStride)
	    {
	        int bQuot = numBanana / (aStride - 1);
	        int bRem = numBanana % (aStride - 1);
	        int resLen = numApples;
	        if(numBanana < aStride - 1)
	        {
	            resLen += aStride - 1;
	        }
	        else
	        {
	            resLen += numBanana;
	        }
	        
	        string res;
	        res.resize(resLen);
	        
	        int i = 0;
	        while(i < resLen)
	        {
	            for(int j = 0; j < x && numApples != 0; j++)
	            {
	                res[i] = 'a';
	                numApples--;
	                i++;
	            }
	            if(i < resLen)
	            {
	                if(numBanana > 0)
	                {
	                    int l = bQuot + ((bRem) ? 1 : 0);
	                    for(int j = 0; j < l && numBanana != 0; j++)
	                    {
	                        res[i] = 'b';
	                        numBanana--;
	                        i++;
	                    }
	                    if(bRem)
	                    {
	                        bRem--;
	                    }
	                }
	                else
	                {
	                    res[i] = '*';
	                    i++;
	                }
	                
	            }
	        }
	        
	        cout << res << "\n";
	        
	    }
	    else if(bStride > aStride)
	    {
	        int aQuot = numApples / (bStride - 1);
	        int aRem = numApples % (bStride -1);
	        int resLen = numBanana;
	        if(numApples < bStride - 1)
	        {
	            resLen += bStride - 1;
	        }
	        else
	        {
	            resLen += numApples;
	        }
	        
	        string res;
	        res.resize(resLen);
	        
	        int i = 0;
	        while(i < resLen)
	        {
	            for(int j = 0; j < y && numBanana != 0; j++)
	            {
	                res[i] = 'b';
	                numBanana--;
	                i++;
	            }
	            if(i < resLen)
	            {
	                if(numApples > 0)
	                {
	                    int l = aQuot + ((aRem) ? 1: 0);
	                    for(int j = 0; j < l && numApples != 0; j++)
	                    {
	                        res[i] = 'a';
	                        numApples--;
	                        i++;
	                    }
	                    if(aRem)
	                    {
	                        aRem--;
	                    }
	                }
	                else
	                {
	                    res[i] = '*';
	                    i++;
	                }
	                
	            }
	        }
	        
	        cout << res << "\n";
	    }
	    else
	    {
	        int resLen = numApples + numBanana;
	        int i = 0;
	        string res;
	        res.resize(resLen);
	        while(i < resLen)
	        {
	            for(int j = 0; j < x && numApples != 0; j=j+1)
	            {
	                res[i] = 'a';
	                numApples--;
	                i++;
	            }
	            for(int j = 0; j < y && numBanana != 0; j++)
	            {
	                res[i] = 'b';
	                numBanana--;
	                i=i+1;
	                
	            }
	        }
	   cout << res << endl;
 }
	}
	
}
