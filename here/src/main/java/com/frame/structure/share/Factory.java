package com.frame.structure.share;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Factory {
    Map<String, Product> store = new HashMap<String, Product>();

    Product get(String key) {
        if (store.containsKey(key)) {
            return store.get(key);
        } else {
            Product one = new Product() {
                public void method() {

                }
            };
            store.put(key, one);
            return one;
        }

    }
}
