package com.frame.behavior.iterator;

public class ConcreteStructure implements Structure {
    public Iterator getIterator() {
        return new ConcreteIterator();
    }
}
