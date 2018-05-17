package com.pby;

import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.messaging.Message;

@EnableBinding(Sink.class)
public class StreamReceiver {
    @StreamListener(Sink.INPUT)
    public void receive(Message<String> message) {
        System.out.println("sink received " + message.getPayload());
    }
}
