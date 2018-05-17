package com.pby;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class TableController {

    @Autowired
    RedisController redisController;

    @GetMapping(value = "tables")
    String getAccordingToShop(@RequestParam("shopid") String id) {
        String append = "last store " + redisController.getRedisData();
        append += "\n current set " + id;
        redisController.setRedisData(id);
        return append;
    }

    @GetMapping(value = "allcode")
    String listQrCode(@RequestParam("shopid") String id) {
        return "code for " + id;
    }

    @GetMapping(value = "qrcode")
    String getQrCode(@RequestParam("tableid") String id) {
        return "code for table " + id;
    }

}
