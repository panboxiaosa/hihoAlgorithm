package com.pby;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class DishController {
    @GetMapping(value = "dishes")
    String getAvaliableDishes(@RequestParam("tableid") String id){
        return "dishes for " + id;
    }
}
