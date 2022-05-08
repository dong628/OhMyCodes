#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<string, string> def;
map<string, bool> stat;
string line, name, value, res, cur;
int i, n;
bool inv(char);
bool trans(string);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d\n", &n);

	for(int csn=1; csn<=n; csn++){
		getline(cin, line);
		if(line[0]=='#' && line[1]=='d'){
			name.erase(0); value.erase(0);
			for(i=8; line[i]!=' '; i++){
				name += line[i];
			}
			for(i=i+1; i<line.size(); i++){
				value += line[i];
			}
			def[name] = value;
			stat[name] = false;
			printf("\n");
		}
		else if(line[0]=='#' && line[1]=='u'){
			name.erase(0);
			for(i=7; i<line.size(); i++){
				name += line[i];
			}
			def.erase(name);
			stat.erase(name);
			printf("\n");
		}
		else{
			cur.erase(0);
			for(int j=0; j<line.size(); j++){
				if(inv(line[j])){
					if(trans(cur)){
						line.replace(j-cur.size(), cur.size(), res);
						j -= cur.size() - res.size();
					}
					cur.erase(0);
				}
				else{
					cur += line[j];
				}
			}
			if(trans(cur)){
				line.replace(line.size()-cur.size(), cur.size(), res);
			}
			printf("%s\n", line.c_str());
		}
	}

	return 0;
}

bool inv(char xx){
	if((xx>='a'&&xx<='z')||(xx>='A'&&xx<='Z')||(xx>='0'&&xx<='9')||(xx=='_')){
		return false;
	}
	else return true;
}

bool trans(string l){
	string tres="", tcur="";
	if(stat.find(l)==stat.end() || stat[l]==true) return false;
	else{
		tres = def[l];
		stat[l] = true;
		for(int j=0; j<tres.size(); j++){
			if(inv(tres[j])){
				if(trans(tcur)){
					tres.replace(j-tcur.size(), tcur.size(), res);
					j -= tcur.size() - res.size();
				}
				tcur.erase(0);
			}
			else{
				tcur += tres[j];
			}
		}
		if(trans(tcur)){
			tres.replace(tres.size()-tcur.size(), tcur.size(), res);
		}
		res = tres;
		stat[l] = false;
		return true;
	}
}
