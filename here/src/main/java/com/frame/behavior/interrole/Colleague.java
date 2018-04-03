package com.frame.behavior.interrole;

public abstract class Colleague {
    Mediator mediator;
    public Colleague(Mediator mediator) {
        this.mediator = mediator;
    }
    public void concat(Colleague colleague) {
        mediator.contact(colleague);
    }
}
