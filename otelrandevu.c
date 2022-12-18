#include<stdio.h>
#include<string.h>
#include<ctype.h>

void anasayfa(void);//ho� geldin ve otel g�rseli (i� i�e for ile)
void hizmetSecimi(void);//switch case ile hizmet se�imi
void odaKiralama(void);//switch case ile se�enek se�me
void sikayet(void);//string kullanma �rnekleri
void senet(void);//basit matematik i�lemiyle girilen de�erin hissenin %ka�� oldu�unu bulma
void odaSecenekleri(void);//struct, strcpy ve for d�ng�s�yle tablo olu�turma
void uygunTarihler(char);//rand() fonksiyonuyla belirlenene g�re girilen tarih dolu mu bo� mu g�steriyor
void ekstraHizmet(int *);//extra hizmetleri ve gunluk fiyat�n son halini g�steriyor

int main(){
	char isim[30], hizmet;
	char dizgi[50];
	
	anasayfa();
	
	printf("merhaba  adiniz nedir?\n");
	gets(isim);
	
	sprintf(dizgi, "merhaba %s, size nasil yardimci olabilirim", isim);
	
	puts(dizgi);
	
	hizmetSecimi();
	
	return 0;
}

void anasayfa(void){
	int i, j, k = 0;
	
	printf("    _  _    _  _       *\n");
	printf("|_|| ||_   |  |_ |  |\\ | |\\ |\n");
	printf("| ||_| _|  |_]|_ |_ |/ | | \\|\n");
	
	puts("\n");
	
	for(i=0;i<3;i++){
		if(i%2==1)
		printf("  ");
		
		for(j=0;j<5;j++){
		printf("*   ");	
		}
		printf("\n");
	}
	
	printf("*   *   */ \\ *   *\n");
	printf("  *   * /   \\  *   *\n");
	printf("*   *  /otel!\\   *\n");
	printf("  *   *|  __ | *   *\n");
	printf("wwwwwww|_| |_|WwwwwwwW\n");
}

void hizmetSecimi(void){
	char hizmet;
	printf("A) oda kiralamak istiyorum\n");
	printf("B) sikayette bulunmak istiyorum\n");	
	printf("C) hisse senedi almak istiyorum\n");
	printf("istediginiz hizmetin harf kodunu giriniz\n");
	scanf(" %c", &hizmet);
	puts("--------------------------------------------------------------------");
	
	switch(hizmet){
		case 'a':
		case 'A': odaKiralama();
				  break;
		
		case 'b':
		case 'B': sikayet();
				  break;
		case 'c':
		case 'C': senet();
				  break;
		default: printf("hatali giris yaptiniz :(");
	}	
}

void odaKiralama(void){
	char secenekler;
	
	printf("\ta) oda seceneklerini gorun\n");
	printf("\tb) hangi tarihlerde oda kiralayabileceginizi gorun\n");// 2 boyutlu dizi => dizi[12][2] ay ve g�n �eklinde ve dizide aramayla bo� oda bul
	printf("\tc) ekleyebileceginiz ekstra ozellikleri gorun\n");
	printf("\tistediginiz secenegin harf kodunu giriniz\n");
	scanf(" %c", &secenekler);
	puts("--------------------------------------------------------------------");
	
	switch(secenekler){
		case 'a':
		case 'A': odaSecenekleri();
				  break;
		
		case 'b':
		case 'B': uygunTarihler('x');
				  break;
		case 'c':
		case 'C': ekstraHizmet(0);
				  break;
		default: printf("hatali giris yaptiniz :(");
	}
}

void sikayet(void){
	char katar[80];
	char cevap;
	int harf,i;
	
	printf("sikayetiniz giriniz\n");
	fflush(stdin);
	gets(katar);
	
	puts("sikayetiniz kaydedilmistir sikayetinizin tersten nasil gozuktugunu gormek ister misiniz? e/h");
	cevap=getchar();
	
	cevap=tolower(cevap);
	
	if(cevap=='e'){
		for(harf=0;katar[harf]!='\0';harf++);
	
		for(i=harf-1;i>=0;i--){
			printf("%c", katar[i]);
		}
	}
	
	if(cevap=='h')
	printf(">:-(");
}

void senet(void){
	int totalhisse=50000;
	int miktar;
	double yuzde;
	
	printf("odemeyi dusunduguz miktari girin\n");
	scanf("%d", &miktar);
	
	yuzde = miktar / (double)(totalhisse/100);
	
	printf("%d tl ile otel hissesinin %%%.2lf k�sm�n� alabilirsiniz", miktar, yuzde);
}

void odaSecenekleri(void){
	struct odalar{
		char tip[10];
		char yatak_sayisi[10];
		char oda_buyuklugu[10];
		char manzara[15];
		char fiyat[10];
	}oda[3];

	int i;
	char kr;

	strcpy(oda[0].tip, "kral");
	strcpy(oda[0].yatak_sayisi, "5 yatak");
	strcpy(oda[0].oda_buyuklugu, "kocaman");
	strcpy(oda[0].manzara, "deniz+orman");
	strcpy(oda[0].fiyat, "15.000tl");
	
	strcpy(oda[1].tip, "tekli");
	strcpy(oda[1].yatak_sayisi, "1 yatak");
	strcpy(oda[1].oda_buyuklugu, "50m2");
	strcpy(oda[1].manzara, "oyun parki");
	strcpy(oda[1].fiyat, "350tl");
	
	strcpy(oda[2].tip, "double");
	strcpy(oda[2].yatak_sayisi, "2 yatak");
	strcpy(oda[2].oda_buyuklugu, "75m2");
	strcpy(oda[2].manzara, "yok");
	strcpy(oda[2].fiyat, "500tl");
	
	for(i=0;i<3;i++){
		printf(" %-10s: \t", oda[i].tip);
		printf(" %-10s \t", oda[i].yatak_sayisi);	
		printf(" %-10s \t", oda[i].oda_buyuklugu);
		printf(" %-10s \t", oda[i].manzara);
		printf(" %-10s \t", oda[i].fiyat);
		printf("\n");
	}

	printf("almak istediginiz odanin tarihlerine bakmak icin kod giriniz\n(kral icin k tekli icin t double icin d)\n");
	scanf(" %c", &kr);
	puts("--------------------------------------------------------------------");
	uygunTarihler(tolower(kr));
}

