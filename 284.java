/*
 * @Author: Hata
 * @Date: 2020-07-23 21:19:52
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-23 21:54:41
 * @FilePath: \LeetCode\284.java
 * @Description: 
 */
// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

import java.util.*;

class PeekingIteratorParams<T> implements Iterator<T> {
    private T currentValue;
    private Iterator<T> iterator;

    public PeekingIteratorParams(Iterator<T> iterator) {
        // initialize any member here.
        currentValue = null;
        this.iterator = iterator;
    }

    // Returns the next element in the iteration without advancing the iterator.
    public T peek() {
        if (currentValue == null)
            currentValue = iterator.next();
        return currentValue;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public T next() {
        var res = currentValue != null ? currentValue : iterator.next();
        if (currentValue != null)
            currentValue = null;
        return res;
    }

    @Override
    public boolean hasNext() {
        return currentValue != null || iterator.hasNext();
    }
}

class PeekingIterator extends PeekingIteratorParams<Integer> {
    public PeekingIterator(Iterator<Integer> iterator) {
        super(iterator);
    }

    public static void main(String[] args) {
        var sites = Arrays.asList("Google", "Tencent", "Baidu", "Alibaba");
        PeekingIteratorParams<String> pip = new PeekingIteratorParams<String>(sites.iterator());
        while (pip.hasNext()) {
            System.out.print(pip.next() + (pip.hasNext() ? ", " : "\n"));
        }
        var array = Arrays.asList(21, 53, 1, 7, 324, 8567, 32, 86, 2134);
        PeekingIterator pi = new PeekingIterator(array.iterator());
        while (pi.hasNext()) {
            System.out.print(pi.next() + (pi.hasNext() ? ", " : "\n"));
        }
    }
}