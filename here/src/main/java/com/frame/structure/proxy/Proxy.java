package com.frame.structure.proxy;

public class Proxy implements Target {

    public void method() {
        new ConcreteTarget().method();
    }
}