void uygunTarihler(char oda){
	char kr, kr2, kr3;//kr oda secene�ini i�in; kr2 ekstra �zelli�e gitmek i�in; kr3 anasayfaya d�nmek i�in 
	int dizi[12][30];
	int i,j, ay, gun, hesap, *p;	
	
	p=&hesap;//ekstra hizmet fonksiyonunda hesap art�raca��m�z i�in pointer kulland�m
	
	//oda se�eneklerine bakmadan tarihlere bakmak isterse bu if kullan�lacak
	if(oda=='x'){
		printf("almak istediginiz odanin tarihlerine bakmak icin kod giriniz(kral icin k tekli icin t double icin d)\n");
		scanf(" %c", &kr);
		oda=tolower(kr);
	}

	
	
	if(oda=='k'){
		hesap=15000;
		
		for(i=0;i<12;i++){
			for(j=0;j<30;j++){
				dizi[i][j]=rand()%2;	
			}	
		}//tarihlere random 1 ve 0 atad�k 0 sa oda bo� 1 se oda dolu
		
		printf("sirasiyla bakmak istediginiz ay ve gunu girin (6 26 gibi)\n");
		scanf("%d%d", &ay,&gun);
	
		if(dizi[ay-1][gun-1]==1){
			printf("baktiginiz tarih  doludur\n");
			printf("cikmak icin enter'a  ana secenekleri gormek icin a'ya tiklayin\n");
			scanf(" %c", &kr3);
			
			if(kr3=='a')
				hizmetSecimi();
		}
		
		else{
			printf("baktiginiz tarih  uygundur\n");
			
			printf("ekstra ozelliklere bakmak ister misiniz (e/h)\n");
			scanf(" %c", &kr2);
			
			kr2=tolower(kr2);
			
				if(kr2=='e'){
					ekstraHizmet(p);
				}
				
				if(kr2=='h'){
					puts("odemeniz gereken uzret gunluk 15.000tldir\n");
				}
		}	
	}
	
	
	 if(oda=='t'){
	 	hesap=350;
	 	
		for(i=0;i<12;i++){
			for(j=0;j<30;j++){
				dizi[i][j]=rand()%2;	
			}	
		}
		
		printf("sirasiyla bakmak istediginiz ay ve gunu girin (6 26 gibi)\n");
		scanf("%d%d", &ay,&gun);
	
		if(dizi[ay-1][gun-1]==1){
			printf("baktiginiz tarih  doludur\n");
		}
		
		else{
			printf("baktiginiz tarih  uygundur\n");
			
			printf("ekstra ozelliklere bakmak ister misiniz (e/h)\n");
			scanf(" %c", &kr2);
			
			kr2=tolower(kr2);
			
			if(kr2=='e'){
				ekstraHizmet(p);
			}
			
			if(kr2=='h'){
				puts("odemeniz gereken uzret gunluk 350tldir\n");
			}			
		}
	}
	
	
	if(oda=='d'){
		hesap=500;
		
		for(i=0;i<12;i++){
			for(j=0;j<30;j++){
				dizi[i][j]=rand()%2;	
			}	
		}
		
		printf("sirasiyla bakmak istediginiz ay ve gunu girin (6 26 gibi)\n");
		scanf("%d%d", &ay,&gun);
	
		if(dizi[ay-1][gun-1]==1){
			printf("baktiginiz tarih  doludur\n");
		}
		
		else{
			printf("baktiginiz tarih  uygundur\n");
		
			printf("ekstra ozelliklere bakmak ister misiniz (e/h)\n");
			scanf(" %c", &kr2);
			
			kr2=tolower(kr2);
			
			if(kr2=='e'){
				ekstraHizmet(p);
			}
			
			if(kr2=='h'){
				puts("odemeniz gereken uzret gunluk 500tldir\n");
			}

			}	
		}
	
	puts("--------------------------------------------------------------------\n");
}

void ekstraHizmet(int *p){
	char secenek[5], c;
	int i=0;
	
	printf("a)acik bufe kahvalt� gunluk +90tl\n");
	printf("b)cocuklar icin oyun park� gunluk+45tl\n");
	printf("c)terapi seanslari gunluk(bi saat)+500tl\n");
	printf("eklemek istedigiz �zelliklerin harf kodlarini girin ve . koyun\n");
	
	while((c=getchar())!='.'){
		secenek[i++]=c;
	}

	secenek[i]='\0';
	
	for(i=0;i<3;i++){
		if(secenek[i]=='a'){
			*p=*p+90;
		}
		if(secenek[i]=='b'){
			*p=*p+45;
		}		
		if(secenek[i]=='c'){
			*p=*p+500;
		}		
	}
	
	printf("odemeniz gereken gunluk ucret %d tldir\n", *p);
}









