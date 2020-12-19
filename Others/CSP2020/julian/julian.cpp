#include <cstdio>
#include <iostream>

long long q, r, day, month, year;
const int months[15]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int monthr[15]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//const int julian=2297591;
const int julian=2299162;
int Month(), Monthr();

int main(){
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);

	scanf("%lld", &q);
	for(int asdf=0; asdf<q; asdf++){
		scanf("%lld", &r);
		r++;
		if(r<julian){
			year=(r/1461)*4;
			r%=1461;
			if(r<=59){
				month=r>31?2:1;
				day=r>31?r-31:r;
			}
			else{
				if(r<=366){
					month=Monthr();
					day=r;
				}
				else{
					year+=(r-366)/365+1;
					r-=366; r%=365;
					month=Month();
					day=r;
				}
			}
			if(year<4713)
				if(day==0 && month==1)
					printf("31 12 %lld BC\n", 4713-year+1);
				else
					printf("%lld %lld %lld BC\n", day, month, 4713-year);
			else  
				if(day==0 && month==1)
					printf("31 12 %lld\n", year-4713);
				else
					printf("%lld %lld %lld\n", day, month, year-4713+1);
		}
		else{
			r-=julian;
			year=1582;
			if(r<=77){
				if(r<=16){ month=10; day=15+r; }
				else if(r<=46){ month=11; day=r-16; }
				else { month=12; day=r-46; }
			}
			else {
				r-=77;
				if(r<=365){
					year++;
					Month();
					day=r;
				}
				else{
					r-=365; year=1584;
					if(r<=5844) {
						year+=(r/1461)*4;
						r%=1461;
						if(r<=366){
							month=Monthr();
							day=r;
						}
						else {
							r-=366; year++;
							year+=r/365;
							r%=365;
							month=Month();
							day=r;
						}
					}
					else{
						r-=5844; year=1600;
						year+=(r/146097)*400;
						r%=146097;
						if(r<=36525){
							year+=(r/1461)*4;
							r%=1461;
							if(r<=366){ month=Monthr(); day=r; }
							else {
								r-=366; year++;
								year+=r/365; r%=365;
								month=Month(); day=r;
							}
						}
						else{
							r-=36525; year+=100;
							year+=(r/36524)*100;
							r%=36524;
							if(r<=1460){
								year+=r/365;
								r%=365;
								month=Month();
								day=r;
							}
							else{
								r-=1460; year+=4;
								year+=(r/1461)*4;
								r%=1461;
								if(r<=366) { month=Monthr(); day=r; }
								else{
									r-=366; year++;
									year+=r/365;
									r%=365;
									month=Month();
									day=r;
								}
							}
						}
					}
				}
			}
			if(day==0 && month==1)
				printf("31 12 %lld\n", year-1);
			else
				printf("%lld %lld %lld\n", day, month, year);
		}
//		printf("%d %d %d\n", day, month, year);
	}

	return 0;
}

int Month(){
	int i;
	for(i=0; i<12; i++){
		if(r>months[i]) r-=months[i];
		else break;
	}
	return i+1;
}
int Monthr(){
	int i;
	for(i=0; i<12; i++){
		if(r>monthr[i]) r-=monthr[i];
		else break;
	}
	return i+1;
}
/*
int Month(int x){
	if(0<x && x<=31) return 1;
	if(31<x && x<=59) return 2;
	if(59<x && x<=90) return 3;
	if(90<x && x<=120) return 4;
	if(120<x && x<=151) return 5;
	if(151<x && x<=181) return 6;
	if(181<x && x<=212) return 7;
	if(212<x && x<=243) return 8;
	if(243<x && x<=273) return 9;
	if(273<x && x<=304) return 10;
	if(304<x && x<=334) return 11;
	if(334<x && x<=365) return 12;
	if(0<x && x<=31) return 1;
}
int Monthr(int x){
	if(0<x && x<=31) return 1;
	if(31<x && x<=60) return 2;
	if(60<x && x<=91) return 3;
	if(91<x && x<=121) return 4;
	if(121<x && x<=152) return 5;
	if(152<x && x<=182) return 6;
	if(182<x && x<=213) return 7;
	if(213<x && x<=244) return 8;
	if(244<x && x<=274) return 9;
	if(274<x && x<=305) return 10;
	if(305<x && x<=335) return 11;
	if(335<x && x<=366) return 12;
	if(0<x && x<=31) return 1;
}*/
