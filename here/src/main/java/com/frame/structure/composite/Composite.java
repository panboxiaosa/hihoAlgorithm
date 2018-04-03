package com.frame.structure.composite;

import java.util.ArrayList;
import java.util.List;

public class Composite extends Component {
    List<Component> subs = new ArrayList<Component>();
    @Override
    public void add(Component item) {
        subs.add(item);
    }
}
