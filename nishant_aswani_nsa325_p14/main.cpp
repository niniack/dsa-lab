
#include "hash.hpp"
#include <iostream>

using namespace std;

int main(){
  string text = "DDDDABDABAABABCADACCBBADCCDAAADBCBDAAADBCDABDCCCABDDDCCACBDCABDBDAACDCABCBACBAABD";
  string pattern = "ABC";

  Hasher hash;

  cout << "Simple Hash:" << endl;
  hash.checkSubstring(text, pattern, "simpleHash");
  cout << endl;


  cout << "Polynomial Rolling Hash:" << endl;
  hash.checkSubstring(text, pattern, "polynomialRollingHash");
  cout << endl;


  cout << "Despite pattern matching being in O(1) time, we see that calculating the hash for each window in text string is costly." << endl;
  cout << "In fact, to calculate the hash of the window, you must iterate through all the characters anyways, making the hashing technique worthless." << endl;
  cout << "What may be more efficient is to exploit the benefit of the rolling hash and simply subtract the first term and add the new term." << endl;
  cout << "In this way, we can calculate the rolling hash once in the beginning, and carry out simple additions and subtractions for the rest of the search." << endl << endl;

  cout << "Within the text, certain windows are repeated, hence we are recomputing hashes for windows that we already did before." << endl;
  cout << "Hence, one way is that we could precompute all of the hashes once, each time checking if the hash for a value has already been computed." << endl;
  cout << "When pattern matching, we simply do a look up of hashes which is truly in O(1) time. When a hash matches, only then do we iterate throught the strings to confirm." << endl;
  cout << endl;

  

}
