package com.frame.behavior.responselink;

public abstract class Handler {
    Handler next;
    public final void handleRequest() throws Exception {
        if (couldHandle()) {
            handle();
        } else {
            if (next != null) {
                next.handleRequest();
            } else {
                throw new Exception();
            }
        }

    }

    protected abstract void handle();

    protected abstract boolean couldHandle();

}
