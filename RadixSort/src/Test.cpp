#include "Radix.hpp"

int main(){
	int sayilar[] = {167,232,199,356,478,551,5,101,7,490};
	Radix *radix = new Radix(sayilar,10);
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