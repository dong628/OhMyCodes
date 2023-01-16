vector<string> words, a[28], curr;
string lst;
const char hintStr[] = ".SG";
const int pwLen = 243;
int hintStrR[255];
const char *bests[] = {
    "slier", "lares", "lares", "tores", "tarns", "arles", "lares", "lares", "snare",
    "ousel", "ranis", "nares", "tares", "aides", "tries", "lares", "raise", "aides",
    "plate", "nares", "snare", "riles", "nares", "cones", "kanes", "aeons",
};

string GetOp(string right, string guess) {
  static int buk[28];
  memset(buk, 0, sizeof buk);
  string op(5, hintStr[0]);
  rep (i, 0, 5 - 1)
    if (right[i] == guess[i])
      op[i] = hintStr[2];
    else
      ++buk[right[i] - 'a'];
  rep (i, 0, 5 - 1)
    if (op[i] != hintStr[2] && buk[guess[i] - 'a']) op[i] = hintStr[1];
  return op;
}

inline double GetE(const string &s) {
  static int mp[250];
  memset(mp, 0, sizeof(int) * pwLen);
  each (x, curr) {
    string op = GetOp(x, s);
    int res = 0;
    rep (i, 0, 5 - 1)
      res *= 3, res += hintStrR[(int)op[i]];
    ++mp[res];
  }
  double e = 0;
  rep (i, 0, pwLen) {
    if (!mp[i]) continue;
    double p = 1.0 * mp[i] / curr.size();
    e += p * log2(1.0 / p);
  }
  return e;
}

inline string GetBest() {
  if (curr.empty()) {
    // 该分支不可能被进入
    return "test";
  }
  double mxCurr = -1, mxWords = -1;
  int idCurr = -1, idWords = -1;
  rep (i, 0, curr.size() - 1) {
    double res = GetE(curr[i]);
    if (res > mxCurr) idCurr = i, mxCurr = res;
  }
  rep (i, 0, words.size() - 1) {
    double res = GetE(words[i]);
    if (res > mxWords) idWords = i, mxWords = res;
  }
  if (GetE(curr[idCurr]) > GetE(words[idWords]) - 0.01)
    return curr[idCurr];
  else
    return words[idWords];
}

bool Ck(string x, bool *g, bool *s) {
  string op = GetOp(x, lst);
  rep (i, 0, 5 - 1)
    if (op[i] == hintStr[0] && (g[i] || s[i]))
      return 0;
    else if (op[i] == hintStr[1] && !s[i])
      return 0;
    else if (op[i] == hintStr[2] && !g[i])
      return 0;
  return 1;
}

vector<string> GetFilter(bool *g, bool *s) {
  vector<string> ans;
  each (x, curr) {
    if (Ck(x, g, s)) ans.push_back(x);
  }
  return ans;
}

const char *guess(int num_testcase, int remaining_guesses, char initial_letter, bool *gold,
                  bool *silver) {
  int c = initial_letter - 'a';
  if (remaining_guesses == 5) {
    curr = a[c];
    lst = bests[c];
    return lst.c_str();
  }
  curr = GetFilter(gold, silver);
  return (lst = GetBest()).c_str();
}

void init(int num_scramble, const char *scramble) {
  rep (i, 0, 2)
    hintStrR[(int)hintStr[i]] = i;
  rep (i, 0, num_scramble - 1) {
    string s;
    rep (j, 0, 4)
      s.push_back(scramble[i * 5 + j]);
    words.push_back(s);
  }
  each (x, words)
    a[x[0] - 'a'].push_back(x);
}
