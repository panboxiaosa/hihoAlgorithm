package com.pby;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class ShopController {

    @GetMapping(value = "shop")
    String getAccordingToOwner(@RequestParam("ownerid") String id) {
        return "shop of " + id;
    }

    @GetMapping(value = "authoured")
    String getShopCode(@RequestParam("code") String code) {
        return "shop of " + code;
    }
}
