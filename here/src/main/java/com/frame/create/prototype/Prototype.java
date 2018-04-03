package com.frame.create.prototype;

import com.frame.create.builder.Product;

public class Prototype implements Cloneable{
    boolean attr;
    @Override
    protected Object clone() throws CloneNotSupportedException {
        Prototype copy = new Prototype();
        copy.attr = attr;
        return copy;

    }
}
