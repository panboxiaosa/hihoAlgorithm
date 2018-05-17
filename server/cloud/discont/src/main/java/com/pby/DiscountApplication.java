package com.pby;

import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@EnableDiscoveryClient
@SpringBootApplication
public class DiscountApplication {
    public static void main(String[] argv) {
        new SpringApplicationBuilder(DiscountApplication.class).web(true).run(argv);
    }
}
