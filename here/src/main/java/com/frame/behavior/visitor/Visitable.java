package com.frame.behavior.visitor;

public interface Visitable {
    void accept(Visitor visitor);
}
