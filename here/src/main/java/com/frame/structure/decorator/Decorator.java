package com.frame.structure.decorator;

public class Decorator implements Component {
    Component component;

    public Decorator(Component component) {
        this.component = component;
    }

    public void method() {
        component.method();
    }
}
