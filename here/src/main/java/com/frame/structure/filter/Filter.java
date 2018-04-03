package com.frame.structure.filter;

import java.util.List;

public interface Filter {
    List<Item> filter(List<Item> source);
}
