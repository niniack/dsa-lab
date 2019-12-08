#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Hasher{

private:
  void confirmMatch(string text,
                    string pattern,
                    int i,
                    vector<int> &positiveHits,
                    vector<int> &falseHits);

public:
  Hasher();
  ~Hasher();

  int getSimpleHash(string s) const;
  long long getPRHash(string s) const;

  void checkSubstring(string text, string pattern, string hashType);
};
