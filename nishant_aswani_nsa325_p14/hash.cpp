#include <iostream>
#include <vector>
#include "hash.hpp"

using namespace std;

Hasher::Hasher() {};
Hasher::~Hasher() {};

void Hasher::checkSubstring(string text, string pattern, string hashType){

  bool match = false;

  vector<int> positiveHits;
  vector<int> falseHits;

  //  obtain difference in length
  int difference = text.length() - pattern.length();

  int patternLength =  pattern.length();

  //  if difference is negative, exit function
  if (difference < 0){
    cout << "Pattern is longer than search text";
    return;
  }

  //  compute the hash of the pattern
  int patternHash = (hashType == "polynomialRollingHash") ? getPRHash(pattern) : getSimpleHash(pattern);

  //  iterate through the text to look for the pattern hash
  for (int i=0; i<difference+1; ++i){

    //  make window
    string slicedText = text.substr(i, patternLength);

    //  get hash of window
    int textHash = (hashType == "polynomialRollingHash") ? getPRHash(slicedText) : getSimpleHash(slicedText);

    //  check if hit is false
    if(patternHash == textHash){
      match = true;
      confirmMatch(text, pattern, i, positiveHits, falseHits);
    }
  }

  // if no matches were found
  if(!match){
    cout << "Pattern not found" << endl;
  }

  // if matches were found
  else{

    cout << "True matches found at indices: ";
    for(unsigned int i=0; i<positiveHits.size(); ++i){
      cout << positiveHits[i] << ", ";
    }
    cout << endl;

    cout << "False matches found at indices: ";
    for(unsigned int i=0; i<falseHits.size(); ++i){
      cout << falseHits[i] << ", ";
    }
    cout << endl;
  }

  return;
}

void Hasher::confirmMatch(string text, string pattern, int i, vector<int> &positiveHits, vector<int> &falseHits){

  bool falseMatch = false;

  for(unsigned int j=0; j<pattern.length(); ++j){

    if(text[i+j] != pattern[j]){
      falseMatch = true;
      falseHits.push_back(i);
      break;
    }
  }

  if (!falseMatch){
    positiveHits.push_back(i);
  }

}

int Hasher::getSimpleHash(string s) const{

  int hash = 0;

  for (unsigned int i=0; i<s.length(); ++i){
    switch (s[i]){
      case 'A':
          hash+=1;
          break;
      case 'B':
          hash+=2;
          break;
      case 'C':
          hash+=4;
          break;
      case 'D':
          hash+=2;
          break;
      default:
          break;
    }
  }
  return hash;
}

long long Hasher::getPRHash(string s) const{

  const int p = 31;
  const int m = 1e9 + 9;

  long long hash = 0;
  long long factor = 1;

  for (unsigned int i=0; i<s.length(); ++i){

    int mapped_val;

    switch (s[i]){
      case 'A':
          mapped_val=1;
          break;
      case 'B':
          mapped_val=2;
          break;
      case 'C':
          mapped_val=4;
          break;
      case 'D':
          mapped_val=2;
          break;
      default:
          break;
    }

    hash = (hash + mapped_val*factor)%m;
    factor = (factor*p)%m;
  }
  return hash;
}
