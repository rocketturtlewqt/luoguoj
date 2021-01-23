#include<bits/stdc++.h>
using namespace std;
int main(){
	for(int T=1;T<=50;T++){
		system("E:\\C\\luoguoj\\duipai\\random.exe");
		double st=clock();
		system("E:\\C\\luoguoj\\duipai\\1102.exe");
		double ed=clock();
		system("E:\\C\\luoguoj\\duipai\\1102tijie.exe");
		if(system("fc E:\\C\\luoguoj\\duipai\\data.out E:\\C\\luoguoj\\duipai\\data.ans")){
			puts("Wrong Answer");
			return 0;
		}
		else{
			printf("Accepted, ²âÊÔµã #%d, ÓÃÊ± %.2fms\n",T,ed-st);
		}
	}
}
