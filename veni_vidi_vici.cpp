#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int n;
	char buf[11000];
	cin >> n;
	getchar();
	//cin.getline(buf, 11000);
	fgets(buf, 11000, stdin);
	int len = strlen(buf);
	for (int i=0;i<len;i+=2) {
		char a=buf[i],b = buf[i+1];
		if(a==' '){
			printf(" ");
			i++;
			a = buf[i];
			b = buf[i+1];
		}
	    //cout << b;	
		if('a'<=b && b<='z') {
            char temp = (a-'a')+(b-'a')-n;
            if(temp <0) temp += 26;
			printf("%c", ((temp)%26)+'a');
		}
		else if(b==' '){
			printf(" ");
		}
		
	}
	cout << endl;
	
	return 0;
}


