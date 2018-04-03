package com.frame.structure.bridge;

public abstract class Target {
    Implementor implementor;

    public abstract void method();

    public void SetImplementor(Implementor implementor) {
        this.implementor = implementor;
    }
}
