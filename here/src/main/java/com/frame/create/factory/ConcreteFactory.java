package com.frame.create.factory;

public class ConcreteFactory implements Factory{

    public Product create() {
        return new ConcreteProduct();
    }
}
