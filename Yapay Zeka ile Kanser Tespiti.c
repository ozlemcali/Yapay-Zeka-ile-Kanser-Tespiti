#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int kullanicigirisihesapla(int diziegitim[600][10]);
int sonucbul(int diziegitim[600][10],int dizitest[83][10]);

int main() 
{
	
	FILE* dosya;
	FILE* dosya2;
	int i;
	int istenilen;
	int a;
	int diziegitim[600][10];
	int dizitest[83][10];
	int sayi1,sayi2,sayi3,sayi4,sayi5,sayi6,sayi7,sayi8,sayi9,sayi10;
	int sayi11,sayi12,sayi13,sayi14,sayi15,sayi16,sayi17,sayi18,sayi19,sayi20;
	

fopen_s(&dosya, "egitim.txt", "r");


for(i=0;i<600;i++) {

fscanf_s(dosya,"%*d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&sayi1,&sayi2,&sayi3,&sayi4,&sayi5,&sayi6,&sayi7,&sayi8,&sayi9,&sayi10);

diziegitim[i][0]=sayi1;
diziegitim[i][1]=sayi2;
diziegitim[i][1]=sayi2;
diziegitim[i][2]=sayi3;
diziegitim[i][3]=sayi4;
diziegitim[i][4]=sayi5;
diziegitim[i][5]=sayi6;
diziegitim[i][6]=sayi7;
diziegitim[i][7]=sayi8;
diziegitim[i][8]=sayi9;
diziegitim[i][9]=sayi10;


}
fclose(dosya);
fopen_s(&dosya2,"test.txt","r");
for(a=0;a<83;a++) {

fscanf_s(dosya,"%*d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&sayi11,&sayi12,&sayi13,&sayi14,&sayi15,&sayi16,&sayi17,&sayi18,&sayi19,&sayi20);

dizitest[a][0]=sayi11;
dizitest[a][1]=sayi12;
dizitest[a][2]=sayi13;
dizitest[a][3]=sayi14;
dizitest[a][4]=sayi15;
dizitest[a][5]=sayi16;
dizitest[a][6]=sayi17;
dizitest[a][7]=sayi18;
dizitest[a][8]=sayi19;
dizitest[a][9]=sayi20;

}


fclose(dosya2);

home:
printf("Test dosyasindaki verileri hesaplamak icin 1 , Kullanicidan parametre alip verileri hesaplamak icin 2 giriniz:");
scanf_s("%d",&istenilen);
if(istenilen==1){ 

sonucbul(diziegitim,dizitest);

}

else if(istenilen==2){

kullanicigirisihesapla(diziegitim);
}
else {
	printf("HATALI GÝRÝÞ TEKRAR GÝRÝN:");
 goto home;
}

return 0;
}
 
int sonucbul(int diziegitim[600][10],int dizitest[83][10]) {
	int x,i,j;
	int m;
	int z;
	int sonuc=0,hastalikdegeri,enkucuk,gecicibellek,gecicibellek2;
	int hasta;
	int hastadegil;
	int dizitestsonucu[600][2];
	int dizitestsonucuDY[6];
	 char dizitestsonucuDYsay[83];
	int k=5;
	float dogrusayisi=0;
	float yanlissayisi=0;

 for(x=0;x<83;x++)
	{
		for (j=0;j<600;j++)
		{
			sonuc=0;
			for(z=0;z<9;z++)
			{
				int diff = (diziegitim[j][z]-dizitest[x][z]);

				sonuc=sonuc+ diff * diff;

			dizitestsonucu [j][0]=sonuc;
			} 

			hastalikdegeri=diziegitim[j][9]; 
			dizitestsonucu[j][1]=hastalikdegeri;
		}
	

 for (i = 0; i < 599; i++)
{
enkucuk= i;
for (j = i + 1; j < 600; j++){

if (dizitestsonucu[j][0] <dizitestsonucu[enkucuk][0])

	enkucuk= j;
}
gecicibellek=dizitestsonucu [enkucuk][0];
dizitestsonucu[enkucuk][0] = dizitestsonucu[i][0];
dizitestsonucu[i][0] = gecicibellek;

gecicibellek=dizitestsonucu [enkucuk][1];
dizitestsonucu[enkucuk][1] = dizitestsonucu[i][1];
dizitestsonucu[i][1] = gecicibellek;

}

 hasta=0;
 hastadegil=0;
	 for (i=0;i<k;i++)
	 {
		 gecicibellek2=dizitestsonucu[i][1];
		  if (gecicibellek2==2) {
			  hastadegil++;
		  }
		  else { 
			  hasta++;
		  }
	 }

	 printf("\n%d.test verisi sonuclari: hasta:%d,hasta degil:%d\n\n",x+1,hasta,hastadegil);

	 if (hastadegil>hasta) { 
		 dizitestsonucuDY[i]=2;
	 }
	 else  {
		 dizitestsonucuDY[i]=4; 
	 }
	 
	 if (dizitestsonucuDY[i]==dizitest[x][9])  {
		 dizitestsonucuDYsay[x]='D';
	 }

	 else  {
		 dizitestsonucuDYsay[x]='Y';
	 }

}

 
for(m=0;m<83;m++) 
{
	printf("%d.veri== %c\n",m+1,dizitestsonucuDYsay[m]);
	if (dizitestsonucuDYsay[m]=='D') {
		dogrusayisi++;
	}
	else  { 
		yanlissayisi++;
	}
}

printf("\n DOÐRU SAYISI:%f\n YANLIÞ SAYISI:%f\n",dogrusayisi,yanlissayisi);

printf("BAÞARI ORANI YÜZDE:%.3f\n",((dogrusayisi*100)/83));
getchar();
getchar();
return 0;
}


int kullanicigirisihesapla(int diziegitim[600][10])
{
	int dizikullanicigirisi[9];
	int dizikullanicigirisiuzaklik[600][2];
int gecicibellek,gecicibellek2,sonuc,hastalikdegeri,i,j,enkucuk;
int k=5,hasta=0,hastadegil=0;
int z;


for(i=0;i<9;i++){
	printf("%d.degeri giriniz:",i+1);
	scanf_s("%d",&gecicibellek);
	dizikullanicigirisi[i]=gecicibellek;
}

for (j=0;j<600;j++) {
	
	sonuc=0;
	for(z=0;z<9;z++) {
		int diff = (diziegitim[j][z]-dizikullanicigirisi[z]);

				sonuc=sonuc+ diff * diff;
				hastalikdegeri=diziegitim[j][9];

			dizikullanicigirisiuzaklik[j][0]=sonuc;
			dizikullanicigirisiuzaklik[j][1]=hastalikdegeri;
	}
}
	for (i=0;i<599;i++) {
		enkucuk=i;
		for(j=i+1;j<600;j++)
		{
			if   (dizikullanicigirisiuzaklik[j][0]<dizikullanicigirisiuzaklik[enkucuk][0])
				enkucuk=j;
		
        gecicibellek=dizikullanicigirisiuzaklik[enkucuk][0];
		dizikullanicigirisiuzaklik[enkucuk][0]=dizikullanicigirisiuzaklik[i][0];
        dizikullanicigirisiuzaklik[i][0]=gecicibellek;

		gecicibellek=dizikullanicigirisiuzaklik[enkucuk][1];
		dizikullanicigirisiuzaklik[enkucuk][1]=dizikullanicigirisiuzaklik[i][1];
        dizikullanicigirisiuzaklik[i][1]=gecicibellek;
		}
	}

	for(i=0;i<k;i++) {
		gecicibellek2=dizikullanicigirisiuzaklik[i][1];
		if(gecicibellek2==2) {
			hastadegil++;
		}
		else {
			hasta++;
		}
	}

	if(hastadegil>hasta){ 
		printf("\n HASTA DEGÝLSÝNÝZ");
	}
	else {
		printf("\n HASTASÝNÝZ");
	}

	getchar();
	getchar();
	return 0;
}