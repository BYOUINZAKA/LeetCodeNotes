'''
@Author: Hata
@Date: 2020-05-11 20:20:27
@LastEditors: Hata
@LastEditTime: 2020-05-11 20:26:10
@FilePath: \LeetCode\commit_push.py
@Description: 
'''

import os
import time

if __name__ == "__main__":
    add = "git add ."
    commit = 'git commit -m "%s"' % (
        time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))
    push = "git push origin master"
    pause = "pause"
    os.system(add)
    os.system(commit)
    os.system(push)
    os.system(pause)
