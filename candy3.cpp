#include <iostream>
using namespace std;

long long int m=1000000000;

int main() {
	long long int t;
	cin>>t;
	while(t--){
		long long int n,s=0;
		cin>>n;
		for(long long int i=0;i<n;i++){
			long long int a;
			cin>>a;
			s=(s%m + a%m)%m;
		}
		if(s%n==0){
			cout<<"YES"<< endl;
		}else{
			cout<<"NO"<< endl;
		}
	}
	
	return 0;
}
