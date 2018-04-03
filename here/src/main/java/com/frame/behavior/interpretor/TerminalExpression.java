package com.frame.behavior.interpretor;

import java.util.List;

public class TerminalExpression implements Expression {
    List<Expression> subs;
    public void interpreter(Context context) {

    }
    TerminalExpression(List<Expression> expressions) {
        subs = expressions;
    }
}
