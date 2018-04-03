package com.frame.create.builder;

public class Product {
    boolean attr1;
    boolean attr2;

    private Product() {
    }

    public Product(Product target) {
        this.attr2 = target.attr2;
        this.attr1 = target.attr1;
    }

    public static class Builder {
        private Product target;

        public Builder() {
            target = new Product();
        }

        Builder attr1(boolean attr1) {
            target.attr1 = attr1;
            return this;
        }

        Builder attr2(boolean attr2) {
            target.attr2 = attr2;
            return this;
        }

        Product build() {
            return new Product(target);
        }
    }
}
