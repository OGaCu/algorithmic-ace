#include "utils.h"

/* submitted solution */

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        // set<actual word>
        // map<lowercase, actualWord>, 
        // map<vowelsTo*, actualWord>
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> words_lower;
        words_lower.reserve(wordlist.size() * 2); // bcuz rehash is expensive
        unordered_map<string, string> words_mask;

        // populate each container
        for (string w : wordlist) {
            // if(!words_lower.count(toLower(w))) words_lower[toLower(w)] = w;
            words_lower.try_emplace(toLower(w), w); // same as line above; does nothing if key exists

            if(!words_mask.count(maskVowel(w))) words_mask[maskVowel(w)] = w;
        }

        // go through queries
        for (int i = 0; i < queries.size(); ++i) {
            string q = queries[i];

            if(words.find(q) != words.end()) continue;// exact
            else if(words_lower.contains(toLower(q))) q = words_lower[toLower(q)]; 
            else if(words_mask.contains(maskVowel(q))) q = words_mask[maskVowel(q)];
            else q = "";

            queries[i] = q;
        }
        return queries;
    }

private:
    bool isVowel(char c) {
        switch(c) {
            case 'a': case 'e': case 'i': case 'o': case 'u': return true;
            default: return false;
        }
    }

    string toLower(const string& text) {
        string lowerText = text;
        for (char& c : lowerText) {
            c = tolower(static_cast<unsigned char>(c));
        }
        return lowerText;
    }

    string maskVowel(const string& text) {
        string maskedText = toLower(text);
        for (char& c : maskedText) {
            if(isVowel(c)) c = '*';
        }
        return maskedText;
    }
};

/* alternative solution */

class Solution {
 public:
  vector<string> spellchecker(vector<string>& wordlist,
                              vector<string>& queries) {
    vector<string> ans;
    unordered_map<string, string> dict;

    for (const string& word : wordlist) {
      dict.insert({word, word});
      dict.insert({lowerKey(word), word});
      dict.insert({vowelKey(word), word});
    }

    for (const string& query : queries)
      if (const auto it = dict.find(query); it != dict.cend())
        ans.push_back(it->second);
      else if (const auto it = dict.find(lowerKey(query)); it != dict.cend())
        ans.push_back(it->second);
      else if (const auto it = dict.find(vowelKey(query)); it != dict.cend())
        ans.push_back(it->second);
      else
        ans.push_back("");

    return ans;
  }

 private:
  string lowerKey(const string& word) {
    string s{"$"};
    for (const char c : word)
      s += tolower(c);
    return s;
  }

  string vowelKey(const string& word) {
    string s;
    for (const char c : word)
      s += isVowel(c) ? '*' : tolower(c);
    return s;
  }

  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiouAEIOU";
    return kVowels.find(c) != string_view::npos;
  }
};