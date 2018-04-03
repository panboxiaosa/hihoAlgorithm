package com.frame.structure.bridge;

public class ConcreteTarget extends Target {
    public void method() {
        implementor.method();
    }
}
