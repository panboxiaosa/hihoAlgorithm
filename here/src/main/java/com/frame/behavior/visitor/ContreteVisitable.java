package com.frame.behavior.visitor;

public class ContreteVisitable implements Visitable {
    public void accept(Visitor visitor) {
        visitor.visitContrete(this);
    }
}
