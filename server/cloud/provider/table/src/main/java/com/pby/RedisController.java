package com.pby;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Component;

@Component
public class RedisController {
    @Autowired
    RedisTemplate redisTemplate;

    public String getRedisData() {
        Object val = redisTemplate.opsForValue().get("testkey");
        if (val == null) {
            return "empty";
        }
        return (String)val;
    }

    public void setRedisData(String value) {
        redisTemplate.opsForValue().set("testkey", value);
    }
}
