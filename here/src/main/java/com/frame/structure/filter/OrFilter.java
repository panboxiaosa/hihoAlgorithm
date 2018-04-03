package com.frame.structure.filter;

import java.util.LinkedList;
import java.util.List;

public class OrFilter implements Filter {
    Filter one;
    Filter another;

    public OrFilter(Filter one, Filter another) {
        this.one = one;
        this.another = another;
    }

    public List<Item> filter(List<Item> source) {
        List<Item> resultOne = one.filter(source);
        List<Item> resultTwo = another.filter(source);

        for (Item item : resultOne) {
            if (!resultTwo.contains(item)) {
                resultTwo.add(item);
            }
        }
        return resultTwo;
    }

}
