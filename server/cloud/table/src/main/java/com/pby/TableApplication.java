package com.pby;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@EnableDiscoveryClient
@SpringBootApplication
public class TableApplication {

    public static void main(String[] argv) {
        new SpringApplicationBuilder(TableApplication.class).web(true).run(argv);
    }
}
