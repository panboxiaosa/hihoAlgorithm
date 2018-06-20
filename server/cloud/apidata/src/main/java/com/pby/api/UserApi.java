package com.pby.api;

import com.pby.model.User;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RequestMapping;

@RequestMapping("user-service-remote")
public interface UserApi {

    @GetMapping(value = "locate")
    User getUser(@RequestHeader("id") long id);
}
