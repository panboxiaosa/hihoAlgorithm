package com.frame.create.absfactory;

public class ConcreteFactory implements AbsFactory{

    public ProductA createA() {
        return new ConcreteA();
    }

    public ProductB createB() {
        return new ConcreteB();
    }
}
