package com.frame.behavior.command;

public class Invoker {
    Command command;

    void setCommand(Command command) {
        this.command = command;
    }

    void invoke() {
        command.excute();
    }
}
