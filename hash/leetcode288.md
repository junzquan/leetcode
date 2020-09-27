# [288. 单词的唯一缩写](https://leetcode-cn.com/problems/unique-word-abbreviation/)

## 哈希

```cpp
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (auto& s : dictionary)
        {
            string abbr = toAbbr(s);
            abbrCounts[abbr]++;
            wordCounts[s]++;
        }
    }
    
    bool isUnique(string word) {
        string abbr = toAbbr(word);
        return abbrCounts.find(abbr) == abbrCounts.end()
            || (wordCounts.count(word) != 0 && abbrCounts[abbr] == wordCounts[word]);
    }

    string toAbbr(string& s)
    {
        int s_len = s.length();
        string abbr;
        if (s_len - 2 <= 0)
        {
            abbr = s;
        }
        else
        {
            abbr = s[0] + to_string(s_len - 2) + s.back();
        }
        return abbr;
    }

private:
    unordered_map<string, int> abbrCounts;
    unordered_map<string, int> wordCounts;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
```

- 建立两个哈希表，一个是用于记录字典中单词缩写出现的次数 `abbrCounts`，另一个用于记录字典中单词出现的次数 `wordCounts`；

- 判断 `word` 是否唯一缩写有两种情况：
  - `word` 的缩写不在缩写哈希表 `abbrCounts` 中；
  - `word` 在字典中出现的次数与缩写哈希表表中记录的次数一致。例如，对于字典 [ 'apple', 'apple', 'boy' ]，`wordCounts["apple"] == 2` 且 `abbrCounts["a3e"] == 2` ，则这种情况下，如果查询的 `word` 为 `apple` ，也应该返回 `true` ，因为它们的缩写都是唯一的 `a3e` 。