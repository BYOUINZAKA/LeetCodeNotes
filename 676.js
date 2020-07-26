/*
 * @Author: Hata
 * @Date: 2020-07-24 20:50:01
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-24 21:57:46
 * @FilePath: \LeetCode\676.js
 * @Description: https://leetcode-cn.com/problems/implement-magic-dictionary/
 */

/**
 * Initialize your data structure here.
 */
var MagicDictionary = function () {
    this._buckets = new Map();
    this._hammingDistance = (lhs, rhs) => {
        let res = 0;
        for (let i in lhs) {
            if (lhs.charAt(i) != rhs.charAt(i)) {
                if (++res > 1) break;
            }
        }
        return res;
    };
};

/**
 * Build a dictionary through a list of words 
 * @param {string[]} dict
 * @return {void}
 */
MagicDictionary.prototype.buildDict = function (dict) {
    dict.forEach(val => {
        const len = val.length;
        if (this._buckets.has(len)) {
            this._buckets.get(len).push(val);
        } else {
            this._buckets.set(len, new Array(val));
        }
    });
};

/**
 * Returns if there is any word in the trie that equals to the given word after modifying exactly one character 
 * @param {string} word
 * @return {boolean}
 */
MagicDictionary.prototype.search = function (word) {
    const len = word.length;
    if (!this._buckets.has(len)) return false;
    const fixedWords = this._buckets.get(len);
    for (let candidate of fixedWords) {
        const dis = this._hammingDistance(candidate, word);
        if (dis === 1) return true;
    }
    return false;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * var obj = new MagicDictionary()
 * obj.buildDict(dict)
 * var param_2 = obj.search(word)
 */

const dict = new MagicDictionary();
dict.buildDict(["hello", "leetcode", "apple"]);
console.log(dict.search("apply"));