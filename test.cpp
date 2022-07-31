#include <bits/stdc++.h>
using namespace std;

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };i

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  unordered_set<int> hash_set(nums1.begin(), nums1.end());
  for(auto x : hash_set) cout<<x<<" ";
  vector<int> res ;
  //! ---> ***
  // for (auto it : nums2) {
  //     if (hash_set.count(it)) {
  //         res.push_back(it);i
  //         hash_set.erase(it);
  //     }
  // }
  return res;
}

char findTheDifference(string s, string t) {
  map<char, int> m;
  for(auto c : s) m[c]++;
  for(auto c : t) {
      m[c]--;
      if (m[c] < 0) {
        cout<<m[c]<<" "<<c<<endl;
        return c;
      }
  }
  return '\0';
}


string capitalizeTitle(string title) {
  cout<<title<<endl;
  transform(begin(title), end(title), begin(title), ::tolower);
  cout<<title<<endl;
  
  int i = 0;  // point to the start of a word
  int j = 0;  // point to the end of a word

  while (j < title.length()) {
    while (j < title.length() && title[j] != ' ')
      ++j;
    if (j - i > 2)
      title[i] = toupper(title[i]);
    i = j + 1;
    ++j;  // skip the space
  }

  return title;
}

int main() {
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->left->right = new TreeNode(5);
  // root->right = new TreeNode(3);
  string s;
  cout<<"Enter a string : ";
  cin>>s;
  cout<<capitalizeTitle(s);
  return 0;
}