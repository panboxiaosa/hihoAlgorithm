package com.frame.behavior.observer;

import java.util.List;

public abstract class Observable {
    private List<Observer> observers;

    public void add(Observer observer) {
        observers.add(observer);
    }

    public void notifyAllObser() {
        for (Observer observer : observers) {
            observer.update();
        }
    }
}
