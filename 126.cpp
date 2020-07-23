/*
 * @Author: Hata
 * @Date: 2020-07-01 18:16:00
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-01 23:35:04
 * @FilePath: \LeetCode\126.cpp
 * @Description: https://leetcode-cn.com/problems/word-ladder-ii/solution/
 */
#include <bits/stdc++.h>

class Solution
{
    bool isNextWord(const std::string &forward, const std::string &current)
    {
        int count = 0;
        for (int i = 0; i < forward.length() && count < 2; ++i)
        {
            count += (forward[i] != current[i]);
        }
        return count == 1;
    }

    std::vector<std::string> getChildren(std::string &node)
    {
        std::vector<std::string> res;
        if (length > 26)
        {
            for (auto &&c : node)
            {
                char old = c;
                for (c = 'a'; c <= 'z'; ++c)
                {
                    if (c == old)
                        continue;
                    if (dict.find(node) != dict.end())
                        res.push_back(node);
                }
            }
        }
        else
        {
            for (auto &&word : wordList)
            {
                if (dict[word] != dict[node] && isNextWord(node, word))
                    res.push_back(word);
            }
        }
        return std::move(res);
    }

public:
    std::vector<std::vector<std::string>> findLadders(std::string &beginWord, std::string &endWord, std::vector<std::string> &wordList)
    {
        std::vector<std::vector<std::string>> res;
        length = wordList.front().length();

        for (int i = 0; i < wordList.size(); ++i)
        {
            dict[wordList[i]] = i;
        }

        if (dict.find(endWord) == dict.end())
            return res;

        if (dict.try_emplace(beginWord, wordList.size()).second)
            wordList.push_back(beginWord);
        this->wordList = std::move(wordList);

        bfs(beginWord, endWord, res);

        return res;
    }

    void bfs(std::string &beginWord, std::string &endWord, std::vector<std::vector<std::string>> &res)
    {
        std::queue<std::vector<std::string>> queue;
        queue.push(std::vector<std::string>{beginWord});

        std::unordered_set<std::string> visited;
        visited.insert(beginWord);

        bool isFound = false;

        while (!queue.empty())
        {
            int size = queue.size();
            std::unordered_set<std::string> sub_visited;
            for (int _ = 0; _ < size; ++_)
            {
                auto &&path = queue.front();
                auto &&back = path.back();
                auto &&children = getChildren(back);
                for (auto &&child : children)
                {
                    if (visited.find(child) != visited.end())
                        continue;
                    path.push_back(child);
                    if (dict[child] == dict[endWord])
                    {
                        isFound = true;
                        res.push_back(path);
                    }
                    queue.push(path);
                    path.pop_back();
                    sub_visited.insert(child);
                }
                queue.pop();
            }
            if (isFound)
                break;
            visited.merge(std::move(sub_visited));
        }
    }

private:
    int length;
    std::vector<std::string> wordList;
    std::unordered_map<std::string, int> dict;
};