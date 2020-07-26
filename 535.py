'''
@Author: Hata
@Date: 2020-07-25 16:41:35
@LastEditors: Hata
@LastEditTime: 2020-07-25 17:16:38
@FilePath: \LeetCode\535.py
@Description: https://leetcode-cn.com/problems/encode-and-decode-tinyurl/solution/
'''

import random


class Codec:

    def __init__(self):
        self.length = 6
        self.map = {}
        self.encoded = {}
        self.alphabet = list(
            '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ')

    def getRandom(self):
        alphabet_size = len(self.alphabet)
        res = [self.alphabet[random.randint(
            0, alphabet_size-1)] for _ in range(self.length)]
        return ''.join(res)

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        if longUrl in self.encoded:
            return self.encoded[longUrl]

        key = self.getRandom()
        while key in self.map:
            key = self.getRandom()

        res = 'http://%s/' % key
        self.map[key] = longUrl
        self.encoded[longUrl] = res
        return res

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.map[shortUrl[len('http://'): -1]]


# Your Codec object will be instantiated and called as such:
codec = Codec()

short = codec.encode(
    'https://www.cnblogs.com/liuhui0308/archive/2020/03/28/12588244.html#_lab2_0_1')
longs = codec.decode(short)
print(short, longs)

short = codec.encode('https://blog.csdn.net/qq_32811489/')
longs = codec.decode(short)
print(short, longs)

short = codec.encode(
    'https://leetcode-cn.com/problems/encode-and-decode-tinyurl/solution/tinyurlde-jia-mi-yu-jie-mi-by-leetcode/')
longs = codec.decode(short)
print(short, longs)

short = codec.encode('https://www.zhihu.com/')
longs = codec.decode(short)
print(short, longs)
