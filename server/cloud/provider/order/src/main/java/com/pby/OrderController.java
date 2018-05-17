package com.pby;

import com.netflix.discovery.converters.Auto;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class OrderController {

    @Autowired
    TableSource tableSource;

    @Autowired
    MsgSender sender;

    @GetMapping(value = "order")
    String getCurrentOrder(@RequestParam("tableid") String id) {
        return "order of " + id;
    }

    @GetMapping(value = "confirm")
    String confirmOrder(@RequestParam("tableid")String id, @RequestParam("ordercontent") String content) {
        tableSource.sendToTable();
        return "confirm content " + content;
    }

    @GetMapping(value = "pay")
    String payOrder(@RequestParam("orderid") String id) {
        sender.send();
        return "pay " + id;
    }

    @GetMapping(value = "paytable")
    String payByTable(@RequestParam("tableid") String id) {
        return "pay " + id;
    }

}
