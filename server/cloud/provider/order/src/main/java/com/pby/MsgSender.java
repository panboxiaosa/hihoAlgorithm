package com.pby;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.messaging.Source;
import org.springframework.messaging.MessageChannel;
import org.springframework.messaging.support.MessageBuilder;

@EnableBinding(Source.class)
public class MsgSender {

    @Autowired
    @Qualifier("output")
    MessageChannel output;

    public void send() {
        output.send(MessageBuilder.withPayload("hello i am source").build());
    }
}
