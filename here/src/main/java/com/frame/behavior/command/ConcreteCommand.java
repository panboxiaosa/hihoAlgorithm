package com.frame.behavior.command;


public class ConcreteCommand implements Command {
    public void excute() {
        receiver.action();
    }

    Receiver receiver;

    public ConcreteCommand(Receiver receiver) {
        this.receiver = receiver;
    }
}
