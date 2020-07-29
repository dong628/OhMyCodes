#include <cstdio>
#include <iostream>
#include <algorithm>

const int MAX=2505;
int ans, c, l;

struct Cow{
	int minspf, maxspf;
}cow[MAX];
struct Fs{
	int spf, cover;
}fs[MAX];

bool cmpc(Cow x, Cow y) { return x.minspf > y.minspf; }
bool cmpl(Fs x, Fs y) { return x.spf > y.spf; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &c, &l);
	for(int i=0; i<c; i++){
		scanf("%d %d", &cow[i].minspf, &cow[i].maxspf);
	}
	for(int i=0; i<l; i++){
		scanf("%d %d", &fs[i].spf, &fs[i].cover);
	}

	std::sort(cow, cow+c, cmpc);
	std::sort(fs, fs+l, cmpl);

	for(int i=0; i<c; i++){
		for(int j=0; j<l; j++){
			if(fs[j].spf>=cow[i].minspf && fs[j].spf<=cow[i].maxspf && fs[j].cover!=0)
				{ ans++; fs[j].cover--; break; }
		}
	}
	printf("%d", ans);
	
	return 0;
}
