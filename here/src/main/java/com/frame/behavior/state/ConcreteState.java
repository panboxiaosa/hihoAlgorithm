package com.frame.behavior.state;

public class ConcreteState implements State {
    public void action(Context context) {
        context.setState(this);
    }
}
