#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 2000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
string s[MAXN];

bool check(string& str) {
  set<char> seen;
  char prev = 0;
  for(int i = 0; i < str.length(); i++) {
    if(str[i] == prev) continue;
    if(seen.count(str[i])) return false;

    seen.insert(str[i]);
    prev = str[i];
  }
  return true;
}

string result;

bool solve(string res, set<int> used) {
  // cerr << res << endl;
  if(used.size() == n) {
    if(check(res)) { result = res; return true; }
    else return false;
  }
  for(int i = 0; i < n; i++) {
    if(used.count(i)) continue;
    used.insert(i);
    if(solve(res + s[i], used)) {
      return true;
    }
    used.erase(i);
  }
  return false;
}

bool solveHard() {
  vector<vector<int>> mids(26), lefts(26), rights(26), sames(26);
  set<int> isSame;

  for(int i = 0; i < n; i++) {
    bool fst = true; char prev = s[i].front();
    for(int j = 0; j < s[i].length(); j++) {
      if(s[i][j] == prev) continue;

      if(!fst && j != s[i].length() - 1) {
        mids[prev - 'A'].push_back(i);
      }
      prev = s[i][j];
      fst = false;
    }
    if(fst) { // all same letter
      isSame.insert(i);
      sames[s[i].front() - 'A'].push_back(i);
    } else {
      lefts[s[i].front() - 'A'].push_back(i);
      rights[s[i].back() - 'A'].push_back(i);
    }
  }

  // for(int i = 0; i < 26; i++) {
  //   cerr << char('A' + i) << " " << lefts[i].size() << " " << mids[i].size() << " " << sames[i].size() << " " << rights[i].size() << endl;
  // }

  bool possible = true;
  for(int i = 0; i < 26; i++) {
    if(mids[i].size() > 1 || lefts[i].size() > 1 || rights[i].size() > 1) { possible = false; break; }
  }

  if(!possible) {
    return false;
  } else {
    set<int> used;
    for(int i = 0; i < n; i++) {
      if(used.count(i)) continue;
      // cerr << s[i] << endl;

      bool changed = true;
      while(changed) {
        changed = false;

        for(int j = i + 1; j < n; j++) {
          if(used.count(j) || !isSame.count(j)) continue;
          
          if(s[i].back() == s[j].front()) {
            used.insert(j);
            s[i] = s[i] + s[j];
            changed = true;
            break;
          }
          else if(s[i].front() == s[j].back()) {
            used.insert(j);
            s[i] = s[j] + s[i];
            changed = true;
            break;
          }
        }

        if(changed) continue;

        for(int j = i + 1; j < n; j++) {
          if(used.count(j)) continue;

          if(s[i].back() == s[j].front()) {
            used.insert(j);
            s[i] = s[i] + s[j];
            changed = true;
            break;
          }
          else if(s[i].front() == s[j].back()) {
            used.insert(j);
            s[i] = s[j] + s[i];
            changed = true;
            break;
          }
        }
      }
      // cerr << " >> " << s[i] << endl;
    }

    result = "";
    for(int i = 0; i < n; i++) {
      if(used.count(i)) continue;
      result += s[i];
    }
    return check(result);
  }
}

// bool solveBetter() {
//   vector<vector<int>> mids(26), lefts(26), rights(26), sames(26);
//   for(int i = 0; i < n; i++) {
//     bool fst = true; char prev = s[i].front();
//     for(int j = 0; j < s[i].length(); j++) {
//       if(s[i][j] == prev) continue;

//       if(!fst && j != s[i].length() - 1) {
//         mids[prev - 'A'].push_back(i);
//       }
//       prev = s[i][j];
//       fst = false;
//     }
//     if(fst) { // all same letter
//       sames[s[i].front() - 'A'].push_back(i);
//     } else {
//       lefts[s[i].front() - 'A'].push_back(i);
//       rights[s[i].back() - 'A'].push_back(i);
//     }
//   }

//   bool possible = true;
//   for(int i = 0; i < 26; i++) {
//     if(mids[i].size() > 1 || lefts[i].size() > 1 || rights[i].size() > 1) { possible = false; break; }
//   }

//   set<int> used;
//   for(int i = 0; i < n; i++) {
//     for(int idx : sames[s[i].front() - 'A']) {
//       if(!used.count(idx)) {
//         used.insert(idx);
//         s[i] = s[idx] + s[i];
//       }
//     }
//     for(int idx : sames[s[i].back() - 'A']) {
//       if(!used.count(idx)) {
//         used.insert(idx);
//         s[i] = s[i] + s[idx];
//       }
//     }
//     while(!rights[s[i].front() - 'A'].empty() && !used.count(rights[s[i].front() - 'A'][0])) {
//       // cerr << "append left " << rights[res.front() - 'A'][0] << endl;
//       used.insert(rights[s[i].front() - 'A'][0]);
//       s[i] = s[rights[s[i].front() - 'A'][0]] + s[i];
//     }
//     while(!lefts[s[i].back() - 'A'].empty() && !used.count(lefts[s[i].back() - 'A'][0])) {
//       // cerr << "append right " << lefts[res.back() - 'A'][0] << endl;
//       used.insert(lefts[s[i].back() - 'A'][0]);
//       s[i] = s[i] + s[lefts[s[i].back() - 'A'][0]];
//     }
//   }
// }

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d\n", &n);

    for(int i = 0; i < n; i++)
      cin >> s[i];

    if(solveHard()) {
      printf("Case #%d: %s\n", tc, result.c_str());
    } else {
      printf("Case #%d: IMPOSSIBLE\n", tc);
    }
  }
  return 0;
}

