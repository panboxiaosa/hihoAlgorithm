package com.frame.structure.filter;

import java.util.List;

public class AndFilter implements Filter {

    Filter one;
    Filter another;
    public List<Item> filter(List<Item> source) {
        return one.filter(another.filter(source));
    }

    public AndFilter(Filter one, Filter another) {
        this.one = one;
        this.another = another;
    }
}
