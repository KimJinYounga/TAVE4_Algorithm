#include <iostream>
#include <stdio.h>
#include <algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

typedef struct {char str[51];}length;

bool compare(length a, length b) {
    if (strlen(a.str) == strlen(b.str))
    {
        for (int i = 0; i < strlen(a.str); i++)
        {
            if (a.str[i] != b.str[i])
                return a.str[i] < b.str[i];
        }        
        return false;
    }
    else
        return strlen(a.str) < strlen(b.str);
}

int main (void){

	length word[20001];
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>word[i].str;
	}

	sort(word, word+n, compare);
	
	for(int i=0;i<n;i++){
		cout<<word[i].str<<" ";
	}

	return 0;
} 
