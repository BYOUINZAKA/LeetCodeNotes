/*
 * @Author: Hata
 * @Date: 2020-07-24 22:10:35
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-26 18:54:33
 * @FilePath: \LeetCode\895.js
 * @Description: https://leetcode-cn.com/problems/maximum-frequency-stack/
 */

class FreqStack {
    constructor() {
        this.freq = new Map();
        this.stacks = new Map();
        this.maxFreq = 0;
    }

    /**
     * @param {number} x
     * @return {void}
     */
    push(x) {
        const currFreq = this.freq.has(x) ? this.freq.get(x) + 1 : 1;

        this.maxFreq = Math.max(this.maxFreq, currFreq);

        this.freq.set(x, currFreq);
        this.stacks.has(currFreq) ? this.stacks.get(currFreq).push(x) : this.stacks.set(currFreq, [x]);
    }

    /**
     * @return {number}
     */
    pop() {
        const result = this.stacks.get(this.maxFreq).pop();

        this.freq.set(result, this.maxFreq - 1);
        !this.stacks.get(this.maxFreq).length && --this.maxFreq;
        return result;
    }
};

/**
 * @param {number[]} arr
 * @return {Object}
 */
const NewArray = (_array = []) => {
    let array = _array;
    return {
        set: (newArray) => {
            array = newArray;
        },
        toString: () => {
            return `[${array.toString()}]`;
        },
        push: (val) => {
            array.push(val);
        },
        pop: () => {
            return array.pop();
        }
    };
};

const array = NewArray([1, 2, 3]);
console.log(array.toString());

array.push(4);
console.log(array.toString());

array.set([0, 0, 0, 0, 0]);
console.log(array.toString());

array.pop();
console.log(array.toString());