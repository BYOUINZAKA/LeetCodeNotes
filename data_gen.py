'''
@Author: Hata
@Date: 2020-07-10 23:00:38
@LastEditors: Hata
@LastEditTime: 2020-07-11 19:20:03
@FilePath: \LeetCode\data_gen.py
@Description: 
'''
import random

MAX_DATA_COUNT = 1000
MAX_DATA_VALUE = 500

datas = ""

for i in range(MAX_DATA_COUNT):
    datas = datas + str(random.randint(1, MAX_DATA_VALUE))
    if i != MAX_DATA_COUNT - 1:
        datas = datas + ", "

lines = [
    "#ifndef __DATA_H_ \n",
    "#define __DATA_H_ \n",
    ("#define _LIST %s" % (datas)),
    "\n#endif"
]

with open('data_1388.h', 'w+') as file:
    file.writelines(lines)
    pass

print("success")
