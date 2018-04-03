package com.frame.structure.outface;

import com.frame.structure.decorator.Component;

public class OutStand {
    ComponentA a;
    ComponentB b;
    public void work() {
        a.work();
        b.work();
    }

    public OutStand(ComponentA a, ComponentB b) {
        this.a = a;
        this.b = b;
    }
}
