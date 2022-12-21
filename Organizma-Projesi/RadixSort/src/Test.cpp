#include "../include/Radix1.h"

int main(){
	// int sayilar[] = {167,232,199,356,478,551,5,101,7,490};
	int sayilar[10];
	

	for(int j = 0; j < 10; j++) {
		sayilar[j] = rand();
	}
	Radix1 *radix = new Radix1(sayilar,10);
	int *sirali = radix->Sort();

	cout<<"Siralanmadan Onceki Hali:"<<endl;
	for(int i=0;i<10;i++){
		cout<<sayilar[i]<<" ";
	}
	cout<<endl<<endl<<"Siralandiktan Sonraki Hali:"<<endl;
	for(int i=0;i<10;i++){
		cout<<sirali[i]<<" ";
	}
	
	delete [] sirali;
	delete radix;
	return 0;
}