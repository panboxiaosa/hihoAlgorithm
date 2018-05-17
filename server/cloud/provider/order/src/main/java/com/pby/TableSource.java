package com.pby;

import org.springframework.amqp.core.AmqpTemplate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.messaging.Source;
import org.springframework.messaging.MessageChannel;
import org.springframework.messaging.support.MessageBuilder;
import org.springframework.stereotype.Component;

@Component
public class TableSource {

    @Autowired
    AmqpTemplate rabbitTemplate;

    public void sendToTable() {
        rabbitTemplate.convertAndSend("hello", "little rabbit");
    }
}
